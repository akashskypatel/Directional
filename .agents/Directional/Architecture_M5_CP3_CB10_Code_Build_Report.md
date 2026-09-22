# M5-CP3-CB10 Code + Build Report

**Turn:** `M5-CP3-CB10`
**Boundary:** Code + Build only / runtime-free / test-authority-only
**Result:** **COMPLETE / STATIC SCOPE GREEN / GMP COMPILE-PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Exact successor:** `M5-CP3-TB1-R9-EXEC`

## 1. Authority and bounded change

CB10 entered from `M5-CP3-TB1-R8-REV` and executed
`Architecture_M5_CP3_CB10_Chart_Admissible_Nonzero_Z4_Witness_Correction_Plan.md` without widening scope.
The sole semantic path changed is `tests/SurfaceCellTransitionQuotientTests.cpp` (**+322 / -5** versus the frozen
pre-CB10 source). No `src/**`, public header, committed fixture, selector, CMake target, benchmark, frozen definition,
relation/atlas implementation, accepted expectation, or row6 body changed.

The source snapshot used for inspection was run `35661739663`, snapshot job `106538402460`, artifact
`10667574147`, event/snapshot SHA `3b57ad4aa964df8249f2092980d58e2d2267b6f3`. Its provider/local outer SHA-256 is
`daf8948f027a1cfd77c94e715d3099fbb4cb35d2be6039797455c5e2b93a07b4`; contained `source.tar.gz` hashes to
`3a501a5ad8e63f9170e443feddb7b965680b72ae70dc82a0e6ffbb5e1ea817ef`; the source manifest covers **5296/5296**
files. The semantic/test commit and exact compile source is `9040f74a8de0849920973fd985b19db2539812ee`.

## 2. Implemented witness correction

The CB9 global quarter winding is replaced exactly by the Review-precommitted seam ramp:

```text
delta(theta) = (pi - theta) / 6
```

with `theta = atan2(centroid.y, centroid.x)` normalized into `[0, 2*pi)`. The authored cross remains the reviewed
right-handed tangent-frame rotation `[x, y, -x, -y]`; no ramp family search, coefficient tuning, phase tuning, or
runtime-derived adjustment occurred.

CB10 also adds a test-local, pre-product `TorusChartAdmissibilityOracle`. Before the product pipeline is called it
fails closed unless the source subject satisfies the frozen chart conditions independently of product output:

- the hard-edge authority equals the exact row408 set and contains exactly **18** unique source edges;
- the authored field is re-derived from committed torus geometry and the exact seam-ramp formula, with finite,
  unit, orthogonal, consistently handed source frames;
- the cut-domain dual is constructed by omitting the 18 hard edges, and a deterministic global branch gauge is
  propagated from finalized source matching across the remaining dual;
- each boundary side has an unambiguous field branch with alignment strictly greater than `0.7`, on both incident
  source faces;
- the two frozen hard-edge cycles collapse under the canonical global quarter-turn gauge to exactly four runs
  `[0,1,2,3]`;
- the signed boundary turn sum is exactly `+4`;
- orthogonal development closes within `1e-10 * max(1,totalIntrinsicLength)`;
- after source-field finalization, the existing pre-product nonzero row408-carrier check still requires at least
  one nonzero directed Z4 transition before product inspection.

The oracle does not inspect produced periodic relations, materialization output, product failure codes, or tamper
results to define its expected source subject. The existing exact source/A3 carrier/occurrence direction oracle,
forward-versus-inverse discrimination, rows4/5 debt assertions, and row6's recovery-proved absence/invariance
contract remain intact.

## 3. Static scope and falsifier review

Static inspection against the frozen plan is green:

1. the implemented angle expression is exactly `(std::numbers::pi - majorAngle) / 6.0` after the existing
   `[0,2*pi)` normalization;
2. the pre-product oracle derives its evidence only from committed geometry, exact hard-edge authority, authored
   raw field, and finalized source transition/matching authority;
3. no production implementation or selector/fixture/frozen-definition surface changed;
4. rows4/5 continue to use `nonzero_z4_torus_witness_fixture()` and retain their source/A3-selected relation,
   nonzero rotation+translation, materialization/certificate-consumption, and action-only tamper discriminators;
5. row6 remains on the ordinary produced `torus_fixture()` and its body is byte-unchanged.

The numeric Review predictions (minimum alignment `0.7753279615208046`, four runs `[0,1,2,3]`, turn sum `+4`,
closure residual `1.9860273225978185e-15`) remain **precommitted R9 falsifiers**. CB10 is runtime-free, so it does
not claim those dynamic source-oracle receipts have executed; R9 must execute and report them without changing the
candidate.

## 4. Work preservation and remote application

The semantic patch was staged through the established Google Drive transport and applied by run/job
`35663238807 / 106543166451` from exact base `3b57ad4aa964df8249f2092980d58e2d2267b6f3`.
The complete staged patch SHA-256 was
`b2fdbee6b557883a72bedc88ae6cd4309d5a321e3e438724a1bed6bb0ccd06a4`; the apply job pushed exact semantic
source `9040f74a8de0849920973fd985b19db2539812ee` with `runtimeExecution=false`.
Apply result/log artifacts are `10667104916 / 10667319754` at provider SHA-256
`b9a51eb8475031d0662905a40690e57757f62240b60e341ad15919af6e10af27 /
819dcc483121ec6cb6715eb1236bfdb2edcb87533aa18b2e90a3acb90b3b41b4`.

The workflow reported owner-side Drive retirement required for File ID `1oNqBH7QmfdAsxW6WpuWV7eh3CTMwVEmV`. The
connected owner cleanup call returned `404 notFound`; per policy no unsupported Drive search/retry was performed.

## 5. Mandatory GMP compile/package gate

Compile run/job `35663421502 / 106543714403` completed successfully through the durable
`agent-compile-reusable.yml` path from exact source `9040f74a8de0849920973fd985b19db2539812ee`.
All eight mandatory targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The package records preflight/build exit **0/0**, `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
`exactArithmeticBackend=GMP`, explicit `libgmpxx.so` + `libgmp.so` linkage, and empty source-status receipts before
configure, after configure, after build, and at finalization. No generated Directional binary, test, benchmark,
discovery command, `ctest`, CLI, fuzzer, help/version command, or custom input executed.

Candidate artifact `10668437359` has provider/download SHA-256
`c5deac0871004fbf9e7f318a124d599c7548641be2083419a0f465b503ff3206`; compile log artifact `10668302525`
hashes to `c1ded88407c14ac534ce198ea149b9dfb320590a534732df8f6e66b49e87896a`. The self-excluding root
`SHA256SUMS` verifies **28/28** and hashes to
`75b0241e3f5c340cd7d5e2369aa3ea632c98a56abc57fc342f656b59c436dee3`; packaged source archive SHA-256 is
`3de9286684ff550b7377e9a7d383fe1640c2c9ec38910861c4a09f86a9f3c5b3`.

## 6. Acceptance boundary and successor

CB10 earns compile/package evidence only. Candidate `10668437359` is **unpromoted** and no produced debt,
direction observation, selector-publication precommitment, or M5 acceptance credit is claimed before runtime.
Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains
**50 events / 14 categories / 36 recurrences**; project produced-witness debt remains **3**, with the two remaining
M5 nonzero-Z4 debts still open.

Exact successor is immutable artifact-only `M5-CP3-TB1-R9-EXEC` under
`Architecture_M5_CP3_TB1_R9_Artifact_Only_Test_Benchmark_Plan.md`. It must execute the unchanged **446** fresh
exact-filter processes with benchmark **0**, then route to mandatory `M5-CP3-TB1-R9-REV` regardless of semantic
outcome.

## 7. Process note

The current continuation used the already acquired immutable source/compile artifacts for substantive inspection and
avoided rebuilding locally. The exact turn-local connector ledger was not preserved from the first invocation;
consistent with conservation policy it is reported as **partial/unknown** rather than reconstructed with
accounting-only calls.
