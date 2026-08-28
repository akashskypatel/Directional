# M3-CP4c-2 Artifact-Only Test + Benchmark Plan

## Purpose and immutable authority

This plan is the executable successor to `M3-CP4c-2-CB1`. It consumes the immutable GMP package produced by
compile run `33196876096` and must not rebuild or modify it.

Authority:

- semantic/test source: `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`
- immutable package artifact: `9696201700`
- package digest:
  `sha256:af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`
- packaged source archive SHA-256:
  `8694f0fb85d101e3c5862e5a6a8a8a3ed241c723fd229eb44f83844b30321687`
- exact arithmetic backend: GMP
- accepted predecessor selector: 355 /
  `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- candidate 357 selector:
  `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- candidate 358 selector:
  `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`
- X2 non-gating selector:
  `88af227b7c7ca78d2a6247624b3a5f860026cf50fd3c2bd6a215756b086dafc8`

The Test + Benchmark turn is split into execution and review subturns. Execution collects evidence only; review
interprets existing evidence and plans/routs the next bounded step. No TB subturn may edit production, test,
benchmark, selector, fixture, or build logic or compile a replacement revision.

## Immutable preflight — required before any Directional binary

1. Download package artifact `9696201700` once and verify its outer digest exactly.
2. Extract it into a fresh TB-local directory.
3. Run packaged `SHA256SUMS` verification and require every entry to pass.
4. Verify:
   - `metadata/source-commit.txt` is exactly `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`;
   - build and preflight exit codes are both zero;
   - every packaged source-status snapshot is empty;
   - `metadata/command-boundary.txt` contains `runtimeExecution=false`,
     `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
   - GMP/GMPXX linkage evidence is present;
   - all eight required packaged targets are present with unchanged byte hashes and expected file modes.
5. Verify the packaged source archive digest and extract it read-only for selector/source evidence.
6. Recompute and require:
   - accepted 355 count/hash exactly as above;
   - accepted prefix hashes 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`,
     346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`,
     and 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
   - candidate 357 is 357 identities with its frozen hash;
   - candidate 358 is 358 identities with its frozen hash;
   - X2 selector is exactly one identity with its frozen hash.
7. Snapshot package and extracted-source byte/mode inventories for immutable postflight.
8. Any preflight mismatch is orchestration/evidence failure and stops before runtime.

No configure, compile, relink, regeneration, generated discovery, repair, source/fixture/selector mutation, or
package mutation is permitted.

## TB-X2-EXEC — exact next subturn

Execute only:

`GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`

from the packaged `directional_surface_cell_producer_tests` binary in one fresh process.

Requirements:

- exactly one selected test identity;
- preserve complete stdout/stderr and process exit status;
- the test is intentionally report-only and may return red; its red does **not** receive gate credit;
- preserve the complete `m3Cp4c2X2;...` report without interpreting or editing it;
- do not execute C1, C3, C6, or either cumulative selector in this subturn;
- zero-selected is orchestration failure.

After evidence upload, advance to **`M3-CP4c-2-TB-X2-REV`**.

## TB-X2-REV — scope decision, no new runtime

Review only the immutable X2 evidence against
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` §6.3/§7 X2:

- If the prescribed-sphere network is already cellular **and**
  `RotationSystemInconsistent` persists with a certified cellular embedding, C3 remains deferred and
  `selected_gate=357`.
- If non-cellularity caused that failure and the failure disappears once the certified embedding is supplied,
  C3 rejoins CP4c-2 and `selected_gate=358`.
- If the evidence fits neither frozen branch, stop before gate execution and route to planning/review; do not
  invent a third selector or edit a frozen selector inside TB.

Record the selected frozen selector count/hash verbatim and advance to
**`M3-CP4c-2-TB-GATE-EXEC`** only when the decision is supported.

## TB-GATE-EXEC — selected full required gate

Using the same immutable package, execute the selected ordered selector one identity per fresh process.

For either selector:

- accepted predecessor ordinals 1–355 must remain the exact frozen 355 prefix;
- C1 is
  `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`;
- C6 is
  `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`;
- C3
  `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`
  executes only when X2 selected the frozen 358 gate;
- each identity must select exactly once;
- zero-selected, timeout used as semantic disposition, harness crash, or escaping C++ exception is red;
- do not partition/retry/stitch a full required gate merely to evade elapsed runtime;
- no result receives credit from a different binary/source/package.

Capture C1's `m3Cp4c2X1X7` publication in full. The gate cannot be promoted by count alone.

After raw evidence is preserved, advance to **`M3-CP4c-2-TB-GATE-REV`**.

## TB-GATE-REV — acceptance review

Review all evidence, including every observed regression/candidate, and update
`Regression_Root_Cause_Tracker.md` before durable TB closeout.

CP4c-2 may close only if all of the following are established on the immutable package:

1. selected cumulative gate is fully green: 357/357 or 358/358;
2. accepted predecessor prefixes remain green;
3. torus X1 publishes `V=48`, `E=48`, source `χ=0`, and implied cellular face count 0 before cuts;
4. torus pre-cut non-disc complementary components satisfy prediction 2: `χ==0`, exactly two boundary cycles,
   and at least one such component exists;
5. torus cut graph contains at least two cut edges;
6. torus produces a plan with **non-zero** region count;
7. C6 examined-region count is non-zero and covers produced regions; every examined region carries
   `eulerCharacteristic==1`, `boundaryWalkCount==1`, connected source faces, and mandatory preservation;
8. X5 determinism and X6 idempotence required identities are green within the selected gate/accepted authority;
9. no prohibited X9 behavior is evidenced;
10. immutable postflight matches the preflight byte and mode inventories exactly.

A green C6 over zero regions is explicitly **red**.

Deviation from DEFN §8 predictions 1–4 is material and routes to the project’s required independent review
boundary. The orchestrator must stop at that boundary. Prediction 5 is the intentionally uncertain X2 scope
decision and, when it lands in one of the two frozen branches above, does not itself require independent review.

## Immutable postflight

After the final allowed runtime command:

- recompute package and extracted-source byte hashes and file modes;
- require exact match with preflight;
- record `configureOccurred=false`, `compileOccurred=false`, `relinkOccurred=false`,
  `repairOccurred=false`, `generatedDiscoveryOccurred=false`, and `mutationOccurred=false`;
- preserve result and diagnostic-log artifacts separately.

No benchmark acceptance workload is defined for this correctness checkpoint; `directional_benchmarks` is
packaged provenance only and must not be executed unless a later frozen plan explicitly requires it.
