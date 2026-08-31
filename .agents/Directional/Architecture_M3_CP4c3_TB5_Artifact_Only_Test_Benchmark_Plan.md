# M3 CP4c-3 TB5 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB5`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `49536cf7b4b261bd52f36a91c861b6459db356a4`
- Corrected compile run/job: `33445894845 / 99664857496`
- Raw result artifact `9778128771`, SHA-256 `64ff0422c09f5a9a434e978b9496f5cf4a1f3e5f555a4bae5e1f3dbecc13996c`
- Raw log artifact `9778129236`, SHA-256 `cc9019d9a4eb171d658826864ccf65b9b0fab633af2554b50f038ee0a13c0490`
- Immutable mode-preserving package **74**: artifact `9778267541`, Actions SHA-256 `bad0ade74ff8e47c9937013c0fcc3f1084272c66eda35a2db60800ff7b6b767d`
- Inner `package74.tar.gz` SHA-256 `c8d5167652ea95504252f5adb4d1dc5d9f463a4dfacfb7e5e11bd086fe935d8e`
- Packaged source archive SHA-256 `5afa250d0dd8e003b91e7e5f887e3eed8658f16faa6754722bf8a2dd37a1c931`
- Frozen selector 373: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Benchmark: **none**; correctness/diagnostic validation only.

## Objective

Measure Amendment 17's one-datum vertex election on the exact mechanical production path while re-proving the accepted 365-prefix. Consume CB6's now-readable ordinal-370 atlas error and prescribed-sphere subreason, retain Amendment-15 controls, and keep AP6 diagnostics visible without granting them gate credit.

## Immutable preflight — before any Directional runtime

1. Download artifact `9778267541` directly. Verify its Actions digest and exact inner tar digest.
2. Extract `package74.tar.gz` with ordinary `tar` semantics that preserve archived executable mode bits. **Do not use Python `zipfile.extractall` for executable payloads and do not `chmod` or repair permissions/content.**
3. Verify all 58 internal `SHA256SUMS` entries, source commit, source-archive digest, clean source-status records, `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, and generated link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and all six test/benchmark executables at mode `0755`.
5. Recompute selector 373 and predecessor 357/358/361/365/367/370 hashes from immutable source. Require exactly 373 unique identities, 64-lowercase-hex digests, byte-prefix continuity, and static mapping of every identity to exactly one packaged executable.
6. Record a package-tree byte/mode census for postflight comparison.
7. No configure, compile, relink, generated discovery, package repair, source/test/fixture/selector mutation, or benchmark is permitted.

Any preflight mismatch is **orchestration failure**. Stop before runtime and do not count a semantic attempt.

## Ordered semantic gate

Run the frozen cumulative selector **from ordinal 1**, one exact identity per fresh process. Each filter must select exactly one test. Stop immediately at the first semantic red; zero-selected or duplicate-selected is orchestration failure, not pass.

Required closure result is **373/373 PASS**. In particular:

- ordinals **1–365** must remain 365/365 green;
- ordinal **366** must exercise `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- if 366 remains red, preserve the complete `vertexTransitState[*]` publication and compare every reachable state's representative direction with the transported incoming direction, path, branch label, composed quarter-turn, and `incomingInSector`;
- if 366 passes, record that the old two-candidate `VertexTransitSectorUnresolved` is cleared but do not infer CP4c-3 closure until the entire gate and postflight are green.

The complete acceptance/full semantic gate must run uninterrupted to an organic process result. Do **not** impose a workflow/job elapsed-time cutoff on the full suite and do not partition/stitch retries to evade runtime.

## Required diagnostic interpretation when reached

- **366 / Amendment 17:** determine whether one-datum election is unique on the mechanical locus. If still unresolved, the published state table is the primary discriminator; do not add ordering/tolerance/sector changes in TB.
- **368 / sphere:** record `NoCarrierMatch` versus `AmbiguousCarrierMatch` and pass name. `SourceEdgeUnavailable` is expected only for the newly wired no-source-edge path. **AL4 forbids designing a sphere fix in TB.**
- **369:** preserve existing `saturationUsed` evidence.
- **370:** the atlas assertion now prints typed `FieldAtlasBuildError` and locus. Classify `M3-CP4c3-TB4-DIAG-CAND-01` as invalid witness/precondition, changed product contract, or legitimate fail-closed behavior from the observed typed code; do not repair the witness in TB.
- **371/372:** if upstream mechanical transit is green, these finally measure Amendment 15's barrier exclusion and Euler-cut identity; otherwise record them blocked, not falsified.
- **373:** synthetic binding green is not sufficient to close `M3-CP4c3-DEFN-R1-CAND-01`; require the mechanical production witness to publish `unboundSingularityCount=0`.

## AP6 report-only pass

After the semantic gate verdict is fixed, execute frozen ordinals **367–373** once as a separate report-only diagnostic pass, each in a fresh process, with **zero gate credit**. This pass must not alter the already-recorded first-red/green gate verdict. Its rationale remains the same as TB4: downstream diagnostics must stay observable rather than disappearing behind an upstream first red.

## Regression/accounting review

Before TB5 closes, categorize every observed semantic red/candidate in `Regression_Root_Cause_Tracker.md`. Promote stable totals only when the tracker's stable criteria are met; otherwise record/update a non-stable candidate and state why totals remain unchanged. Compile-only CB6 failures are not semantic runtime events.

## Immutable postflight

After all authorized runtime, re-run the internal manifest; re-check source archive, selector hashes, binary hashes and `0755` modes; compare the package-tree byte/mode census; and prove configure/compile/relink/repair/generated-discovery/product/test/fixture/selector mutation and benchmark flags remain false. A postflight mismatch invalidates semantic authority and is orchestration evidence, not a product verdict.

## Stop/rerun rules

A valid semantic first red stops the gate and routes to independent `REVIEW + PLAN`; do not rebuild or correct product/test/fixture bytes in TB. An orchestration-only failure may be retried only after its exact control defect is diagnosed, with package 74 unchanged. Never rerun an unchanged deterministic failure merely to see whether it passes.

## Completion criteria

- **Green:** 373/373 gate PASS + immutable postflight PASS → CP4c-3 may close, subject to candidate/accounting documentation.
- **Red:** valid first semantic red → CP4c-3 remains open; exact successor is independent `REVIEW + PLAN`.
- **Blocked:** immutable/orchestration preflight or postflight invalid → repair only the control plane and retain package 74.
