# Architecture M3 CP4c-2 — TB-X2-R6-EXEC Artifact-Only Evidence

- Phase: `M3-CP4c-2-TB-X2-R6`
- Subturn: `M3-CP4c-2-TB-X2-R6-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/test evidence source: `cebc12082c6dbe4830095df08169797b7dab0c5c`
- Immutable GMP package: `9714226920`, `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`
- Packaged source archive: `sha256:3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`
- Runtime execution plane: local immutable-artifact execution in the ChatGPT container; no GitHub Actions runtime workflow
- Raw evidence archive: `Directional__M3-CP4c-2-TB-X2-R6-EXEC__raw-evidence.tar.gz`, `sha256:340f2e569d372809a299d5b7c065966756797fb2a6e47db959d82ea62213e4f5`
- Benchmark execution: **none**

## EXEC disposition

**COMPLETE AT THE FROZEN R6-1 STOP / ACCEPTED-PREFIX SEMANTIC RED AT ORDINAL 310 / R6-2, R6-3, R6-4, 357, 358 NOT RUN / UNCONDITIONAL POSTFLIGHT PASS.**

R6 immutable preflight passed and the accepted-prefix re-proof began in the plan's declared order, one exact
GoogleTest identity per fresh process. Accepted ordinals **1-309 PASS**. In particular, ordinal 305
`GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` now passes, so the specific R5 rejection locus
that opened `PR8-R043 / M3-CP4c2-R001` is not reproduced by that identity on the CB4 package. Ordinal **310**
`GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` selected exactly once and
exited `1`. The frozen hard-stop rule therefore prevented ordinals 311-355 and all CP4c-2-local diagnostics/gates
from running.

This EXEC record preserves execution evidence and the regression-tracker classification required by the plan. It
does **not** accept CP4c-2, close `PR8-R043`, authorize a correction, select a 357/358 branch, or perform the
independent review. Exact next is `M3-CP4c-2-TB-X2-R6-REV`.

`selected_r2_branch=NONE`, `selected_gate=NONE`, and `gate_execution_authorized=false` remain binding.

## Immutable preflight

Before the first Directional process, R6 verified:

- outer package digest exactly `931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`;
- package internal `SHA256SUMS` in full;
- `metadata/source-commit.txt` exactly `cebc12082c6dbe4830095df08169797b7dab0c5c`;
- package command boundary `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- authoritative build evidence contains both `gmpxx` and `gmp` and the runtime binary resolves `libgmp.so.10`;
- all eight packaged targets are present and all six runtime binaries retain executable mode `0755`;
- packaged source archive hash exactly `3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`;
- package and materialized-source pre-runtime byte-and-mode inventories were captured;
- frozen selector hashes recomputed exactly: 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.

Static identity-to-binary ownership was derived from packaged source/CMake text, with all 355 selector identities
mapping exactly once: producer 209, completion 75, validation 41, authority-kernel 30. No
`--gtest_list_tests`, configure, compile, relink, code generation, package repair, or generated discovery was used.

Runtime environment recorded for reproduction: Linux x86_64 kernel `6.18.35`, Debian glibc `2.41`; package
producer test binary dynamically resolves `libgmp.so.10`, `libstdc++.so.6`, and `libc.so.6` from the container.

## R6-1 accepted-prefix raw evidence

The ordered execution manifest contains **310** fresh-process rows and no duplicate identity. Exactly 309 rows
exit `0`; the first and only red row is:

```text
310	accepted-316	310	GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling	directional_surface_cell_producer_tests	1	1	10
```

Ordinal 310 stdout reports one selected test and the exact failed equality:

```text
baselinePlan.semantic_digest() = 12176020141753559903
relabeledPlan.semantic_digest() = 14339407889897379635
```

Raw ordinal-310 hashes:

- stdout `7e2780fe5d9153997035ce4f33eb412219f1877a50b84e2fd30c2e2cf12bf7b0`;
- stderr `5023344a86ee85bb23e86456f2a0c19af6c61e422f8ec226305d9376acef849e`;
- combined `ba5f869f04aa48cc811cb737a5873eba1befe1f7c28af85f614ab6b70c22e70d`.

The test establishes the intended semantic/provenance split before the red: the baseline and gauge-relabeled
networks have equal `FieldAlignedCurveNetwork::semantic_digest()`, unequal atlas digests, and are expected to
produce unequal exact `GlobalTopologyPlan::network_digest()` provenance while retaining equal plan semantic
identity. Only the final plan semantic equality is red.

## Static localization required for regression tracking

Static inspection of the exact packaged source localizes the representation-sensitive input without changing or
re-executing anything:

- `tests/FieldAlignedCurveNetworkTests.cpp:2457-2463` proves network semantic identity is invariant while atlas
  provenance differs, then requires plan semantic identity to remain invariant;
- `src/geometry/GlobalTopologyPlan.cpp:1511-1519` deliberately consumes gauge-invariant
  `network.semantic_digest()` but also consumes `candidate.cutGraphDigest` into the plan semantic digest;
- `src/geometry/SurfaceCutGraph.cpp:263-265` computes that cut-graph digest from `candidate.atlasDigest` as well
  as semantic source/network/cut/certificate terms; and `canonical_candidate` stores `network.atlas_digest()` in
  `candidate.atlasDigest`.

Therefore the new pre-region authority reintroduces representation-dependent atlas provenance into a digest that
`GlobalTopologyPlan` treats as semantic. This is a direct recurrence of existing
`REPRESENTATION_DEPENDENT_IDENTITY / RP-05`, the same semantic/provenance-domain failure class previously tracked
for CP2b. Because ordinal 310 belongs to the previously accepted CP4c-1 355/355 authority, R6 records a new stable
regression event `PR8-R044 / M3-CP4c2-R002`. Independent R6-REV owns final corrective guidance; EXEC authorizes no
implementation change.

## Frozen downstream disposition

Because the accepted prefix stopped at ordinal 310:

- ordinals 311-355: **NOT RUN**;
- R6-2 `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`: **NOT RUN**;
- R6-3 retained source-edge-barrier diagnostic: **NOT RUN**;
- R6-4 `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`: **NOT RUN**;
- selector 357: **HASH VERIFIED ONLY / NOT RUN**;
- selector 358: **HASH VERIFIED ONLY / NOT RUN**;
- cumulative CP4c-2 gate: **NOT RUN**;
- benchmark: **NOT RUN**.

No runtime disposition is inferred for the independent actual-complex oracle, retained barrier diagnostic, D2,
or any 357/358 branch.

## R6-5 unconditional immutable postflight

Unlike R5, the R6 harness did not allow the nonzero semantic result to suppress finalization. Postflight executed
unconditionally after ordinal 310 and passed:

```text
postflightStatus=PASS
packageModesEqual=true
packageHashesEqual=true
sourceModesEqual=true
sourceHashesEqual=true
configureOccurred=false
compileOccurred=false
relinkOccurred=false
repairOccurred=false
generatedDiscoveryOccurred=false
mutationOccurred=false
benchmarkExecution=false
```

The outer package remained `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`,
the source archive remained `sha256:3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`,
and package internal `SHA256SUMS` reverified. This runtime directly closes the orchestration-only
`M3-CP4c2-TB-X2-R5-ORCH-01`: a semantic red no longer suppresses postflight evidence.

One start-of-turn control-plane incident is retained separately from semantic evidence. Creating the cleanup
manifest at turn initialization triggered the durable cleanup workflow immediately because that path is itself its
push trigger. Run `33261070466` completed GREEN before the later R6 snapshot/runtime work; it executed no
Directional binary and changed no semantic/package/test/fixture state. This repeats the already-known deferred
cleanup-manifest lifecycle defect and does not alter stable semantic accounting.

## Regression/accounting state at EXEC close

- `PR8-R044 / M3-CP4c2-R002`: **ACTIVE STABLE / PRODUCT / REPRESENTATION_DEPENDENT_IDENTITY / RP-05**; new
  accepted-green regression at ordinal 310.
- `PR8-R043 / M3-CP4c2-R001`: remains **ACTIVE** pending independent R6-REV. R6 proves ordinal 305 now passes but
  does not re-prove the full 355 predecessor and EXEC does not close a reviewed stable event.
- `M3-CP4c2-TB-X2-R5-ORCH-01`: **RESOLVED / R6 HARNESS CONFIRMED / ORCHESTRATION / NON-STABLE**.

Stable accounting advances **43 events / 14 categories / 29 recurrences -> 44 events / 14 categories / 30
recurrences**. Produced-witness debt remains **5**. M3 package count remains **63** because R6 consumed, rather
than created, immutable package `9714226920`.

## Exact next state

`M3-CP4c-2-TB-X2-R6-REV` — independent evidence review only. It consumes this record, the raw R6 archive, the
frozen R6 plan, and immutable package/build authority. It must run **no new Directional runtime**, must not infer
R6-2/R6-3/R6-4 results, must not run 357/358 or the cumulative gate, and must not begin corrective CB, mechanical/C2,
or CP4c-3 until review durably authorizes a later successor.
