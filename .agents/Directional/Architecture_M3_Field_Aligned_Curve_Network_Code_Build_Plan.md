# Architecture M3 — Field-Aligned Curve Network Code + Build Plan

Date: 2026-08-18 UTC
Status: **CP1 PACKAGE 6 RUNTIME-REJECTED; A1 INVARIANT DISPROVEN — immutable `M3-CP1-TB-R2` on `95006048225df765b5b9c31e235fed82330a1469 / 9354456191` is 258/281, A1 3/6, retained M2 255/275, M1 producer 118/138. `M3-CP1-A1-RESCOPE` established that the failure is not a sign error: the asserted cycle-transport congruence is false in general and A1's planar `z = 0` fixtures only ever exercise the degenerate `0 ≡ 0` case. See `Architecture_M3_CP1_A1_Rescope_Review.md`; section 5G is superseded. CP1 is 6/6, M3 7/11; no package is authorized. Exact successor is Review/planning-only `M3-CP1-PLAN-AMEND`, which must record the A1 design amendment and the allocation amendment CP1 6 -> 7 / M3 -> 8/11 before any `M3-CP1-CB-R5`. CP2 remains blocked.**
Predecessor: **M2 CLOSED / ACCEPTED** on exact source/package `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431`, accepted by `M2-CP4-TB-R2` `32183306224 / 95861164621` at **275/275 + static M2 K=0**.

## 1. Objective and normative basis

M3 implements the Pipeline-B topology primitive required by `DESIGN.md` A1/A2a/A2b and `REORIENTATION_PLAN.md` section 7. The architectural outcome is not merely another tracing helper. It is a typed, immutable authority chain in which:

- A1 publishes a `FieldTransportAtlas` and a checkable `FieldQuadrangulabilityCertificate` before topology planning;
- A2a publishes a `FieldAlignedCurveNetwork` whose singularity ports, mandatory feature/boundary edges, trace transport, intersections, and terminal events are explicit typed authority;
- A2b derives the topology-region decomposition from that network and publishes a `GlobalTopologyPlan` with disc-topology proof per emitted region;
- no downstream stage repairs a malformed network or recomputes its semantic decisions.

The design requires the tracing primitive to be combinatorial rather than nearest-direction numerical integration: branch choices are made from inflow/outflow interval pairing, source positions remain exact source-attached values, traces terminate on first contact, and crossings/intersections become graph nodes rather than post-hoc geometric repairs.

M3 must not implement M4's global positive rail schedule, M5 quotient/chart certificate work, M6 occurrence/embedding verification, M7 disposition, M8 module hardening, or Pipeline A.

## 1.1 Independent review findings — resolve in CP0

The plan was reviewed at M2 closure and is **correctly aligned and adequately decomposed**. CP0 resolved the design gaps below in the retained authority census. Those resolutions are normative for CP1+ and may change only by an explicit plan/census update.

### 1.1.1 M3 is new capability, not a cutover — the cost model differs

M1 and M2 were **migrations**: the behaviour already existed and was re-typed, so every checkpoint could be validated against accepted behaviour and the frozen selector stayed green throughout. **M3 builds a new tracing algorithm.** For the new parts there is no accepted behaviour to preserve — only the predecessor's.

Two consequences:

- The M1 calibration (cost tracks independent semantic domains per checkpoint) was derived **entirely from cutovers**. It remains the best available heuristic but is being applied outside its reference class; treat M3 estimates as weaker than M1/M2 estimates, not equal.
- A red M3 checkpoint is more likely to be a *design* defect than a *migration* defect, because there is no prior correct behaviour to diverge from. Stop-and-replan should trigger earlier than it did in M2.

**Verified clean:** `FieldTransportAtlas`, `FieldQuadrangulabilityCertificate`, `FieldAlignedCurveNetwork`, and `GlobalTopologyPlan` have **zero occurrences** in `src/`, `include/`, and `tests/`. They are genuinely new, so "introduce" is the correct verb — this plan does **not** repeat M2's mis-stated-seam defect.

### 1.1.2 Two open design obligations are M3 prerequisites and are not wired in

Both sit in `TODO.md`'s design backlog and appear nowhere in this plan:

1. **"Define the A1 field-quadrangulability certificate construction and independent tamper oracle."** Section 2 item 1 and section 3 A1 both *require* a published `FieldQuadrangulabilityCertificate`, and section 2 item 9 requires transport-tamper negatives — but its construction and tamper oracle are undefined. **Building CP1 against an undefined certificate is the criterion-5 shape**: naming something whose definition does not yet exist. M1 paid for that twice.
2. **"Validate the M3 combinatorial-trace plus motorcycle/decomposition composition rather than assuming ingredient guarantees transfer."** `DESIGN.md` warns explicitly that composing individually-sound ingredients does not yield a sound composite. CP3 implements exactly that composition, and no checkpoint currently owns the composition proof.

**CP0 resolution:** `Architecture_M3_CP0_Authority_Census.md` section 5 defines the immutable `FieldTransportAtlas`, the conservative closed/relative-boundary `FieldQuadrangulabilityCertificate`, rejection reasons, and an independent factory-free tamper oracle. Section 8 assigns the trace/decomposition composition proof to `M3-CP3b-TB`. CP1 ordinarily may not begin unless CP0 compile/package evidence and CP0-TB accept this frozen design; the user explicitly authorized the recorded CP0-only exception without accepting CP0-TB.

### 1.1.3 Declare the retry budget before CP1

Section 5 of `REORIENTATION_PLAN.md` requires the budget declared before work starts, so a stall is a decision rather than a negotiation. This plan states none. M2 consumed **11 packages** against a nominal 8 ceiling via two authorized reopenings — the pattern to avoid repeating by silence.

**CP0 resolution, amended by the CP1 replans and explicit user authorizations:** the hard cumulative ceiling remains **11 packages**. CP0 consumed 1 and CP1 consumed six, so M3 remains **7/11**. Package 6 was compile-green but immutable `M3-CP1-TB-R2` reproduced the package-5 runtime failure at **258/281**. CP1 is therefore **6/6**, NOT ACCEPTED, and closed to further Code + Build attempts; no package 7 is authorized. The predeclared stop rule now requires `M3-CP1-A1-RESCOPE` before any budget or design request. CP2, CP3a, CP3b, and CP4 retain their previously declared local caps subordinate to the cumulative ceiling, but CP2 cannot begin while CP1/A1 remains unresolved. Eight consumed packages before CP3b is green, or nine before CP4 begins, still triggers global replan. `M3-FULL` remains omitted unless a later explicit reallocation and user authorization amend this plan.

### 1.1.4 CP3 sizing — likely two domains

**CP0 resolution:** the census confirms two independently testable domains. CP3 is split into CP3a (branch-consistent combinatorial tracing into candidate segments, no contact graph) and CP3b (typed first-contact/intersection/termination graph plus independent composition validation, no global topology selection).

## 2. M3 acceptance contract

M3 closes only when one immutable artifact-only gate proves all of the following together:

1. **Field precondition is explicit at A1.** Every traversable source adjacency has typed field transport; singularity/cycle facts are explicit; a `FieldQuadrangulabilityCertificate` is published and a failed certificate is represented as the architecture's `FieldTransportUnestablished` catastrophic precondition rather than deferred to M4 scheduling.
2. **Singularity ports are typed and complete.** Port count is derived from cross-field index; every required port is owned exactly once; numeric coincidence cannot substitute for typed ownership.
3. **Mandatory topology is first-class.** Source boundaries and user/authoritative hard features enter the graph as mandatory edges and survive network selection/simplification.
4. **Tracing is branch-consistent.** Transported branch identity is preserved along the entire trace; no nearest-direction or row-number heuristic may silently change branch authority.
5. **Network geometry is structurally clean.** Traces cannot cross/merge without an explicit network node; every trace terminates at a typed event (existing trace, boundary, hard feature, singularity); silent regular-face-interior termination is not representable.
6. **Topology regions are derived.** `GlobalTopologyPlan` consumes the network rather than assuming region membership; each emitted region has a disc-topology proof unless explicitly typed otherwise.
7. **Reduction preserves required topology.** Network selection may remove redundant traces but cannot alter required singularity index/port topology or mandatory boundary/feature graph edges.
8. **Metamorphic invariance passes.** Tracing order, start-port ordering, source-face row ordering, and equivalent cross-field branch labeling do not change semantic network/topology authority.
9. **Independent/tamper evidence passes.** Required positives and negatives include port ownership, crossing/interior-termination rejection, mandatory-edge preservation, transport tamper, and disc-region proof. A negative counts only if its intended seam is reached.
10. **Frozen predecessor remains green.** Exact M2 required-green **275/275** remains accepted unless a later M3 plan explicitly freezes a superset with independently justified M3 contracts.

M3 has no degraded mode. A0/A1/A2a/A2b failures are not repaired by local substitution.

## 3. Required implementation shape

### A1 — field transport authority

The final source surface must expose one immutable `FieldTransportAtlas` authority rather than reconstructing transport from raw matching/index arrays at each consumer. It must own or reference, with typed IDs:

- traversable source adjacency;
- quarter-turn/branch transport;
- singularity/index facts;
- holonomy/cycle facts required to establish field quadrangulability;
- the `FieldQuadrangulabilityCertificate`.

Existing accepted typed transport algebra may be reused. M3 must not create a parallel raw semantic representation merely because legacy APIs expose matrices/rows.

The frozen construction is in `Architecture_M3_CP0_Authority_Census.md` section 5. The atlas binds exact A0 source authority, reciprocal typed traversable adjacency, explicit nontraversable boundary/feature edges, the complete local/boundary/`2g` cycle basis, exact integer lifts/compositions, typed singularity facts, component topology, and a checkable certificate. Closed components use only the documented conservative sufficient holonomy witness; the gcd condition is not claimed necessary. Boundary components require a constructive relative cut-to-disk/boundary-turn witness. Anything not positively established is `FieldTransportUnestablished`.

### A2a — field-aligned curve network

`FieldAlignedCurveNetwork` must make explicit at minimum:

- stable typed network-node IDs;
- typed singularity-port IDs and owner singularity/index authority;
- typed trace/curve IDs;
- source-attached support for nodes and trace segments;
- mandatory boundary/feature edge classification;
- exact branch/transport provenance per segment;
- typed terminal-event kind and owner;
- explicit graph incidence for contact/intersection nodes.

The product is immutable after publication. No later topology stage may mutate a trace to resolve a cycle, crossing, tiny region, or missing event.

### A2b — topology plan

`GlobalTopologyPlan` is derived from the embedded network. It must own/reference:

- regions as faces of the selected graph;
- typed boundary-arc ownership;
- source boundary/hard-feature/cut classification;
- singularity-port ownership relevant to region corners;
- disc-topology proof/certificate for each emitted region;
- the stable typed authority needed by M4 to schedule one shared rail sequence later.

M3 stops before selecting positive subdivision counts or breakpoint sequences.

## 4. Checkpoint decomposition

Every checkpoint follows normal `Code + Build -> Test + Benchmark` cadence. On 2026-08-18 the user explicitly granted a **one-time CP0-only cadence exception**: omit `M3-CP0-TB` and proceed to `M3-CP1-CB` because CP0 changed no product/test code and predecessor product/tests were already accepted at M2. The omission is not CP0-TB acceptance; CP0 remains compile evidence only. Normal cadence resumes at CP1, whose required successor remains `M3-CP1-TB`.

| Checkpoint | Bounded Code + Build outcome | Required successor |
|---|---|---|
| `M3-CP0-CB` | **Inventory/census + compile only.** Enumerate the existing A1/A2a/A2b semantic surface, current transport/network/region representations, producer/consumer sites, raw semantic aliases, relevant accepted tests, and exact change candidates. Freeze the census and compile the approved predecessor owner targets with `runtimeExecution=false`. **No M3 semantic implementation in CP0.** | `M3-CP0-TB` |
| `M3-CP1-CB` | Establish the single A1 field-transport/quadrangulability product boundary using accepted typed transport algebra; eliminate only the census-proven duplicate/reconstructed semantic transport authority in CP1 scope. | `M3-CP1-TB` |
| `M3-CP2-CB` | Introduce typed singularity-port and mandatory boundary/feature graph authority and a closed `FieldAlignedCurveNetwork` product skeleton; no tracing-order algorithm yet beyond product construction/validation. | `M3-CP2-TB` |
| `M3-CP3a-CB` | Implement branch-consistent combinatorial tracing from typed atlas/ports into candidate segments; no contact/intersection event graph or topology selection. | `M3-CP3a-TB` |
| `M3-CP3b-CB` | Publish typed first-contact/intersection/termination incidence and close the trace-plus-event composition seam; no global topology selection. | `M3-CP3b-TB` |
| `M3-CP4-CB` | Derive/select the global network topology and publish `GlobalTopologyPlan` regions with mandatory-topology preservation and disc-topology proof; stop before M4 rail scheduling. | `M3-CP4-TB` |
| `M3-FULL-CB` | **Omitted by default.** It may exist only after an explicit plan update reallocates the hard 11-package ceiling and the user authorizes it; it may not add a semantic domain or run vacuously. | `M3-FULL-TB` only if separately authorized |

The frozen CP0 census fixes the first CP1 vertical slice at ten files: three new atlas/oracle files and seven build/ID/tracing/pipeline registrations listed in census section 7. It may not silently enlarge M3 into M4+ work. Any newly required file or semantic domain stops CP1 for a census/plan update before implementation.

## 5. Completed turn — `M3-CP0-CB`

`M3-CP0-CB` was a runtime-free Code + Build turn. **The census discharged the section 1.1 design gaps: the A1 certificate/oracle is defined, composition proof is assigned to CP3b-TB, CP3 is split, and the 11-package retry/stop budget is frozen.** It completed all of the following:

1. Re-verify exact entering semantic authority `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431` and the accepted M2 TB-R2 record.
2. Inventory, before editing, every current producer/consumer representation that could carry:
   - cross-field adjacency transport / quarter-turn branch authority;
   - singularity index and port-equivalent authority;
   - trace/network node/segment/event authority;
   - boundary/hard-feature mandatory graph authority;
   - topology-region extraction/disc-region authority;
   - A1 quadrangulability/admissibility facts.
3. Classify each candidate as authoritative product, stage-local calculation, diagnostic/projection leaf, legacy duplicate/reconstruction, test-only seam, or deferred/non-M3 domain.
4. Freeze exact CP0 census files/counts and identify the smallest independently testable CP1 change set. Do not infer a semantic defect merely from lexical proximity.
5. Identify existing tests that genuinely reach each M3 seam and separately list missing contracts. Do not promote inherited-red tests without accepted-predecessor differential evidence.
6. Make **no M3 semantic implementation change**. CP0 source changes are limited to retained census/plan/test-selector metadata if required for the immutable CP0 evidence package.
7. Compile/link the exact predecessor owner targets required to package the frozen census through `.github/workflows/agent-compile-reusable.yml`, preserving the durable compiler-cache namespace/schema and `runtimeExecution=false`.
8. Package exact source, census, dependency/status/manifest evidence, and every executable needed by `M3-CP0-TB` to reconstruct the census without rebuilding.
9. Record an exact artifact-only `M3-CP0-TB` acceptance procedure in the handoff/report before closing the turn.

No generated Directional runtime, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom mesh input may execute in `M3-CP0-CB`.

### 5.1 Immutable completion evidence

- exact compiled source: `f51b7d7fc5b63c9efeeffabdf286a897119d75d9`;
- run / compile job: `32188666437 / 95878012079`;
- result artifact / outer SHA-256: `9343406869 / edf7be6e739cc769758f232b4f9dafc36018de6935e91788965423be35e5c7e4`;
- persistent log / outer SHA-256: `9343407254 / bfbad6d15b70373fc425954ba361f57ba97aa21bef535c7d2d11cd0399310f96`;
- approved eight targets: **121/121** Ninja steps, `build_exit=0`, `compile_status=0`;
- manifest: **25 entries / 26 files**, all green; zero symlinks; five empty status snapshots; nine dependency revisions;
- boundary: `runtimeExecution=false`; no generated Directional runtime, test, discovery, benchmark, or custom input executed.

Temporary workflow cleanup commit `e6495b881eee227c03414709a680d46fae180b1a` preceded trigger cleanup commit `0952f76fe58317b68c023050bf46f9021815cc40`. The retained report is `Architecture_M3_CP0_Code_Build_Report.md`.

`M3-CP0-TB` was **omitted by explicit user authorization and was not executed or accepted**. Its frozen artifact-only procedure remains retained in the CP0 report as documentary evidence. CP1 then used the frozen ten-file vertical slice; the latest accepted semantic runtime authority remains M2.

## 5A. Blocked turn — `M3-CP1-CB`

CP1 remained inside the frozen ten-file A1 slice and consumed its complete **2-package** allocation.

Package 1 implemented the atlas/certificate/pipeline boundary at semantic commit `4dad58a66c439c152560cb685f96a178f0902542`. Exact marker-source `cec8dfad2c4aba2330865d5664d7cb873db37a42` compiled and packaged green in run/job `32192286177 / 95889006356` at **123/123**, `runtimeExecution=false`. Result artifact `9344803199` has outer SHA-256 `79a99a2addc84fd0f004897c08a7e71ca1363c86008d4e3ca4349a4df136ccd8`. Its manifest, source archive, dependency/status inventory, owners, and symlink checks passed. Closeout source audit nevertheless found that the frozen contract was not complete: the independent oracle covered only adjacency/topology portions, certificate source/atlas digests were absent, and the full holonomy signature omitted handle-cycle lifts. Therefore this compile-green artifact is not a CP1 acceptance candidate.

Package 2 revision `c2d6a76337aa2fb6be62ae57b89a202e5f4c2cd9` stayed within three existing slice files and attempted to add explicit source/atlas/holonomy digests, complete cycle/singularity/admissibility validation, and the full typed tamper matrix. Run/job `32194456711 / 95895504105` failed compiling the expanded test oracle at step **101/123**: two qualified calls could not find the `QuarterTurn` hidden-friend `compose`, and an Eigen `cross()` used dynamically sized row-expression types. Core and pipeline libraries linked; no result artifact was produced. Verified log artifact `9345461584` has outer SHA-256 `1ada8f90d485c40e9e44e16e8d4504108eb9d7a8eda9b25c92d4a8f5d1d50e86`. `runtimeExecution=false` and no generated Directional software ran.

Temporary state for both packages was removed caller-first and marker-second. Package 2 cleanup commits are `62323b7ad895c62142ba16ad03efc79eabbfd424 / af93d376f50104bfde6274416fa1250364687554`. Only the three durable workflows remain, with no connector trigger, observation, or payload directory.

Under the then-frozen two-package rule, the second non-green package stopped CP1 for restructuring; there was no silent third attempt. M3 has consumed **3/11** packages total. The retained evidence and diagnostics are in `Architecture_M3_CP1_Code_Build_Report.md`.

That stop was discharged by the independent documentation-only review at `ec2a8efb62859a8654105229cf6327c7cc396b44`. Its retained authority is `Architecture_M3_CP1_Replan_Guidance.md`.

## 5B. Final repair package outcome — `M3-CP1-CB-R1`

The user-authorized final CP1 package consumed cumulative M3 package **4/11**. Repair revision `86fa44473b05f78e76f1737e33e3a168070efa4a` preserved production blobs `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`, fixed the reviewed ADL/Eigen mechanics, completed the per-fact source-derived oracle audit, and added first-target preflight evidence to the durable compile workflow.

Exact marker-source `5ce79f39f60186098c271b5810496d627e6504c2` ran as `32199666445 / 95910558538`. The standalone `directional_surface_cell_authority_kernel_tests` preflight stopped on one newly introduced test-only declaration: `FieldCycleId` was not imported or qualified at `tests/FieldTransportAtlasTests.cpp:743`. Core and pipeline linked; preflight exit was 1; the full target set was skipped; no result artifact was produced; `runtimeExecution=false`. Verified log artifact `9347043139` has outer SHA-256 `20ff3e58f258f82225e9c167a35c41cf9a66fef822775fd87fbfb7fcf3a06ecc`.

This was compile-mechanics/process evidence, not semantic/design evidence. Under the then-current cap CP1 was **3/3 exhausted** and correctly advanced to Review/planning-only `M3-CP1-PROCESS-REPLAN`; no silent fourth package was spent. That historical stop is preserved here because it established the process defect later corrected by R2.

## 5C. Process-gated final package outcome — `M3-CP1-CB-R2`

The process replan approved the A1 design unchanged, required a true external pre-package compile, and recommended one final CP1 package. The user explicitly authorized the local cap from 3 to **4**, while retaining the M3 hard cumulative ceiling of 11 and forbidding package 5.

Exact semantic source `9f54c77ae92161226e833cf313bf38e516aa276c` differs from the reviewed R1 repair by one test-only import of `directional::authority::FieldCycleId`. The production atlas blobs remain byte-identical at `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`; no assertion, expected value, product semantic, or build configuration changed.

A separate pre-package run `32201791916 / 95916966789` compiled only `directional_surface_cell_authority_kernel_tests` on the literal semantic source SHA and passed **91/91**, with result/log `9347775163 / 9347775370` and `runtimeExecution=false`. That artifact is mechanics evidence only, not TB input.

After the green pre-package compile, the closeout source audit reconfirmed the frozen slice, the one-line delta, unchanged production bytes, and unchanged independent-oracle semantics. No product/test/build source edit occurred afterward.

The full package run `32201987864 / 95917547662` then compiled the identical literal semantic source. The authority-kernel preflight passed 91/91 and the remaining target closure passed 32/32, for **123 build actions**. Result artifact `9347879320` has outer SHA-256 `213cc0dfd06370da71e964271f36e49494bf31633a70c1ae9bfe6bba1b8bcb4a`; log artifact `9347879687` has outer SHA-256 `d5ab6b1f7f771b480277f9d298cd4af71e5174be04bc5c0b2f67c4c1eb021b89`. The package verifies **27/27** self-excluding manifest entries across 28 files, six owner executables, two libraries, five empty source-status snapshots, nine dependency revisions, and a 548-member zero-symlink source archive. `runtimeExecution=false`: no generated Directional software executed.

CP1 is **4/4** and M3 is **5/11**. The compile-green package entered immutable TB and was rejected; it remains failed evidence, with no package 5 authorization.

## 5D. Immutable CP1 runtime outcome — `M3-CP1-TB`

Artifact-only `M3-CP1-TB` `32204335734 / 95924452913` selected all **281/281** frozen identities without rebuild/repair/mutation and finished **256/281**: A1 **2/6**, retained M2 **254/275**, with retained loss isolated to M1 producer **117/138**.

The 21 retained reds share stable recurrence `PR8-R038 / M3-CP1-R001`, `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: reconstructed local tangent-bundle cycle/binding representation is promoted to canonical A1 source authority and rejects valid predecessor paths early. Four new A1 baseline-construction reds are non-stable `M3-CP1-TB-CAND-01`.

This is first-order M3 semantic evidence. CP1 is NOT ACCEPTED. Exact next is Review/planning-only `M3-CP1-RUNTIME-REPLAN`; no additional package is authorized by this plan text and CP2+ remain blocked.

## 5E. Runtime replan and R3 pre-package correction

Independent `M3-CP1-RUNTIME-REPLAN` retained A1. It refined `PR8-R038` from a broad rejection of `dual_cycles` to two bounded representation-to-authority defects: stored sparse algebraic zeros were interpreted as semantic support, and the generic local `TriMesh` reconstruction was incorrectly mandatory for a trivial one-face relative-boundary region.

Exact source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` changes only `src/authority/FieldTransportAtlas.cpp`; tests, fixtures, headers, and build configuration are unchanged. External owner pre-package `32208365044 / 95935875386` is **91/91 green** with result/log `9349870579 / 9349870841` and `runtimeExecution=false`. This compile is mechanics evidence only and consumes no package.

CP1 package 5 compiled green on the identical preflighted source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` as `32209993498 / 95940623789`, producing result `9350420635` after 123 approved build actions with `runtimeExecution=false`. CP1 is 5/5 and M3 6/11. No package 6 is authorized. Exact next is immutable `M3-CP1-TB-R1`; CP2+ remain blocked.

## 5F. Package-5 immutable runtime outcome — `M3-CP1-TB-R1`

Artifact-only `32211699382 / 95945506893` consumed exact `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635` with all **281/281** selected and immutable package/source postflight. Result is **258/281 FAIL**: A1 **3/6**, retained M2 **255/275**, with retained loss isolated to M1 producer **118/138**. Result/log `9350958978 / 9350959164` have outer SHA-256 `eb43ba06e63ba230cf9c77bcdf1efc5e856b2adb660b04ce5fac8e3378286793 / a5346129311c70d084124b342f59f3c2c0097e198606ff14dca69a1f4ed6c03e`. No rebuild, relink, package repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.

The R3 corrections restore the hard-feature A1 contract and one retained hard-feature decline contract, but the surviving earliest atlas rejection is `CycleTransportMismatch`. This narrows but does not resolve `PR8-R038 / M3-CP1-R001`. The precise remaining mechanism is not established by TB and must be reviewed before any mutation. Stable totals remain **38 / 14 / 24**; the three remaining new A1 reds stay under non-stable `M3-CP1-TB-CAND-01`.

CP1 is **NOT ACCEPTED**, **5/5**, M3 **6/11**. Exact next is `M3-CP1-RUNTIME-REPLAN-R2` Review/planning only. No package 6 is authorized; CP2+ remain blocked.


## 5G. Independent A1 review and F5 derivation — `M3-CP1-A1-DERIVATION`

The independent implementation review correctly identified three surviving
cycle-seam defects: the producer searches over whole-cycle reversal and mutates
`turningLift`, the cycle-row coefficient and `reverse_cycle_edges(...)` form two
competing orientation mechanisms, and the nominal independent oracle reads the
published `turningLift` instead of deriving the exact index from source
authority. The review also correctly observed that the hard pipeline gate fans
an A1-local rejection out into the twenty retained M1-producer reds.

**SUPERSEDED by `M3-CP1-A1-RESCOPE` — see `Architecture_M3_CP1_A1_Rescope_Review.md`.** The
congruence this section concluded is **false in general**: the cycle index is
built from `effort` and `curvature`, `matching` is an integer branch offset
computed from different inputs, and any curved non-singular cycle falsifies the
relation. The section below is retained as history and must not be read as a
specification. The corresponding design amendment is authored by
`M3-CP1-PLAN-AMEND`, not by this section.

The planning-only derivation in
`Architecture_M3_CP1_A1_Derivation_Review_Report.md` resolves F5 without
changing the frozen A1 design. Under the accepted repository conventions:

- `polygonal_edge_topology` orients `EV(e,0) -> EV(e,1)` with `EF(e,0)` on the
  left;
- the signed `dual_cycles` row coefficient is the one cycle-orientation
  authority, with positive support traversing `EF(e,0) -> EF(e,1)` and negative
  support the reverse;
- `QuarterTurn` composition adds signed integer matchings modulo four;
- `effort_to_indices` defines the exact integer cycle index as
  `(sum(s_e * effort_e) + 4*K_C)/(2*pi)`.

`principal_matching` implies
`effort_e ≡ 4*alpha_e + 2*pi*m_e (mod 8*pi)`. Around a closed oriented dual
cycle the face-branch phases telescope and the discrete connection holonomy is
the same oriented curvature `K_C`, so

`I_C ≡ sum(s_e * m_e) (mod 4)`.

Therefore the intended comparison
`QuarterTurn::from_integer(turningLift) == composedTransport` is valid. The
defect is the implementation's search over orientation, not the invariant.

The final correction is bounded to one semantic domain and two files:

1. `src/authority/FieldTransportAtlas.cpp` — compute `turningLift` once; let the
   cycle-row sign direct every edge; order without reversing semantic direction;
   fail closed if directed support is not one cycle or if typed composition does
   not equal `turningLift mod 4`; never mutate the expected value to make the
   comparison pass.
2. `tests/FieldTransportAtlasTests.cpp` — independently reconstruct source
   connection, oriented cycle support/curvature, raw branch matching/effort, and
   exact cycle index; compare that source-derived fact to the product before
   applying tamper cases. Published `cycle.turningLift` is never expected-state
   authority.

The independent review's C1 recommendation is narrowed at the acceptance
boundary. `DESIGN.md` section 7.5 and M3 acceptance criterion 1 require A1 to be
a hard precondition **before topology planning**, while criterion 10 requires
the retained M2 gate to stay green. CP1 therefore may not be accepted with an
A1 bypass or a plan flag that postpones re-arming to CP2+. The twenty retained
reds must be restored by making valid predecessor inputs satisfy A1, not by
routing around A1. `RemeshPipeline.cpp` is not in the final repair surface.

This planning turn consumes no package. CP1 remains **5/5** and M3 **6/11**.
One final bounded CP1 package is justified technically but remains unauthorized.
If the user explicitly amends the CP1 local cap **5 -> 6**, exact next is
`M3-CP1-CB-R4`: implement the two-file correction, run a true external
owner-target pre-package compile on one fixed semantic source SHA, stop on any
red without consuming a package, and only after a green source audit spend
package 6 on the identical source. A green package advances to immutable
`M3-CP1-TB-R2`, whose acceptance target remains the unchanged **281/281**.

Stop if the fixed-orientation producer plus independent source-derived oracle
still rejects the derived congruence on a valid baseline. Do not search another
sign, weaken the invariant, bypass A1, or authorize another CP1 package.

## 5H. Completed CP1 R4 package — fixed cycle orientation and independent source oracle

`M3-CP1-CB-R4` is complete as Code + Build evidence on exact semantic source
`95006048225df765b5b9c31e235fed82330a1469`. The final semantic delta is confined to the two planning-approved
files. Production no longer searches whole-cycle orientation or mutates
`turningLift`; the independently derived signed cycle row owns orientation. The
oracle now independently reconstructs source connection/matching/effort,
cycle-basis support/orientation, curvature, and exact lift before comparing the
published witness.

The mandatory external pre-package owner compile `32222508189 / 95975565518` passed **91/91** and
consumed no package. Authorized package 6 `32222669309 / 95976032350` then compiled the identical
source across the full approved target set **123/123**, producing immutable
candidate `9354456191` with outer SHA-256 `da1b4e111642c4b637746c81df1f7d24eb56d47dda9ac3de0a69b5d126313c18`. Its log `9354456667`
has SHA-256 `2a1b91ff7667b8071e5647bbe9f3004f1fe34851f8ed917fea90a8ef0f1a6d97`. Both runs record `runtimeExecution=false`.

CP1 is **6/6**, M3 **7/11**, but CP1 is **not accepted** by compilation. Exact
successor is immutable `M3-CP1-TB-R2` on `95006048225df765b5b9c31e235fed82330a1469 / 9354456191`, acceptance target
**281/281**. If that gate still rejects the derived congruence on a valid
baseline, stop and re-scope A1 rather than searching another sign, bypassing the
precondition, or spending another CP1 package. CP2+ remain blocked.

## 6. Test strategy to freeze during CP0

M3 evidence must eventually cover the `DESIGN.md` curve-network matrix:

- **Positive:** all singularity ports owned exactly once; traces terminate at typed events; mandatory source boundary/hard-feature edges retained; disc topology derived.
- **Negative/tamper:** unowned/duplicate port, branch-transport tamper, explicit crossing/contact inconsistency, silent regular-face termination, mandatory-edge deletion, non-disc region proof mismatch.
- **Metamorphic/property:** tracing-order permutation, start-port permutation, source-face row permutation, equivalent quarter-turn branch relabeling.
- **Independent/representative at M3 scope:** at least one periodic/torus-style topology witness and one feature-bearing mechanical-style topology witness through the production M3 entry path. These are M3 topology-network evidence only and do not substitute for later Bunny/Vase product/resource acceptance.

Every acceptance witness must prove its precondition before its target assertion becomes required-green evidence.

`M3-CP3b-TB` owns the composition proof: an independent graph sweep checks earliest declared contact, absence of undeclared interior crossings, exactly one typed terminal owner per endpoint, no silent regular-interior stop, exactly-once port consumption, candidate rotation-system/face-walk consistency, order-invariant semantic digest, and targeted contact/crossing/event/incidence tamper rejection. CP4 separately owns selected `GlobalTopologyPlan` regions and final disc certificates.

## 7. Standing stop conditions

Stop and replan rather than patch around evidence if any checkpoint would require:

- restoring semantic authority to mutable `surfaceCellContext` or a new equivalent cross-stage context;
- adding a second writer for field transport, network ownership, or topology-region authority;
- nearest-direction heuristic branch switching where the architecture requires combinatorial transport;
- post-hoc crossing, limit-cycle, tiny-region, or non-disc repair of an already published network/topology product;
- implementing M4's positive rail schedule inside M3;
- treating proximity/equal coordinates as graph or quotient identity;
- weakening predecessor assertions or using zero-selected filters as pass evidence;
- introducing a global numeric factorization into Pipeline B;
- using a degraded producer for A1/A2a/A2b failure.

## 8. Carried-forward obligations that M3 does not discharge

- `G4-B001 / PR8-R034 / G4-R007` remains a later direct-torus product blocker unless M3 evidence independently proves its exact owning seam; M3 must not claim closure by unrelated network green.
- `G4-B002` and its three produced-witness debts belong to M4.
- `G4-B003` and its two produced nonzero-Z4 debts belong to M5.
- `G4-B004` belongs to M5/M6.
- M7 owns the verifier-assigned `Certified` re-proof of the three M1 structural fixtures.
- Bunny/Vase and calibrated T5 resource/quality acceptance remain later product gates.

Historical stable regression totals entering M3 are **37 events / 14 categories / 23 recurrences**. Produced-witness debt is **5**.
