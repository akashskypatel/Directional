# M4-CP-COND-CB1 Code + Build Plan

**Turn:** `M4-CP-COND-CB1`
**Type:** Code + Build / compile-only
**Runtime:** forbidden
**Definition authority:** `Architecture_M4_CP_COND_Frozen_Definitions.md`

## Objective

Implement the smallest production seam that makes Amendment-20 conditioning a real pre-A0 product with one writer, an independently checkable certificate and typed refusal, while preserving accepted CP3 A3/A4 semantics and selector408 unchanged. Author the frozen CP-COND witness/test surface and a complete artifact-only TB plan, but do not execute any Directional test/benchmark binary in this turn.

## Required implementation

1. Introduce typed `ConditionedSourceProduct`, `ConditioningCertificate`, `ConditioningPolicy`, correspondence records and `ConditioningFailure` codes matching the frozen definition exactly.
2. Implement one `InputConditioner` entry point that consumes the complete SurfaceCells raw bundle before A0 and returns Produced or Rejected exactly once.
3. Exactify finite binary64 values bit-for-bit before semantic decisions. The initial lattice is the frozen dyadic `k / 2^e` policy with integer exponent/range authority and exact nearest/ties-to-even rounding.
4. Implement only the frozen CB1 operation set: canonical exactification, exact dyadic lattice quantization, exact-equality post-quantization merge with §4.1 safety, exact sliver **refusal**, and unique/canonical discrete `Z4` field reindex. Do not implement topology-changing sliver repair.
5. Implement an independent certificate validator that recomputes digests/correspondence/operation validity from raw input + policy rather than trusting producer fields.
6. Route the SurfaceCells raw entry through this one conditioner before A0. Keep legacy `BoundedMeshPreconditioner` non-authoritative and prevent it from becoming a second SurfaceCells semantic writer.
7. Demote the current `finalize_surface_cell_raw_cross_field` `1e-12` norm and `1e-6` cycle-rounding checks from semantic admissibility authority for conditioned SurfaceCells input. They may remain defensive diagnostics only if they cannot override or create a conditioner verdict.
8. Preserve non-SurfaceCells compatibility unless the new single-writer contract proves a direct conflict; any wider API migration requires review rather than opportunistic refactoring.

## Test source to author and compile — do not execute

Author exact, independently falsifiable tests for:

- identity Produced product and raw/conditioned digest separation;
- one non-empty exact lattice quantization operation;
- exact-equality merge with canonical minimum owner and one unsafe-merge refusal;
- exact sliver-policy refusal with independently derived rational predicate;
- high-valence raw fixture whose valence precondition is derived independently;
- negative-index singularity raw fixture with independently derived discrete index expectation;
- deliberately inadmissible field with independent exact cycle/matching contradiction and typed refusal;
- boundary-truncated separatrix precondition helper; if A2a reachability cannot be proved without runtime, compile it as non-selector evidence and leave the gate blocked rather than asserting expected green;
- correspondence tamper matrix: vertex, face, field permutation, feature/operation record and digest;
- idempotence on one clean and one non-empty-operation Produced fixture;
- S6 exact same-lattice-cell perturbation pair with independently proved exact precondition;
- negative controls proving legacy `BoundedMeshPreconditioner` output or current tolerant raw-field finalization cannot substitute for a valid conditioner certificate.

Every test must establish its raw precondition before calling the production mechanism. A helper that can return an empty witness must make emptiness a named failure, not vacuous success.

## Compile gate

Use the durable GitHub Actions compile workflow with GMP/GMPXX. Compile all directly affected SurfaceCells library/test targets and the public/compiled API target required by the repository's current M4 compile policy. Do not run `ctest`, gtest binaries, benchmarks or custom runtime probes. Packaging must retain an empty source status, root checksum manifest and `runtimeExecution=false` evidence.

If determining the exact target set reveals a broader dependency than expected, compile the additional dependent target rather than narrowing build coverage; document the reason in the CB report.

## Required CB outputs

- implementation/source authority and exact diff census;
- compile-only workflow run/job evidence and immutable package artifact/digest;
- package manifest/source status/GMP-GMPXX/runtimeExecution evidence;
- test identity inventory, distinguishing prospective gating identities from report-only/blocked preconditions;
- `Architecture_M4_CP_COND_CB1_Artifact_Only_Test_Benchmark_Plan.md`, freezing a fresh-process artifact-only TB-EXEC plus mandatory TB-REV boundary;
- updated handoff/TODO/current documents without promoting runtime acceptance.

## STOP rules

STOP before compile if implementation requires any of the following:

- A3/A4 semantic change or selector408 edit;
- a second value writer or raw-to-A0 bypass for SurfaceCells;
- epsilon/proximity authority in correspondence/admissibility;
- topology-changing sliver repair, face deletion/retriangulation, or field-vector perturb-until-pass;
- reusing `BoundedMeshPreconditioner` as the CP-COND certificate owner;
- a gate with a hand-asserted or empty raw precondition;
- CP-SCALE threshold calibration, genus>=2 work, M5/M6/M7 semantics, or CP4 debt;
- generated Directional runtime during CB.

If any STOP fires, preserve the patch, record the exact conflict and return to a bounded definition/review correction rather than weakening the contract.

## Mandatory successor on green compile

Exactly one successor is authorized after a green CB1 compile/package: `M4-CP-COND-TB1-EXEC`, using the CB-authored artifact-only plan. Runtime promotion/classification remains owned by the following mandatory `M4-CP-COND-TB1-REV`.
