# M4-CP1-CB3 Build Record

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / NOT YET RUNTIME-ACCEPTED
**Turn:** `M4-CP1-CB3`
**Semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Immutable compile package:** package114, artifact `10142108806`

## Scope and result

CB3 implements the first M4 A3 known-feasible `GlobalConformityPlan` slice under the independently amended
`M4-DEFN-R1` solver authority. The compiled implementation owns one exact positive count per full A2b arc,
preserves multiplicity-bearing incidences and parity, exposes compact arbitrary-precision breakpoint ordinals,
exactifies binary64 ingress, minimizes the frozen exact objective, publishes an independently checkable
`GlobalConformityWorkLedger`, and validates the product without reusing producer-private validation helpers.

The active solver identity is
`HeistermannWarnettBommes2023ExactBiMDFRefinementM2`, with fixed `M=2` and theorem class
`FiniteExactConvergence`. The weighted-perfect-matching primitive is LEMON 1.3.1 at pinned commit
`813c63d4f1d603858d941ac6f04abbe57901996a`, reached through an exact `EInt` weight adapter. Upstream
`libSatsuma` remains reference/control-flow material only; its bounded/floating numeric surfaces are not semantic
authority.

The independent `M4-DEFN-R1` verification addendum was discharged before solver source was relied upon:
Corollary 3.7 gives finite convergence for fixed `M`; Theorem 3.8 covers global optimality of a non-improving
iteration for `M >= 2`; Corollary 3.9 gives the exact refinement consequence. Fixed `M=2` therefore remains within
the frozen definition.

## Source and preservation chain

The CB3 inspection snapshot was control/source commit
`2a098fbc044eec722168764f949a68f44cae0261`, snapshot run/job
`34436940372 / 102743911221`, artifact `10136506689`, provider digest
`sha256:541f8b7dd2ef04b2633df58a5861450eb97efa556c407c4b9fb8a8971be0e079`,
with `runtimeExecution=false`.

Semantic implementation evolved only through preserved, reviewable patches:

- `cfab3e145d65bd6de2c3ab569001e35b5797bead` — A3 product, exact solver, exact-weight adapter, independent
  validator, focused compiled tests, selector373, and initial build integration.
- `ca85ec20bb77b3438c32a9d854e11b70c6a6c041` — independent-validator hardening.
- `05008f7ef6d54769464024301fd7baa9e2c04697` — LEMON header dependency/export correction.
- `680f9f1573d3c7e56a273366436463e40e196131` — final compile correction in `GlobalConformityPlan.cpp`.

The first two correction compiles failed closed during configure/compile and produced no runtime authority.
They were used only to locate build defects; neither failure changes stable regression accounting.

## Selector authority prepared for TB1

`Architecture_M4_CP1_Required_Green_Selector_373.txt` contains exactly **373** LF-normalized identities.

- full LF SHA-256:
  `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- first-365 prefix SHA-256:
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- prefix relation: byte-identical accepted M3 selector365 plus exactly eight CP1 identities.

The eight appended identities are:

1. `GlobalConformityPlan.MultiPieceCompactOrdinalsAndReverseIncidenceSymmetry`
2. `GlobalConformityExactSolver.PreservesSameRowBidirectedMultiplicityPositivityAndParity`
3. `GlobalConformityPlan.ExactBinary64IngressCanonicalizesSignedZeroAndSubnormal`
4. `GlobalConformityExactSolver.HugeExactCapRadixAndLexObjectiveNeverNarrow`
5. `GlobalConformityExactSolver.FixedM2RefinementMatchesSeparateTinyExhaustiveOracle`
6. `GlobalConformityExactSolver.GenuinelyBidirectedLoopPermutationAndReversalAreDeterministic`
7. `GlobalConformityPlan.IndependentValidatorRejectsTamperMatrix`
8. `GlobalConformityExactSolver.ExactValuesExceedLibSatsumaAndBlossomScalarWidths`

These identities are **compiled, not executed**. Selector373 is therefore a TB1 gate candidate, not accepted
runtime authority.

## Mandatory compile/package evidence

The authoritative compile used the durable GitHub-only reusable compile path against exact semantic source
`680f9f1573d3c7e56a273366436463e40e196131`.

- workflow run: `34452123494`;
- compile job: `102790053181`;
- targets: `directional_core`, `directional_surface_cell_producer_tests`;
- exact arithmetic backend: GMP/GMPXX, explicitly found and linked;
- package114 artifact: `10142108806`;
- provider artifact SHA-256:
  `9a87181f771a1814fa854bc2056050b05880b6ec8dfe4ef9c9346102ee26fa36`;
- packaged `bin/directional_surface_cell_producer_tests` SHA-256:
  `5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd`;
- packaged `lib/libdirectional_core.a` SHA-256:
  `0325a5d45181014ff45783596c8d952a14f86d383b46d9f6ba43ccfc92315c4b`;
- boundary: `runtimeExecution=false`, `semanticContracts=compiled-not-executed`.

No Directional executable, test, benchmark, selector, discovery command, or CLI was executed in CB3.

## Static source audit

Before closeout, the active CP1 source was checked against the CB3 prohibitions:

- no active Gabow solver identity or inherited Gabow complexity bound;
- no generic ILP/IQP/Gurobi/branch-and-bound optimization path;
- fixed `M=2` and exact non-improvement remain the optimization terminal contract;
- semantic weights/capacities use exact arbitrary-precision values; bounded integers remain only for structural
  indexes/counters or literal construction, not optimization-value narrowing;
- binary64 values enter through exactification, not tolerance-based semantic comparison;
- solver-private execution state is not part of the semantic plan identity;
- no CP2 certificate/infeasibility producer and no CP3 consumer cutover was implemented;
- accepted selector365 bytes remain unchanged.

## Authority after CB3

CB3 proves **buildability only**. M3 package113/TB48 remains the latest reviewed semantic runtime authority at
selector409 **405 PASS / 4 RED / 0 SKIP**, with accepted required-green selector365 **365/365**. Stable accounting
remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package count
**113**, and ownership **300 / 0 / 0**.

Package114 is an immutable compile package but is not an accepted runtime package until the separately scheduled
artifact-only TB/review path supplies that authority.

**Exact next boundary:** `M4-CP1-TB1-EXEC`, executing the artifact-only plan in
`Architecture_M4_CP1_TB1_Test_Benchmark_Plan.md`. CB3 itself executes none of that runtime.
