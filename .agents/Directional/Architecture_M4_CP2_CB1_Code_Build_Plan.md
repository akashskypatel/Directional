# M4-CP2-CB1 Code + Build Plan — certification and typed infeasibility

**Status:** ISSUED / EXACT NEXT / RUNTIME-FREE
**Turn:** `M4-CP2-CB1`
**Entering reviewed runtime authority:** package115/TB2, selector373 **373/373**
**Entering semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Normative authority:** `Architecture_M4_DEFN_Frozen_Definitions.md` §§3.1, 7-9, 11

## 1. Purpose and assumptions

Implement the frozen CP2 addition: carried positivity/parity/optimality certification for scheduled components plus a typed subset-scoped infeasibility alternative. **CP1 feasible schedule semantics are immutable entering authority.** CP2 may add data, outcome structure, certificate production and verification; it may not change the accepted CP1 objective, fixed `M=2`, cap/radix construction, canonical ordering, breakpoint generator, incidence semantics, or known-feasible schedule chosen for an input.

Keep `GlobalConformityKnownFeasibleInput` / `make_known_feasible` behavior valid for existing callers. Do not silently reuse a type named "known feasible" as the public possibly-infeasible production contract; add the smallest additive generic input/outcome surface consistent with repository style.

If a frozen CP2 requirement cannot be implemented without inventing a semantic rule not present in the frozen definitions, **stop before semantic implementation and route to `M4-CP2-DEFN`**. Same-agent DEFN is authorized, but CB1 may not define missing semantics by convenience.

## 2. Scheduled-component certificate

Add the `GlobalConformityCertificate` data required by frozen §8.1. At minimum it must bind:

- source/network/cut/topology/metric/normalized-problem identity;
- exact scheduled counts, preferred counts, exact objective `J*`, positivity results, every region/family balance and explicit parity result;
- the exact terminal fixed-`M=2` refinement problem;
- deterministic producer-native terminal WPM/refinement witness sufficient to reconstruct the zero-improvement claim and its mapping back to semantic schedule coordinates;
- theorem-hypothesis evidence for the fixed-`M=2` optimality implication;
- WorkLedger dimensions, bit-width bounds and observed maxima.

The certificate stays compact: no O(`x_s`) breakpoint expansion. A solver-emitted boolean such as `terminalExactNonImprovementValidated` is not sufficient by itself. Preserve exact arbitrary-precision arithmetic throughout.

## 3. Independent CP2 verifier

Extend the independent validation path without sharing producer-private semantic-derivation helpers. From the public/topology-bound input plus carried certificate, independently re-derive the normalized exact terminal problem and:

1. recompute the exact schedule objective and all positivity/balance/parity facts;
2. validate the exact terminal `M=2` refinement instance and the certificate-to-semantic-coordinate mapping;
3. validate the carried matching/refinement witness and independently establish that no negative-cost admissible terminal refinement exists;
4. validate the theorem hypotheses and WorkLedger bounds used to convert terminal non-improvement into semantic optimality;
5. reject any binding, objective, parity, terminal-problem, matching-witness, mapping, theorem-hypothesis, or WorkLedger tamper.

Sharing the exact arithmetic primitive and the pinned weighted-perfect-matching primitive is allowed; sharing a producer semantic derivation whose defect would make producer and verifier agree for the same reason is not. Do not add a second generic schedule solver.

## 4. Typed subset-scoped infeasibility

Add the production CP2 alternative `ConformityInfeasibleSubset` and reason domain `BalanceCut | PositivityCut | ParityCut` exactly as frozen in §8.2. Ordinary mathematical infeasibility must no longer be encoded as `GlobalConformityPlanError`. Fatal errors remain reserved for malformed/binding/contract/resource failures from §8.3.

The CP2 production outcome must partition the normalized incidence graph into deterministic connected constraint components. Every boundary incidence is covered exactly once by either a scheduled component with certificate or a verified infeasible-subset fact; one region may participate in multiple components. For an infeasible component publish canonical sorted affected region/incidence/span IDs, exact source/topology/metric/problem digests, and an algorithm-native residual/cut/deficit witness that the independent verifier reconstructs exactly. The subset need not be cardinality-minimal; it must be deterministic and valid. No A4 replacement schedule is permitted.

Do not weaken the existing CP1 all-feasible validator to accept partial schedules. Prefer an additive CP2 outcome/verifier surface so the accepted CP1 `make_known_feasible` path remains a strict regression oracle.

## 5. Mandatory deferred CP1 oracle strengthening

This is the first later Code + Build turn authorized to edit test source, so it owns the TB1-review obligation. Extend the separate exhaustive oracle with at least one **multi-coordinate** instance that carries the bidirected `±2` structure and lies inside the already-frozen `E<=6, x_s<=8` envelope. Enumerate the full count vector, compare its exact optimum/tie result with the fixed-`M=2` solver terminal schedule, and make the receipt identify coordinate count and `±2` presence.

Do not modify the frozen solver or objective merely to satisfy the oracle. Any disagreement is a hard stop and routes to REVIEW/DEFN evidence rather than being patched around.

## 6. Exact gating identities and selector lineage

Author exactly seven new direct deterministic identities in `tests/GlobalConformityPlanTests.cpp`, appended after the accepted selector373 in this order:

1. `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`
2. `GlobalConformityCertificate.CarriesBindingPositivityParityObjectiveAndTerminalWitness`
3. `GlobalConformityCertificate.IndependentVerifierRejectsTerminalWitnessTamper`
4. `GlobalConformityOutcome.FeasibleCP2PathPreservesCP1ScheduleExactly`
5. `GlobalConformityOutcome.InfeasibleComponentReturnsTypedSubsetInsteadOfFatalError`
6. `GlobalConformityOutcome.InfeasibleSubsetIsCanonicalAndVerifierRejectsWitnessTamper`
7. `GlobalConformityOutcome.MixedComponentsCoverEveryIncidenceExactlyOnce`

The successor selector is therefore `Architecture_M4_CP2_Required_Green_Selector_380.txt`: exact accepted selector373 bytes as prefix plus those seven identities. Update `Required_Green_Selector_Manifest.md` only after the source definitions exist and static one-owner mapping is proven. These are gating identities under frozen §11 because their preconditions are fully constructed and independently checkable.

Within identity 6, use a tamper matrix that covers reason/witness/binding/affected-set corruption; within identity 2/3, cover the certificate fields listed in §§2-3 rather than creating many shallow existence-only tests. At least one genuinely infeasible production fixture must reach a typed subset through the public CP2 path.

## 7. Source/build scope

Expected semantic touch surface is narrow:

- `include/directional/geometry/GlobalConformityPlan.h`;
- `src/geometry/GlobalConformityPlan.cpp`;
- `src/geometry/GlobalConformityExactSolver.h/.cpp`;
- `src/geometry/GlobalConformityValidator.cpp`;
- `tests/GlobalConformityPlanTests.cpp`;
- `cmake/DirectionalTests.cmake` only for explicit packaged-contract ownership of the seven new identities;
- the new selector380 and derived selector manifest;
- one CP2 artifact-only successor harness/plan if needed for immutable TB execution.

Do not refactor unrelated M3/M4 code, move existing test sources between owner targets, alter reusable-workflow permissions, or begin CP3 producer cutover. If implementation proves another file is semantically required, record why before touching it.

## 8. Code + Build verification

Before remote compile, run static source/diff checks only: exact selector prefix/order and one-owner mapping, no CP1 expected-output drift, no forbidden floating/tolerance optimization authority, no O(`x_s`) certificate expansion, and no runtime invocation in CB1 tooling.

Compile/package only through `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX linkage. Use the durable cache namespace unchanged and package all selector-owner binaries required for the cumulative selector380 gate, not only the producer binary containing new tests. Record exact semantic source SHA, artifact ID/provider digest, source archive, executable hashes, complete `SHA256SUMS`, and `runtimeExecution=false`.

**CB1 success is compile/package authority only.** Do not execute tests, `--gtest_list_tests`, discovery, benchmarks, CLI/GUI binaries, or custom Directional runtime inputs.

## 9. Successor TB plan and stop conditions

After compile/package succeeds, issue an artifact-only `M4-CP2-TB1-EXEC` plan tied to the exact package and selector380. It must run the seven CP2 identities twice as a focused deterministic receipt and the complete selector380 one identity per fresh process through exact owner mapping, report the accepted 373-row prefix separately, and prove immutable package/source/execution-view postflight.

Stop before packaging or TB handoff if:

- the multi-coordinate `±2` exhaustive oracle disagrees with fixed-`M=2`;
- CP1 feasible-path schedule/objective/semantic digest changes for the same input;
- ordinary infeasibility still escapes only as `GlobalConformityPlanError`;
- a certificate cannot independently establish terminal optimality from carried evidence;
- any incidence is uncovered or multiply covered across scheduled/infeasible components;
- selector380 is not an exact selector373 prefix extension with one owner per identity;
- GMP/GMPXX compile authority is absent.

No runtime result may be inferred in CB1.
