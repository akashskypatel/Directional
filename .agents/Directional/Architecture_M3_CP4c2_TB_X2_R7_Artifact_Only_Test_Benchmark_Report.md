# M3-CP4c-2 TB-X2-R7 Artifact-Only Test + Benchmark Report

## Status

**EXECUTION COMPLETE / ACCEPTED 355 RE-PROOF GREEN / NON-GATING TORUS DIAGNOSTIC RED / REVIEW REQUIRED**

This report closes only `M3-CP4c-2-TB-X2-R7-EXEC`. It does not adjudicate stable-regression closure, select
357 versus 358, authorize a cumulative CP4c-2 gate, or begin corrective implementation. Exact successor is the
independent planning-only `M3-CP4c-2-TB-X2-R7-REV`.

## Immutable authority

- semantic/test source: `755485865a7cf9c485d754f22b82a41ee151824b`
- immutable GMP package artifact: `9719216316`
- package outer SHA-256: `acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`
- packaged source archive SHA-256: `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`
- compile/package run: `33267732093`
- successful R7 control event SHA: `869d57c9ef5be5c0e23c746a140c7a58e38ed6d2`
- successful R7 run/job: `33276039911 / 99162853852`
- result artifact: `9721564203` / `sha256:a854e562facfd616f9f61eddf653dc9e5814c3b932661993b2b2861b2bdab8db`
- diagnostic-log artifact: `9721564377` / `sha256:8edd56072491aa4267e3cd0d2c0942b0910a3e5a01f15e6bc21164bd0fbef3ec`
- raw evidence archive: `Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz` /
  `sha256:933190d3591aa7633fd3ebb6c1a119c1ad7d0b04cc2ca4254a8c325d3c7f1200`

Two preceding retries in this same EXEC turn stopped on harness/preflight orchestration defects before any
Directional process. They are not semantic evidence. The run above is the authoritative runtime attempt.

## R7-0 immutable preflight

R7-0 passed on the unchanged CB5 package: outer digest, packaged semantic source, packaged source archive,
**28/28** internal manifest, GMP/GMPXX command-boundary evidence, executable modes, and all six selector
derivations matched the corrected frozen authority. This satisfies the runtime proof boundary for the prose-only
`R7-ORCH-01` correction without changing selector bytes.

No package, source, test, fixture, selector, or generated discovery data was repaired or modified.

## R7-2 through R7-5 — non-gating evidence

Each identity ran exactly once in a fresh process before the accepted-prefix gate, as frozen by AE8.

| phase | identity / evidence | result |
|---|---|---|
| R7-2 | `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` | **PASS**; semantic digest `13559155349784658228 == 13559155349784658228`, provenance digest `3398751569552983810 != 4134247641157939318` |
| R7-2 | `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` | **RED / NON-GATING**; exactly one test ran and failed before digest comparison because `baselineAtlas` was `false` at `FieldAlignedCurveNetworkTests.cpp:2220` |
| R7-3 | `ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating` | **PASS**; independent actual-embedded-graph records published, including torus `V=72,E=76,F=4,chi=0,sourceChi=0` |
| R7-4 | `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable` | **PASS**; exactly one Y1 record per torus/sphere/two-ring and publication count `1/1/1/3` |
| R7-5 | `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable` | **PASS**; sphere Y2 record published with `producerGlobalCountsReached=true`, `surfaceCutGraphError=CellularityNotEstablished`, `localizedSite=474-global-certificate`, and `localizationConsistent=false` |

The torus R7-2 red grants no accepted-count debit. EXEC evidence localizes it only to failure of the diagnostic's
baseline-atlas precondition; no semantic/provenance digest comparison occurred for that witness. Root-cause and
disposition belong to R7-REV.

## R7-1 — accepted 355 re-proof

The frozen CP4c-1 selector was executed in order as **355 fresh processes**. Every identity selected exactly once
and exited zero: **355/355 GREEN**.

Required regression loci are both green in the same complete run:

- ordinal **305** `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` — PASS;
- ordinal **310** `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` — PASS.

This mechanically satisfies the frozen runtime closure conditions recorded for `PR8-R043 / M3-CP4c2-R001` and
`PR8-R044 / M3-CP4c2-R002`, but EXEC does **not** reclassify or close those stable records. Independent R7-REV owns
that adjudication. Stable accounting therefore remains **44 events / 14 categories / 30 recurrences** in this
closeout.

## R7-6 immutable postflight

Postflight passed. Package and packaged-source byte/mode inventories matched preflight; internal `SHA256SUMS`
reverified; all frozen mutation/build flags are false:

`configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`,
`sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`,
`packageMutation=false`, `benchmarkExecution=false`.

## Frozen non-actions

The following remained explicitly **NOT RUN**: selector 357, selector 358, a cumulative CP4c-2 gate, and all
benchmarks. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false` remain unchanged.
CP4c-2 is therefore still runtime-unaccepted even though its inherited accepted 355 predecessor gate has now been
fully re-proved on CB5.

## Regression/candidate handoff

- `R7-ORCH-01`: corrected documentation authority is now runtime-preflight-proved; formal disposition may be
  recorded in R7-REV.
- `PR8-R043` and `PR8-R044`: their exact frozen runtime closure conditions are satisfied by the same 355/355 run;
  stable status/count adjudication is deferred to R7-REV.
- new non-stable R7 torus diagnostic candidate: baseline-atlas precondition red; cause beyond that locus is not
  established by EXEC.
- `M3-CP4c2-TB-X2-CAND-04`: R7-5 finally publishes the prescribed-sphere localization record; the record itself
  reports `localizedSite=474-global-certificate` and `localizationConsistent=false`, so review must interpret the
  conflict rather than EXEC promoting a cause.

Exact next: **`M3-CP4c-2-TB-X2-R7-REV`**, independent review/planning only. No new runtime, implementation,
test/fixture/build-logic mutation, 357/358 execution, cumulative gate, or benchmark is authorized by this report.

---

**Successor note (added by `M3-CP4c-2-TB-X2-R7-REV`; this report's own evidence is unchanged).** The review is
complete: `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`. It closed `PR8-R043`, `PR8-R044` and
`R7-ORCH-01`, left stable totals at **44 / 14 / 30**, selected no gate, and issued measures **AF0–AF9**. Two
corrections to how this report's R7-5 and R7-3 rows should be read:

- The R7-5 summary above omits `errorSourceFace=25-27-28` and `publishedLocusClass=419-or-437-source-face-locus`,
  which the regression tracker preserves. Those two fields are what make the record interpretable: the
  `CellularityNotEstablished` on that path is `topology_error`'s `default:` bucket for 36 distinct
  `GlobalTopologyPlanErrorCode` values, not a cellularity verdict, and `localizationConsistent=false` is false by
  construction because the harness compares the actual embedded graph against the withdrawn source-edge-barrier
  proxy.
- R7-3 publishes one oracle row **per witness**, including the prescribed sphere; this report quoted only the torus
  row. The sphere's row is in retained result artifact `9721564203` and is the measurement the checkpoint's standing
  prediction has been waiting for. Measure **AF1** extracts it.
