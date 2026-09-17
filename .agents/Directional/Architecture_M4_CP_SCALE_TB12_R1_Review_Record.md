# M4-CP-SCALE-TB12-R1 Review Record

**Turn:** `M4-CP-SCALE-TB12-R1-REV`
**Role:** independent runtime-free REVIEW + PLAN
**Reviewed candidate:** artifact `10509313705`, semantic source `3abb1e99e2cb42f385afcad4f6d185af4e7687cd`
**Accepted predecessor authority:** package `10473134357`, semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`, selector426 **426/426**
**Verdict:** **FOCUSED RED UPHELD / PRODUCTION CYCLE-BASIS ORDERING DEFECT / NON-STABLE / S5 UNACCEPTED**
**Exact successor:** `M4-CP-SCALE-CB15`

## 1. Scope and boundary

This Review is runtime-free. It reopens the immutable CB14 package/source and the TB12-R1 raw focused evidence, independently re-derives the decisive topology/selector/package facts, statically audits the exact `FieldTransportAtlas` failure path, classifies the candidate, and freezes one bounded successor. It does **not** execute a generated Directional binary, retry the focus, run selector426, build, benchmark, mutate fixtures/tests/products/selectors, or publish selector427.

The reviewed focus is `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`. TB12-R1 selected exactly that one identity once and obtained one semantic failure at `independentAtlas.has_value()`. Frozen fail-fast therefore left selector426 **0/426** and benchmark execution **0**.

## 2. Independent byte/evidence re-derivation

Review independently re-opened the immutable package and retained runtime evidence rather than accepting the TB report as self-proving:

- package ZIP SHA-256 re-hashes to `fd9cb98e3f5b295cfaa7533d2a8626f66f8199c80832d626ccb97be695342de1`;
- its root `SHA256SUMS` verifies every listed payload entry; packaged source is exactly `3abb1e99e2cb42f385afcad4f6d185af4e7687cd`;
- packaged source archive SHA-256 re-hashes to `496162e8582b00b380bcc7f7d817a3a512bee035242bb5878927799013fed52d`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, mandatory GMP/GMPXX link evidence and zero preflight/build exit codes are present; producer/test binaries retain archived mode `0755`;
- retained fixture SHA-256 values independently re-hash to `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3` (`genus_two.obj`), `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e` (`genus_two.rawfield`) and `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76` (fixture metadata);
- an independent OBJ census derives **V/E/F=120/366/244**, one face-connected component, every edge incident to exactly two faces, zero boundary edges/loops, orientable closed two-manifold, `chi=-2`, genus `2`;
- selector426 independently re-hashes to `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; its first425 LF rows independently re-hash to `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; row426 remains exactly `M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`;
- the compact runtime-evidence archive re-hashes to `f11b565fff58916c581ef0592e866a0ad8837c30353c68c4946f4262334c1f9b`; its focus ledger is exactly selected `1`, passed `0`, failed `1`, exit `1`, and its retained raw stdout names the exact focus and the same `IncompleteCycleBasis` failure.

No current selector byte is changed or promoted by this Review. Accepted M4 runtime authority therefore remains package `10473134357` / selector426 **426/426**, owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**.

## 3. The retained raw field is not the cause of `CycleOrderingFailed`

The TB report correctly left a fork between invalid retained-field authority and production cycle ordering. Static source inspection resolves the **observed failure** to the production topology/cycle-basis side without asserting that every later field-admissibility property has already been proved.

In `src/authority/FieldTransportAtlas.cpp` the relevant sequence is:

1. the local region mesh is built and `PCFaceTangentBundle::init` publishes `bundle.cycles`;
2. expected cycle dimensions are checked;
3. raw cross-field effort is mapped to the bundle's inner adjacencies and exact lift integrality is checked;
4. for each nonzero coefficient of one `bundle.cycles` row, production constructs a `DirectedCycleEdge` solely from the coefficient sign, local `EF` incidence, source-face mapping and the already-existing adjacency for that source edge;
5. `order_cycle_steps(directed)` must turn that support into one closed, single-successor face loop;
6. only after ordering succeeds does production compose the cycle's actual quarter-turn transports and compare them with the turning lift.

`order_cycle_steps` itself is structural. It sorts by `(fromFace,toFace,sourceEdge)` and returns failure for duplicate `fromFace`, missing next `fromFace`, re-use of an already-consumed support edge, an impossible directed-adjacency face pair, or failure to close/consume all support. None of those predicates reads raw effort, matching, singularity index, or quarter-turn value. The raw field can determine whether an earlier lift-integrality gate is reached/passed and can determine the later `CycleTransportMismatch`, but it cannot make the same algebraic support row orderable or unorderable.

TB12-R1 reports the specific reason `CycleOrderingFailed`, not `NonIntegralCycleLift` or `CycleTransportMismatch`. The first failing region is topology region 0 with `V/E/F=24/59/36`, `chi=1`, one boundary loop, genus `0`, fourteen interior local vertices, expected/captured cycle count `15/15`, and 49 inner adjacencies. Its transport diagnostics contain zero barrier edges/components. This is therefore not evidence that a genus-two handle generator has bad field holonomy; the failure occurs while linearizing a topology-only cycle-basis row in an ordinary cut region before transport composition.

The source owner reinforces that classification. `directional::dual_cycles` constructs an **algebraic cycle basis**: local one-ring rows, aggregated boundary rows, and tree/co-tree generator rows are assembled sparsely and sliced to inner edges. `FieldTransportAtlas` then assumes every resulting row can be represented as one simple directed face cycle. The failure says that assumption does not hold for at least one row on this valid produced region. The current receipt does not identify which row or which `order_cycle_steps` subcondition, so a semantic repair is not yet justified.

Finally, comparison of accepted semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` to candidate source `3abb1e99e2cb42f385afcad4f6d185af4e7687cd` contains no `src/**` or `include/**` production change. The candidate added S5 witness/fixture authority around pre-existing production behavior. This is a latent production defect newly exposed by broader witness coverage, not a production regression introduced by CB13/CB14.

**Adjudication:** changing the retained raw field merely to avoid this `CycleOrderingFailed` would hide the observed production defect. The field may still require later admissibility proof after the cycle-basis defect is diagnosed/corrected, but invalid raw-field authority is **not** an adequate explanation for the current red.

## 4. Regression classification and accounting

`M4-CP-SCALE-TB12-R1-EXEC-CAND-01` is reclassified as:

**OPEN / PRODUCTION FIELD-TRANSPORT CYCLE-BASIS ORDERING DEFECT / `RP-07 CYCLIC_TOPOLOGY_LINEARIZATION` / NON-STABLE.**

The recurring mechanism is existing `RP-07`: an algebraic cyclic-topology object is being forced through an incidental linear/simple-loop representation. This is a new instance of the existing pattern, not a new category. The exact ordering subfailure remains unresolved and is the next diagnostic owner.

There is no accepted-green loss. The S5 focus has never been part of an accepted selector, selector426 did not execute in TB12-R1, and accepted package `10473134357` remains green under its reviewed selector426 authority. Therefore stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**. No new stable regression ID is assigned and the `RP-07` stable history counters are unchanged.

`M4-CP-SCALE-TB12-EXEC-CAND-01` remains **CLOSED / RECOVERY PROVED / NON-STABLE**: CB14's source-retention correction is proved by exact-byte runtime consumption and is distinct from this semantic defect.

## 5. S5 credit and obligations

S5 receives **zero** selector/publication credit in this Review. What is now proved is narrower and stronger than the old "no fixture" state:

- retained genus-two topology exists and is independently verified;
- the frozen producer focus reaches actual production source labels and attempts A1 field-transport-atlas construction on that exact source/field;
- atlas authority is not established, A2a/A2a'/A2b/A3 are not produced, and no S5 gate row is authorized.

`M4-CP-SCALE-DEFN-OBS-04` remains open. Its next bounded owner is the diagnostic chain beginning with `M4-CP-SCALE-CB15`; S5 can receive no credit until a later artifact-only run and Review prove admissible atlas authority and genuine A3 reachability on the same independently verified genus>=2 witness.

Other open CP-SCALE obligations remain unchanged: S1 representative/stress calibration, the zero-transport helper audit, and the S2 arrival exact-fallback owner. `G4-B002`/`G4-B003` produced-witness debts keep their existing milestone owners.

## 6. Exact bounded successor — diagnostics only

The exact next turn is `M4-CP-SCALE-CB15` under `Architecture_M4_CP_SCALE_CB15_Cycle_Ordering_Diagnostics_Code_Build_Plan.md`.

CB15 is **diagnostics-only Code + Build**. It may add decision-neutral structured diagnostics to the existing `CycleOrderingFailed` path sufficient to identify:

- topology region and exact cycle-row index;
- row class derivable from the existing partition (`LocalVertex`, `BoundaryLoop`, `HandleGenerator`);
- nonzero support cardinality and exact source face/edge locus summaries;
- one explicit ordering-failure subtype that distinguishes duplicate source-face origin, missing successor, already-used support, directed-adjacency face mismatch, and non-closing/unconsumed support.

The implementation must preserve `FieldAtlasBuildErrorCode::IncompleteCycleBasis`, preserve `IncompleteCycleBasisReason::CycleOrderingFailed`, preserve every branch decision and produced semantic value, and keep fixture bytes, the focus's semantic assertions and selector426 byte-identical. No semantic cycle repair, raw-field edit, fixture edit, selector427 publication, or generated Directional runtime is authorized. Standard targets compile/package through the mandatory GMP/GMPXX reusable workflow with `runtimeExecution=false`.

A later `M4-CP-SCALE-TB12-R2-EXEC` may consume that immutable package and execute the focus exactly once to expose the missing diagnostic discriminator, followed by mandatory Review. The expected focus remains RED because CB15 must be decision-neutral. If it turns GREEN, changes error code/reason, changes a product/hash, or changes selector/fixture/test semantics, treat that as diagnostic non-neutrality and stop rather than taking S5 credit.

## 7. Consolidation

The consumed `Architecture_M4_CP_SCALE_CB13_S5_GenusTwo_Witness_Code_Build_Plan.md` is folded into `M4_Consolidated_Record.md` with its historical role preserved: it authorized construction/compile only and prohibited runtime/selector publication. The current retained CP-SCALE role set is:

- normative `Architecture_M4_CP_SCALE_Frozen_Definitions.md`;
- accepted runtime report/review `Architecture_M4_CP_SCALE_TB11_Artifact_Only_Test_Benchmark_Report.md` + `Architecture_M4_CP_SCALE_TB11_Review_Record.md`;
- current semantic-RED evidence `Architecture_M4_CP_SCALE_TB12_R1_Artifact_Only_Test_Benchmark_Report.md` + this Review record;
- exactly one next plan `Architecture_M4_CP_SCALE_CB15_Cycle_Ordering_Diagnostics_Code_Build_Plan.md`;
- selector426 and every historical byte-frozen selector; consolidated record, tracker/changelog and durable project authority.

CB14's consumed correction plan and the non-semantic TB12 attempt were already folded by the preceding closeout. No selector, frozen definition, closure record, unresolved blocker or current runtime evidence is deleted.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 = `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` |
| Decisive claims independently re-derived | package digest/manifest/source/GMP/modes; fixture byte hashes and independent genus-two census; focus ledger/raw stdout; exact production cycle-order path; accepted-to-candidate production-source comparison |
| Non-vacuity checked | focus selected/executed exactly once and failed at the asserted atlas precondition after real cross-field/source-label production; topology census is non-empty and independently recomputed |
| Prior obligations discharged/carried | missing-fixture candidate remains closed recovery-proved; `DEFN-OBS-04` carried to CB15 diagnostic chain; S1/S2 helper/S2-arrival and inherited debts retain owners |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; no accepted-green loss and no new stable ID |
| New candidates/obligations recorded | TB12-R1 candidate reclassified to open production `RP-07` cycle-basis ordering defect; exact subfailure diagnostic obligation assigned to CB15 |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R1-REV`, 2026-09-17 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | corrected retained-genus-two state; added genus-two witness row; reprioritized to CB15; recorded new instance of existing `RP-07` |
| CHANGELOG | Review adjudication, non-stable classification and exact successor recorded |
| ROADMAP | S5 state updated from unresolved fork to production cycle-ordering defect; exact next CB15 |
| Selector manifest | n/a — no selector appended/promoted; selector426 remains current accepted gate and re-hashes unchanged |
| LESSONS | n/a — no genuinely new recurring category; existing `RP-07` cyclic-topology-linearization and diagnostic-first lessons govern |
| Consolidation under CLEAN_UP_POLICY | consumed CB13 plan folded/indexed into `M4_Consolidated_Record.md`; current TB11 authority and TB12-R1 RED evidence retained |
| Successor frozen | exactly `M4-CP-SCALE-CB15`; diagnostics-only scope/falsifiers in the CB15 plan |
| Turn boundary held | yes — runtime-free Review; no generated Directional runtime/build/benchmark/product/test/fixture/selector mutation |
| review_check.py boundary | required PASS on final Review diff with selector426 declared hash |
| `STATUS` lifecycle maintained | entry/resume beacon preserves original start/latest resume; final COMPLETE beacon is reserved as the last repository mutation after durable docs and cleanup |
| Pushed to origin, branch in sync | required final closeout check after patch application/cleanup and before final COMPLETE beacon |
