# M4-CP-SCALE-CB9 — S4 Independent Oracle + Reachability Code + Build Plan

**Turn:** `M4-CP-SCALE-CB9`
**Type:** Code + Build, compile/package only
**Entering accepted authority:** package `10425344367`, semantic source `01b1124af094044e32d6887ff0615881333d12ce`, selector425 **425/425**, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
**Owned obligation:** prerequisite portion of `M4-CP-SCALE-DEFN-OBS-03`
**Selector rule:** selector425 stays byte-frozen; **no selector426** in CB9

## 1. Bounded objective

Establish the missing S4 **independent-oracle and reachability prerequisite** without activating production early rejection. CB9 may author test authority that independently derives an exact incremental connectivity/Betti impossibility result from the authoritative candidate topology state and proves that the same reachable negative fails the unchanged final actual-embedded certificate. It must also carry positive/adversarial controls that the oracle does not reject.

This turn does **not** implement or authorize a new production topology decision. Its purpose is to make the later S4 production change falsifiable before that change exists.

## 2. Frozen semantic authority

The final topology authority remains unchanged:

- `SurfaceCutGraphCellularityCertificate::proves_embedded_cellularity()`;
- `SurfaceCutGraphFaceCertificate::proves_disc_topology()`;
- downstream consumption by `GlobalTopologyRegionDiscCertificate`.

The retired source-support `RegionEulerCharacteristicNotOne` proxy is not authority. An eventual incremental S4 accelerator may only reject earlier when an independently derived invariant proves the unchanged final actual-embedded certificate cannot succeed. It may never become a second topology authority.

## 3. Required source/test inspection before editing

From one exact source snapshot, trace and record:

1. the production construction path that produces the candidate topology state observable before the final disc/cellularity certificate;
2. all incidence data available at that point, including multiplicity/orientation/component information required to derive connectivity/cycle rank without reusing the final certificate helper chain;
3. the final exact certificate construction and the exact reasons a chosen negative fails it;
4. the call path proving the negative and controls actually reach the intended candidate-state seam through all upstream semantic preconditions.

If no stable read-only candidate-state seam exists, STOP. Do not expose a new production decision or add a mutable diagnostic API merely to make the test convenient.

## 4. Independent oracle requirements

The test-side reference oracle must be structurally independent of the product certificate it checks. It may consume the same authoritative incidence facts, but it must not call `proves_embedded_cellularity()`, `proves_disc_topology()`, or a shared helper that already computes the decisive topology result.

At minimum it must derive, with exact integer graph/topology arithmetic where applicable:

- connected-component count of the observed embedded candidate state;
- cycle-rank / first-Betti information needed by the covered rejection class;
- the exact local/global invariant that makes final disc certification impossible for the negative subject;
- a deterministic receipt tying the oracle result to the authoritative topology-state identity.

The oracle must document its covered class. CB9 must not claim a universal theorem from a bounded subject family.

## 5. Required focused subjects

Author one diagnostic prerequisite identity, outside selector425:

`M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral`

It must include all of the following in one deterministic test authority:

1. **reachable negative:** reaches the intended production candidate-state seam, independent oracle rejects, unchanged final exact certificate also rejects for the same topological impossibility class;
2. **positive control:** reaches the same seam, oracle does not reject, final certificate succeeds;
3. **adversarial control:** perturbs incidence/topology near the covered boundary while preserving upstream admissibility and proves the oracle outcome follows the independent invariant rather than fixture identity or row order;
4. **enumeration/relabeling control:** semantically equivalent row/edge/component enumeration does not change the oracle result;
5. **decision-neutrality control:** removing/bypassing the diagnostic oracle code from the test harness cannot change product output, error code, cut set, or certificate bytes.

Every claimed reachability precondition must be asserted before the decisive oracle comparison. A failure before the intended seam is a test-authority failure, not S4 evidence.

## 6. Prohibited moves / STOP guards

CB9 must not:

- change A2a' cut candidate generation, cut addition/removal/order, backtracking, or repair;
- add a production early-reject branch;
- weaken or replace the final actual-embedded certificate;
- revive source-support Euler as disc authority;
- infer exact topology from floating geometry/tolerance;
- append selector426 or edit selector425;
- repair an unreachable fixture until it passes; if reachability is false, record the falsifier and STOP;
- execute Directional runtime in Code + Build.

If a product semantic change is necessary to expose the prerequisite, stop and route that design issue to Review instead of broadening CB9.

## 7. Allowed semantic scope

Expected semantic scope is test-source-only plus narrowly necessary compile ownership metadata if a genuinely new test source file is introduced. Prefer adding the focused identity to an existing appropriate test owner so CMake need not change. Product source/header, fixtures, benchmarks, accepted tests, selector files and reusable workflow permissions remain frozen unless static inspection proves a narrower assumption false; such a conflict is a STOP, not implicit authorization.

## 8. Compile/package gate

After the exact local patch is preserved and applied through the approved repository workflow:

1. compile from the exact pushed source using durable `.github/workflows/agent-compile-reusable.yml`;
2. `DIRECTIONAL_ENABLE_GMP=ON` is mandatory;
3. prove both GMP and GMPXX linkage and `exactArithmeticBackend=GMP`;
4. compile all accepted selector425 owner binaries plus the owner of the new focused prerequisite identity;
5. preserve clean source-status receipts and self-verifying package manifest;
6. package the exact source archive and selector425 bytes;
7. record `runtimeExecution=false` and execute no generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer, or custom input.

Compile failure may be repaired only when the correction remains within CB9's frozen single-variable test-authority scope. A semantic/product broadening requires STOP.

## 9. Required static closeout evidence

CB9 closeout must record:

- exact semantic source SHA and complete changed-path set;
- static proof that selector425 is byte-identical at SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` and still 425 unique rows;
- exact definition count and owner binary for the focused prerequisite identity;
- source-level proof that product cut selection/final certificate behavior did not change;
- independent-oracle derivation and reachability assertions in test source;
- compile run/job IDs, package/log artifact IDs and digests, GMP/GMPXX evidence, source archive and package-manifest hashes;
- explicit no-runtime receipt.

CB9 cannot accept S4 or discharge `M4-CP-SCALE-DEFN-OBS-03`; it can only make the prerequisite eligible for artifact-only execution and Review.

## 10. Frozen successor Test + Benchmark plan

If and only if CB9 compiles/packages GREEN without violating scope, the next runtime turn is `M4-CP-SCALE-TB8-EXEC`, followed by mandatory `M4-CP-SCALE-TB8-REV`.

TB8-EXEC must consume the immutable CB9 package without rebuild/repair and:

1. verify package/source/selector425 identity and owner map before runtime;
2. execute `M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral` exactly once as a fresh focused process;
3. execute selector425 as **425 additional fresh exact-filter processes in exact selector order**;
4. fail on zero-selection, skip, crash, timeout, nonzero exit, or any selector/owner/census mismatch;
5. preserve package/source/execution-view pre/post byte+mode censuses and package manifest;
6. record the focused oracle's reachable-negative, positive, adversarial, relabeling, and decision-neutral receipts separately from cumulative selector results;
7. execute no benchmark and mutate no immutable package/source/fixture/selector bytes.

TB8-EXEC is mechanical evidence only. Only `M4-CP-SCALE-TB8-REV` may decide whether the independent oracle/reachability prerequisite is accepted, whether `DEFN-OBS-03` may advance to production-accelerator implementation, and what exact later CB is authorized. Selector426 remains prohibited until a later Review has accepted both prerequisite reachability and the actual production early-rejection semantics.
