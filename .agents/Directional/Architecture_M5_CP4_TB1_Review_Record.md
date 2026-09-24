# M5-CP4-TB1 independent Review record

**Turn:** `M5-CP4-TB1-REV`
**Boundary:** runtime-free independent Review of CB1/TB1 immutable evidence
**Disposition:** **PREPUBLICATION ROW449 ACCEPTED / SELECTOR449 EXACTLY PRECOMMITTED / M5 CLOSURE HELD**

## 1. Evidence authority independently re-opened

Review re-opened the immutable primary evidence rather than inheriting the EXEC summary.

- CB1 compile/package run/job: `35934640705 / 107428875643`.
- CB1 result/log artifacts: `10782841045 / 10782293664`.
- CB1 provider ZIP SHA-256: `3772d2c323bb4995bcb4503960d1bef1251442a3a7a95d8c0660680008042da6`.
- CB1 semantic source: `535ec760b7c39dd437de69afebec568fafb44aab`.
- CB1 root `SHA256SUMS`: **26/26** verified; SHA-256 `ab5d9d7bdbc5583b3df69d781830dff91afe6b619386a6fde3c8e57447743985`.
- Packaged source archive SHA-256: `004be77dd02bd7f691cb3bf6a29aa551601b78a621e54dbdaa366f709e17112d`.
- CB1 metadata independently confirms `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and generated link authority contains both GMPXX and GMP.
- TB1 run/job: `35937669401 / 107438319768`.
- TB1 result/log artifacts: `10784376393 / 10784391222`.
- TB1 provider ZIP SHA-256: result `9860fa758b5d5be614d06314a67d65fdeefe4c70da0fe504d6166c47bcd24173`; log `f1d291a56c2cb9b45e7d6bd315540986ace57a51bb432477281c8e4cb9759f01`.
- TB1 result self-manifest: **912/912** verified; SHA-256 `c5c27d782d41d5a81fd6f3cd67c4ec7ebb14b2801195912e9590f9f66cfc4d8b`.

The Review source snapshot is run/artifact `35951539588 / 10787869520`, exact snapshot SHA `e0a0404e9743055d10340c8261586ca00ee5c084`, archive SHA-256 `91e2d746cd9b8b9aea1f75b81f9b82d7029798adbd7d2b6245bb32f998579c43`, **5305/5305** manifest entries, `runtimeExecution=false`.

## 2. Mechanical TB1 evidence independently re-derived

The 449-row execution ledger was parsed independently from the archived result:

- exact ordinals `1..449` with no gap or duplicate;
- **449 unique identities**;
- every row has `exit=0`, `selected=1`, `skipped=0`, `passed=1`, `result=PASS`;
- every one of the 449 raw-log SHA-256 values matches its ledger receipt;
- every raw log contains exactly one GTest `[ RUN ]`, exactly one `[ OK ]`, and zero `[ SKIPPED ]` lines;
- owner census is **32 authority-kernel / 301 producer / 75 completion / 41 validation**;
- protected ordinals 191/192/247/408/446/447/448/449 all PASS;
- benchmark executions are **0**;
- ledger SHA-256 independently re-hashes to `34eec870c0b5c198ff4ecf8a94eab608530daac65656f79920c31933e93c001c`;
- immutable postflight reports the package, packaged source, selector448 and routing448 unchanged.

Row449 is `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion` in `directional_surface_cell_producer_tests`. Its raw log SHA-256 is `0261f8d0a85c29f2b30fee2ce7706465678548122296e62d7f05184f194ce995`; it selects once, PASSes once, and reports no unmet frozen fact.

## 3. Non-vacuity adjudication against the six frozen facts

**Accepted for the prepublication gate.** The row449 test is not a conjunction of facts borrowed from different regions, fixtures or stages. It obtains one produced A4/phase-front product from the fixed `torus_fixture()` subject and binds every decisive assertion to one selected `SourceTopologyRegion`.

1. **Pipeline-produced fixed subject — proved.** `torus_fixture()` is `make_torus_pipeline_fixture()`: it loads the committed torus mesh/raw field, applies the fixed row408 18-edge user hard-rail set, calls `pipeline::remesh_from_raw_cross_field`, takes the retained `traceNetwork` product, and requires `Produced`. Row449 additionally asserts `disposition()==Produced` and `is_produced()`. It does not construct a draft product, inject isolation-sheet labels, or switch subjects after runtime.
2. **Same authoritative region spans at least two sheets — proved.** The test selects a region only when all `sourceAuthority.rows_for_region(region.id())` rows cover that region's faces and the region's authoritative `sheet_for_row` values contain at least two distinct `IsolationSheetId`s. The selected `region` object is then reused by facts 3-6.
3. **Internal isolation seam owned by that region — proved.** Row449 requires `region.isolation_seams()` nonempty. Independently, `SurfaceTopologyRegion::make` rejects an isolation seam that is also in the region boundary-edge set, so this authority is internal rather than a relabelled external boundary.
4. **Checked seam certificate for the same region/seam — proved.** The test finds a `SurfaceIsolationSeamTransportCertificate` whose `region()` equals the selected region and whose seam is one of that region's isolation seams, then independently checks region ownership of both faces, face-sheet authority, distinct sheets, exact seam/source incidence, source transition identity, row identities and reciprocal quarter-turn transport. Production builds these certificates through the checked factory; `SurfaceIsolationSeamTransportCertificate::make` independently enforces region/seam ownership, face ownership/incidence, distinct authoritative sheets and reciprocal transport. `SurfacePhaseFrontProduct::make` requires certificate keys to biject the product's expected region/seam keys.
5. **Canonical periodic quotient relation owned by the same region — proved.** Row449 filters `product.periodicHolonomies()` by `relation.sourceTopologyRegion()==region.id()`, requires at least one, and checks its ID against the independent carrier-content oracle `independent_periodic_relation_id(region.id(), route, cutRoute)`. That oracle derives the route/cut carrier tuples, canonicalizes only by simultaneous reversal, and calls `PeriodicRelationId::from_carriers`; it does not read the production relation ID. Product construction separately recomputes canonical relation identity and rejects renumbered/duplicate/conflicting/foreign-region authority.
6. **Reciprocal `PeriodicCut` pair explicitly names that exact owner — proved.** The test requires a `PeriodicCut` edge in the selected region whose `periodicRelation` is one of those canonical same-region relations, then checks the reciprocal opposite edge is also `PeriodicCut`, names the identical owner, remains in the same region, preserves shared A3 interval provenance, reverses the route/ordinal orientation, and has a distinct boundary occurrence. Product validation independently requires each `PeriodicCut` owner to exist, match the edge region, and agree reciprocally with its opposite edge.

These checks satisfy the `M5-DEFN-R2` same-subject producer reading. They do **not** use A5 occurrence-complex exact-once materialization, embedding, final mesh output or independent verifier acceptance. The M5/M6 ownership boundary therefore remains intact.

### Frozen falsifiers

- **F1 torus lacks the joined subject:** falsified by the green row449 region-scoped assertions.
- **F2 proof requires M6 authority:** not triggered; all decisive evidence is phase-front/A4 producer authority.
- **F3 multiple sheets exist only through injected labels/fixture mutation:** not triggered; sheets are read from the produced source-authority table and `torus_fixture()` injects no sheet labels.
- **F4 no periodic relation belongs to that same region:** falsified by the canonical same-region relation and reciprocal `PeriodicCut` owner checks.
- **F5 accepted prefix regresses:** not triggered; rows1-448 are 448/448 green in the same fresh ledger.
- **F6 product semantic change is required:** not triggered; CB1 changed one focused test only, and TB1 consumed the immutable compiled package.
- **F7 facts are combined across regions/fixtures:** not triggered; facts2-6 retain one `region` and one fixed `torus_fixture()` product.

## 4. Exact selector449 precommit

Review independently re-hashed accepted selector448 and its routing receipt, then constructed the only authorized append-only publication candidate locally. **These bytes are precommitted, not published in this Review.**

| Authority | Rows | SHA-256 | Required relation |
|---|---:|---|---|
| accepted selector448 | 448 | `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` | current accepted prefix |
| precommitted selector449 | 449 | `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` | first 448 rows hash exactly to selector448 |
| accepted routing448 | 448 | `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c` | owners 32/300/75/41 |
| precommitted routing449 | 449 | `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` | first 448 rows hash exactly to routing448; owners 32/301/75/41 |

Exact appended selector line:

`M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`

Exact appended routing line:

`449<TAB>M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion<TAB>directional_surface_cell_producer_tests`

`M5-CP4-CB2` may publish **only** these exact bytes under `Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt` and `Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv`. Any other ordering, identity, prefix, owner or hash returns to Review.

## 5. Authority and observation disposition

- `M5-CP3-TB2-REV-OBS-01`: **PREPUBLICATION PROOF ACCEPTED / CLOSURE GATE STILL OPEN.** The semantic gap it identified is now non-vacuously proved on the frozen subject, but the frozen sequence still requires selector449 publication, fresh cumulative TB2 execution and final Review. Ownership advances to `M5-CP4-CB2 -> M5-CP4-TB2-EXEC -> M5-CP4-TB2-REV`.
- `M5-DEFN-R1-REV-OBS-01`: retained as process history. This Review does not treat it as a semantic blocker; the final COMPLETE beacon remains required as the last repository write.
- `M5-CP4-TB1-EXEC-OBS-01`: **CONFIRMED PROCESS-ONLY / +0.** Workload-gated schema validation succeeded before runtime; it changes no runtime bytes or semantic evidence and repeats an already-recorded control-plane limitation.
- `M5-CP4-TB1-EXEC-OBS-02`: **CONFIRMED PROCESS-ONLY / +0.** The first documentation transport was rejected before commit/push on an expected/actual path mismatch; the runtime/package evidence is unaffected.
- `M5-CP4-TB1-REV-OBS-01`: **RECORDED PROCESS-ONLY / +0.** The first Review documentation-apply caller reached GitHub as `startup_failure` before any workload job because its caller permission ceiling omitted `id-token: write`, which the durable Google Drive reusable requires for OIDC. The caller was corrected before a diagnosed retry; the retry schema validation and Drive apply completed successfully. No runtime, package, selector, source, or semantic evidence was affected. This is the already-known reusable-workflow permission-ceiling failure class and adds no new `LESSONS.md` pattern.
- No semantic regression candidate is created. Stable accounting remains **51 events / 14 categories / 37 recurrences**; the sole project produced-witness debt remains the separate M6-owned closed-complex debt.

Accepted M5 runtime authority remains selector448 and package/source `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`. TB1/CB1 are accepted as **prepublication evidence only**. §13.1 conjunct8 is still not milestone-accepted, selector449 is not published, and M5 closure remains held.

## 6. Document consolidation

This Review retains the current TB1 runtime report, this Review record, the current frozen/definition/closure records, selectors, and exactly one forward plan. It folds three now-historical per-turn records into `M5_Consolidated_Record.md` §§4.35-4.37/§5 and git history:

- `Architecture_M5_CP4_CB1_Multi_Isolation_Quotient_Witness_Plan.md` — consumed CB1 plan;
- `Architecture_M5_CP4_CB1_Code_Build_Report.md` — superseded CB1 build report;
- `Architecture_M5_DEFN_R1_G4_B004_Review_Record.md` — superseded predecessor Review.

No normative definition, selector, closure record, current runtime report or current Review record is folded.

## 7. Successor

Exactly one successor is authorized: runtime-free **`M5-CP4-CB2`** under `Architecture_M5_CP4_CB2_Selector_449_Publication_Code_Build_Plan.md`.

It publishes only the exact precommitted selector449/routing449 bytes, compiles/packages the four standard owner executables through mandatory GMP/GMPXX authority, and executes no Directional binary. It must stop on any selector/prefix/routing/hash drift, any product/test/fixture/field semantic change, any non-GMP compile authority, package-owner incompleteness, or any attempted runtime execution.

After compile-green, the only semantic successor is artifact-only `M5-CP4-TB2-EXEC`; final `M5-CP4-TB2-REV` alone may accept conjunct8 and close M5.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; routing448 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`. |
| Decisive claims independently re-derived | CB1/TB1 provider hashes and manifests; all 449 ledger/raw outcomes; row449 fixed-subject construction; six same-region facts; checked seam factory; canonical relation-ID oracle/product validation; reciprocal `PeriodicCut` owner checks. |
| Non-vacuity checked | **PASS.** One fixed produced torus product and one selected topology region own facts2-6; no separate-region/stage composition and no M6 acceptance authority is used. |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01` advances as prepublication-proved but closure-pending through CB2/TB2/final Review. DEFN-R1 process OBS retained as history. TB1 EXEC OBS-01/02 confirmed process-only +0. |
| Stable accounting | 51 / 14 / 37; debt 1 M6-owned. Accepted runtime package/source remains `10771899191 / cef1c6ee...` under selector448. |
| New candidates/obligations recorded | No new semantic candidate. `M5-CP4-TB1-REV-OBS-01` records the fail-closed caller permission-ceiling startup failure as process-only +0. Publication/fresh-runtime/final-Review obligations are frozen in the CB2 plan and existing CP4 sequence. |
| ORIENTATION currency line | `M5-CP4-TB1-REV`, 2026-09-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3/current M5 authority and §7 `G4-B004` owner advanced to CB2/TB2/final Review. Witness table unchanged. §8 unchanged: no new recurring defect pattern. |
| CHANGELOG | Agent and root entries appended. |
| ROADMAP | M5 row and `G4-B004` status advanced to Review-accepted prepublication proof / CB2 next. |
| Selector manifest | n/a — selector449 is only precommitted; no selector file is added or accepted in this Review. |
| LESSONS | n/a — no new defect pattern; existing authority-domain, non-vacuity, chronology and control-plane lessons suffice. |
| Consolidation under CLEAN_UP_POLICY | CB1 plan/report and predecessor DEFN-R1 Review folded into `M5_Consolidated_Record.md` §§4.35-4.37/§5; current TB1 report retained. |
| Successor frozen | Exactly `M5-CP4-CB2`, with falsifiers/stop rules in `Architecture_M5_CP4_CB2_Selector_449_Publication_Code_Build_Plan.md`. |
| Turn boundary held | Runtime-free Review; no product/test/fixture/CMake/benchmark/selector mutation. |
| review_check.py boundary | `boundary --expect-selector 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**; no product/test/fixture/build or selector mutation; durable markers preserved. |
| `STATUS` lifecycle maintained | Entry `M5-CP4-TB1-REV / IN_PROGRESS` published before substantive mutation; final `COMPLETE -> M5-CP4-CB2` will be the last repository write. |
| Pushed to origin, branch in sync | **PASS.** Durable Review docs were pushed through verified Drive transport; temporary caller/markers/payload state was removed by workflow-first cleanup. Origin hygiene at `a0d2d9c540cfc5c97a57db8eebbab94c14c255f6` showed exactly the seven durable workflows and no trigger, workflow-observation, or turn-payload directories. This record update writes directly to origin through the connector; only the final `STATUS` beacon remains. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD with corrections.** Row449 prepublication acceptance, the selector449/routing449 precommit and the successor `M5-CP4-CB2` stand. Accounting is unchanged at 51 / 14 / 37 with debt 1.

**What I re-derived, from fresh GitHub downloads.**
- **TB1 result/log and CB1 package.** The ZIP hashes match. The manifests are 912/912 and 26/26. The ledger hashes to `34eec870…`.
- **All 449 rows.** Every row is exit0 / selected1 / skipped0 / PASS. The raw-log hashes match, and each log holds exactly one `[ RUN ]` and one `[ OK ]` naming its identity, with no skip. Prefix identities equal selector448, prefix binaries equal routing448, and owners are 32/301/75/41. `row449-diagnostic.txt` reports `first_unmet_fact=none`. Package and source censuses are identical before and after.
- **Selector449 and routing449.** I rebuilt both from the accepted bytes, and they hash exactly to `d4a0d1b7…` and `9c88a5ed…`. The routing file is byte-identical to the TB1 runner's `routing449.tsv`.
- **CB1 package.** GMP is on and the link evidence carries GMPXX. The packaged test source equals HEAD, and no product source changed since `20761d5a`.
- **Row449 source** (`tests/SurfaceCellTransitionQuotientTests.cpp:2884-3045`):
  - it asserts the six facts in order, each with a fact-naming message;
  - all six are bound to one selected region;
  - seam incidence and source transition are checked independently against the source mesh (`edge_faces`, `edge_matching_indices`);
  - the relation ID is recomputed by the independent carrier oracle;
  - the reciprocal `PeriodicCut` provenance is checked field by field.
- **`ledgers --base 20761d5a`** PASSes.

**The risk I raised at the DEFN-R2 review did not materialize.** I asked whether `torus_fixture()`, the variant with 18 hard edges, has a region spanning ≥2 sheets with a non-hard-feature seam. It does, and the fact-ordered asserts show every fact met.

**Corrections:**
1. **An undisclosed attempted re-execution (`M5-CP4-TB1-REV-OBS-02`).** After the authoritative run (`35937669401`, 00:16Z) and its report (00:41Z), the resumed TB1-EXEC turn (02:59Z) installed a new 449-process harness (`c1869d57`) and executor (`3bb4401d`) and triggered them (`573e7e9c`). Four runs failed at startup with 0 jobs because the workflow file was malformed. The harness also misspelled the selector path. No second runtime executed. The TB1 report's unqualified "no retry-after-runtime-start" was annotated, and this Review had reconciled only the named run, not the turn's Actions window. Recorded as `LESSONS.md` 178.
2. **Package target narrowing.** CB1 built only the four owners (26/26), not the reusable's eight-target default. Its plan authorized that, and my DEFN-R2 review missed the narrowing. The CB2 plan §8 now requires all eight, since CB2's package becomes the final M5 authority.
3. **Consolidation defects.** There were duplicate `## 4.35` sections, and CB1/TB1-EXEC sections sat after §5, repeating the R16 OBS-03 defect. They are renumbered to §§4.35-4.37 without content loss. The three new index rows had been placed in an old sub-table and are moved to §5.
4. **Ledger placement.** This turn's agent and root changelog entries had been appended at the file **end**. The agent one sat below the restored pre-2026-09-22 history. Both are moved to the top with line counts preserved.
5. **Stale TODO line.** The M5 milestone line still said "Exact next is `M5-CP4-CB1`" and is corrected.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector448 `70ff0860…` and 430 `1c412850…` via `boundary --expect-selector`. Precommits rebuilt as `d4a0d1b7…` and `9c88a5ed…`. |
| Decisive claims independently re-derived | Artifacts, manifests, ledger, raw logs, protocol, postflight, row449 diagnostic, precommit bytes, test source, package GMP and source identity, **Actions-window run reconciliation** |
| Non-vacuity checked | Six ordered facts on one region, with independent oracles for seam incidence, transition and relation ID |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01` moves to CB2/TB2/final Review. New `-OBS-02` recorded. |
| Stable accounting | 51 / 14 / 37; debt 1; runtime authority `10771899191 / cef1c6ee…` under selector448 |
| New candidates/obligations recorded | `M5-CP4-TB1-REV-OBS-02`; CB2 §8 obligations |
| ORIENTATION currency line | `M5-CP4-TB1-REV` (incl. reviewing-agent addendum), 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 item 1 gains the CB2 §8 note. §8 gains the resumed-EXEC re-arm instance. §3/§4 are correct. |
| CHANGELOG | Both entries moved to top and amended |
| ROADMAP | n/a — correct |
| Selector manifest | n/a — precommit only |
| LESSONS | New 178; cited 176 |
| Consolidation under CLEAN_UP_POLICY | Numbering and index placement repaired |
| Successor frozen | `M5-CP4-CB2`, per plan §§6 and 8 |
| Turn boundary held | Runtime-free; no product/test/selector change |
| review_check.py | `boundary --expect-selector 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 20761d5a`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M5-CP4-CB2` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
