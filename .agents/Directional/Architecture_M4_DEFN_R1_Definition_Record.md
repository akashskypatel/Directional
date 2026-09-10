# M4-DEFN-R1 — Solver Definition Amendment Record

**Turn:** `M4-DEFN-R1` — static definition / review + plan.
**Status:** **COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NO PACKAGE**.
**Measures:** R0–R8.
**Entering semantic authority:** independent `M4-CP1-CB2-REV` at `fcd70da6dc3abd8c955ed9725a2e6b41133932d0`.
**Exact inspection snapshot:** event/source `74dbf78fb11a1d989d77d4ccd0c8d07ad25eb69c`, run `34432662583`, artifact `10135052020`, `runtimeExecution=false`.

This record resolves `M4-CP1-CB2-REV-CAND-01`. It changes only the solver/assurance definition for A3. The frozen A3 semantic product, one-count-per-full-span ownership, exact binary64 ingress, incidence multiplicity, positivity, parity, compact exact ordinals, objective `J`, cap `U`, selectors, M3 authority, and checkpoint order are unchanged.

## R0 — boundary and accounting

No Directional binary, test, benchmark, compile, package, selector, production source, fixture, or reusable workflow was executed or changed by this definition turn. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted package count **113**. M3/package113/TB48 remains reviewed runtime authority and selector365 remains the accepted M4 predecessor.

## R1 — ordinary minimum-cost flow is rejected for the frozen admissible class

The ordinary-MCF branch of `M4-CP1-CB2-REV` FA4 is not selected. The frozen M4 incidence contract deliberately preserves two incidences of one full span even when both ends belong to the same `(NetworkRegionId,family)` row. Such a span may therefore have one matrix coefficient `+2` or `-2`.

Heistermann, Warnett and Bommes define a bi-directed network with incidence entries in `{−2,−1,0,1,2}` and identify `+2/-2` with positive/negative loops. They also describe ordinary-MCF approximations as requiring orientation/fixing of non-orientable edges rather than being exact for the full class. Source: *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization*, ACM TOG 42(4), 2023, DOI `10.1145/3592437`, §§2.1.5, 3.1.

An ordinary directed incidence column has one `+1` and one `-1` end (or cancels to zero for a directed self-loop). Therefore the frozen M4 matrix class cannot be replaced by ordinary directed incidence without an additional transformation that must itself handle the bidirected structure. No such exact ordinary-MCF reduction is established by the reviewed sources. Removing the `+/-2` cases would narrow accepted M4 semantics and is prohibited.

## R2 — direct capacitated b-matching is not selected as the production entry point

A direct b-matching route is mathematically viable but is not frozen for CB3. Miller and Pekny, *A Staged Primal-Dual Algorithm for Perfect b-Matching with Edge Capacities*, INFORMS Journal on Computing 7(3), 1995, DOI `10.1287/ijoc.7.3.298`, publishes an arbitrary-capacity perfect-b-matching algorithm and a polynomial step bound. However, the M4 one-shot deviation Bi-MCF has nonzero node demand `-A d`, while the simple Bi-MCF→weighted-perfect-b-matching reduction explicitly developed in Heistermann et al. §3.7 is specialized to the zero-demand refinement subproblems around an already feasible current flow.

Freezing a one-shot direct b-matching implementation would therefore require another fully traced general-demand reduction chain. That chain is not established by the current reviewed implementation sources. Selecting it now would risk reproducing CB2's traceability failure. It remains a future alternative, not current implementation authority.

## R3 — selected algorithm: exact Bi-MDF iterative refinement with fixed `M=2`

M4 now selects the fully disclosed exact iterative method of Heistermann, Warnett and Bommes 2023 §§3.6–3.9. The paper explicitly develops:

1. construction of a feasible integer starting flow via its double-cover approximation pipeline;
2. conversion of the current feasible solution into a zero-demand bounded Bi-MCF refinement problem;
3. reduction of that refinement problem to capacitated weighted perfect b-matching;
4. reduction of weighted perfect b-matching to weighted perfect matching;
5. exact repeated refinement.

For M4, the refinement bound is frozen to **`M=2`**. Corollary 3.7 establishes finite convergence for any fixed `M`; Theorem 3.8 establishes that a non-improving iteration with `M>=2` is globally optimal; Corollary 3.9 concludes that the refinement algorithm finds an optimum for any Bi-MDF problem. These theorem identities, not Gabow's bound, are the solver authority.

The upstream `libSatsuma` repository is implementation/reference material for this disclosed algorithm, pinned for CB3 planning to commit `4e96979ecb11bbfe8d9c05e8f8be1ecb992ca5fd`. Its control flow and reductions are useful, but its numeric types are not semantic authority: upstream uses `int` flow, `double` target/cost, `int64_t` matching weights, and a floating tolerance to stop refinement. M4 must adapt the algorithm to exact arbitrary-precision arithmetic and exact comparisons.

## R4 — exact M4 objective embedding

The semantic objective is unchanged:

`J(x) = (C(x), x_1, ..., x_E)`, where `C(x)=sum_i |x_i-d_i|`.

The already-proved finite cap remains `1 <= x_i <= U`, with `Q=U+1`, `L=Q^E`, and `q_i=Q^(E-i)`. Instead of making `p/n` deviation edges the production problem, CB3 may express the same exact ordering directly as the separable convex integer edge cost

`c_i(x) = L * |x-d_i| + q_i * x`, for `1 <= x <= U`.

Thus `sum_i c_i(x_i) = L*C(x) + S(x)` and has exactly the same unique order as `J`. This is an exact theorem-derived scalarization, not heuristic big-M. The one-shot `x=d+p-n` construction remains a valid proof of the L1/cap/radix identities but is no longer the required production solver representation.

## R5 — exact initialization and exact refinement requirements

The selected algorithm is accepted only under these M4 adaptations:

- all semantic flow/count, demand, capacity, cost, target, radix and comparison operations use arbitrary-precision exact types;
- binary64 target ingress remains the frozen backend-independent exactification from M4-DEFN;
- the feasible-start construction follows the disclosed double-cover/T-join algorithm but uses exact M4 cost arithmetic and independently validates the returned integer flow before refinement;
- every refinement solves the exact fixed-`M=2` zero-demand subproblem; there is no floating epsilon/tolerance termination;
- an iteration commits only when its exact scalar objective is strictly lower; exact zero improvement terminates and, by Theorem 3.8, establishes global optimality;
- no loop, allocation, graph expansion or retry count may be linear in numeric `x`, `d`, `U`, `H`, `Q`, `L`, or an exact cost value;
- solver-private reductions, matching vertices and temporary edges never enter A3 semantic IDs or digests.

The standing user authorization to add a solver library remains applicable. A library may supply the weighted-perfect-matching primitive or graph containers, but it may not narrow exact M4 numbers. Upstream libSatsuma and Blossom V scalar widths are not accepted as-is. CB3 must compile-prove any selected exact adapter; this definition turn does not claim that a particular template instantiation already compiles.

## R6 — assurance amendment: polynomial → exact finite convergence

This is an explicit definition-level reduction in runtime-complexity assurance. M4 no longer claims a polynomial bound for the **outer exact optimizer**. The new authority is:

- algorithm identity: `HeistermannWarnettBommes2023ExactBiMDFRefinementM2`;
- theorem class: `FiniteExactConvergence` — Corollary 3.7 + Theorem 3.8 + Corollary 3.9, fixed `M=2`;
- per-refinement work remains bounded by graph cardinalities and exact integer bit widths, with fixed `M=2` preventing numeric-throughflow graph expansion;
- CP-SCALE may measure refinement counts and resource scaling but may not relabel them polynomial.

The semantic exactness guarantee is not reduced: the terminal schedule is still the unique exact minimizer of frozen `J`.

## R7 — WorkLedger and CP2 consequence

`WorkLedger` must record evidence that corresponds to the selected algorithm, at minimum:

- semantic `V,E`, bound/radix bit widths, and maximum exact-integer bit width;
- feasible-initialization graph sizes and exact validation result;
- `refinementM=2`, exact `refinementCount`, and exact objective before/after each committed refinement;
- per-refinement Bi-MCF/WPbM/WPM graph sizes, peak matching vertices/edges, and matching-solver identity;
- retry/reset count, fixed at zero.

There is no synthetic polynomial countdown. `WorkBoundExceeded` remains available for violated local cardinality/bit-width guards, never for accepting an approximate answer.

Because the outer polynomial runtime claim is withdrawn, **CP2's independent scalable optimality certificate becomes a mandatory semantic barrier before CP3 cutover**. CP2 must independently verify the terminating zero-improvement `M=2` refinement problem and theorem hypotheses, recompute exact `J`, and verify the mapping between the terminal matching/refinement witness and the semantic schedule. A solver-emitted "no improvement" flag alone is not a certificate.

## R8 — candidate disposition and successor

`M4-CP1-CB2-REV-CAND-01` is **CLOSED / DEFINITION-CORRECTED / NON-STABLE**. It adds **0** stable events and **0** recurrences because it described a planning/definition traceability defect, not runtime product behavior.

The exact next turn is **`M4-CP1-CB3` — canonical Code + Build / runtime-free**, under `Architecture_M4_CP1_CB3_Code_Build_Plan.md`. CB3 may implement and compile the amended solver/product surface but may not execute Directional tests or benchmarks. On successful compile/package evidence it must issue the artifact-only `M4-CP1-TB1` plan; later TB execution remains split into EXEC and independent diagnostic/review turns under the active orchestration policy.

---

## R9 — verification-pass addenda (static, appended after the definition)

A verification pass re-derived R0–R8 against the rules frozen in `M4-CP1-CB2-REV` FA3. **The definition is upheld
and all three rules are discharged.** One load-bearing citation needs verbatim confirmation before CB3 builds on it.

### R9.1 — the three FA3 rules, discharged

- **FA3-R1 (the citation must disclose the algorithm, not only the bound):** discharged. R3 enumerates a
  *construction* from Heistermann, Warnett and Bommes 2023 §§3.6–3.9 — feasible start via double cover, conversion
  to a zero-demand bounded Bi-MCF refinement, reduction to capacitated weighted perfect b-matching, reduction to
  weighted perfect matching, exact repeated refinement — and pins `libSatsuma` to a specific commit as reference
  material rather than authority.
- **FA3-R2 (no inherited complexity labels):** discharged completely. `Gabow1983ArbitraryCapacityMinCostBiflow`
  and `O(E'^2 log V' log Cmax)` appear **nowhere** in this record or the CB3 plan. Identity and theorem class moved
  together to `HeistermannWarnettBommes2023ExactBiMDFRefinementM2` / `FiniteExactConvergence`, and R6's guard —
  *"CP-SCALE may measure refinement counts but may not relabel them polynomial"* — blocks the label creeping back.
- **FA3-R3 (assurance drop stated, not absorbed):** discharged, and better than required. R6 names it a
  definition-level reduction, and R7 draws the right consequence — **losing the outer polynomial claim makes CP2's
  independent scalable optimality certificate a mandatory semantic barrier**, so assurance moves rather than
  evaporates. R6 also correctly separates what did *not* change: the terminal schedule remains the unique exact
  minimizer of frozen `J`.

**R1 and R2 also answered FA4 in the order it was frozen.** The ordinary-MCF rejection is *proof-shaped* — the
frozen incidence contract preserves two incidences of one full span, giving `±2` entries, while an ordinary
directed incidence column has one `+1` and one `−1` — not an observation about current fixtures. That is exactly
what FA4 item 1 demanded.

**R5's scoping of the standing library authorization is better than the one this reviewer proposed.** CB2-REV
looked for a library at the *outer* bidirected solver, where none exists. R5 places it at the **inner
weighted-perfect-matching primitive**, which is precisely where exact-templated implementations do exist. That
makes the chain buildable without weakening any representation rule.

### R9.2 — the whole optimality guarantee now rests on one paraphrased quantifier

R6 preserves the semantic exactness guarantee: *"the terminal schedule is still the unique exact minimizer of
frozen `J`."* Under R5 that guarantee is delivered by a single inference — an exactly-zero-improvement fixed point
of **`M=2`** refinement is the **global** minimizer.

Every statement of that inference in the retained record is a **paraphrase**, and the two documents do not agree on
which published result carries it:

| Location | Attribution |
|---|---|
| R3 | *Corollary 3.7* gives finite convergence for any fixed `M`; **Theorem 3.8** gives global optimality at a non-improving iteration |
| R6 | theorem class = Corollary 3.7 **+** Theorem 3.8 **+** Corollary 3.9 |
| `…CB3_Code_Build_Plan.md:99` | terminal criterion tied to Theorem 3.8; **Corollaries 3.7 and 3.9** are the *"finite-convergence/global-optimality authority"* |

R3 assigns global optimality to Theorem 3.8; the CB3 plan assigns it to Corollaries 3.7 and 3.9. **They cannot both
be the precise mapping**, and the difference matters: if the optimality result is quantified over `M` — holding
only as `M` grows, or for `M` at least some instance-dependent value — then `M=2` converges finitely to a **local**
fixed point and R6's preserved exactness guarantee is false.

This project has now been stopped **twice** by a citation that did not say what the plan needed: Gabow's
`P(V,E,B)` at CB1, and Gabow's deferred problem (5) at CB2. Both times the gap was invisible until implementation.

> **Added to CB3 (non-optional), before any solver source is authored:** quote **Corollary 3.7, Theorem 3.8 and
> Corollary 3.9 verbatim**, with their quantification over `M` shown explicitly, and state which one establishes
> **global** optimality at a non-improving `M=2` iteration. Reconcile R3's attribution with the CB3 plan's; exactly
> one mapping survives. **If the optimality result is conditional on `M`, R6's exactness claim must be revised
> before implementation, not after** — and that is a definition question returning here, not a CB decision.

This is a confirmation obligation, not a defect finding: nothing in R0–R8 is shown wrong. It is the cheapest
possible receipt for the one inference the entire semantic guarantee now hangs on.

### R9.3 — accounting

Unchanged. This addendum is static, adds **+0 events / +0 recurrences**, and does not alter the selected algorithm,
the assurance amendment, the candidate disposition or the successor. **Exact next remains `M4-CP1-CB3`.**
