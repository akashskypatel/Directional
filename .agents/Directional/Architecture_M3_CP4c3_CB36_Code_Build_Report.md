# M3-CP4c-3-CB36 — Code + Build Report

- **Phase:** `M3-CP4c-3-CB36`
- **Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
- **Execution mode:** canonical Code + Build
- **Frozen semantic starting authority:** `d1a2844b32374f6e5b78656167e8e579301d9378` (`M3-CP4c-3-TB30-REV` closeout)
- **Snapshot/control-plane base:** `4320323bf340f5d60bcef1c629e6d7ad6dc01634`
- **Built evidence commit:** `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`
- **Remote synchronization:** verified before the build; the reusable compile workflow checked out the exact evidence commit.

## Implemented

Applied the already-frozen separating-arc rule at the second implementation site in
`src/geometry/GlobalTopologyPlan.cpp`.

The prior code skipped every terminal slit while constructing plan-side fragment/orbit and touched-edge evidence.
CB36 defines:

```cpp
const bool separatesCertifiedFaces = forwardOrbit != reverseOrbit;
```

and narrows the existing early-continue guard to:

```cpp
if (is_terminal_slit(*trace, segmentIndex) &&
    !separatesCertifiedFaces) {
    ...
    continue;
}
```

No other product behavior was changed.

## Engineering-Guideline Review

- **Material assumption:** `forwardOrbit` and `reverseOrbit` are already the certified face-walk orbit labels used at
  this site. The TB30 independent review froze inequality of those two values as the separating-arc criterion.
- **Simplest sufficient approach:** one local boolean plus one guard predicate change at the exact second site named by
  CQ7–CQ8.
- **Why no smaller approach satisfies the contract:** changing only `traceTouchedEdges` would leave the same separating
  terminal slit incorrectly excluded from `tracePieceCount` and `add_fragment_orbit`; the frozen rule applies to the
  whole skip, not one consequence of it. TB31 has an explicit falsification condition if this premise is wrong.
- **Unrelated refactors/style drift:** none.
- **Every changed product line traces to the objective:** yes.

## Files Changed

Product source only:

- `src/geometry/GlobalTopologyPlan.cpp`

Turn-closeout documentation is committed separately from the built evidence commit.

## Domain Invariants

Accepted-prefix safety is structural:

- non-terminal segments never enter the changed branch condition;
- terminal slits with `forwardOrbit == reverseOrbit` still take the pre-existing skip unchanged;
- only terminal slits whose two certified darts are in distinct face-walk orbits now flow through the pre-existing
  fragment/orbit/touched-edge body;
- therefore known non-separating terminal-slit arcs 20 and 24 (`0/0`) are unchanged by construction.

The change does not alter selector identities, fixtures, test definitions, ownership publication, partition
unification rules, or the prescribed-sphere scope.

## Generalization Review

This is not fixture-specific: the predicate is expressed solely in terms of certified orbit separation at the
current trace segment. There are no arc IDs, source-face IDs, ordinal IDs, mesh names, or expected failure strings
in the implementation.

Regression risks considered:

- over-cutting equal-orbit terminal slits — excluded by the new predicate;
- fragment-count inconsistency if `tracePieceCount + 1` is not valid for a separating terminal slit — explicitly
  falsified by TB31 on `TraceCutFaceFragmentCountMismatch`;
- accepted-prefix regression — TB31 re-executes the immutable selector 408 and requires 1–365 = 365/365 PASS.

## Build

- **Workflow/run/job:** durable `.github/workflows/agent-compile-reusable.yml` through run
  `34010011172`, compile job `101424080079`.
- **Result:** SUCCESS.
- **Exact built source:** `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`.
- **Targets (8):** `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`.
- **Compile result artifact:** `9982174864`, `m3-cp4c3-cb36-result-34010011172`, provider ZIP SHA-256
  `8bbc10da2372730a4fd644250a420f0ba7e6dd73f59e93364b2b1ccacfbcf43b`.
- **Compile log artifact:** `9982175106`, provider ZIP SHA-256
  `d7c4fbc4d4ee31a809ccba26e0b39a77dab49a1fc4d43009377354bc0c353d27`.
- **Packaged source archive SHA-256:**
  `f909864226b07a4cd89a9a51669792e8cdd63206c5b2a23d2e0b179476d78cae`.
- **Package verification:** root `SHA256SUMS` passed; source-status files empty; build/preflight exit 0.
- **Arithmetic backend:** GMP/GMPXX evidence present (`libgmpxx.so`, `libgmp.so`).
- **Boundary:** `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `preflightCompile=true`.
- **Tests/benchmarks executed:** none. No produced Directional binary, test, benchmark, discovery command, CLI,
  fuzzer, help/version command, or custom input was executed during CB36.

## Work Preservation / Remote Application

The exact product patch was emitted before remote application and verified with `git apply --check` and
`git diff --check`:

- patch SHA-256 `f584881b6621afe26b03566077adfb5ed28ac3e52bb90745d1af158b2b7d88f2`;
- diff-body SHA-256 `2ebaad39a6932e9e6d808c8d9074d9c95902ce770900bb93b11db7ae88d6b98f`;
- intended product path only `src/geometry/GlobalTopologyPlan.cpp`.

It was staged in `My Drive/Directional-CI`, applied by durable `agent-google-drive-reusable.yml`, and the staged
Drive copy was then permanently retired through the owner-authorized Drive control plane. Apply run
`34009914130`, job `101423888870`, succeeded and produced evidence commit `90bf8430...`.

## Known Risks / Runtime Falsification

CB36 is compile-valid only. It makes no semantic runtime claim.

TB31 must falsify the active candidate before any further correction:

1. if ordinals 366/367 still fail with plan component `0`, `191` faces, seeds `[0,1,3]`, and the same failing
   face-set digest `17919102493633069558`, `M3-CP4c3-TB30-REV-CAND-01` is falsified;
2. if `TraceCutFaceFragmentCountMismatch` appears, the `tracePieceCount` premise is wrong and any successor
   correction must narrow to the `traceTouchedEdges` insertion rather than expanding scope.

Ordinal 398 is not an ownership signal; 368/369/370/374 remain carried surfaces with separate owners.

## Mandatory Test + Benchmark Plan

- **Plan:** `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md`
- **Evidence commit/artifact:** `90bf8430f54c8b81fb90a6bda820cf8edebce6e9` / `9982174864`
- **Focused validation:** 366/367 plan partition and ownership census, plus the explicit falsification conditions.
- **Related regression validation:** immutable selector 408, accepted 1–365, all carried RED surfaces, ownership
  300/0/0, and static selector/identity integrity.
- **Full validation:** all 408 selector identities, one fresh process/workdir per identity.
- **Benchmarks:** none.
- **Stop conditions:** artifact/source/integrity/orchestration failure before runtime; semantic REDs do not stop the
  mechanically valid full-selector execution.

## Next Turn

**Type:** Test + Benchmark

**Exact next subturn:** `M3-CP4c-3-TB31-EXEC` — artifact-only runtime execution. It records raw evidence only and
stops at `M3-CP4c-3-TB31-REV` for semantic adjudication.

## Live Handoff

- **Path:** `.agents/Directional/Future_Chat_Session_Handoff.md`
- **Evidence commit:** `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`
- **Handoff/closeout commit:** documentation-only, recorded after this report is applied.
- **Test plan:** `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md`
- **Agent entry point:** exact next boundary and context plan updated for TB31-EXEC.

## Control-Plane Deviation Recorded

The source-snapshot control-plane orchestration began after the mandatory full
`TOOL_USE_CONSERVATION_POLICY.md` read but before the full project `GitHub_Workflow_Policy.md` read was completed.
The full workflow policy was read before semantic source mutation, Drive patch application, or compilation. The
deviation affected ordering of control-plane preparation only; it did not change the frozen semantic source,
product patch, compile source, runtime boundary, or evidence. It is recorded rather than normalized away.
