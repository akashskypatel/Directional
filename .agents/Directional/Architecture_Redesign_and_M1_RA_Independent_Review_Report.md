# Architecture Redesign and M1 R-A Independent Review

**Turn type:** independent Review; documentation changes only  
**Date:** 2026-08-12 UTC  
**Repository:** akashskypatel/Directional  
**Branch:** agent/surface_cell_quad/p5-recover-bridge-healing  
**Branch authority when review began:** 888d93a98e892fadc6e7dcbcb3549c4b3fd630c2  
**Reviewed R-A source:** bebac907de814b07a55a770add4c897ab6d22ffd  
**Entering immutable runtime authority:** M1l bd140cff4572412e6f4ecd70a6ce0fe85310932c  
**Verdict:** **the redesign is a material improvement; R-A is compile-valid partial implementation, not closed or runtime-accepted**

## Current-status addendum — 2026-08-12 UTC

This report remains the historical independent review of source `bebac907...`; its evidence and original R-A-REV-01/02 findings are not rewritten.

Later commits `eca1ce1141e4cc8b492e4efbfd2227b0a001a76b` and `df386d1ad819879abbf9d7660c3d586778d7daee` correct the exact materializer read-backs and remove the exact raw component/sheet fallback encoding identified below. A closure-gate review of working-branch implementation `5e023f1a8331c53182cfd296732c37cb7a889b88` nevertheless leaves R-A open on R-A-REV-03 through R-A-REV-06: compatibility identities bypass typed fail-closed stitching, downstream validator/optimizer/rail decisions still read raw projection labels, required positive/tamper contracts are absent, and the partial compile package is not internally self-verifying.

The active corrective measures and definition of done are in `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`; exact later compile/package evidence is retained in `CHANGELOG.md`.

## 1. Review boundary and evidence

This review inspected the supplied redesign, its supporting review/context, the current durable architecture and test records, the R-A source, the final compile record, and the source delta between the downloaded review snapshot and the reviewed source.

No project executable, generated test, discovery command, benchmark, ctest, CLI, fuzzer, or custom input was executed. No production, test, fixture, benchmark, validator, build, or workflow source was edited.

R-A compile evidence:

- workflow run/job 31550744314 / 93972723960;
- result artifact 9124167871, digest sha256:31841bfda6ad39fc5f5c3f2112e24beb5d3e872008e8a65d13985441509f95b8;
- log artifact 9124168143, digest sha256:caf0000f304444a960b051b8445c76be74dd238631ac5f30f3e36fee706f66d8;
- Release/static/Ninja/PRE_TEST compile/link **118/118**;
- all generated-runtime, test, benchmark, discovery, ctest, CLI, fuzzer, and custom-input execution flags false.

The inspected source snapshot was c4932dff1a4249d24224e1b64fea81bdccaba06f. Comparison to reviewed source bebac907... found no later R-A production change; the only later production file was the benchmark translation unit. The inspected R-A paths therefore represent the reviewed implementation.

## 2. Redesign assessment

The supplied DESIGN.md materially improves the prior architecture in four ways:

1. Pipeline B is now the explicit normative default: combinatorial cross-field tracing, a field-aligned curve network, a global topology plan, and a deterministic polynomial conformity/flow stage replace global coordinate integration.
2. Pipeline A is retained as an optional, evidence-gated future path with one integer-free global solve rather than iterative mixed-integer refactorization. It cannot become scheduled work until Pipeline B is Certified on the full representative matrix.
3. The missing A1-to-A2 derivation is made explicit through FieldAlignedCurveNetwork, singularity ports, branch-consistent tracing, typed termination events, motorcycle-style decomposition, and disc-region proofs.
4. Binary success/failure is replaced by verifier-assigned dispositions D0-D4. Degradation is explicit, bounded, non-recursive, certificate-carrying, and cannot close strict gates.

The architecture is scientifically plausible and better aligned with the project's performance goal. It does not yet prove that the adapted tracing/motorcycle composition works for the target input class, that every fixed-boundary region has a successful degraded producer, or that the proposed quality path reaches production thresholds. Those are milestone evidence obligations, not reasons to reject the architecture.

### 2.1 Design clarifications that remain open

These points must be resolved before their owning milestone is accepted:

- DESIGN.md section 6.7 invariant 2 says degradations are empty for QualityRelaxed with all gates passed, while D1 is defined by one or more missed calibrated quality gates. D1 must have a quality-gate degradation record; the invariant needs a narrow wording correction.
- M3 must prove that the Ray-Sokolov-style trace construction plus motorcycle termination/decomposition gives the claimed non-crossing, complete, disc-region network on supported triangle-mesh/cross-field inputs. The cited ingredients do not by themselves prove the combined algorithm.
- The A1 field-quadrangulability certificate needs an executable construction and independent tamper oracle before failure may be classified as FieldTransportUnestablished.
- M7 must specify and prove the one declared degraded region producer, including completion/manifoldness under the unmodified fixed boundary. It cannot be treated as guaranteed merely because its interface is named.
- T5 must calibrate geometry, alignment, approximation, and element-quality thresholds before D0/D1 can be assigned honestly.

The attached DESIGN.md is preserved byte-for-byte as the normative source. These are tracked clarification/evidence items rather than silent edits to the supplied design.

## 3. M1 R-A review

### 3.1 What the implementation established

The implementation makes substantial progress against R-A:

- SourceRegionFaceAuthority owns row-independent SourceFaceTopologyKey plus typed IsolationSheetId.
- SurfaceTopologyRegion and SourceTopologyRegions use private state and checked factories.
- the source-authority factory verifies unique row topology, contiguous typed region IDs, exact row coverage, one row binding per member, component agreement, sheet agreement, and topology/member agreement before publication.
- raw sourceFaceComponents and sourceFaceSheets are confined to the source-authority builder ingress.
- SourceEntityId is removed in favor of typed SourceSupport, SourceProjectionChart, and SourceVertexFanId.
- build_authoritative_phase_front_mesh accepts the owning SurfacePhaseFrontProduct, not parallel raw component/sheet arrays.
- materializer occurrences carry required typed occurrence, support, chart, and topology-region values.

These changes are compile-valid. Compile validity is not semantic/runtime acceptance.

### 3.2 Blocking finding R-A-REV-01 — materializer still reads raw sheet payload as authority

OccurrenceData stores typed support/chart/region but no required typed sheet. The materializer then:

- compares SurfacePoint::sheet to decide whether an ordinary-front equivalence crosses isolation sheets (src/pipeline/RemeshPipeline.cpp:2602-2606);
- includes SurfacePoint::sheet in the canonical representative ordering key (src/pipeline/RemeshPipeline.cpp:2800-2816).

Those values are derived from SourceTopologyRegions, but they are persisted in the generic geometry payload and then read back for semantic decisions. That is exactly the duplicate-authority path prohibited by the corrected authority model and R-A items 7-8.

**Required correction:** each occurrence must carry the required typed sheet/member authority obtained from SourceTopologyRegions; equivalence and representative logic must compare typed region/sheet/chart/support values. SurfacePoint component/sheet may remain only as a one-way geometry/export projection that affected production paths never read as authority.

### 3.3 Blocking finding R-A-REV-02 — completion/lineage still encodes raw component and sheet into identity

PureQuadPatch, PureQuadMesh, and PureQuadVertexLineage retain SurfacePoint provenance beside typed topology-region, chart, sheet, and support authority. More importantly, resolved_stitch_identity writes provenance.component and provenance.sheet into SurfaceCellCanonicalIdentity (src/geometry/PureQuadCompletion.cpp:1694-1721). That identity participates in equality, hashing, ownership conflict detection, and stitching.

This is not diagnostic export. It is a semantic read-back of the raw mirror and leaves R-A item 7 open.

**Required correction:** build fallback stitch/ownership identity from the typed lineage authority or make the typed identity mandatory before assembly. Remove raw component/sheet reads from patch, completion, assembly, lineage, verifier, and materializer semantic decisions.

### 3.4 Acceptance consequence

R-A items 1-6 and the API-removal portion of item 8 are substantially implemented. Items 7 and the semantic-consumption portion of item 8 are not complete. Therefore:

- R-A is **not accepted as complete**;
- R-A source is **compile-valid partial implementation**;
- artifact 9124167871 is **not** an M1 runtime-acceptance candidate;
- no new stable runtime regression is assigned because runtime was intentionally not executed;
- M1l remains the latest immutable runtime authority.

## 4. Required next sequence

The next Code + Build turn must:

1. close R-A-REV-01 and R-A-REV-02 without restoring a raw mirror, adapter, hash oracle, fallback, or weakened test;
2. complete R-B through R-G so M1 lands as the one vertical cutover required by DESIGN.md;
3. compile/package only and produce a fresh immutable artifact with the expanded source audit;
4. leave all generated runtime for the retained artifact-only plan;
5. keep Pipeline B's later M3/M4/M7 algorithms out of M1; M1 establishes authority contracts only.

Only the resulting full R-A-through-R-G package may activate the artifact-only Test + Benchmark plan.
