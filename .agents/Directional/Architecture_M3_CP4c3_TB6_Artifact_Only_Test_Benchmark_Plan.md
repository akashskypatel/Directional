# M3 CP4c-3 TB6 — Artifact-Only Test + Benchmark Plan

Date: 2026-09-01 UTC
Turn: `M3-CP4c-3-TB6`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `e926ada023bc51220628be550bbe9a87f98d7067`
- Compile run/job: `33455549602 / 99694672138`
- Raw result artifact `9781459057`, SHA-256 `e66ff9cbb04a586a8862ceb40ee9e0651741a4588ab8fcd8caf2fc2a8c1fcbba`
- Raw log artifact `9781459549`, SHA-256 `5fea70b8a6bed7190eadeda827cafcee6e160b76a6508b83b349e3e31149c2b9`
- Immutable mode-preserving package **75**: package run/job `33456115934 / 99696350077`, artifact `9781487311`, Actions SHA-256 `547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8`
- Inner `package75.tar.gz` SHA-256 `8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896`
- Packaged source archive SHA-256 `64e5189f3c9f22d648e496c50b4093e842a0fad25a885dca65778d7a110b629a`
- Frozen selector 373: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Benchmark: **none**; correctness and diagnostic validation only.

## Objective

Consume CB7's restored exact/reportable vertex-transit producer and re-measure Amendment 17 through the mechanical production witness. Re-prove the accepted 365-prefix, measure the repaired ordinal-370 witness, consume the prescribed-sphere binding publication, execute the new minimal transit witness when reached, and expose every downstream ordinal after the first red without changing gate credit.

## Immutable preflight — before any Directional runtime

1. Download artifact `9781487311` directly. Verify its Actions digest and exact inner tar digest.
2. Extract `package75.tar.gz` with ordinary `tar` semantics preserving archived executable modes. Do **not** use a transport that loses mode bits and do not `chmod`/repair the package.
3. Verify all internal `SHA256SUMS` entries, exact source commit/archive digest, clean source-status records, `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, and generated link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and all six test/benchmark executables at mode `0755`.
5. Recompute selectors 357/358/361/365/367/370/373 from the immutable source. Require exact hashes/cardinality/uniqueness; 358 uses set-subset continuity, while the retained prefix selectors use their frozen byte-prefix relations. Require exactly 373 unique selector identities and static mapping of every identity to exactly one packaged executable.
6. Record a package-tree byte/mode census for postflight comparison.
7. No configure, compile, relink, generated discovery, package repair, source/test/fixture/selector mutation, or benchmark is permitted.

Any mismatch is **orchestration failure**. Stop before runtime and do not count a semantic attempt.

## Ordered semantic gate

Run the frozen cumulative selector **from ordinal 1**, one exact identity per fresh process. Each filter must select exactly one test. Stop immediately at the first semantic red; zero-selected or duplicate-selected is orchestration failure, not pass.

Required closure result is **373/373 PASS**. In particular:

- ordinals **1–365** must remain green;
- ordinal **366** must exercise `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- if 366 remains red, preserve the complete transit error and every `vertexTransitState[*]` row including outcome, exact representative/incoming directions, transport edge/path, composed quarter-turn, and three election booleans;
- `VertexTransitSeedUnavailable` and `VertexTransitWalkUnexamined` are distinct semantic findings and must not be collapsed back into `VertexTransitSectorUnresolved`;
- if a multi-candidate locus is reached, compare the elected incoming directions exactly. **If the elected directions are equal, stop interpretation and route to review**; Amendment 17's falsifier has fired;
- if 366 passes, record that the mechanical witness cleared the former transit stop, but do not infer CP4c-3 closure before the complete gate/postflight are green.

Do not impose a workflow/job elapsed-time cutoff on the full gate and do not stitch partial successful runs into a synthetic pass.

## Required diagnostic interpretation when reached

- **Amendments 17–19 / mechanical transit:** distinguish seed construction, walk examination, election cardinality, and exact transported-direction evidence. A moved first-red is not proof that the previous locus was corrected unless the relevant diagnostic states were actually evaluated.
- **Minimal transit witness:** require a real decision or an evaluated exact diagnostic state. A seed-unavailable or walk-unexamined result is red evidence, not an acceptable fallback.
- **Sphere / ordinal 368:** preserve the claimed trace, claimed `sourceEdge`, trace existence, incoming/outgoing carrier match counts, edge-available-on-trace boolean, and pass/reason. Do not design the sphere fix in TB6.
- **Ordinal 369:** preserve `saturationUsed` evidence.
- **Ordinal 370:** the repaired torus witness must reach the intended empty-rails/empty-network product contract. A recurrence of `NonIntegralCycleLift` is evidence that the witness repair failed; do not weaken the atlas.
- **Ordinals 371/372:** if upstream mechanical transit is green, measure Amendment 15's barrier-exclusion and Euler-cut identities; otherwise classify them as downstream findings, not automatically falsified contracts.
- **Ordinal 373:** synthetic binding green remains insufficient to close `M3-CP4c3-DEFN-R1-CAND-01`; the mechanical production witness still owes `unboundSingularityCount=0`.

## Full report-only remainder pass — zero gate credit

After the first-red/green gate verdict is fixed, execute **every ordinal after the stopping ordinal through 373 exactly once**, one identity per fresh process, as a separate report-only pass with **zero gate credit**. If the gate is fully green there is no remainder pass.

This is AU8's cadence change. It must not alter `first_red_ordinal`, the gate pass count, or acceptance. Preserve each downstream result independently so one upstream defect no longer hides otherwise reachable diagnostics.

## Regression/accounting review

Before TB6 closes, categorize every semantic red/candidate in `Regression_Root_Cause_Tracker.md`. Promote stable totals only when tracker criteria are met; otherwise record/update a non-stable candidate and explicitly state why stable totals remain unchanged. Compile/package-only CB7 activity is not a semantic runtime event.

## Immutable postflight

After all authorized runtime, re-run the internal manifest; re-check source archive, selector hashes, binary hashes and `0755` modes; compare the package-tree byte/mode census; and prove configure/compile/relink/repair/generated-discovery/product/test/fixture/selector mutation and benchmark flags remain false. A postflight mismatch invalidates semantic authority and is orchestration evidence, not a product verdict.

## Stop/rerun rules

A valid semantic first red stops **gate credit** and routes to independent `REVIEW + PLAN` after the required report-only remainder pass and immutable postflight. Do not rebuild or correct product/test/fixture bytes in TB6. An orchestration-only failure may be retried only after the exact control defect is diagnosed, with package 75 unchanged. Never rerun an unchanged deterministic semantic failure merely to see whether it passes.

## Completion criteria

- **Green:** 373/373 gate PASS + immutable postflight PASS → CP4c-3 may close, subject to candidate/accounting documentation.
- **Red:** valid first semantic red + full zero-credit remainder pass + immutable postflight PASS → CP4c-3 remains open; exact successor is independent `REVIEW + PLAN` unless the frozen roadmap requires a definition turn.
- **Blocked:** immutable/orchestration preflight or postflight invalid → repair only the control plane and retain package 75 unchanged.
