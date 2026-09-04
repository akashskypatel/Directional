# M3-CP4c-3-TB23-R1 — Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-3-TB23-R1`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Turn type: Test + Benchmark, **immutable artifact-only runtime execution**
- Frozen semantic/package source: `e12396d471c0754b112a40272a7992020ff49ced`
- Immutable package artifact: `9921914679`, `m3-cp4c3-cb25-package-result-33831662949`
- Immutable package SHA-256: `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`
- Selector 397: 397 identities, SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- Corrected frozen harness: `.agents/Directional/tools/m3_cp4c3_tb23_r1_harness.sh`
- Harness SHA-256: `fdc335ddffe1fbaeb45783a24bfaf45b17ba0843a65df8b22950b29980cc16d7`
- Formal semantic run/job: `33839673886 / 100919253449`, **SUCCESS**
- Result artifact: `9924532894`, SHA-256 `9be9a07702b80e0b5a35e263330b90653faa6cc5409b968e8888f82f5f73f522`
- Diagnostic-log artifact: `9924533267`, SHA-256 `f3e4c83184f129b8cd49f153ded0fc422186bd1726c088f3fa1ec6ce6e78276f`
- Runtime result: **389 PASS / 8 RED**, accepted prefix **365/365**
- Ledger SHA-256: `812241705ee5f0c467ce0272a15d4eed842dbe5c6004b1415f2432cbdedef314`
- Verdict: **SEMANTIC RED / ACCEPTED PREFIX SAFE / IMMUTABLE ARTIFACT PRESERVED**

## Result

TB23-R1 is a valid semantic runtime gate. The corrected execution view was verified before runtime, all 397 frozen
selector identities were executed in ordinal order one exact identity per fresh process, and all package/source/view
immutability and prohibited-operation checks passed. The accepted prefix remains **365/365**.

The complete ledger is **389 PASS / 8 RED** with RED ordinals
`[366,367,368,369,370,374,393,397]`. The inherited RED set
`[366,367,368,369,370,374]` remains present. Two additional semantic RED surfaces are therefore preserved at
ordinals **393** and **397**. This Test + Benchmark turn records those outcomes and their exact output only; it does
**not** diagnose, classify, repair, rerun, or authorize a product/test correction. Those decisions belong to
independent `M3-CP4c-3-TB23-R1-REV`.

## Startup-attempt provenance

The first temporary caller run, `33839600920`, ended at GitHub Actions `startup_failure` with **zero jobs** because
the caller's `contents` permission ceiling was below the durable observer reusable workflow's required ceiling.
No Directional runtime started and no semantic evidence exists from that attempt. The caller permission was corrected
once and the formal run `33839673886` then completed successfully. This is orchestration provenance only, not a
regression event.

## Frozen discriminator ledger

### D1 — accepted prefix

PASS. Ordinals **1–365 are 365/365 PASS**.

### D2 — carried mechanical production locus

PASS. Ordinal 366 remains RED at
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, and the preserved production
locus contains all frozen carried facts:

- `UncutFaceComponentOrbitSeedNotUnique`;
- `uncutFaceComponent=0`;
- seed state `Multiple`;
- seed orbits `[0,1,3]`;
- component face count `191`.

The harness discriminator counters are each exactly 1 for that named detail/component/state/face-count/orbit tuple.

### D3 — CA3 adjacent-uncut pair measurement

The required fields are present and the examined domain is non-empty, but the production witness does **not** satisfy
the frozen expected non-zero differing count:

```text
m3Cp4c3CA3;examined=273;differing=0;witnessCount=64;truncated=true
```

Ordinal 393 is RED at its explicit assertion that the differing count be greater than zero.

### D4 — minority-edge independent certified-face rows

Two CA2 rows are present:

```text
m3Cp4c3CA2;sourceEdge=10-79;seed=3;seedRule=edgeOrbitEvidence;componentFace=10,79,151;labeledFace=10,11,79;componentCertifiedFace=unavailable;labeledCertifiedFace=3
m3Cp4c3CA2;sourceEdge=29-35;seed=1;seedRule=edgeOrbitEvidence;componentFace=28,29,35;labeledFace=29,35,91;componentCertifiedFace=unavailable;labeledCertifiedFace=1
```

The production output therefore exposes two independently named sides but leaves both component-side certified faces
`unavailable`; each available labeled-side certified face equals the shown seed value. Ordinal 393 additionally REDs
at its `certifiedFaceDiffersFromSeed` expectation. TB23-R1 preserves this evidence without interpreting the cause.

### D5 — failing-component certified-face multiset

The production witness publishes:

```text
m3Cp4c3CA4;observed=0;unavailable=191;distinct=0;multiset=;truncated=false
```

Because all 191 component-face observations are unavailable, this runtime result does **not** realize the frozen
one-versus-several discriminator. The remaining branch of `M3-CP4c3-TB21-CAND-01` is therefore not adjudicated by
this Test + Benchmark turn; independent review owns the interpretation and successor decision.

### D6 — carried/new identity results

- carried RED: **367, 368, 369, 370, 374** — RED;
- required carried PASS: **371, 372, 391, 392** — PASS;
- ordinal **393** — **RED**, not the frozen expected PASS;
- ordinal **394** — PASS;
- ordinal **395** — PASS;
- ordinal **396** — PASS;
- ordinal **397** — **RED**.

Ordinal 397's exact failed byte-equality witness is:

```text
expected: ;sourceFace=2,4,6
actual:   ;sourceFace=2,4,6;cutCandidateCount=0
```

TB23-R1 records this as a semantic RED surface. Whether the expected byte string or the production projection owns
that mismatch is explicitly deferred to review.

## Artifact authority and immutability

The formal run re-verified the immutable package before runtime:

- artifact id/name: `9921914679` / `m3-cp4c3-cb25-package-result-33831662949`;
- provider digest and downloaded ZIP SHA-256 both
  `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`;
- package census SHA-256 `9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927`;
- packaged-source census SHA-256 `e7bec1591154b4d9d79cd64ad27871305f54a51ba15946dc2042b55f6d2d8654`;
- identity-map SHA-256 `f0a5d494dbb4fb1d2faaa9cc82f3b6d064d96d0dc37e05ba53b15365d7165213`;
- package pre/post census equal;
- packaged-source pre/post census equal;
- execution-view pre/post census equal;
- corrected fixture rule resolved `sibling` before runtime;
- selector 365, 393 and 397 hashes re-verified, with 365 and 393 exact prefixes of 397.

Execution-boundary evidence is:

```text
script_exit=0
mode=--execute
runtime_started=true
runtime_completed=true
preflight_completed=true
execution_view_verified=true
orchestration_failure=false
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
```

No benchmark, configure, compile, relink, generated discovery, package repair, mode repair, or source/test/fixture/
selector mutation occurred.

## Package provenance retained from the consumed Code + Build records

The immutable package remains the CB25 authority:

- semantic/evidence source `e12396d471c0754b112a40272a7992020ff49ced`;
- pre-package owner-target compile `33831440291 / 100895129339`, SUCCESS;
- authoritative eight-target GMP/GMPXX package compile `33831662949 / 100895799092`, SUCCESS;
- package artifact `9921914679`, SHA-256 `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`;
- compile-log artifact `9921915098`, SHA-256 `7eee7b03e48a2301d9e60235d899a696c731826b4b52bb29230cccd33774e5d6`.

CB26 did not rebuild that package. It committed the corrected harness at
`cd8e9d75d3facab3710dc51127ca3bd4f9e17c9a` and validated it without runtime in preflight
`33838073812 / 100914602406`, result/log artifacts `9923955664 / 9923956087`.

The earlier invalid TB23-EXEC attempt remains provenance only: run/job `33833497955 / 100901221113`, result
artifact `9922540133`, raw **342 PASS / 55 RED, accepted 327/365**. It is not semantic authority and is not mixed
into this ledger.

## Stable-accounting boundary

This TB establishes a new valid semantic runtime result, but it does not classify the two additional RED surfaces
as stable regression events/categories/recurrences. `Regression_Root_Cause_Tracker.md` is intentionally unchanged
because the frozen TB23-R1 plan assigns diagnosis/classification to the independent review. Until that review
adjudicates them, the previously reviewed stable totals remain **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 package count **88**.

## Stale-evidence replacement

After preserving all load-bearing source/package/run/artifact/selector/provenance facts in this report and the
durable current-state records, TB23-R1 retires the following superseded per-turn records from current HEAD under
`CLEAN_UP_POLICY.md`:

- `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` — 112 lines;
- `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` — 115 lines;
- `Architecture_M3_CP4c3_CB26_Code_Build_Report.md` — 111 lines;
- `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` — 200 lines, consumed;
- `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` — 100 lines, invalid-attempt provenance superseded by this report.

Per the standing review-consolidation rule, `M3-CP4c-3-TB23-R1-REV` must add those retired filenames and line
counts to `M3_CP4c_Consolidated_Record.md`'s folded-document index. The current
`Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` is retained because it remains the current review record
until TB23-R1-REV replaces it.

## Exact next boundary — independent review only

**`M3-CP4c-3-TB23-R1-REV`** is the exact successor. It must review the immutable TB23-R1 evidence and, at minimum:

1. verify the 397-row ledger, accepted 365/365 prefix, artifact identity and all three immutability censuses;
2. classify ordinal 393's `examined=273,differing=0`, unavailable component certified faces, seed-equal labeled faces,
   and empty certified-face multiset without assuming which producer/test contract owns the result;
3. classify ordinal 397's exact `;cutCandidateCount=0` byte difference and decide whether it is a product projection
   regression, a stale witness expectation, or another class supported by source authority;
4. decide what the unavailable 191/191 CA4 result means for both live branches of `M3-CP4c3-TB21-CAND-01`;
5. formally dispose `M3-CP4c3-TB23-REV-CAND-02` now that the corrected runtime gate completed;
6. update stable regression accounting only for findings that satisfy the review's classification rules;
7. perform the mandatory REVIEW-turn document consolidation and `ORIENTATION.md` update;
8. authorize at most one bounded successor. No product/test correction is pre-authorized by TB23-R1.

CP4c-3 remains **OPEN**. No runtime rerun or repair is authorized before that review.
