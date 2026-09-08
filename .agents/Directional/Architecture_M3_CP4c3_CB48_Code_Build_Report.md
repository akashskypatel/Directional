# M3-CP4c-3-CB48 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 108 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Starting semantic runtime authority:** promoted TB42 / package107 / source `5dacce6019ea34316c48743f3033d2bb5c26281a`
**Definition authority:** `M3_CP4c_Frozen_Definitions.md` Part XII
**Applied implementation commit:** `531b517fb129425f113b5f811215f1d2b1939ee2`
**Authoritative compile run:** `34276935866`
**Changed-owner compile job:** `102232219122`
**Full package compile job:** `102233583990`
**Immutable package result artifact:** `10076272909` / `m3-cp4c3-cb48-package108-result-34276935866`
**Package result artifact digest:** `sha256:a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`
**Persistent package log artifact:** `10076273608` / `m3-cp4c3-cb48-package108-log-34276935866`
**Package log artifact digest:** `sha256:75e7d8eab9b4064d873c69476e5d96afbcee7164e8a057d106c51e16ea9d8987`
**Packaged source archive SHA-256:** `2bce00134c172973225bbe44e87a2708477bde5fed2d531b8d0b9636945fb7c3`

## 1. Scope and outcome

CB48 implements only Part XII / EE0–EE8. It corrects the protected frontier **evidence-domain contract** without
changing the plan's uncut partition, certifier partition, region construction, fragment/ownership semantics, cut
selection, A2a′ cellularity, selector409, or the product behavior at ordinals 366/367.

The correction is deliberately split by authority:

- the plan census remains producer-owned over exact domain `P_U`;
- the terminal failure subject is classified separately as `Inside | Outside | Partial | Unresolved`;
- `RegionCertification` owns exact region/fragment evidence rather than borrowing a plan-census component;
- the four protected identities 390/393/406/407 must execute their census predicate on real same-domain data and
  reject a deliberately corrupted same-domain copy.

No Directional runtime, test, benchmark, discovery/list/help/version command, or custom fixture execution occurred
in CB48. The expected TB43 color vector remains a falsifier only; CB48 does not synthesize runtime acceptance.

## 2. Implemented EE0–EE5 surface

Exactly five semantic paths changed:

- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

The bounded implementation adds:

1. **EE0 — typed domain relation.** `RegionFrontierSubjectDomainRelation` is
   `Inside | Outside | Partial | Unresolved`. `region_frontier_subject_domain_relation(...)` derives that relation
   from authoritative face membership in the already-built `P_U` census. `regionFrontierFailureStage` remains
   chronology only and no longer controls census applicability.
2. **EE1 — exact owner-orbit relation.** `RegionSourceFaceOwningFragmentMissing` now publishes the complete
   deterministic owner-orbit IDs present for the failing source face, their exact count, and
   `regionOwningFragmentOrbitPresent`, alongside the existing expected orbit. This is diagnostic-only; no fragment,
   owner, region, or failure control flow is changed.
3. **EE2 — bounded projection/rendering.** The new fields project through `RemeshDiagnostics` only when the owning
   failure supplies them. Region projection used by this path is restricted to
   `RegionSourceFaceOwningFragmentMissing`; unrelated failures do not acquire default-valued locus text.
4. **EE3/EE4 — producer-owned census predicates.** The protected helpers consume the producer census rows directly.
   The old helper shape that required a terminal-failure-local frontier component has been removed.
5. **EE5 — non-vacuity receipts.** Each of 390/393/406/407 emits a deterministic
   `branch=UncutCensus` receipt recording `censusPredicateExecuted=yes`, the typed terminal relation, and
   `sameDomainCorruptionRejected=yes`. Each identity validates the real census and an intentionally corrupted
   same-domain copy; skipping the producer oracle cannot produce PASS.

## 3. Frozen-surface audit — EE6

Static checks before remote application established:

- selector409 remains byte-identical at
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- no selector file changed;
- complete test bodies for ordinals **311/312/314/315/356/357/366/367/404/408/409** are unchanged;
- no stage-string comparison controls protected census execution;
- no change was made to `unlabeledFaces`, the mandatory/trace/cut barrier families, region construction,
  ownership, `fragmentCorners`, `fragmentOrbits`, cut selection, Part XI content binding, `region_orbit`,
  orbit-key lookup, or A2a′ cellularity semantics;
- 366/367 still return through their existing `RegionSourceFaceOwningFragmentMissing` product path; CB48 only
  makes the missing relation observable.

The protected 390/393/406/407 test bodies changed only to consume the Part XII domain-owned contract and prove their
oracle is non-vacuous. `git diff --check` and exact-base `git apply --check` were clean.

## 4. Work preservation and source application

The final source preservation patch is
`Directional__M3-CP4c-3-CB48__base-62a4bf49d0d4__work-preservation.patch`.

- exact semantic base: `62a4bf49d0d41f9ea4b1c2690ff938f10d167348`;
- full patch SHA-256: `91ebd35b8b583ea2cbbf6eb24f028e88c4aa7b65c8d0399013391272cbd5cec1`;
- embedded diff-body SHA-256: `259da81053114d54857ced304e724eb86c097154887c34971b7a1cd7f8c22565`;
- intended path count: 5;
- exact-base `git apply --check`: PASS;
- `git diff --check`: PASS.

The exact bytes were staged temporarily in `My Drive/Directional-CI`. Drive-apply run `34276716077` succeeded and
pushed semantic commit `531b517fb129425f113b5f811215f1d2b1939ee2`. Result artifact `10075993502` has digest
`sha256:ab37cb272cd4b5b2ac21cb38116ed1d167cdc2cf3d2e96e608f54e0ae421b364`; persistent log artifact
`10075994081` has digest `sha256:8a1f20c8e9cd59a8431518b11b8c987798c6c175f7d7207a1c9ceee260f1376d`.
The workflow reported owner cleanup required, and the owner-authorized Drive control plane permanently deleted the
consumed staging file after successful push/evidence capture.

## 5. Compile and package evidence — EE7

The durable compile reusable compiled exact semantic source
`531b517fb129425f113b5f811215f1d2b1939ee2` in two ordered jobs:

1. changed-owner target `directional_surface_cell_producer_tests`;
2. after owner success, the standard eight-target package set:
   `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`,
   `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`,
   `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Evidence:

- compile run `34276935866`: **success**;
- changed-owner job `102232219122`: **success**;
- changed-owner result artifact `10076225051`, digest
  `sha256:de5dbeefa346e1d0136438610a8963eed4cf0126c44a12f913d597fc83dfec46`;
- changed-owner log artifact `10076225628`, digest
  `sha256:8db6976d88b9ee6fe60f40026887c0a4953589897d169641516c45e282c26729`;
- full-package job `102233583990`: **success**;
- package108 artifact `10076272909`, digest
  `sha256:a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`;
- package108 log `10076273608`, digest
  `sha256:75e7d8eab9b4064d873c69476e5d96afbcee7164e8a057d106c51e16ea9d8987`;
- root package `SHA256SUMS`: **28/28 PASS**;
- `build-exit-code=0`, `preflight-exit-code=0`, final source status clean;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- authoritative link evidence contains both GMPXX and GMP;
- packaged source archive SHA-256:
  `2bce00134c172973225bbe44e87a2708477bde5fed2d531b8d0b9636945fb7c3`;
- fixed ccache key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`, with 114/116 hits.

Compilation proves only that the bounded implementation builds. It does not establish any runtime color change.

## 6. Authority after CB48

CB48 creates one new immutable compile package and no runtime event, category, recurrence, acceptance result, or
regression disposition.

- semantic runtime authority remains promoted **TB42**: selector409 **398 PASS / 11 RED / 0 SKIP**, accepted
  **365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`;
- ownership remains **300 / 0 / 0**;
- stable accounting remains **47 events / 14 categories / 33 recurrences**;
- produced-witness debt remains **5**;
- package count advances **107 → 108**;
- immutable build/package authority becomes package108 artifact `10076272909` on exact source
  `531b517fb129425f113b5f811215f1d2b1939ee2`.

## 7. Mandatory TB43 contract — EE8

CB48 freezes exactly one successor execution plan:
`Architecture_M3_CP4c3_TB43_Artifact_Only_Test_Benchmark_Plan.md`.

TB43 must consume immutable package108 without rebuild/repair, execute selector409 exactly once per identity in a
fresh process, and measure the real result. If CB48 did only the defined oracle correction while all carried owners
remain unchanged, the frozen falsifier is **402 PASS / 7 RED / 0 SKIP**, accepted **365/365**, RED
`[366,367,368,369,370,374,398]`. That vector is not CB48 evidence and may not be promoted until TB43 actually
measures it.

**CB48 terminates after compile evidence, durable closeout, and temporary-state cleanup. No TB43 runtime is
executed in this turn.**
