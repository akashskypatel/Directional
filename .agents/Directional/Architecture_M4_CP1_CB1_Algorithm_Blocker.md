# M4-CP1-CB1 Algorithm Blocker — Bi-directed Solver Contract

**Status:** CB1 STOP CONDITION TRIGGERED / NO SEMANTIC IMPLEMENTATION MUTATION / INDEPENDENT REVIEW REQUIRED
**Turn:** `M4-CP1-CB1` canonical Code + Build / runtime-free
**Date:** 2026-09-09

## 1. Decision

`M4-CP1-CB1` stops before authoring the A3 product because the frozen solver contract does not currently name or prove an implementable algorithm that simultaneously satisfies all of its mandatory properties. Shipping a heuristic, generic ILP, machine-integer approximation, floating cost, numeric-range scan, or unproved work bound is expressly prohibited by the frozen plan.

No production source, test source, benchmark, selector, build configuration, reusable workflow, or runtime behavior was changed in this turn. No Directional binary was executed and no compile/package run was started. The exact implementation authority therefore remains unchanged.

Exact next boundary: **`M4-CP1-CB1-REV` — independent REVIEW + PLAN / runtime-free.** No implementation, compile, test, benchmark, or package operation is authorized before that review resolves the contract.

## 2. Exact source authority inspected

- semantic branch authority entering the turn: `b523ccb1aba56a08f7d6e19a43f7d67e63464190`;
- source-snapshot control commit: `3ef59b9deeb83040f713055840fd9117c5ea6106`;
- source-snapshot run: `34421215516`;
- source-snapshot artifact: `10130996950`;
- artifact digest: `sha256:b1906692329cc1bc3fba8fa975b263bb0d17153b8b666b286a882098127c7ade`;
- comparison `b523ccb1... -> 3ef59b9d...`: exactly one control-plane source-snapshot marker, no semantic source change.

The active authorities inspected were `DESIGN.md` §4.7/§7.4, `Architecture_M4_DEFN_Frozen_Definitions.md` §7, and `Architecture_M4_CP1_CB1_Code_Build_Plan.md` CB1.4.

## 3. Blocking contract mismatch

The frozen CP1 contract requires all of the following at once:

1. a dedicated bi-directed minimum-deviation/convex-cost-flow solver, not generic ILP/branch-and-bound;
2. arbitrary-precision semantic subdivision counts and ordinals;
3. exact lexicographic objective `(C, x_1, ..., x_E)` with no big-M scalarization;
4. no scan/enumeration whose work depends linearly on numeric count magnitude;
5. an implementation-specific **proved polynomial** state-transition bound `P(V,E,B)` recorded by `WorkLedger`.

The named reference implementation in `DESIGN.md` §4.12 is `libSatsuma`. At upstream commit `4e96979ecb11bbfe8d9c05e8f8be1ecb992ca5fd`:

- `src/libsatsuma/Problems/BiFlowGraph.hh` defines `FlowScalar = int`;
- `src/libsatsuma/Problems/BiMDF.hh` defines both `TargetScalar = double` and `CostScalar = double`.

Those public types cannot serve as CP1's arbitrary-precision count authority or exact lexicographic cost domain without a substantial algorithm/library adaptation that is not frozen by M4-DEFN.

The cited Heistermann/Warnett/Bommes exact method also does not supply the WorkLedger proof frozen by §7.1. In *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization* §3.9, the exact method is iterative refinement. Lemma 3.6/Corollary 3.7 prove that only finitely many lower cost values exist and that the iteration converges after a finite number of steps for fixed `M`; Theorem 3.8 proves optimality when an `M >= 2` refinement iteration cannot improve the objective. That is sufficient for exact termination, but it is not the polynomial `P(V,E,B)` iteration bound required by the frozen `WorkLedger`.

Therefore directly wrapping the cited implementation would violate CP1's exact arithmetic surface, while adapting its solver does not by itself discharge the separately frozen polynomial-step proof. Inventing either missing guarantee inside a bounded CB turn would be new algorithm-definition work rather than implementation of frozen authority.

## 4. Why no implementation workaround was taken

The following tempting substitutions were rejected because they would change the frozen semantics or violate an explicit prohibition:

- **libSatsuma as-is:** machine `int` flow and `double` costs violate exact/arbitrary-precision authority.
- **Generic ILP/IQP:** explicitly prohibited by `DESIGN.md` and M4-DEFN.
- **Bounded enumeration/search around preferred counts:** violates magnitude-independent work and the no-range-scan rule.
- **Big-M encoding of lexicographic tie-breaking:** explicitly prohibited.
- **Finite-convergence WorkLedger presented as polynomial:** unsupported by the cited proof.
- **Restrict CP1 to ordinary directed/non-T-junction instances:** changes the frozen bi-directed input contract and must be adjudicated by review.

The CB plan's own stop rule is therefore active: if the selected dedicated algorithm cannot supply the promised polynomial bound, do not ship a heuristic substitute and route back to review.

## 5. Independent review questions

`M4-CP1-CB1-REV` should resolve exactly one algorithm contract before another CB is authorized. The reviewer should choose and prove one of these directions, rather than leaving the next implementation agent to infer it:

1. **Freeze a specific polynomial exact algorithm** for this signed-incidence problem, including its arbitrary-precision representation, symbolic lexicographic-cost operations, and explicit `P(V,E,B)` bound.
2. **Revise the WorkLedger guarantee** to match the exact libSatsuma-style iterative-refinement theorem (finite exact convergence rather than a currently unsupported polynomial iteration bound), and separately freeze how arbitrary-precision flows plus exact lexicographic costs replace upstream `int`/`double`.
3. **Narrow CP1's admissible graph class** only if source topology proves that restriction is semantically complete for CP1; if so, freeze the proof and a standard polynomial exact solver for that restricted class. A fixture-only restriction is not sufficient.

The review must also decide whether the reference implementation remains normative, illustrative, or is replaced. It should issue one executable CB plan with no unresolved solver-choice or complexity-proof decision.

## 6. Evidence references

- Directional frozen authority: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §7–§7.1.
- Directional CB plan: `.agents/Directional/Architecture_M4_CP1_CB1_Code_Build_Plan.md` CB1.4 and its stop rule.
- Directional architecture: `.agents/Directional/DESIGN.md` §4.7, §4.12, §7.4.
- libSatsuma upstream commit: `cgg-bern/libSatsuma@4e96979ecb11bbfe8d9c05e8f8be1ecb992ca5fd`.
- libSatsuma flow type: `src/libsatsuma/Problems/BiFlowGraph.hh`.
- libSatsuma cost types: `src/libsatsuma/Problems/BiMDF.hh`.
- Reference paper: Heistermann, Warnett, Bommes, *Min-Deviation-Flow in Bi-directed Graphs for T-Mesh Quantization*, ACM TOG 42(4), 2023, §3.9, DOI `10.1145/3592437`.
