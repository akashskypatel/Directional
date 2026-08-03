# Milestone G P5 — Route-Complete Structural Repair Code + Build Report

**Turn type:** Code changes + compile-only build  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Review policy:** `never`

## 1. Authoritative input

This turn implemented `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Plan.md` against the P5-TB9 evidence from artifact `8843206930`.

P5-TB9 established that the non-recursive controller terminates deterministically, but the production bunny still fails closed after two independent single-halfedge candidates each introduce a replacement same-corner ownership claim. It also established that three structural-repair tests use an invalid fixture that assembles successfully before repair.

## 2. Implemented production changes

### Exact route-complete candidates

- Replaced single-halfedge structural candidates with compact exact route candidates.
- Candidate identity contains ordered shared authoritative corners, maximal route chains between those corners, canonical undirected interval identities, geometric support identities, affected patches/domains, component/sheet scope, and deterministic diagnostic hashes.
- Exact identity equality controls candidate equality and ordering. Hashes remain diagnostic only.
- Route chains are derived from arrangement topology and complete boundary evidence; no production patch or halfedge ID is special-cased.

### Topology-derived coupled sectors

- When multiple differing route sectors belong to the same unresolved same-corner relationship, the implementation emits one topology-derived coupled-sector candidate containing their complete canonical interval union.
- The coupled candidate is evaluated before individual route candidates.
- No arbitrary subset or powerset search was introduced.

### Atomic route subdivision

- Every route candidate submits all required undirected intervals in one subdivision request.
- Twin subdivision remains delegated to the existing conforming complex subdivision machinery.
- Inserted-vertex and split-edge totals are validated against the complete candidate.
- Parity repair, coupled side repair, descriptor derivation, patch completion, and assembly run once for the complete transaction.
- The transaction commits only when assembly succeeds and no exact ownership conflict remains.
- Persistent claims, replacement claims, repeated states, incomplete routes, validation failures, and exhausted route budgets remain fail-closed.

### Global ledger and memory discipline

- Preserved the single invocation-owned non-recursive work ledger and exact repair-state deduplication.
- Added route candidate count, consumed count, interval lists, shared-corner identities, route identities, affected domains, compound inserted/split totals, and typed route outcomes.
- Before route evaluation, superseded failed descriptors, completed patch meshes, assembly storage, and repeated failure strings are released while retaining the authoritative rollback complex.
- At most one mutable candidate complex is live.
- Added estimated owned-byte diagnostics for rollback, candidate complex, descriptors, completed patches, assembly, and current/peak structural-repair state.
- Full recomputation remains authoritative because incremental equivalence has not been proven.

No final-face deletion or deduplication, positional vertex merge, source-triangle pairing, source-grid recovery, legacy fallback, patch-ID special case, arbitrary candidate powerset, or validator weakening was introduced.

## 3. Regression-source corrections

Compiled but intentionally not executed:

- Replaced the vacuous structural fixture with an explicit authoritative DCEL/source-support fixture whose initial closed-form completions claim the same authoritative corner cycle through distinct complete boundary routes.
- Structural budget and order-invariance tests assert the initial `SameCornerDistinctBoundaryClaim` precondition before checking ledger behavior.
- Zero- and one-candidate cases require a nonempty route candidate ledger.
- The success fixture requires an actual route-complete subdivision transaction.
- Added an already-successful negative control that requires zero structural work.
- Added route identity, interval-set, affected-domain, compound insertion, typed outcome, owned-byte, and semantic-hash mutation coverage.

Runtime validity is deferred to P5-TB10.

## 4. Source checkpoints

- Route-complete implementation commit: `5dcc6da94977c733ada42967ecdafa566cbc5d0b`.
- Exact compiled source: `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`.
- The exact compiled source differs only by restoration of the standard compile-only workflow and correction of artifact checksum-manifest generation.
- Transient encoded patch material was removed before the implementation commit.

The first compile-only run `30781889869` compiled all required sources successfully but packaged a checksum manifest that included its own in-progress file. That artifact was not accepted as authoritative. The workflow-only packaging correction writes the manifest outside the artifact and moves it into place after hashing.

## 5. Authoritative compile-only evidence

- Workflow run: `30782277625` — **success**.
- Job: `91589158985` — **success**.
- Artifact: `8844133680`, `surface-cell-p5-route-complete-linux-release`.
- Artifact digest: `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`.
- Toolchain: GCC 13.3.0, optimized static Release build.
- Build steps: **131/131 completed**.
- Required targets compiled and linked:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.

Artifact verification:

- `source-commit.txt` is exactly `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`;
- `source-status.txt` is empty;
- all ten packaged checksums pass;
- test and benchmark outputs are Linux x86-64 ELF executables;
- core and pipeline outputs are valid static archives;
- exact source archive, configure/build logs, and recursive submodule revisions are included.

No test, benchmark, or custom mesh executable ran in this turn.

## 6. Status and P5-TB10 handoff

P5 remains open. Compilation proves source validity only; it does not prove that the corrected fixtures pass, that the coupled route resolves the production bunny, or that runtime and memory remain within limits.

The next authoritative turn is **P5-TB10 test and benchmark using artifact `8844133680` without rebuilding**. It must:

1. verify exact source, empty status, and all packaged checksums;
2. execute every corrected route-complete structural test and the prior required suites;
3. run at least two clean-exit direct random-bunny processes with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled;
4. require direct completion success with nonempty pure-quad output;
5. record the exact route candidate ledger, interval sets, affected domains, compound insertions, structural hashes, and owned-byte diagnostics;
6. verify no fallback or recovery;
7. enforce wall time no greater than `39.228299 s` in every formal process;
8. enforce peak memory no greater than `1,115,394,560 B` in every formal and supplementary process.

PR #8 remains draft and unmerged.
