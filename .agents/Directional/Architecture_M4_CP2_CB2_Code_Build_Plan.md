# M4-CP2-CB2 Corrective Code + Build Plan

**Status:** ISSUED / EXACT NEXT CODE + BUILD PLAN
**Turn:** `M4-CP2-CB2`
**Boundary:** runtime-free source/test correction + compile/package only
**Entering accepted authority:** M4-CP1 package115/TB2, selector373 **373/373**
**Unpromoted evidence:** package116/TB1, selector380 **380/380 measured green but rejected by review**
**Owning review:** `Architecture_M4_CP2_TB1_Review_Record.md`

## 1. Purpose and hard boundary

Correct exactly `M4-CP2-TB1-REV-CAND-01/02/03`. The review upheld the existing CP2 component, infeasibility, objective, terminal WPM, and CP1-preservation behavior; do not redesign those areas merely because package116 is unpromoted.

CB2 may edit product/test/CMake/selector authority only as needed for the three frozen-contract repairs below. It may configure/compile/package only through `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX authority. **No generated Directional binary may execute in CB2**: no test, benchmark, `ctest`, discovery/list/help/version command, fuzzer, or custom input.

No definition change is authorized. Frozen `Architecture_M4_DEFN_Frozen_Definitions.md` §§3.2, 7.4, 8.1, 9 and 13 already settle the required semantics.

## 2. CAND-01 — make the multi-coordinate oracle receipt success-visible

Keep the existing ordinal-374 identity and its actual exhaustive comparison:

`GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`

Requirements:

1. retain the current four-coordinate full-vector exhaustive oracle inside `E<=6, x_s<=8` and its same-row bidirected coefficient-magnitude-2 structure;
2. retain exact solver-vs-oracle count-vector equality and fixed-`M=2` terminal assertions;
3. replace success-silent `SCOPED_TRACE` as the only metadata receipt with deterministic stdout/stderr text that is present on PASS;
4. derive receipt facts from the constructed fixture where practical rather than printing an unrelated hard-coded claim;
5. the success receipt must contain at minimum `coordinateCount=4` and `containsBidirectedCoefficientMagnitude2=true`;
6. do not weaken the oracle to one coordinate, a scalar-only objective comparison, or a non-gating diagnostic.

The successor TB harness must require those tokens in ordinal-374 raw logs in focused A, focused B, and cumulative execution. Missing receipt text is a gate failure even if GoogleTest exits zero.

## 3. CAND-02 — complete carried WorkLedger assurance and independent verification

### 3.1 Carried schema

Extend `GlobalConformityWorkLedger` additively so it carries every frozen §7.4 family, including explicit:

- assurance class exactly `FiniteExactConvergence(Corollary3.7+Theorem3.8+Corollary3.9,M=2)`;
- maximum observed exact-integer bit width in addition to the existing target/count/capacity/cost category maxima.

Retain the current exact algorithm and LEMON primitive identities/revision. Do not rename the assurance to a polynomial bound.

### 3.2 Producer accounting

Populate the ledger from actual exact solver state, not constants chosen to satisfy tests. The final ledger must correctly carry:

- semantic row/span dimensions;
- exact initializer node/arc dimensions and exact-feasibility receipt;
- exact `H/U/Q/L` bit widths;
- maximum target/count/capacity/cost widths and overall observed exact-integer width;
- `refinementM=2`;
- exact `refinementCount == refinements.size()`;
- exact before/after objective for each committed refinement with strict scalar decrease;
- each refinement's Bi-MCF/b-matching/WPM dimensions;
- peak matching node/edge counts over committed plus terminal refinement work;
- terminal exact non-improvement evidence;
- retry/reset count zero.

If a current producer field does not in fact mean the frozen quantity (for example a category maximum is only an upper-bound proxy), correct the producer to measure the frozen quantity rather than weakening the verifier.

### 3.3 Independent verifier

`GlobalConformityCP2Validator.cpp` must independently rederive/validate the entire ledger contract from source-derived normalized constraints and carried refinement/terminal evidence. It must not call producer canonicalization or accept a producer boolean as proof of a dimension/bit-width equation.

At minimum reject tamper to initializer dimensions, `H/U/Q/L` widths, category/overall maxima, assurance class, refinement count/history, per-refinement objective/dimensions, peak matching bounds, primitive identity/revision, terminal receipt, or retry/reset count.

### 3.4 New dedicated gate identity

Append selector ordinal **381**:

`GlobalConformityCertificate.IndependentVerifierRejectsWorkLedgerBoundHistoryAndAssuranceTamper`

Use one constructed feasible CP2 outcome and a tamper matrix spanning the omitted field families. Each mutation must independently fail `validate_global_conformity_outcome(...)`. Do not merely repeat `refinementM=3`.

## 4. CAND-03 — add the frozen CP2 semantic outcome digest

Add an additive `semanticDigest` (repository naming style may use an equivalent unambiguous name) to `GlobalConformityOutcome`. **Do not change the accepted CP1 `GlobalConformityPlan::semantic_digest()` for identical CP1 input. Do not overload `normalizedProblemDigest`.**

The CP2 semantic digest must be deterministic/canonical and bind at minimum:

- source/network/cut/topology/target/problem bindings;
- canonical full spans including ordered `supportPieces` rather than only network-arc IDs;
- boundary incidences and exact counts;
- compact schedule/breakpoint-generator semantics without O(`x_s`) expansion;
- every scheduled certificate's objective, row balance/parity, WorkLedger, theorem evidence and terminal refinement/WPM witness;
- every infeasible subset's canonical component/affected IDs, reason, exact witness and bindings;
- presence/absence and CP1-compatible semantic identity of `feasiblePlan` without redefining its accepted digest.

Component/result ordering must be canonical so equivalent input container permutations do not alter semantic identity. Diagnostics, hash-container order, thread order, floating emission order, and test execution order are excluded.

The independent CP2 verifier must rederive the semantic digest in its own implementation path after independently deriving the relevant source semantics. It may share public exact value types/hash primitives but not a producer semantic-digest helper whose defect would make both sides agree.

Append selector ordinal **382**:

`GlobalConformityOutcome.SemanticDigestBindsFullCP2Outcome`

This identity must cover all-feasible and an outcome containing infeasible-subset facts. Include independent rejection of semantic-digest tamper and at least one full-support-path/certificate-or-subset semantic tamper, plus permutation stability for semantically equivalent normalized input.

## 5. Accepted CP1 and existing CP2 behavior are regression guards

For the same known-feasible input:

- CP1 schedule counts, objective and `GlobalConformityPlan::semantic_digest()` must remain exactly unchanged;
- existing CP2 identities 374-380 must remain defined under the same names and ownership;
- typed `BalanceCut | PositivityCut | ParityCut`, deterministic component coverage, terminal WPM witness semantics, and all-feasible CP1 schedule equality must not be weakened to make the new verifier pass.

A correction that changes accepted CP1 semantics is a stop, not an incidental update.

## 6. Selector lineage and ownership

Publish `Architecture_M4_CP2_Required_Green_Selector_382.txt` only after both new source identities exist.

It must be:

1. exact **380-row byte prefix** from `Architecture_M4_CP2_Required_Green_Selector_380.txt`;
2. ordinal 381 WorkLedger tamper identity;
3. ordinal 382 CP2 semantic-digest identity.

Required static receipts before compile:

- selector382 line count: **382**;
- selector380 prefix SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- first373 accepted prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- exactly one owner per identity, zero missing/duplicate definitions;
- expected owner partition if both appended identities remain producer-owned: **30 authority-kernel / 236 producer / 75 completion / 41 validation**.

Record the final selector382 LF SHA-256 in the build report and successor TB plan. Update `Required_Green_Selector_Manifest.md` only after source definitions and ownership are statically proved.

## 7. Compile/package authority

Before remote compile, perform static-only checks: `git diff --check`, selector prefix/order/ownership, no forbidden floating/tolerance optimization authority, no O(`x_s`) certificate expansion, no accepted CP1 expected-output drift, and no runtime invocation in CB2 tooling.

Compile/package only through `.github/workflows/agent-compile-reusable.yml` using the durable cache namespace and mandatory GMP/GMPXX backend. Package all selector-owner binaries, source archive, metadata and checksums needed to run the cumulative selector382 gate.

The build report must record exact semantic source SHA, compile run/job, result/log artifact IDs/digests, source archive hash, selector382/prefix hashes, owner partition, executable hashes, complete package `SHA256SUMS`, GMP/GMPXX evidence, clean source status, and `runtimeExecution=false`.

The new candidate package number is **package117** unless repository authority already consumed that number before CB2; if so stop and re-resolve package numbering rather than silently colliding.

## 8. Stop rules

Stop CB2 without promotion if any of the following occurs:

- ordinal374 loses full-vector `±2` exhaustive semantics or the success-visible receipt cannot be made source-derived/deterministic;
- the independent verifier still leaves a frozen WorkLedger field family producer-trusted/unverified;
- semantic digest omits full support paths, certificate evidence, or infeasible-subset facts;
- producer and independent verifier share semantic-digest derivation authority;
- accepted CP1 schedule/objective/semantic digest changes for the same input;
- existing CP2 typed-infeasibility/terminal-witness behavior is weakened;
- selector382 is not exact selector380-prefix + rows381-382, or first373 ceases to equal accepted selector373;
- any required compile target/GMP/checksum/package evidence is missing;
- any Directional runtime is executed in CB2.

A compile error may be corrected within the same CB2 turn only under the normal runtime-free Code + Build rules. A semantic-contract conflict returns to REVIEW/DEFN; do not invent a weaker criterion.

## 9. Successor TB contract to issue only after compile/package green

After a successful package117 compile, issue an immutable artifact-only `M4-CP2-TB2-EXEC` plan. It must, at minimum:

1. preflight exact package/source/GMP/checksum/selector382/owner authority before runtime;
2. run focused correction ordinals **374, 381, 382** twice in frozen order, one identity per fresh process;
3. require ordinal374's success-visible `coordinateCount=4` and `containsBidirectedCoefficientMagnitude2=true` receipt in both focused phases;
4. run all selector382 identities one per fresh process with no generated discovery;
5. report accepted predecessor rows 1-373, previously measured CP2 rows 374-380, correction rows 381-382, and owner outcomes separately;
6. require selector382 **382/382**, accepted predecessor **373/373**, CP2/correction rows all PASS, zero RED/SKIP/timeout/selection mismatch, and immutable package/source/execution-view postflight;
7. preserve package117 as candidate until the configured TB2 review adjudicates promotion and CP2 closure.

No benchmark is required for this correction unless a new source change introduces a separately justified performance claim; do not add one by default.
