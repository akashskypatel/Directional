# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap  
**Normative design:** .agents/Directional/DESIGN.md, replacement supplied 2026-08-11  
**Current reviewed source:** exact implementation/test source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` at independent-review branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760`
**Decision:** **close M1 as one vertical authority cutover, validate it immutably, then continue the default Pipeline B roadmap**  
**Last updated:** 2026-08-12 UTC

Repository authority: akashskypatel/Directional, branch agent/surface_cell_quad/p5-recover-bridge-healing, draft PR #8. Keep the PR open, draft, and unmerged.

## 1. Purpose and authority

This plan owns migration order, dependencies, stop conditions, and acceptance gates. It does not redefine the architecture.

| Concern | Authority |
|---|---|
| Product, stages, domains, invariants, disposition | DESIGN.md |
| Historical redesign and initial R-A findings | Architecture_Redesign_and_M1_RA_Independent_Review_Report.md |
| Current implementation plan | Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md |
| Dormant immutable validation plan | Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md |
| Normative testing | tests/TESTING_STRATEGY.md |
| Current action/status | TODO.md and Future_Chat_Session_Handoff.md |
| Stable defect patterns and blockers | Regression_Root_Cause_Tracker.md |
| Completed history | CHANGELOG.md and retained historical reports |

If this roadmap conflicts with DESIGN.md, DESIGN.md wins and this roadmap must be corrected before implementation.

## 2. Pipeline decision

### Pipeline B — normative default

Pipeline B contains no global coordinate integration or numeric factorization:

1. A0 SourceAuthoritySnapshot;
2. A1 FieldTransportAtlas, including field quadrangulability;
3. A2a FieldAlignedCurveNetwork;
4. A2b GlobalTopologyPlan;
5. A3 GlobalConformityPlan through deterministic polynomial graph/flow work and strictly positive rail lengths;
6. A4 direct per-region surface-cell construction;
7. A5 occurrence publication;
8. A6 quotient/materialization;
9. A7 geometry embedding;
10. A8 independent verification and disposition;
11. A9 diagnostics/export.

### Pipeline A — optional future

Pipeline A may later replace A2a with one integer-free continuous global solve, isoline/motorcycle extraction, and per-region embedding. It is not implemented, not tested, not scheduled, and not an acceptance requirement. It becomes eligible only after Pipeline B is Certified on the complete representative matrix with stable calibrated quality gates and evidence that integration would materially improve output quality.

## 3. Product disposition

The verifier assigns:

- D0 Certified: complete pure quad, all structural and calibrated quality gates;
- D1 QualityRelaxed: complete pure quad, structural gates pass, named calibrated quality gate misses;
- D2 LocallyDegraded: complete pure quad, named regions produced by the declared degraded producer;
- D3 Partial: pure-quad subset, explicitly omitted regions;
- D4 DiagnosticOnly: no mesh and typed failure/certificate evidence.

Only the closed catastrophic set in DESIGN.md may produce D4. Degradation may occur only at A3/A4/A8 as designed, is bounded and non-recursive, never changes upstream authority, and never closes a strict gate.

## 4. Revised migration sequence

The 2026-08-11 redesign retains prior M0-M2, maps prior M3 to M4, prior M4 to M5, prior M5 to M6, and prior M6 to M8, and introduces M3 and M7.

| Milestone | Contract | State |
|---|---|---|
| M0 | preserve immutable evidence | complete |
| M1 | single-authority cutover | active; overall R-A closure rejected; REV-18-through-REV-21 retained only as bounded compile progress; REV-22-through-REV-24 open |
| M2 | closed stage products and single writers | pending |
| M3 | field-aligned curve network | pending |
| M4 | global conformity plan | pending |
| M5 | certificate-carrying chart and quotient relations | pending |
| M6 | occurrence, embedding, independent verification | pending |
| M7 | disposition and graded degradation | pending |
| M8 | module boundaries and operational hardening | pending |

Later milestones are complete vertical contracts driven by the active Pipeline B product need. They are not permission for representation-only letter slices or compatibility bridges.

## 5. Current M1 checkpoint

### Immutable entering authority

M1a-M1l and T1 were accepted under retained immutable evidence. M1l source `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest runtime-accepted authority. Historical/partial package identities remain in `CHANGELOG.md`; none is an M1 acceptance candidate.

### R-A closure review

Independent Review of exact source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` at branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760` rejected overall R-A.

Retained bounded progress:

- one checked global aggregate `SourceTopologyRegions` is constructed and semantic publication is staged;
- affected source-authority consumers now use exact row-topology binding;
- the named optimizer/verifier raw/legacy compatibility branches remain absent;
- compile run/job `31625763711 / 94211611771` and artifacts `9153147035 / 9153147459` are authentic Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, `runtimeExecution=false` evidence.

Blocking remainder:

- **REV-21 contract completion:** required authority-only row-permutation rejection and consistently paired permutation acceptance are absent;
- **REV-22:** aggregate final validation supplies no boundary/feature/chart authority, disables strict gates, and unconditionally rejects ordinary boundary outputs against an empty expected loop set;
- **REV-23:** aggregate identity rebuilding copies stale kind and emits a stitch-key schema that differs from canonical completion construction;
- **REV-24:** direct source-authoritative validation can accept null typed authority when local-sheet checking is disabled and can falsely report `sourceAuthorityUsed=true`;
- no new semantic contract executed, and the packaged static audit has no reproducible path/count/allowed-leaf inventory.

The targeted runtime task for partial artifacts `9153147035 / 9153147459` is superseded. Exact evidence and corrections are retained in `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`; executable work is in the active Code + Build plan.

## 6. M1 completion sequence

The next Code + Build turn must:

1. close REV-22 with a strict, authority-complete final merged-product oracle and boundary-bearing positive/tamper contracts;
2. close REV-23 with one canonical post-remap stitch-identity constructor plus stale-kind and generated-interior re-stitch contracts;
3. close REV-24 with unconditional direct-validator source-authority binding and optional-gates-disabled negatives;
4. complete the REV-21 permutation-pair test matrix;
5. rerun the complete retained R-A inventory through REV-24 and record reproducible path/count/allowed-leaf evidence;
6. produce a fresh focused compile-only package without generated runtime execution.

A separate immutable artifact-only cadence turn then decides R-A. Only after R-A passes may Code + Build continue R-B through R-G and create the fresh full package consumed by the retained M1 artifact-only plan.

M1 must not implement M3 curve-network topology, M4 conformity flow, M7 degradation, or Pipeline A.

## 7. M2-M8 acceptance orientation

### M2 — closed products

Every applicable producer publishes one immutable exhaustive outcome. Rejected is terminal for that producer. Aggregators validate/remap representation only and never reconstruct semantics.

### M3 — field-aligned curve network

Prove singularity-port ownership, branch-consistent non-crossing tracing, typed termination, complete mandatory topology, disc-region proofs, and permutation invariance. The adapted tracing plus motorcycle decomposition requires its own proof and corpus evidence. A1 quadrangulability needs a constructible certificate and tamper oracle.

### M4 — global conformity

Publish one positive shared schedule before regional production. Use a deterministic polynomial graph/flow algorithm with explicit tie-breaking and work bounds. Infeasible rail subsets become typed subset-scoped D3 inputs. Resolve G4-B002 without post-hoc pairing.

### M5 — relations

Publish explicit relation owners and selected path certificates. Verify them independently. Resolve nonzero periodic Z4 and multi-isolation evidence without relation-vector position or verifier reconstruction.

### M6 — occurrence, embedding, verification

Separate occurrences, quotient construction, materialization, geometry embedding, and elementary independent verification. Establish injective region interiors and calibrated geometry/field/quality evidence.

### M7 — disposition

Introduce OutputDisposition, DegradationCertificate, omitted-region bookkeeping, verifier tier recomputation, and exactly one declared degraded producer as one vertical contract. Prove every tier, both directions of certificate matching, non-interference, determinism, and D0-only strict gates.

### M8 — hardening

Enforce module dependency boundaries, diagnostic non-authority, resource/work accounting, packaging, CI, and removal of remaining tracked architecture debt.

## 8. Testing interlock

Every migration preserves T1 and adds evidence at the correct layer:

- L0 schemas and invalid construction;
- L1 positive/tamper stage contracts;
- L2 metamorphic and generated properties;
- L3 independent semantic oracle;
- L4 full direct representative matrix;
- L5 fuzz/sanitizer replay;
- L6 calibrated quality/resource gates.

Pipeline B strict representative gates require D0. D1-D3 are separately tested truthful outputs, never green substitutes. Pipeline A cannot borrow Pipeline B acceptance if it is later adopted.

## 9. Design clarification gates

Before the owning milestone closes:

1. correct the DESIGN.md section 6.7 D1/degradation-record wording inconsistency;
2. prove the M3 combined tracing/decomposition algorithm;
3. define and verify A1 quadrangulability certificates;
4. specify and prove the M7 degraded region producer;
5. calibrate the D0/D1 quality boundary.

The supplied DESIGN.md remains byte-for-byte normative until a separately reviewed correction is authorized.

## 10. Stop conditions

Stop and revise the owning plan if a change:

- creates a second semantic owner or raw mirror;
- reads a diagnostic/export encoding as authority;
- uses a face row, vector position, hash, or execution order as semantic identity;
- restores an adapter, alias, compatibility numbering, fallback, or reconstruction bridge;
- allows a producer/verifier/aggregator to rewrite upstream meaning;
- introduces a global solve into Pipeline B;
- degrades outside A3/A4/A8, without a substantiated certificate, recursively, or to pass a strict gate;
- schedules Pipeline A before its eligibility gates;
- weakens a fixture, oracle, validator, lineage, failure, or no-substitution contract;
- uses compile success as runtime or semantic acceptance.

## 11. Resume rule

Current exact action is the amended M1 Code + Build plan for REV-22 through REV-24 plus the missing REV-21 contracts. Partial artifacts `9153147035 / 9153147459` are not executable acceptance candidates. The full artifact-only plan remains dormant until a fresh full R-A-through-R-G package exists. After M1 acceptance, choose the smallest revised M2-M8 contract that owns the highest-prerequisite active Pipeline B product blocker.
