# TB-REV-161 — independent immutable gate and downstream owner review

## Situation

**PASS for the immutable TB161 test-and-benchmark gate; STOP for production activation CB-179.** This review does not approve a product change. It freezes one definition-only successor, `M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY`. The staged graph proves embedded cellularity, but the staged `GlobalTopologyPlan` fails before a valid region plan exists. No new stable regression, product acceptance, or selector promotion is claimed.

## Background — independent source and byte checks

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, open draft PR #8; immutable CB-178 compiled source `d9d685edf372573c6b07a3be06dc75e2bbec67e7`, compile package `14741239012`; test source is not recompiled in this Review.
- Gate run [44993753731](https://github.com/akashskypatel/Directional/actions/runs/44993753731), artifact `14743677304`, outer ZIP SHA-256 `a3adc1c1de4aca07aa34c2e937c50f57510408d0ae0861e270c071340f830ea0`: **1,966/1,966** internal entries independently hashed, 979 planned/executed/PASS, zero missing, abnormal, duplicated, skipped or RED. Boundary reports `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`; membership 1,060.
- TB160 gate artifact `14737647064`, SHA-256 `9dc2bb7669be86f70f2db2acf9c2c7ad12f0b4d39d40c85ae89194b5abe0ffc3`, independently verified **1,964/1,964**. First **978/978** manifest rows are byte-identical. TB160 manifest hash `d7eb3c355cdc3febd35f20cb8d2178489f8cb6d2aecf1f600ef8dd2b6151ca5a`; TB161 manifest `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`. The additional identity is precisely `TraceTerminationCorrection.PrescribedSphereStagedSlideEntryStopDownstreamStagesArePublished`; accepted CP2 first **491/491** remain PASS.
- First **978** ledger identities match independently. Their **978** complete raw logs match under frozen N1 (GoogleTest duration only), N2 (line endings), N3 (complete M3 support records as a multiset): **1,750 vs 1,750** M3 records, exact multiset equality, zero other exceptions. New row979's raw-log digest matches its ledger.
- Census TB160 artifact `14737279153`, SHA-256 `94341d1128af1794f33ece3f61a7f13257fb716378ea693a1b0c54d2c368657e`, and TB161 artifact `14741883606`, SHA-256 `cc3f200101168f5fd3ff1e0e0dca986adb750dcd7e107a0b03ecc786b4d50b59`: **9/9** checksums each. All **3/3** case identities and normalized complete logs equal under frozen N1–N4 (N4 changes only opaque GoogleTest pointer-object presentation), with eight M3 records equal. Cylinder PASS; BunnyRandom and Vase expected RED at their unchanged original sites; no new invalid binding or struck-index result is observed **with the stop still OFF**. Three platform-digest lines are equal. No runtime was executed in this Review.
- Exact source-inspection snapshot: `f9e912a0bed5d1ed233e2d554b85fc35b60ec1b0`, [run 44997333366](https://github.com/akashskypatel/Directional/actions/runs/44997333366), artifact `14744102934`, ZIP SHA-256 `2f8725b78e3a92eef123f6f34097fcc13ecf5305dd03ed20a25fb94350f36bef`; **5,716/5,716** source checksums verified. Analysis used that local copy. It is an inspection authority, not a claim of rebuilding or rerunning CB-178.

## Assessment — row979 and independent source check

The 41 raw receipts comprise one `SphereStagedCutGraph`, one `SphereStagedPlan`, 24 distinct `SphereStagedTrace` (0–23), 14 `SphereStagedSlidePiece`, and one summary. All four prescribed slide-contact traces (5, 8, 17, 20) report eight segments. Staged cut graph: `V=18 E=30 F=14 chi=2 sourceChi=2` with embedded-cell certificate built; production branch still reports `CutSearchExhaustedBeforeCellularity`, 10 carrier candidates classified and zero selected. The staged plan instead reports **`UncutFaceComponentOrbitSeedNotUnique` at face `2-5-12`**, with edge/trace/secondTrace/χ/V/E/F/fragment/trace-piece fields absent (`-`). The production sphere still fails; no surface mesh is certified.

Source inspection narrows, but does **not** decide, the new fault: `GlobalTopologyPlan.cpp` constructs an uncut source-face component partition with mandatory, trace-touched and cut-edge barriers, then calls `check_certified_source_face_owner_consistency` on `SurfaceCutGraph` certificate data. In `CertifiedSourceFaceOwnerConsistency.h`, failure occurs if any face has an absent owner, a trace-crossed or non-established owner, an owner without exactly one certified orbit, **or** a component contains more than one distinct orbit. Therefore the word `NotUnique` **does not prove a multi-owner collision**. `sourceFace=2-5-12` is an iteration-order locus (first invalid face or component first face), not necessarily the causal face. The reported plan result exposes none of the already computed `ownerEvidence` component and orbit counts. A valid embedded cut graph (`proves_embedded_cellularity`) is not itself a certificate of the downstream source-face owner partition (`proves_cellularity`).

### Frozen adversarial obligations and stop rules

| Source | Review disposition and owner |
|---|---|
| V1 | **Discharged at staged embedded cut graph only**: χ2 matches sourceχ2; owner/plan/output proof remains open; `M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY` first. |
| V2 | **Upheld**: withdrawn monolithic CB-178 activation stays withdrawn; no compile-only turn may invent runtime premises. |
| V3 and V4 / U3 | **Carried to future activation plan**: replace dormant row648 sphere premise only from observed plan data; cover all eight carrier ends including 5/8/17/20, not four literals. |
| V5 | **Carried**: future stop-ON BunnyRandom census must not end with `InvalidNetworkBinding` or struck-index/carrier-contact binding failure even if RED site changes. Current stop-OFF census does not discharge this falsifier. |
| V6 / V3b | **Carried**: node-specific canonical `(0,2)` composition remains unwitnessed; independent mutation at the pure composition helper and later separately gated CB-180; no fabricated canonical builder. |
| V7–V9 | **Upheld**: row979 is non-vacuous for staged graph vs production cut; the plan and detailed receipts are diagnostics, not acceptance assertions; cut failure is asserted. |
| V10 | **Carried unchanged**: row971 ordinary-ray/count/collision assertions stay intact; any new RED after activation is a STOP requiring independent classification, not a reason to weaken the test. |
| V11 | **Carried**: future switch must change `canonical_field_aligned_candidate` at its one shared source or remove the false-default flag; production-only branch switching would diverge from replay and census validation. |
| RA-281 F1/F2/F3, W3/W4, RA-275 S4a | **Carried**: Amendment 14 interim cut restriction, slide-start subdivision, along-edge key, upstream witness conditions and downstream conformity remain held. |

The review found no accepted-green loss: stable **66 events / 17 categories / 49 recurrences**, one produced-witness debt, 81 deferred; CP2 491 accepted, CP3 497 frozen/unpromoted. Neither the staged result nor the test's PASS permits CP3, selector497, D0 or H4 promotion.

## Recommendation — exactly one next turn

**Freeze `M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY` as a runtime-free definition and independent evidence-disambiguation turn.** It must inspect the actual certificate/partition data and existing diagnostics for the first conflicting uncut component, using exact source identities. Its bounded outputs are:

1. Enumerate every face in the first conflict component and its exact barrier-adjacency partition. Record the `invalidFace` state and each face's `find_source_face_owner` outcome: absent, `trace_crossed`, not `established`, zero/one/multiple certified face orbits. Record the distinct-orbit counts and multiplicities; distinguish `None`, `Unique-but-invalid`, and `Multiple` without trusting the error label.
2. Compare that partition and owner evidence against `SurfaceCutGraph` certificate source-face ownership, including the graph's embedded versus source-face cellularity predicates. Identify the earliest responsible producer or violated consumer precondition; preserve source-face/sheet identities and all required hard barriers.
3. Produce a **minimal falsifiable** separate Code + Build proposal only if the evidence identifies a correct single-writer fix. State the independent test-oracle and negative-control predictions in advance, including exact first failure and no downstream success claim. If evidence cannot distinguish the cases without new runtime instrumentation, specify only the smallest diagnostic-only Code + Build followed by a separate immutable Test + Benchmark turn. Do not invent live values in a compile-only turn.
4. Explicit STOP if owner evidence is absent or ambiguous, certificate/partition authority conflicts, same-sheet or hard-rail preservation is unproved, the baseline tests would need weakening, or producer/consumer responsibility cannot be established. Do **not** activate CB-179, start CB-180, change selectors, or alter production in the definition turn.

This is a dependency gate for later CB-179, not its implementation or a product acceptance. A new operator name, changed diagnostic class, or χ2 alone cannot discharge it.

## Procedure and verification note

Initial direct multi-document connector reads preceded the mandatory snapshot-mode selection, violating `TOOL_USE_CONSERVATION_POLICY.md` §2 Step 2. The error is disclosed; further source inspection used only the verified local snapshot. The locally executed verification script parsed published artifacts and never executed Directional code. Turn-local tool-call accounting is incomplete and is reported unknown rather than invented.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB160 `d7eb3c355cdc3febd35f20cb8d2178489f8cb6d2aecf1f600ef8dd2b6151ca5a`; TB161 `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`; rows 1–978 byte-identical; CP2 491/491. |
| Decisive claims independently re-derived | ZIP and internal SHA-256, 979/979, predecessor 978/978 raw logs (N1–N3; 1,750 M3), census 3/3 (N1–N4; 8 M3), row979 41 receipts and source-owned guard. |
| Non-vacuity checked | Row979 asserts production failure and staged built certificate; the plan receipt has no success assertion. Future owner fix requires independent positive/negative oracle. |
| Prior obligations discharged/carried | V1 staged-only discharged; V2 upheld; V3–V11, U3, V3b, W3/W4, RA-281 F1/F2/F3 and RA-275 S4a explicitly carried above. |
| Stable accounting | 66 / 17 / 49; debt1; deferred81; CP2 accepted 491/491; CP3 497 frozen and unpromoted. |
| New candidates/obligations recorded | Plan owner-consistency ambiguity; tracker and this review; owner `M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY`, with exact falsifiers. |
| ORIENTATION currency line | TB-REV-161, 2026-11-22, revised. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 new gate and hold; §4 new staged plan witness; §7 replaces obsolete CB-178 priority; §8 clarifies false inference from error label. |
| CHANGELOG | TB-REV-161 entry added. |
| ROADMAP | n/a: checkpoint remains M6-CP3 active, no acceptance/selector movement. |
| Selector manifest | n/a: 979 is an unpromoted gate case; no accepted selector changed. |
| LESSONS | Existing single-writer, non-vacuity, evidence, and owner-consumer rules reused; no new general pattern requiring a new lesson. |
| Consolidation under CLEAN_UP_POLICY | Existing history kept in its owner files; current handoff/TODO/ORIENTATION updated in place without duplicating a transcript. |
| Successor frozen | `M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY` with four disambiguation tasks and STOP rules in this report. |
| Turn boundary held | Review-only; zero product, test, fixture, selector, benchmark, workflow, build or runtime changes. |
| review_check.py boundary | Ran locally on a verified source snapshot with synthetic Git baseline. All selector hashes and no-code/test checks passed, but the full check **failed** because historical rewrite commit `8b7299b43` is absent from the shallow snapshot. Historic durable-section validation is not claimed; must be completed with full Git history before formal closeout. |
| `STATUS` lifecycle maintained | Entry beacon published for this turn; final beacon is the last repository action after evidence/cleanup. |
| Pushed to origin, branch in sync | Not yet established by this prepared file. Require verified dispatcher push, matching six-path commit, clean remote branch head, and historical boundary check before final COMPLETE; otherwise maintain current turn in progress. |
