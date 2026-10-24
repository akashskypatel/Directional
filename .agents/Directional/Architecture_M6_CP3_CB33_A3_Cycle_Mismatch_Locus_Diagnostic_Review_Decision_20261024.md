# CB33-REV — A3 cycle-mismatch diagnostic independent Review (2026-10-24)

**Turn:** `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC-REV`. **Verdict:** CB33 **ACCEPTED for diagnostic-only compile fidelity**, with **RA-149.3's proposed S1-versus-S2 causal split CORRECTED**. No runtime acceptance and no product repair.

## Independent source and package evidence

- Independently inspected exact semantic commit `f807c2b890b990fc53ea8f84c7228edd94f0659d`, source tarball inside immutable compile package `12556364042`, plus exact [GitHub commit diff](https://github.com/akashskypatel/Directional/commit/f807c2b890b990fc53ea8f84c7228edd94f0659d). Exactly **three files** and **three intended areas** changed (+22/-4 source lines): `FieldTransportAtlas.h`, `FieldTransportAtlas.cpp` (two sites), `SurfaceCellsPhase10Tests.cpp` (one formatter). No selector, test assertion, control-flow predicate or return-location movement.
- Independently rehashed immutable [run 40084311360](https://github.com/akashskypatel/Directional/actions/runs/40084311360) artifact `12556364042`: outer SHA-256 `f984368a213012b2adf5996afe7443817b024f2cb9ef579e5e77e1c99e5ca291`; internal **28/28** `SHA256SUMS` verified; `preflight=0`, `build=0`; eight compiled targets, `DIRECTIONAL_ENABLE_GMP=ON`, real `libgmpxx.so` + `libgmp.so` link command; source SHA exact; five clean source-status files; `runtimeExecution=false` and `turnBoundary=Code+Build-only`. No binaries executed in Review.
- The post-CB33 source snapshot [run 40086981200](https://github.com/akashskypatel/Directional/actions/runs/40086981200) is exact SHA `b59b28c80d8ea7c5f802da6b9b7fda0861f5ca31`, ZIP digest `b2bf309ad12354ab827c2cfa1627fea5dc1387ee1dacd0e0315188d1e459045e`, **5,840/5,840** file hashes and tar digest verified. GitHub compare semantic→snapshot lists only docs/STATUS/dispatcher and snapshot marker, no `src/`, `include/`, `tests/`, selectors or build changes.

## Locus and non-vacuity audit

- **S1:** `src/authority/FieldTransportAtlas.cpp` checks composed quarter-turn against `normalized_quarter_turn(turningLift)` before publishing each cycle. On mismatch it preserves the existing `CycleTransportMismatch`, topology region and exact return location, and now attaches `site=cycle-transport` with the previously constructed `cycleRowIndex` and `cycleKind`. The optional `sourceVertex` is unavailable until the code *after* this return; RA-149.4 expressly forbids reordering. It therefore remains unset.
- **S2:** For the canonical boundary cycle, the code first requires `correction % 4 == 0`, then sets `turningLift += correction`. S1 has already proved `composedTransport == turningLift mod 4` for that same cycle. Hence `(turningLift + correction) mod 4 == turningLift mod 4`, and **the S2 `CycleTransportMismatch` condition cannot be reached in defined integer arithmetic**. This disproves RA-149.3's suggestion that the seven inherited REDs might be split between two independent mismatch sites. Do not infer an index-sum / boundary-correction defect from absence of S2 observations.
- S2's new `cycleRowIndex=boundaryCycleIndices.front()` is an **atlas-global `cycles` vector index**, while S1's row index is **region-local** `bundle.cycles` row. This is a secondary diagnostic namespace inconsistency, latent while S2 is unreachable. It must not be interpreted as the same row coordinate. Neither issue authorizes a source change in this Review.
- `describe_field_atlas_build_error` prints nonempty `site`, and populated cycle row/kind in SP10; no existing assertion changed. The two existing `FieldTransportAtlas.IndependentOracleRejects*` guards are unchanged and check rejection codes, **not** the new locus display: they are regression controls, not direct tests of S1 formatting. The seven SP10 tests are the only planned exercising population. Site, kind and row observations remain **unexecuted** until TB34.

## Frozen next immutable Test + Benchmark scope

- Manifest: `Architecture_M6_CP3_TB34_A3_Cycle_Locus_Cases.tsv`; **12 identities** = `selector:189–195` (seven inherited expected RED), **two** atlas tamper controls, and **three** TB33 factory controls. Semantics and binary ownership resolved from frozen selector449, TB33 manifest and `cmake/DirectionalTests.cmake`.
- TB34 must use the **unchanged CB33 package** `12556364042` (digest above), execute each identity in a fresh process, retain all raw logs and immutable postflight, with no rebuild/relink/repair. For each seven-row RED, capture *actual* code, `site`, `cycleKind`, `cycleRowIndex`, region; allow an independently observed unexpected PASS as evidence, never coerce it to RED. A missing or different site/earlier rejection is not a successful S1 measurement. The guards and factory controls must PASS as before.
- **Falsifiers / stops:** missing/duplicate/skipped identity; package/source/hash drift; direct binary that cannot run its exact test; a changed reject code without adjudication; logs that do not reach the SP10 formatter; any attempted diagnosis relying on S2 as an independently reachable cause. After TB34, mandatory TB34-REV must inspect each actual S1 cycle row/kind and discriminate fixture-vs-transport contract without assuming the outcome.
- Authorized successor: `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST` (artifact-only TB). No source/test/selector changes in this Review, and no runtime acceptance. RP-01 open, RP-02 unreached, Gate C suspended. CP2 accepted **491/491**; TB32 candidate **481/500**, original 497 **478 PASS / 19 RED**, stable **66 events / 17 categories / 49 recurrences**, debt **1**.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no selector authored/accepted; exact 497 identity manifest stays frozen, n/a to new prefix |
| Decisive claims independently re-derived | Three source hunks, unreachable S2 modulo-four proof, global/local row distinction, 28/28 package and 5,840/5,840 snapshot hashes, binary target ownership |
| Non-vacuity checked | S1 exercised only if seven SP10 cases reach formatter; two atlas guards check codes only; S2 redundant, not treated as a reachable branch |
| Prior obligations discharged/carried | RA-149.4 compile fidelity discharged; RA-149.3 two-site premise corrected; RA-149.5 measurement carried to TB34; 19 residual REDs, G4-B002/A6 and CP3 exit carried |
| Stable accounting | 66/17/49, debt1; accepted CP2 491/491; TB32 481/500 candidate; selector497 frozen |
| New candidates/obligations recorded | Review observation: S2 unreachable and S2 row-namespace ambiguity, review-owned correction to RA-149; tracker entry, no new stable regression |
| ORIENTATION currency line | Updated for CB33-REV (2026-10-24) |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 corrected; §4 unchanged (no new witness); §8 cites existing vacuity/authority namespace lessons |
| CHANGELOG | Review entry added |
| ROADMAP | n/a: M6 CP3 remains active, no checkpoint moves |
| Selector manifest | n/a: no selector changed or accepted |
| LESSONS | Existing §§2,5,7 applied; no new generalized lesson |
| Consolidation under CLEAN_UP_POLICY | Current CB33 code/build record and RA-149 runtime authority still needed; no superseded current family record folded; current review linked from M6 consolidated index |
| Successor frozen | `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST` with 12-row manifest and falsifiers above |
| Turn boundary held | Static Review only; zero runtime, zero product/test/selector/build mutations |
| review_check.py boundary | Executed on verified snapshot with synthetic Git; code/selector checks passed, but rewrite-history checks failed because original Git objects were excluded. Independently verified real Git ancestry by GitHub compare `8b7299b43..081b30ec` (1192 ahead, zero behind, merge-base equals rewrite baseline), and all protected headings in the three durable docs against their actual baseline blobs. A full original-history local script PASS is not claimed. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon must match Review closeout |
| Pushed to origin, branch in sync | Durable Drive apply run 40088654321 succeeded; exact patch SHA and applied commit `081b30ec8a29f158f34b35bbc732f4e28e6cb849` independently verified; PR #8 head matched that commit. No real-clone `git status -sb` result claimed. |
