# M3-CP4c-2 TB-X2-R7 Artifact-Only Test Plan

## Status and authority

**EXECUTED / EVIDENCE PRESERVED / INDEPENDENT REVIEW PENDING**

Authoritative retry run/job: `33276039911 / 99162853852`. Exact result is retained in
`Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md`. This file remains the frozen execution
contract; do not reinterpret its non-gating identities as gate credit.

This plan is the exact runtime successor to build-green `M3-CP4c-2-CB5`. It consumes immutable GMP package
`9719216316` (`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`), built from exact semantic/test source
`755485865a7cf9c485d754f22b82a41ee151824b`. Packaged source archive: `sha256:78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`.

R7 is **artifact-only**. It may execute packaged test binaries, but may not configure, compile, relink, repair,
regenerate discovery data, patch source/tests/fixtures/selectors, or mutate the immutable package. One exact test
identity runs per fresh process. Zero-selected or multiply-selected filters are orchestration failures, never passes.

Accepted runtime predecessor remains CP4c-1 **355/355**. At R7 start:
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

`M3-CP4c-2-DOC-R1` corrected only the four mistranscribed selector digests and the sequencing required by AE8.
The package, semantic/test source, selectors, test identities, closure conditions, and gate authority are unchanged.

## R7-0 — immutable preflight

Before any Directional runtime:

1. Download package `9719216316` once and verify outer SHA-256 `acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`.
2. Verify internal `SHA256SUMS` completely; expected CB5 build evidence is **28/28 PASS**.
3. Verify `metadata/source-commit.txt` equals `755485865a7cf9c485d754f22b82a41ee151824b` and packaged source archive SHA-256 equals
   `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`.
4. Verify `metadata/command-boundary.txt` records `exactArithmeticBackend=GMP`, `runtimeExecution=false` for the
   build, and `turnBoundary=Code+Build-only`; verify GMP/GMPXX evidence and all six packaged runtime binaries are
   executable.
5. Recompute and verify the six frozen selector hashes from the named committed selector bytes. Do not trust a
   prose copy without reproducing the listed derivation:

   | authority | source file | derivation | expected SHA-256 |
   |---|---|---|---|
   | 316 | `Architecture_M3_CP4c1_Required_Green_Selector.txt` | `head -n 316 <file> \| sha256sum` | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
   | 346 | `Architecture_M3_CP4c1_Required_Green_Selector.txt` | `head -n 346 <file> \| sha256sum` | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
   | 353 | `Architecture_M3_CP4c1_Required_Green_Selector.txt` | `head -n 353 <file> \| sha256sum` | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
   | 355 | `Architecture_M3_CP4c1_Required_Green_Selector.txt` | whole file: `sha256sum <file>` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
   | 357 | `Architecture_M3_CP4c2_Required_Green_Selector_357.txt` | whole file: `sha256sum <file>` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
   | 358 | `Architecture_M3_CP4c2_Required_Green_Selector_358.txt` | whole file: `sha256sum <file>` | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |

6. Record before-run package/source file hashes and modes for unconditional postflight comparison.
7. If any preflight check fails, **do not self-heal or substitute an observed value for planned authority**. Before
   returning the hard orchestration stop, run the same package/source integrity comparison needed to prove that
   preflight itself did not mutate the immutable input, and publish that evidence.

Any preflight mismatch is a hard orchestration stop. Do not repair the package.

## Execution order after a green R7-0

Run the non-gating measurements first, each in its own fresh process, then the accepted-prefix gate:

`R7-2 -> R7-3 -> R7-4 -> R7-5 -> R7-1 -> R7-6`

This is AE8's publication-order correction. R7-2 through R7-5 are non-gating, grant no accepted-count credit,
mutate nothing, and cannot change the R7-1 result. Each executes in a fresh process against the same immutable
package. Their evidence is therefore published regardless of the later accepted-prefix outcome. If package/process
integrity is compromised, stop and proceed to postflight instead of continuing diagnostics.

## R7-2 — CB5 semantic/provenance boundary diagnostics — non-gating

Run each once in a fresh process from `directional_surface_cell_producer_tests`:

1. `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness`
2. `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness`

These are **non-gating** and grant no accepted-count credit. Preserve the published baseline/relabeled semantic and
provenance digests. Expected diagnostic invariant: semantic equality and provenance inequality for each witness.
A diagnostic red is evidence, not accepted-count debit; preserve it and continue the remaining non-gating R7
measurements unless the process/package integrity itself is compromised.

## R7-3 — independent actual-embedded-graph oracle — non-gating

Run once, fresh process:

`ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`

Preserve every witness record. This is non-gating and independently reconstructs the actual embedded graph for
comparison; it must not be interpreted through the withdrawn source-edge-barrier proxy.

## R7-4 — retained barrier diagnostic — non-gating

Run once, fresh process:

`GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`

Preserve all `m3Cp4c2Y1` records. This remains a **diagnostic source-edge-barrier complex only** and is not a
cellularity oracle or gate-credit source.

## R7-5 — D2 prescribed-sphere localization — non-gating

Run once, fresh process:

`GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`

Preserve the complete `m3Cp4c2Y2` record, including producer re-derivation locus, component counts, actual
`SurfaceCutGraph` status/error, and localization consistency. D2 is non-gating and now runs before the accepted
prefix so its evidence is published even if R7-1 later stops early. It grants no gate credit and changes no
closure condition.

## R7-1 — full accepted 355 re-proof — gating

Use `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt` as the ordered 355 identity authority.
For ordinal 1 through 355:

1. resolve the owning packaged binary from the accepted identity census;
2. start a **fresh process** with exactly `--gtest_filter=<identity>`;
3. prove exactly one test was selected and executed;
4. preserve stdout, stderr, combined output, exit code, elapsed time, ordinal, identity, and binary;
5. stop at the **first nonzero semantic result**.

A red before ordinal 355 is a frozen hard stop for acceptance: do **not** run 357/358, a cumulative CP4c-2 gate,
or benchmarks. R7-2 through R7-5 have already run as non-gating measurements and remain diagnostic evidence only.
Proceed directly to unconditional R7-6 postflight and preserve the first actionable accepted-prefix red.

If and only if all **355/355** are green, record specifically:

- ordinal **305** green in the full run — runtime condition required to close R043;
- ordinal **310** `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` green in
  the same full run — runtime condition required to close R044.

A 309- or 310-ordinal prefix is not closure for either regression.

## R7-6 — unconditional immutable postflight

This phase runs **regardless of semantic green/red after any Directional runtime has started**. Re-verify:

- package hashes and modes exactly equal R7-0;
- packaged source hashes and modes exactly equal R7-0;
- internal `SHA256SUMS` still passes;
- no configure, compile, relink, repair, generated-discovery, source/test/fixture/selector mutation, or package
  mutation occurred;
- `benchmarkExecution=false`.

A missing postflight is orchestration failure. Semantic red must not suppress postflight. A preflight-only stop is
covered by R7-0 step 7 and still requires an integrity report even though no Directional runtime started.

## Frozen non-actions and stop boundary

R7-EXEC does **not** run selector 357, selector 358, the cumulative CP4c-2 gate, or any benchmark. It does not
select an R2 branch or gate, touch mechanical/C2, or begin CP4c-3. Those remain review/planning decisions after R7
evidence. `selected_r2_branch`, `selected_gate`, and `gate_execution_authorized` therefore remain `NONE`, `NONE`,
and `false` during R7.

## Required evidence package

Preserve one immutable R7 result archive containing:

- R7-0 preflight manifest/hashes/modes and exact package/source authority;
- R7-2 through R7-5 raw records after a green R7-0, regardless of the later accepted-prefix outcome;
- ordered 355-row execution ledger through the organic stop/completion point;
- per-process stdout/stderr/combined hashes and exit states;
- R7-6 postflight comparison and mutation/build flags;
- explicit NOT-RUN rows for every downstream phase blocked by a hard stop;
- workflow run/job IDs and result/log artifact IDs/digests.

TB-EXEC should preserve raw evidence only. Regression categorization/closure and any next corrective scope belong to
the required follow-on review/closeout under the active turn cadence; no implementation mutation is authorized in
R7-EXEC.
