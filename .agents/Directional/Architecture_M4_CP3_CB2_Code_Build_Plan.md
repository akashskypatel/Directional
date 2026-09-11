# M4-CP3-CB2 Code + Build Plan — family-free baseline parity A3 semantic rebase

**Status:** READY / AUTHORITATIVE NEXT TURN / RUNTIME-FREE CODE + BUILD
**Issued by:** `M4-CP3-DEFN-R1`
**Normative definition:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17
**Review authority:** `Architecture_M4_CP3_DEFN_R1_Review_Record.md`
**Accepted runtime predecessor:** package117 / selector382 **382/382**

## 1. Turn boundary

This is a canonical **Code + Build** turn. Source/test/build-definition edits and compile-time/static verification are allowed. Directional runtime is not.

Allowed: implement the frozen parity A3 core, author regression tests/selectors, commit/push, compile exact pushed source through the durable GitHub compile reusable with mandatory GMP/GMPXX, package compile evidence, and issue the immutable artifact-only TB plan.

Forbidden: execute Directional tests/benchmarks/discovery/help/version commands; production-wire the new A3 plan into A4; remove local `gridU/gridV` or `support_key` production behavior; weaken/rewrite accepted selector382 identities; use local builds; change reusable workflow permissions.

## 2. Hard pre-mutation guards

Before semantic mutation prove from current source that:

1. production A2b still exposes exact full-arc/support/region-boundary incidence authority for `Mandatory`, `Trace`, and `Cut` arcs;
2. the new baseline binder can be expressed without deriving or accepting `ConformityFamily`/`ConformitySign`;
3. every bound span has one or two incidence occurrences; same-region multiplicity and one-ended source-boundary terminals are representable exactly;
4. exact target preference `d_s`, compact `{span, exactOrdinal}` breakpoints and exact digest/support vocabulary can be reused without changing semantics;
5. any retained old framed CP1/CP2 solver path can be made **explicitly non-production and structurally unreachable** from the new production-baseline binder.

If any guard fails, stop before semantic mutation and route back to definition review. Do not invent an optional-family fallback or implicit mode switch.

## 3. Smallest implementation scope

Implement only the semantic core needed for the new baseline contract.

### 3.1 Baseline input/product types

Add or refactor an explicit family-free production incidence type containing span, region, boundary-occurrence identity and orientation. Production baseline construction must reject attempts to smuggle family/sign into validity decisions.

Preserve full-span exact support, digest bindings, arbitrary-precision positive counts, compact breakpoint generators and semantic output digest.

If source compatibility requires the old framed test surface, isolate it under a separately named legacy/framed entry point or type. It must not be reachable from `RemeshPipeline` or the baseline production binder, and it may not share a hidden optional-field switch with baseline semantics.

### 3.2 Exact parity scheduler

For canonical spans:

1. derive preferred exact `d_s` exactly as before;
2. form preferred parities `q_s=d_s mod 2`;
3. reconstruct each region parity residual from boundary-incidence multiplicity;
4. build the exact region-incidence graph, including same-region loops and component-local exterior vertices for one-ended terminals;
5. solve the exact minimum-cardinality T-join;
6. perform canonical lex-prefix refinement by constrained optimal T-join re-solves;
7. materialize the unique positive count implied by each final parity;
8. generate the unchanged compact exact breakpoint rule.

No generic ILP/branch-and-bound, floating optimization, tolerance, target-grid heuristic, family/sign balance row, numeric-magnitude enumeration, retry, or approximate fallback.

Reuse existing exact weighted-perfect-matching infrastructure only if it can consume graph-cardinality integer weights without machine-width semantic narrowing. Otherwise use the smallest exact graph primitive that proves the same minimum-cardinality T-join contract.

### 3.3 Certificate and independent validator

Carry and validate:

- exact binding digests and support/incidence coverage;
- preferred parities and independently reconstructed residual/T set;
- component-local exterior construction;
- exact minimum flip count and selected flip set;
- each constrained lex-prefix optimum/decision;
- final positive counts and per-region even boundary sums;
- compact breakpoint-generator and final semantic digest.

The validator must rebuild the graph from A2b region boundary walks rather than consume producer-normalized parity rows. Production scheduler and validator may share exact low-level arithmetic/graph primitives, but not the candidate's derived row/T data.

### 3.4 Baseline mathematical outcomes

For a well-formed binding, ordinary parity scheduling is always feasible (`x_s=2` is a witness). Do not expose `ConformityInfeasibleSubset`, `BalanceCut`, `PositivityCut`, or `ParityCut` as baseline production outcomes. Keep historical framed behavior only to the minimal extent needed for accepted compatibility tests, explicitly outside production.

## 4. Required test source authored in CB2

Author deterministic tests that compile in this turn and execute only in the successor TB. At minimum cover:

1. mixed `Mandatory`/`Trace`/`Cut` binding without family/sign;
2. exact per-region even boundary parity with incidence multiplicity;
3. same-region double incidence/self-loop behavior;
4. one-ended source-boundary terminal plus component-local exterior;
5. minimum-cardinality flip choice on a case where greedy local parity is not globally sufficient;
6. canonical lex refinement on at least two distinct minimum-cardinality T-joins;
7. `d_s=1` flip maps to `2`, while `d_s>1` flip maps to `d_s-1`;
8. independent fixed-small exhaustive parity oracle reproduces optimum and lex tie;
9. validator rejects independent tamper of residual/T, flip set/optimum, lex receipt, count/parity and semantic digest;
10. canonical permutation/reversal invariance, including reversed exact-ordinal consumption metadata;
11. all-even constructive witness proves no ordinary baseline infeasibility outcome;
12. static/structural test that the production-baseline binder cannot dispatch to the retained framed solver surface.

Use deliberate asymmetric values. Expected optima must be derived independently of the production implementation. Do not reuse the production T-join helper to compute test expectations.

## 5. Selector discipline

Accepted selector382 remains immutable historical authority. Do not edit it or mutate its existing test assertions to make the new implementation pass.

After the new identities exist and compile, publish a new M4-CP3 required-green selector as an **exact selector382 LF prefix plus only the new CB2 identities**. Record line count, LF SHA-256, selector382 prefix SHA-256, static one-definition ownership mapping, and owner partition. Any existing framed CP1/CP2 identity that stops compiling/passing is a compatibility defect to resolve without weakening it, not permission to drop the prefix.

## 6. Compile/package gate

After source/test/selector changes are complete:

1. review the full diff and prove only intended production/test/selector/docs/build-discovery changes exist;
2. commit/push exact source authority;
3. use the durable `agent-compile-reusable.yml` through a narrow temporary caller; do not duplicate compile logic or change reusable permissions;
4. mandatory backend is GMP/GMPXX with `DIRECTIONAL_ENABLE_GMP=ON` and authoritative link-command proof;
5. compile the existing required owner targets plus any target needed by the new parity tests;
6. package candidate **package118** only if every approved target links and compile evidence is complete;
7. verify package manifest/source status and `runtimeExecution=false`;
8. do not execute any produced binary.

On compile failure, preserve the first actionable compiler/linker error, make the smallest source correction, push, and recompile exact new authority. Do not diagnose by running the binary.

## 7. Code-review falsifiers before compile acceptance

CB2 is not acceptable if any of these is present:

- production family/sign derivation from raw `FieldBranch`, geometry, tolerance, boundary ordinal or arbitrary convention;
- hidden optional fields that silently switch between framed and baseline semantics;
- A4 production cutover in this turn;
- local target/grid or `support_key` edits unrelated to compiling the new A3 core;
- generic ILP/branch-and-bound or floating solver semantics;
- O(`x_s`) breakpoint storage or narrowing exact ordinals/counts;
- producer and validator sharing the same derived parity/T rows;
- a selector that drops/edits accepted selector382 rows;
- a test oracle that invokes the production scheduler to generate its own expected answer;
- any Directional runtime execution.

## 8. Success criteria

CB2 closes only when:

- baseline family-free input/product/scheduler/certificate/validator code matches §17;
- all new regression/oracle test source exists and compiles;
- accepted selector382 is byte-unchanged and is an exact prefix of the new selector;
- production baseline is structurally unable to dispatch to legacy framed semantics;
- exact pushed source compiles through mandatory GMP/GMPXX workflow and yields immutable package118 evidence;
- no Directional runtime occurred;
- an executable artifact-only TB plan is issued for exactly that package/source.

If compile succeeds, exact next becomes `M4-CP3-TB1-EXEC` against immutable package118. Production A3->A4 cutover remains deferred until the parity semantic core is runtime accepted.
