# M3-CP4c-3-TB14 Artifact-Only Test + Benchmark Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB14`
Status: **COMPLETE / VALID SEMANTIC RED / USER-AUTHORIZED ORCHESTRATION RECOVERY / NON-STABLE**

## Immutable authority and execution boundary

TB14 consumed immutable package **84** only. Semantic/package source is
`6808c090f2dd229a48550d758f459bfd156da4b6`; package artifact `9867334959` has Actions SHA-256
`67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`, inner `package84.tar.gz` SHA-256
`8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`, and packaged source tar SHA-256
`ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95`.

Selector **380** verified at `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` with 380 unique
identities; selector 379 is its exact first-379 prefix at
`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`, and the first 365 identities reproduce
accepted authority `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

The replacement execution was explicitly user-authorized after the first local attempt was classified orchestration
invalid. No package/source/test/fixture/selector byte was changed. The complete replacement ran on GitHub Actions with
**no repository timeout** and one exact identity per fresh process:

- run/job: **`33689875040 / 100445977571`**;
- workflow event/control SHA: `11f9b15d162894d41598288b165c739b8b28038e` — orchestration only, not semantic source;
- result artifact: **`9869697113`**, Actions SHA-256
  **`a96d8ff82b467c0cfd89c1437fc0a146461ab18d4850e04515acc562070b975a`**;
- diagnostic-log artifact: **`9869697543`**, Actions SHA-256
  **`5e961520a3844d5b01ab77d4b85b5117c4124bfa03d4993812270e4563deb5f2`**.

Preflight verified the external/inner/source hashes, internal `SHA256SUMS`, source commit, exact GMP backend, 27
package-relative fixtures, six executable modes (`755`), 58-file package census, selectors 373-380 and every
append-only prefix relation. Boundary flags: `runtimeExecution=true`; `benchmarkExecution=false`;
`configureExecution=false`; `compileExecution=false`; `relinkExecution=false`; `packageRepair=false`;
`generatedDiscovery=false`; product/test/fixture/selector mutation all false.

## Orchestration recovery and evidence-parser correction

The first TB14 attempt remains retained as superseded infrastructure evidence: the local tool host interrupted ordinal
130 and later 137 after GoogleTest `[ RUN ]`. The user then explicitly authorized fixing the orchestration error and
re-executing TB14. Moving the complete immutable selector run to GitHub Actions removed the local host wall-clock
constraint. In the replacement run, ordinals **130** and **137** both completed organically, and execution continued
through ordinal 380 plus the required non-gating diagnostic.

One **reporting-only** defect was found after the valid replacement run: the temporary runner recognized PASS with an
exact full-line comparison to `[       OK ] <identity>`, while GoogleTest appends duration text such as `(17 ms)`.
That parser therefore mislabeled every selector row as RED and emitted a false `0 PASS / 380 RED` summary even though
it retained each exact exit code and complete per-identity log. This did **not** alter selection, process execution,
exit status, test output, package bytes, or execution order.

The semantic ledger was reconstructed once from the immutable raw artifact using the authoritative process evidence:
an ordinal is PASS iff its process exit code is 0 and its exact log contains the terminal `[       OK ] <identity>`
record (allowing GoogleTest's duration suffix); otherwise it is RED. All 380 logs independently contain the exact
filter, exactly one selected test, `[ RUN ]`, and an organic terminal result. The corrected ledger SHA-256 is
**`0b42866471ce0ad5939ab2d3c2d5c82f4efebb93c0a56ca7a60e295fad07397b`**. No semantic identity was rerun to
correct the parser. This resolved orchestration candidate `M3-CP4c3-TB14-ORCH-02` with zero regression accounting.

## Gate result

Corrected selector disposition is **371 PASS / 9 RED**.

- ordinals **1-365: 365/365 PASS**;
- first semantic red: **ordinal 366**;
- report-only reds: **366, 367, 368, 369, 370, 371, 372, 374, 380**;
- report-only passes after the frontier: **373, 375, 376, 377, 378, 379**;
- selector-380 witness: **RED**;
- selector-379 witness `GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry`: **PASS**;
- selector-378 diagnostic-projection witness: **PASS**;
- separate non-gating `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`: **RED**, exit 1, zero gate
  credit.

The first red has moved again. Ordinal 366 now reports:

`NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent;detailCode=CellularityNotEstablished;sourceEdge=25-31;sourceFace=25,30,31;rotationSystemReason=EdgeTraceSecondaryRankInvalid;cutCandidateCount=450;certificationAttempt=0;certificationCutEdges=0`

The TB13 vertex-10 `(8,10,11)` / `VertexTracePortOrdinalInvalid` failure is absent. The new frontier is an **edge-locus
trace secondary-rank failure** at source edge `25-31`, source face `(25,30,31)`, still at certification attempt 0
with zero cut edges.

## BL9 discriminator disposition

1. **PASS — accepted boundary.** Ordinals 1-365 are re-proved **365/365 PASS** on package 84.
2. **PASS — vertex-10 correction.** Ordinal 366 no longer reports source vertex 10, face `(8,10,11)`, or the old
   ambiguous `VertexTracePortOrdinalInvalid` path. Runtime advances to `EdgeTraceSecondaryRankInvalid` at edge
   `25-31` / face `(25,30,31)`.
3. **DISCRIMINATED — reason separation.** No production `VertexTracePortOrdinalInvalid` or
   `VertexTraceSecondaryParameterUnavailable` red remains at the frontier. Selector 380 reaches its focused
   exact-corner/typed-failure checks without an earlier assertion failure, then fails only at its final production
   assertion because attempt-0 rotation stops later at `EdgeTraceSecondaryRankInvalid`. The vertex-trace ambiguity
   that motivated CB16 is therefore cleared; the new failure is a distinct edge-trace mechanism.
4. **NOT PROVEN — BK7/v47 conjunction.** The old v47 `RotationRayOrderKeyCollision` remains absent, and selector 379
   still passes, but the new edge-locus failure occurs before complete attempt-0 rotation publication. TB14 does not
   publish the required five-ray v47 production rotation with distinct former-pair ranks. Absence of the old error
   alone remains insufficient.
5. **PARTIAL — candidate closure.** CB16's exact vertex-10 defect is runtime-cleared, but the whole selector-380
   identity is RED and discriminator 4 is not satisfied. `M3-CP4c3-TB11-CAND-01` and
   `M3-CP4c3-TB12-REV-CAND-01` remain open. Final disposition of `M3-CP4c3-TB13-CAND-01` and
   `M3-CP4c3-TB13-REV-CAND-01` is reserved for independent TB14-REV so a focused local success is not confused with
   production closure.
6. **NOT REACHED — downstream face-walk evidence.** The mechanical witness still stops inside rotation-system
   construction. No legitimate `nonDiscComponentCount` or `remainingAdmissibleEdgeCount` is produced at the actual
   ordinal-366 frontier.

There remains **no vertex-30 discriminator**.

## Carried report-only surfaces

The report-only remainder preserves prior ownership unless the new runtime directly discriminates it:

- **367** inherits the same new mechanical `EdgeTraceSecondaryRankInvalid` frontier as 366;
- **368** reproduces the prescribed-sphere `RotationSystemInconsistent -> TraceEventPositionInvalid`, trace 2 /
  event 30, `NoCarrierMatch / SourceEdgeUnavailable` surface;
- **369** reproduces `saturationUsed=true` where the frozen identity expects ordinary proposal selection;
- **370** still does not return the expected `EmptyNetworkOnClosedSurface` typed code and still lacks the required
  `sourceFace` locus;
- **371/372** again fail only because their shared mechanical fixture constructor reaches the same upstream
  `EdgeTraceSecondaryRankInvalid` failure;
- **374** still stops at `atlasBuild=false` in the pre-classified folded-cone fixture;
- **373/375/376/377/378/379** pass report-only.

The required non-gating mechanical diagnostic independently reports the same mechanical provenance:
`pipelineFailure=NotProductionReady`, failed stage `surface-cut-graph`, origin `RotationSystemInconsistent`,
`originatingRotationSystemReason=EdgeTraceSecondaryRankInvalid`, `traceEventClaimedSourceEdge=25-31`, furthest stage
`field-aligned-network`, with source-topology/atlas/network snapshots present and no global-topology-plan snapshot.
It remains zero-credit diagnostic evidence.

## Regression/candidate categorization

- **`M3-CP4c3-TB14-CAND-01` — ACTIVE / GATING / NON-STABLE:** new first-red mechanism
  `EdgeTraceSecondaryRankInvalid` at source edge `25-31` / face `(25,30,31)`. Root cause is not assigned by TB14;
  independent review must distinguish missing/stale edge-trace provenance from a real rank-construction contract
  gap before a product correction is authorized.
- **`M3-CP4c3-TB14-ORCH-01` — RESOLVED / INFRASTRUCTURE / NON-STABLE:** moving the complete replacement to GitHub
  Actions produced organic results for the previously interrupted ordinals and the entire selector.
- **`M3-CP4c3-TB14-ORCH-02` — RESOLVED / REPORTING / NON-STABLE:** exact `[ OK ]` line matching mislabeled valid
  logs; corrected from immutable exit codes/logs without semantic rerun.

These are on the still-unaccepted CP4c-3 surface and cause no accepted-green loss. Stable accounting therefore
remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package
count remains **81**.

## Immutable postflight

The complete 58-file package-tree byte/mode census is exactly identical before and after runtime. Corrected
pre/post census SHA-256 is **`fc6b983f8544e27c805aaf00020a5b92be835b0dfccf5d81c73aa73905c484b5`** for both sides, and the package
internal manifest remains valid. No package repair, rebuild, relink, configure, generated discovery,
source/test/fixture/selector mutation, or benchmark occurred.

## Phase status and exact successor

TB14 is **COMPLETE / VALID SEMANTIC RED / NON-STABLE**. Accepted semantic authority remains **365/365**; the current
measured first-red frontier is ordinal **366**, now `EdgeTraceSecondaryRankInvalid` at edge `25-31` / face
`(25,30,31)`. CB16/package84 remains current build/package authority.

Exact successor is **`M3-CP4c-3-TB14-REV` — independent REVIEW + PLAN only**, under
`Architecture_M3_CP4c3_TB14_Independent_Review_Plan.md`. It must statically determine the exact edge-locus incidence
and contract behind `EdgeTraceSecondaryRankInvalid`, preserve the v47 five-ray obligation, adjudicate candidate
closure, and freeze one bounded Code + Build successor. No runtime, benchmark, compile, package, or product/test/
fixture/selector mutation is authorized in that review.
