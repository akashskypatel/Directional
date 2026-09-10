# M4-CP1-CB3 Code + Build Plan — Exact Finite-Convergence Global Conformity Schedule

**Status:** FROZEN BY `M4-DEFN-R1` / EXACT NEXT = `M4-CP1-CB3`
**Turn type:** canonical Code + Build
**Runtime:** PROHIBITED
**Definition authority:** `Architecture_M4_DEFN_Frozen_Definitions.md` as amended by `Architecture_M4_DEFN_R1_Definition_Record.md`

## 1. Objective

Implement the first M4 A3 known-feasible schedule-authority slice using the exact fixed-`M=2` Bi-MDF iterative-refinement algorithm disclosed by Heistermann, Warnett and Bommes 2023. Preserve every existing M4 semantic contract; change only the solver implementation/assurance path that `M4-DEFN-R1` amended.

CB3 succeeds only when the required owners compile/link under the mandatory GMP/GMPXX backend and an immutable runtime-free package is produced. No Directional binary may execute in this turn.

## 2. Entering authority

- M3 remains CLOSED / ACCEPTED; package113/TB48 remains reviewed runtime authority at selector409 `405 PASS / 4 RED`, accepted required-green selector365 `365/365`;
- stable accounting remains **47 / 14 / 33**, debt **5**, packages **113**;
- `M4-CP1-CB1` and `M4-CP1-CB2` are historical correct pre-mutation stops;
- `M4-CP1-CB2-REV-CAND-01` is closed by `M4-DEFN-R1` as definition-corrected/non-stable;
- no M4 runtime exists;
- solver identity is `HeistermannWarnettBommes2023ExactBiMDFRefinementM2`; outer assurance class is exact finite convergence, not polynomial.

## 3. Surgical scope and assumptions

Expected semantic owners remain the narrow A3 surface already planned for CB2:

- strong A3 IDs only where existing authority types are insufficient;
- one immutable `GlobalConformityPlan` public value surface;
- new geometry implementation files for binding, exact binary64 conversion, exact Bi-MDF scheduling and independent validation;
- minimal CMake/dependency integration needed for exact solver support;
- one focused CP1 test source and minimum test registration;
- one append-only first-M4 selector whose prefix is byte-identical selector365;
- compile/build report and executable `M4-CP1-TB1` plan after build success.

Do not refactor unrelated M3 code, change A4 consumption, change regional `gridU/gridV` selection, change post-hoc rail pairing, implement CP2 certificate/infeasibility production, or import M5/M6 work.

Assumptions to prove statically before implementation proceeds:

1. a selected weighted-perfect-matching implementation can be instantiated/adapted without narrowing M4 exact weights;
2. the Heistermann reductions can be represented with fixed `M=2` without storage proportional to numeric M4 count/capacity values;
3. exact feasible-start construction can be adapted without floating termination or machine-width semantic decisions;
4. every new external dependency is license-compatible and pinned/reproducible under the repository build policy.

If any assumption fails, stop with a precise implementation blocker. Do not substitute a new optimization algorithm or restore the retired Gabow identity/bound.

## 4. Required implementation

### CB3.1 — semantic values and exact bindings

Implement the unchanged frozen A3 contracts:

- one `ConformitySpanId` per full A2b boundary arc;
- multiplicity-preserving `ConformityBoundaryIncidenceId`;
- `ConformityBreakpointId { span, EInt exactOrdinal }`;
- one positive exact `EInt` count per span;
- exact ordered source-support pieces and compact ordinal breakpoint generation;
- backend-independent finite-binary64 exactification, signed-zero canonicalization and typed rejection of invalid target inputs.

No `size_t`, `int64_t`, floating tolerance, source-simplex split variable or world-space quantization may own semantic count/breakpoint identity.

### CB3.2 — exact target, cap and scalar objective

For canonical rows/spans compute with arbitrary precision the unchanged values:

- preferred exact count `d_s` from the frozen exact metric threshold rule;
- `D=sum d_s`, `H=E*2^V`, `U=2D+E*H`;
- `Q=U+1`, `L=Q^E`, `q_i=Q^(E-i)` in canonical span order.

Represent the production Bi-MDF edge objective directly as

`c_i(x) = L*|x-d_i| + q_i*x`, `1 <= x <= U`.

The semantic authority remains `J=(sum|x-d|,x_1,...,x_E)`. The validator must recompute the semantic vector independently and prove agreement with the private scalar representation. `U`, radix values and costs are proof/data values, never loop bounds over their numeric magnitude.

### CB3.3 — exact feasible initializer

Adapt the disclosed Heistermann et al. §§3.6–3.7 feasible-start pipeline with exact M4 arithmetic:

1. construct the exact pseudo-flow target from per-edge convex minima;
2. perform the parity/even-right-hand-side adjustment without `double`, `llround`, epsilon comparisons or machine-width overflow;
3. construct the symmetric/asymmetric double-cover ordinary-MCF subproblem as specified by the algorithm;
4. solve only with exact integer values/cost comparisons;
5. translate the result back and independently check lower/upper bounds plus every exact bidirected balance row before it becomes `f0`.

For CP1's focused known-feasible inputs, failure to produce or validate `f0` is a hard implementation/test failure. CP2 later owns typed production infeasibility.

### CB3.4 — fixed-`M=2` exact refinement

Implement Heistermann et al. §§3.7–3.9 around current feasible `f`:

- derive the zero-demand bounded Bi-MCF refinement problem relative to `f` with maximum node throughflow `M=2`;
- reduce Bi-MCF → capacitated weighted perfect b-matching using the disclosed node-splitting construction;
- reduce WPbM → weighted perfect matching using the disclosed construction;
- solve the resulting WPM exactly and deterministically;
- translate the matching back through every reduction and validate the candidate exact circulation before applying it;
- commit only exact strictly negative/improving cost changes;
- terminate on exact zero/non-improvement. No epsilon such as upstream libSatsuma's `-1e-20` is permitted.

The terminal criterion is tied explicitly to Heistermann et al. Theorem 3.8; Corollaries 3.7 and 3.9 are the finite-convergence/global-optimality authority. There is no Gabow tag and no inherited Gabow complexity bound.

**Required before any solver source is authored (`M4-DEFN-R1` §R9.2).** Quote **Corollary 3.7, Theorem 3.8 and
Corollary 3.9 verbatim**, showing their quantification over `M` explicitly, and state which one establishes
**global** optimality at a non-improving `M=2` iteration. `M4-DEFN-R1` §R3 attributes that to Theorem 3.8 while
this plan attributes it to Corollaries 3.7/3.9; exactly one mapping survives and CB3 must reconcile them. **If the
optimality result is conditional on `M`, stop** — `M=2` would then converge finitely to a local fixed point and
§R6's preserved exactness guarantee would be false. That is a definition question returning to `M4-DEFN`, not a
Code + Build decision. Two turns have already been stopped by a citation that did not say what the plan needed.

### CB3.5 — exact weighted-perfect-matching primitive

Use the standing solver-library authorization where it reduces implementation risk. Prefer a mature WPM primitive with an implementation-visible published algorithm. LEMON is an acceptable candidate only if CB3 proves at compile time that its weight/comparison interface can use the selected arbitrary-precision exact adapter without narrowing. Blossom V's `int` cost API and upstream libSatsuma's `int64_t` matching weights are not acceptable semantic paths.

A solver-private exact wrapper may be added around GMP/`EInt` to satisfy graph-library numeric traits. It must preserve exact order/add/subtract/comparison and must not convert to `double`, `long long`, or another bounded type for any semantic decision.

Pin any new dependency and document its license/version/revision. Do not import all libSatsuma as semantic authority; port/adapt only the disclosed reductions/control flow needed by the selected algorithm, retaining attribution/license where copied code requires it.

### CB3.6 — WorkLedger

Publish algorithm-corresponding evidence:

- semantic `V,E` and exact `H/U/Q/L` bit widths;
- maximum target/count/capacity/cost integer bit widths observed during the solve;
- initializer graph dimensions and exact validation receipt;
- `refinementM=2`;
- exact `refinementCount`;
- exact objective before/after every committed refinement;
- each refinement's Bi-MCF/WPbM/WPM node/edge dimensions and peak matching graph size;
- matching primitive identity/version;
- retry/reset count exactly zero.

Local implementation loops need finite guards derived from graph/container cardinality or encoded bit width. There is no synthetic global polynomial countdown and no numeric-magnitude iteration.

### CB3.7 — immutable `GlobalConformityPlan`

Publish only semantic authority:

- exact source/network/cut-graph/A2b/target bindings;
- canonical spans and support-piece paths;
- boundary incidences with preserved family/sign/orientation/multiplicity;
- one positive exact count per full span;
- compact breakpoint generator;
- semantic objective `J` and WorkLedger evidence;
- deterministic semantic digest.

Do not serialize double-cover nodes, refinement variables, matching graph vertices, scalar radix internals or container ordinals into semantic identity.

### CB3.8 — independent validator

Keep validator derivation independent of producer private helpers. It must independently check all frozen bindings, span/support continuity, incidence multiplicity, positivity, parity, exact breakpoint reversal, preferred targets, `J`, finite cap/radix identities, WorkLedger dimensions/bit widths and semantic digest.

For the solver result it must at least verify exact feasibility and exact objective reconstruction. CP2 remains responsible for the scalable carried optimality certificate; CB3 must not manufacture that certificate early.

### CB3.9 — focused compiled test authority

Author but **do not execute** deterministic tests covering at least:

1. multi-piece full-span ownership and compact ordinals;
2. reverse incidence/ordinal symmetry;
3. same-row `+2/-2` loop and repeated-incidence preservation;
4. positivity plus mandatory parity;
5. binary64 exactification including subnormal and signed zero;
6. huge `EInt` count/cap/radix values beyond 64-bit without narrowing;
7. exact scalar objective agrees with semantic `J` and resolves lexicographic ties;
8. exact feasible initializer on multiple small bidirected graph classes;
9. fixed-`M=2` refinement makes strictly decreasing exact steps and terminates only on exact non-improvement;
10. a required case where same-row `+/-2` structure makes the problem genuinely bidirected;
11. deterministic permutation/reversal invariance;
12. independent tamper rejection for count, balance, parity, binding, objective, cap/radix and WorkLedger fields;
13. production result equals a **separate tiny exhaustive exact oracle** on known-feasible instances under a hard fixture cap such as `E<=6`, `x<=8`;
14. exact-value cases exceeding upstream libSatsuma/Blossom-V scalar widths, proving no such narrowing path owns the result.

The tiny oracle is test-only, bounded by compile-time fixture limits and shares no producer solver helpers.

### CB3.10 — append-only first M4 selector

After exact test names stabilize, create one selector whose first 365 LF rows are byte-for-byte selector365, then append only CP1 gating identities. Record full count, LF SHA-256 and first-365 prefix SHA. Do not append final-M3 audit-only 366–409 rows merely because selector409 exists.

## 5. Compile/build contract

All compile work uses durable `.github/workflows/agent-compile-reusable.yml`; local build is prohibited. Mandatory GMP compile policy remains unchanged. The authoritative build must:

- configure `DIRECTIONAL_ENABLE_GMP=ON`;
- verify `gmpxx` and `gmp` in authoritative link commands;
- compile/link every changed owner and test target required by the appended CP1 identities;
- package exact source/dependency revisions, build logs, manifest, source status and `exactArithmeticBackend=GMP`;
- report `runtimeExecution=false`.

No generated Directional executable may run for tests, discovery, help, version, custom input, `ctest` or benchmark execution. A compile failure may be corrected in the same CB turn only when the correction stays within this frozen implementation contract.

## 6. Static audit before package acceptance

Before CB3 closes, verify from source/build evidence:

- no Gabow solver identity or bound remains on the active CP1 path;
- no generic ILP/IQP/Gurobi/branch-and-bound path is reachable;
- no `double`, tolerance, `int`, `int64_t`, `size_t` or bounded matching weight participates in a semantic solver decision;
- no graph expansion/loop is proportional to numeric `x,d,U,H,Q,L` or exact cost magnitude;
- `M=2` is fixed for exact refinement and exact non-improvement is the only optimization terminal;
- solver-private graph/reduction state is excluded from semantic IDs/digest;
- CP2 certificates/infeasibility and CP3 production cutover are absent;
- selector365 bytes are unchanged.

Any failure blocks package authority or returns to review if it contradicts the amended definition.

## 7. Required Test + Benchmark plan produced by CB3

On compile success, CB3 must author an executable artifact-only `M4-CP1-TB1` plan tied to the exact immutable package. It must include:

- package/source/hash/mode/GMP preflight and immutable postflight;
- ordered focused CP1 solver/validator tests, tiny-oracle cases and cumulative selector execution;
- zero-selected-filter failure rules;
- deterministic repeat/permutation checks;
- exact WorkLedger and >64-bit arithmetic assertions;
- regression classification requirements;
- no rebuild/relink/fixture repair/package mutation.

TB execution is a later artifact-only turn; this CB turn executes none of it.

## 8. Stop guards

Stop and return to review rather than improvise if:

- the selected WPM primitive cannot support exact arbitrary-precision weights without semantic narrowing and no equally traceable exact WPM implementation fits the frozen algorithm;
- a disclosed Heistermann reduction cannot represent a frozen M4 incidence case without changing semantics;
- feasible initialization requires unbounded numeric enumeration or inexact decisions;
- implementation would require changing the semantic objective, positivity/parity/incidence definitions, CP2/CP3 ownership or accepted predecessor;
- source inspection exposes a contradiction with `M4-DEFN-R1` theorem hypotheses.

A stop is not permission to switch back to Gabow, generic ILP, heuristic approximation, or machine-width arithmetic.

## 9. Falsifiable prediction

If CB3 implements this plan, exactly one known-feasible A3 schedule-authority family plus its independent validator and focused compiled test surface will exist; the solver source will visibly implement the fixed-`M=2` disclosed Bi-MDF refinement pipeline using exact arbitrary-precision arithmetic; the first M4 selector will extend selector365 only; all approved targets will compile/link with GMP/GMPXX; package evidence will report `runtimeExecution=false`; and no M4 runtime claim will be made until the subsequent artifact-only TB turn.
