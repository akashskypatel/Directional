# M4-CP1-CB2 Algorithm Blocker

**Status:** STOPPED BEFORE SEMANTIC MUTATION / INDEPENDENT REVIEW REQUIRED
**Turn:** `M4-CP1-CB2` — canonical Code + Build / runtime-free
**Date:** 2026-09-10

## 1. Stop verdict

`M4-CP1-CB2` stops before product, test, selector, build-system, or runtime mutation. The frozen CB2.5 contract requires the private production solver implementation to be traceable to the selected **Gabow 1983 arbitrary-capacity minimum-cost biflow algorithm** and explicitly says to stop rather than substitute a different method when that traceability cannot be established.

The selected publication does not disclose the required algorithm. Gabow's 1983 STOC paper / Colorado technical report identifies problem (5) as minimum-cost biflow with arbitrary integral capacities and states the `O(E^2 log V log C)` bound, but then says that sections 3–6 sketch only problems (1)–(4) and that **problem (5) will be discussed elsewhere**. The available selected source therefore supplies the theorem-level claim and complexity bound, not an implementable algorithm whose phases, augmentations, blossom operations, loop handling, and work counters can be traced into CB2's required `WorkLedger`.

Proceeding would require at least one prohibited move: inventing the missing algorithmic details, silently substituting a different exact solver/reduction while retaining the `Gabow1983ArbitraryCapacityMinCostBiflow` authority tag and bound, or weakening the frozen solver/work-evidence contract. None is permitted in Code + Build.

**Exact next:** independent `M4-CP1-CB2-REV`. No implementation, compile/package, test, benchmark, or Directional runtime is authorized before that review adjudicates a traceable exact solver authority and its complexity/evidence contract.

## 2. Source and repository authority

The turn froze semantic source `075f3c738d8f689437397fe925faa7eb12d72ac3`. The ChatGPT-Web source-snapshot trigger advanced the branch only by control marker commit `9c32b5bd932dd17c40a7fe12c2441547e1ecc6a5`; its parent is the frozen semantic source and its only changed path is `.agents/connector-triggers/source-snapshot/m4-cp1-cb2-20260909.txt`.

Source-snapshot evidence:

- run `34429824055`; snapshot job `102722806001`;
- source artifact `10134050428`; provider digest `sha256:ca75c3869f3a6e6039fcce3f663887c9748a58b0810a1d062747d991ba221c22`;
- snapshot archive SHA-256 `8c0f21fcb68963a5b96055939162f41aa768ec91aa3a2991eadc412740ab8f5d`;
- `5222/5222` manifest files verified;
- `runtimeExecution=false`.

M3/package113/TB48 remains the reviewed semantic runtime authority. Selector365 remains the accepted required-green predecessor. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, packages **113**, ownership **300/0/0**.

## 3. Frozen contract that fired

`Architecture_M4_CP1_CB2_Code_Build_Plan.md` §CB2.5 requires one deterministic private arbitrary-capacity Integral Bi-MCF solver corresponding to Gabow 1983, with exact demands/capacities/cost comparisons, bidirected endpoint signs, parallel edges, and same-node `+/-2` loops. It then states:

> If the implementation cannot be traced to the selected arbitrary-capacity min-cost biflow algorithm, stop rather than substituting a different method.

The same plan requires the `WorkLedger` to identify `Gabow1983ArbitraryCapacityMinCostBiflow`, bind the published `O(E'^2 log V' log Cmax)` theorem class, and expose counters belonging to the actual implementation. A solver reconstructed from unspecified details cannot satisfy that evidence contract honestly.

## 4. Bounded source audit

Primary authority checked:

- Harold N. Gabow, *An Efficient Reduction Technique for Degree-Constrained Subgraph and Bidirected Network Flow Problems*, STOC 1983, DOI `10.1145/800061.808776`.
- The Colorado technical-report text mirrored by the University of Michigan matching bibliography. It lists arbitrary-capacity minimum-cost biflow as problem (5), gives the `O(E^2 log V log C)` bound, and explicitly defers problem (5) rather than presenting its algorithm.

A bounded search for a disclosed follow-on Gabow publication did not locate a primary source supplying the missing arbitrary-capacity minimum-cost bidirected-flow procedure. This is **not** an exhaustive claim that no such source exists; it is sufficient to show that CB2 cannot trace an implementation to the source currently frozen as authority without further review.

Secondary corroboration only:

- Medvedev et al., *Maximum Likelihood Genome Assembly* (2011), §5.1 describes Gabow's min-cost biflow algorithm as polynomial but difficult to implement and reports that the authors could not find an efficient implementation. Their directed-flow reduction is only a worst-case 2-approximation and is therefore not an admissible M4 semantic substitute.

## 5. What was not done

Because the algorithm-traceability stop fired before semantic mutation:

- no `GlobalConformityPlan` product or solver source was authored;
- no test/fixture/oracle or selector was authored or changed;
- no CMake/build configuration was changed;
- no compile/package workflow was run;
- no generated Directional binary, test, benchmark, discovery/help/version command, or custom input was executed;
- no reusable workflow permission was changed;
- no M4 semantic acceptance claim is made.

This is a successful fail-closed plan guard, not runtime evidence and not a semantic regression.

## 6. Review question

Independent review must decide one implementable, citable exact path before Code + Build resumes. In particular it must not inherit the 1983 complexity label onto a different algorithm without proving the correspondence. Acceptable outcomes include locating the missing primary algorithmic publication, freezing a different exact bidirected-flow / equivalent combinatorial algorithm with its own traceable polynomial bound and representation proof, or revising the algorithm/evidence contract while preserving the already-frozen semantic objective and exactness requirements.
