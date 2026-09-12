# M4-CP3-TB3 Artifact-Only Test + Benchmark Plan — exact A3→A4 shared-boundary cutover

**Status:** FROZEN BY `M4-CP3-CB5` AFTER BUILD GREEN
**Execution turn:** `M4-CP3-TB3-EXEC`
**Review turn:** `M4-CP3-TB3-REV`
**Package source:** `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`
**Package run/job:** `34670989680 / 103492183626`
**Package artifact:** `10290933668`
**Package artifact SHA-256:** `3c73ce15c626b9811a0122cccaaa9615f76f1a6b5d6e93692a05fef524a36571`
**Accepted predecessor selector403:** `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
**Candidate selector408:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`

## 1. Turn boundary

This is immutable **artifact-only runtime execution**. It may consume only the exact CB5 package named above. It must not configure, compile, relink, regenerate GTest discovery/code, modify packaged source/fixtures/manifests, repair permissions, or execute an unpackaged binary.

Extract the package with a normal archive tool that preserves executable mode bits. Python `zipfile.extractall` is forbidden for executable payloads. A missing executable bit is orchestration failure, not permission to `chmod` the package.

`TB3-EXEC` records raw mechanical evidence only. It may not promote the package, close CP3, alter stable regression accounting, or diagnose a red result. `TB3-REV` independently re-opens the package/results and owns acceptance, regression classification, CP3 closure, and successor planning.

## 2. Immutable preflight

Before any produced binary executes, verify and record:

1. downloaded artifact ID and outer SHA-256 exactly match the CB5 closeout;
2. package metadata binds to source `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e` and records `runtimeExecution=false` for the build;
3. recursive package `SHA256SUMS` self-check passes exactly with no missing/extra/changed packaged entries;
4. source archive SHA and manifest SHA match the CB5 closeout record;
5. all four selector-owner executables are present and executable without mutation:
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
6. accepted selector403 is present byte-identical at SHA `c3f509af...cb7`;
7. candidate selector408 is present at SHA `c689c0cd...484` and has exactly 408 LF rows;
8. selector408 rows 1-403 are byte-identical to accepted selector403;
9. static package/source test-definition ownership maps all 408 identities uniquely with owner partition **30 authority-kernel / 262 producer / 75 completion / 41 validation**;
10. no build tree, compiler invocation, CMake configure, generated discovery file, or repaired package state is introduced by TB.

Any failed preflight item is **orchestration RED**. Do not execute the semantic gate after immutable package authority fails.

## 3. Exact fresh-process runtime ledger — 821 processes

Every test process must use one exact fully qualified GTest identity and must select exactly one test. Zero selection, multiple selection, skip, crash, timeout, or nonzero exit is RED.

### Gate A — focused CB5 rows 404-408, pass A: 5 processes

Execute each appended selector408 identity once, in selector order:

404. `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
405. `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals`
406. `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback`
407. `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign`
408. `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

Required result: **5/5 PASS**.

### Gate B — focused CB5 rows 404-408, pass B: 5 processes

Repeat the same five exact-filter processes from a fresh execution view and record a second verdict/receipt vector.

Required result: **5/5 PASS** and byte/equality-identical deterministic receipts wherever the tests publish structured evidence.

### Gate C — accepted predecessor selector403: 403 processes

Execute every accepted selector403 identity once in a fresh exact-filter process against its statically mapped owner executable.

Required result: **403/403 PASS**, zero skip/timeout/selection mismatch.

This is the predecessor-compatibility gate. Any accepted identity loss is RED even if selector408 is otherwise green.

### Gate D — candidate selector408: 408 processes

Execute every selector408 identity once in a fresh exact-filter process against its statically mapped owner executable.

Required result: **408/408 PASS**, zero skip/timeout/selection mismatch.

The first 403 verdicts must equal the accepted selector403 gate. Rows 404-408 must all pass.

### Exact total

```text
focused A       5
focused B       5
selector403   403
selector408   408
-----------------
total         821 fresh processes
```

No aggregate GTest process substitutes for these 821 exact-filter processes.

## 4. Frozen CB5 semantic acceptance predicates

The executor records the raw result for each predicate; review decides promotion.

### P1 — production A3 authority receipt

Row404 must prove the production A4 phase-front product carries an immutable receipt whose topology-plan digest, baseline-plan digest and schedule-entry count equal the independently validated A2b/A3 products passed by `RemeshPipeline`.

A green test over no shared hard-rail pair is vacuous and RED.

### P2 — fixed-plan target/grid perturbation

Row405 must hold one accepted A3 topology/baseline plan fixed while executing at least two distinct A4-local target/grid settings. The typed shared-boundary interval identities must be equal between the two results even if interior construction differs.

The evidence must establish that accepted A3 subdivision dominates A4-local target/grid choices. Comparing two executions that accidentally use identical local settings is vacuous and RED.

### P3 — no rounded/tolerance fallback

Row406 must show both:

- removing an interval identity from an otherwise accepted hard-rail product is rejected; and
- tampering one interval's span/ordinal authority is rejected.

Neither case may pair through rounded barycentric coincidence, former `support_key` behavior, local target size, or post-hoc partner agreement.

### P4 — A4-local frame semantics preserved

Row407 must establish that hard-rail family and `advanceSign` continue to derive from A4 lattice direction and remain opposite-compatible across paired copies. No A3 incidence family/sign value may be copied into A4 as shared-boundary identity.

### P5 — exact torus blocker removed through accepted span+ordinal identity

Row408 must traverse the production torus pipeline with the independently built `GlobalTopologyPlan` and `GlobalConformityBaselinePlan`, produce A4 typed shared-boundary intervals, and advance past the prior `InvalidHardRailPairing` stop.

The pass is invalid if achieved by:

- weakening/removing family/sign checks;
- positional/tolerance pairing;
- source-grid recovery;
- legacy fallback;
- modifying accepted A3 schedule/counts/breakpoints inside A4.

Later downstream failure is allowed only if it is distinct from `InvalidHardRailPairing` and the row's exact assertions all pass; review owns whether such a downstream result is acceptable for CP3 closure.

## 5. Carried observations remain out of gate

`M4-CP3-TB1-R1-REV-OBS-01` and `M4-CP3-CB4-REV-OBS-02` remain non-blocking carried observations unless rows404-408 naturally emit independently falsifiable evidence for them. TB3 must not add extra runtime solely to discharge those obligations.

The three `G4-B002` produced-witness debts remain CP4-owned and are not silently credited by CP3 gate success.

## 6. Immutable postflight

After all 821 fresh processes, repeat package/source/execution-view integrity checks and require:

- package `SHA256SUMS` still passes exactly;
- packaged source census/hash matches preflight;
- execution-view census/hash matches preflight except for explicitly external result/log directories;
- selector403 and selector408 bytes/hashes unchanged;
- no compiler/configure/relink/discovery/package-repair command occurred;
- no packaged source, fixture, executable, manifest or permission bit was changed.

Record exact per-process filter, owner executable, selection count, exit code, elapsed time, stdout/stderr location, verdict, and timeout state in machine-readable evidence.

## 7. Required EXEC outputs

`M4-CP3-TB3-EXEC` must preserve:

- raw per-process ledger for all 821 processes;
- focused A/B receipt comparison;
- selector403 and selector408 summary tables;
- owner totals and owner-result totals;
- package/source/execution-view pre/postflight hashes;
- exact torus row408 stdout/stderr and terminal-stage evidence;
- immutable result/log artifacts with recursive manifests;
- one concise EXEC report that makes no promotion or root-cause decision.

## 8. Review handoff

The mandatory successor after valid EXEC evidence is `M4-CP3-TB3-REV`.

Review must independently re-open the CB5 package and raw result artifacts, re-derive the 821-process ledger and selector prefix/ownership facts, inspect rows404-408 for non-vacuity, and decide all of:

1. candidate package promotion or rejection;
2. selector408 promotion or rejection;
3. whether `G4-B002`'s `InvalidHardRailPairing` CP3 owner is closed;
4. whether CP3 itself closes or requires one bounded correction;
5. stable regression accounting changes, if any;
6. exact next turn.

No implementation turn may begin before that Review boundary is formally closed.
