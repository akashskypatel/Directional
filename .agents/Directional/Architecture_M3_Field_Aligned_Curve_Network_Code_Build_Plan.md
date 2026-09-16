# Architecture M3 — Field-Aligned Curve Network Code + Build Plan

**Current status (2026-08-24):** `M3-CP4ab` is **CLOSED / ACCEPTED at 316/316** on exact semantic source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, immutable TB-R3 run/job `32758293793 / 97530833220`. The checkpoint consumed **acceptance attempt 1/3** and **diagnostic 1/2** in its final reset window. M3 packages remain **34**. `PR8-R042 / M3-CP4b-R001` is resolved stable by the cumulative accepted gate. CP4c-CB1/DG1/CB2 completed and **TB-R1 is VALID RED 316/322** (accepted prefix 316/316 PASS, C1-C6 0/6). Its independent review split CP4c into **`M3-CP4c-1` (318)**, **`-2` (321)** and **`-3` (322)**, and the user abolished the attempt/diagnostic budgets and the `DG` turn type. Exact next is **`M3-CP4c-1-CB`** under corrective measures X0-X5 of `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review). The paragraphs below retain the CB-R9/CB-R10/DG-R4/DG-R5 remediation history that led to the accepted CP4ab authority; they are historical context, not current routing.

CB-R10 implemented U0-U8 and DG-R5 moved the gate to **9 PASS / 3 FAIL** with zero `InvalidNetworkBinding` — the terminal-0-cell disposition is confirmed by runtime and its subcause is **RESOLVED**. The DG-R5 independent Review then adjudicated the remainder:

- **A5 and B2 are one product validation-ordering defect.** A consumer rejects before the check that owns its input's well-formedness. A5: the stage-1 unowned check (`GlobalTopologyPlan.cpp:2660-2680`) is a *global support* check by documented design and the erased face is crossed, so `build_region_certificates` (`:2682`) dies at `χ = 0` before the canonical fragment-ownership comparison at `:2789-2801`, which already emits exactly `RegionSourceFaceUnowned` for exactly this tamper. B2: `region_orbit` (`:1166-1175`) elects the orbit whose cycle *equals* `region.boundary`; a doubled boundary matches none, so `:2441-2445` returns `RotationSystemInconsistent` with only `region` set, while `validate_single_boundary_walk` (`:1815-1864`) would return `RegionBoundaryNotSingleWalk` with `error().arc == secondWalkArc`. The χ code's own comment (`:2373-2374`) names that validation as its precondition. Third instance of the class after B3's P4 hoist. **Neither tamper may be weakened.**
- **B4 is a test-oracle arithmetic defect.** A dart-orbit face walk yields the **capped** surface's faces, so `V_g − E_g + F_g^all = χ(S) + b`; the oracle compares the all-orbits count to `χ(S)` and gets `9 − 11 + 4 = 2 ≠ 1`, and got `6 − 8 + 4 = 2 ≠ 1` before CB-R10, so it predates the terminal fix. Exterior orbits are already derived lawfully at `tests/FieldAlignedCurveNetworkTests.cpp:1647-1652`, only after the Euler check. B4 must also publish a typed failure reason.
- **U5/U6 were compiled and never executed.** Both live in `TEST(FieldAlignedCurveNetwork, ...)`, outside the frozen twelve `TEST(GlobalTopologyPlan, ...)` identities, so DG-R5 structurally could not reach them. `DG-R6` must widen the selector by exactly those two already-accepted CP3b identities, recorded as a diagnostic-only selector.

Corrective measures **V0-V8**, with V0 as a binding precondition of writing code, were implemented by CB-R11. DG-R6 then passed the frozen twelve CP4ab identities plus the two accepted CP3b U5/U6 identities at **14/14**, and TB-R3 accepted the unchanged cumulative **316/316** gate. M3 packages are **34**; CP4ab acceptance/diagnostics are **1/3, 1/2** in the final reset window. CP4ab is closed; exact next is `M3-CP4c-CB`.

Date: 2026-08-24 UTC
Status: **CP1/CP2/CP2b/CP3a/CP3b/CP4ab ACCEPTED — `M3-CP4-DEFN` is COMPLETE; CP4a/CP4b are superseded by accepted CP4ab.** Current accepted runtime authority is exact source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, immutable TB-R3 `32758293793 / 97530833220`, **316/316**. CB-R11 remains the runtime-free compile/package authority for that semantic source; DG-R6 is valid green diagnostic evidence at **14/14**; TB-R3 is the acceptance authority. M3 packages are **34**. Exact next is `M3-CP4c-1-CB` under `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review) X0-X5. Attempt/diagnostic budgets and the `DG` turn type are abolished.
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

**CP0 resolution:** `Architecture_M3_CP0_Authority_Census.md` — RETIRED at M3 CP3 closure; consolidated in `CHANGELOG.md` section 5 defines the immutable `FieldTransportAtlas`, the conservative closed/relative-boundary `FieldQuadrangulabilityCertificate`, rejection reasons, and an independent factory-free tamper oracle. Section 8 assigns the trace/decomposition composition proof to `M3-CP3b-TB`. CP1 ordinarily may not begin unless CP0 compile/package evidence and CP0-TB accept this frozen design; the user explicitly authorized the recorded CP0-only exception without accepting CP0-TB.

### 1.1.3 Retry budget — SUPERSEDED by the per-checkpoint attempt regime

Section 5 of `REORIENTATION_PLAN.md` requires a budget declared before work starts, so a stall is a
decision rather than a negotiation. The original resolution here was a hard cumulative M3 ceiling.

**That resolution is retired.** The user has authorized replacing cumulative per-milestone package
> **ABOLISHED 2026-08-25 by user authorization.** The attempt budget, the diagnostic-gate cap, the
> mandatory-review-on-third-red ratchet, and the **`DG` turn type** no longer exist. The workflow is
> `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing and mandatorily routes to review. The
> text below is retained as historical context only and must not be treated as live procedure. See
> `Future_Chat_Session_Handoff.md` "Turn workflow" and
> `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review).

ceilings with a **per-checkpoint attempt budget** for M3 and all remaining milestones. The
normative statement of the regime is `REORIENTATION_PLAN.md` **section 5 item 4**; this section
mirrors it for M3:

- **one attempt = one complete Code + Build -> immutable TB pair.** The pair is the unit; neither
  half is an attempt on its own, and a CB and its TB are never counted as two. It is consumed when
  the pair completes — when that CB's package produces a valid gate result under its TB. A created
  but unsubmitted package has consumed nothing; a harness re-run against the same package is not a
  second attempt; a TB producing no valid gate result consumes nothing. Review turns, the mandatory
  pre-package compile, diagnostic gates, documentation/control-plane commits, and a CB that stops
  before packaging consume nothing;
- **at most one un-submitted package per checkpoint at a time.** Creating a second before the first
  reaches its TB is a stop condition returning to Review;
- **diagnostic gates (`<checkpoint>-DG`) — new-contract-only, attempt-free.** Executes **only** the
  checkpoint's own new identities, never the frozen predecessor selector, so it cannot produce an
  acceptance claim. Artifact-only under the same immutability flags as any TB. The **same package**
  may serve a DG and then its acceptance TB, so a green DG plus that package's TB is **one attempt
  total**; a red DG means correcting the fixture, which requires a new package and a fresh
  pre-package compile, with no attempt consumed. It answers one question — *did these identities
  reach their intended semantic seams?* — and must name the seam each red identity reached. A green
  DG is **not acceptance**: the predecessor selector was never run, so predecessor safety is
  unproven, and no checkpoint may be advanced, closed, or unblocked on DG evidence. **Cap 2 per
  checkpoint per attempt window**, each followed by an acceptance attempt or a Review;
- **3 attempts per checkpoint.** A third red TB forces a **mandatory independent Review**
  before a fourth attempt;
- a completed mandatory review restores 3 fresh attempts, under a **ratchet**: the second mandatory
  review on one checkpoint (6 red attempts) must rescope, amend the design, or recommend stopping —
  it may not re-authorize the same approach unchanged; the third (9 red attempts) is a hard stop
  requiring explicit user authorization;
- **cumulative cost is reported, not gated.** Packages consumed per milestone stay recorded in
  `CHANGELOG.md` and the handoff so a runaway milestone is visible — diagnostic packages included —
  but no turn is blocked on the count and no cumulative-ceiling amendment is needed again for M3-M8.
  Report attempts and packages as separate numbers; under the pair definition they are no longer the
  same quantity.

**Why.** Section 1.1.1 already established that the M1/M2 cost calibration came entirely from
cutovers and does not transfer to new-capability work. M3's history bore that out: the ceiling was
amended under pressure every time it bound — 11, then `5 -> 6`, `6 -> 7`, `11 -> 12`, and a pending
request for `12 -> 13`. A stop rule renegotiated at each firing costs a turn and changes no
decision. The per-checkpoint rule keeps a genuine non-negotiable trigger and ties it to the
checkpoint that is actually failing rather than to a shared pool that unrelated checkpoints also
draw from. Applied to CP1's history it would have forced the mandatory review at three red
attempts rather than six.

M3 has produced **21 packages**; CP3b is the latest accepted runtime authority at source/package `611b3f8f3926792baee9d1078d6677d22006a6c4 / 9456073195`, immutable TB `32515222447 / 96875297990`, **304/304**. Cumulative package count carries no authorization weight.

The regime is now working as intended. CP3a and CP3b each closed on **acceptance attempt 1 of 3** — against CP1's six and CP2b's six. The difference is the diagnostic gate: CP3a's red 2/6 diagnostic bought a full round of semantic evidence and a corrective build for **zero** acceptance attempts, and CP3b needed no diagnostic at all. Keep allocating diagnostics to checkpoints that introduce a new witness.

`M3-FULL` remains omitted and the final CP4 gate remains the cumulative M3 exit gate.

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

The frozen construction is in `Architecture_M3_CP0_Authority_Census.md` — RETIRED at M3 CP3 closure; consolidated in `CHANGELOG.md` section 5. The atlas binds exact A0 source authority, reciprocal typed traversable adjacency, explicit nontraversable boundary/feature edges, the complete local/boundary/`2g` cycle basis, exact integer lifts/compositions, typed singularity facts, component topology, and a checkable certificate. Closed components use only the documented conservative sufficient holonomy witness; the gcd condition is not claimed necessary. Boundary components require a constructive relative cut-to-disk/boundary-turn witness. Anything not positively established is `FieldTransportUnestablished`.

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
| `M3-CP4-CB` | **SUPERSEDED.** Split into `M3-CP4-DEFN` (planning, complete), `M3-CP4a` (topology derivation and region product, gate 310), `M3-CP4b` (disc proof and the unestablished-transport negative, gate 316), and `M3-CP4c` (representative witnesses and the M3 exit gate, gate 322). Implementation authority is `Architecture_M3_CP4_DEFN_Frozen_Definitions.md`. | see 4A.3 and the DEFN document |
| `M3-FULL-CB` | **Omitted by default.** the final CP4 gate (`M3-CP4c`) is the cumulative M3 exit gate, so a separate full package would only repeat the same semantics. It may exist only after an explicit plan update and user authorization, and may not add a semantic domain or run vacuously. | `M3-FULL-TB` only if separately authorized |

The frozen CP0 census fixes the first CP1 vertical slice at ten files: three new atlas/oracle files and seven build/ID/tracing/pipeline registrations listed in census section 7. It may not silently enlarge M3 into M4+ work. Any newly required file or semantic domain stops CP1 for a census/plan update before implementation.

## 4A. Remaining checkpoint decomposition — amended at CP3 closure

Re-reviewed at CP3 closure, superseding the CP2-closure amendment. The section 4 table remains correct
in kind for CP0–CP3b, all of which are now accepted. **Its single `M3-CP4-CB` row is superseded by
section 4A.3**, which splits CP4 into a planning turn plus three implementation checkpoints.

### 4A.1 CP2b, CP3a, CP3b — closed; consolidated elsewhere

**CP2b, CP3a, and CP3b are CLOSED / ACCEPTED.** A2a is complete. Their task lists, corrective arcs, and
per-attempt histories are consolidated in `M3_CP2b_Closure_Record.md` and `M3_CP3_Closure_Record.md`;
exact per-turn evidence is in `CHANGELOG.md`. This section retains only what still binds CP4.

**Two obligations from section 4A.2 were never assigned an owning identity and transfer to CP4** —
rotation-system / face-walk consistency, and crossing tamper. `M3_CP3_Closure_Record.md` section 6 states
exactly what is and is not proven. They are carried in the CP4 task list below.

**A binding instruction in the retired CP3a task list was false and must not be reused.** It directed
reuse of the accepted CP2b skew-fan witness on the grounds that a green gate had proven it
non-degenerate. In a one-ring fan every edge opposite the singular vertex is a boundary edge, so the
multi-face-traversal requirement was unsatisfiable on that mesh by construction. A witness proven
adequate for one checkpoint's contract is not thereby adequate for the next one's. CP4 authors its
witnesses against **CP4's** requirements and proves the precondition inside the fixture, as the accepted
CP3a two-ring fixture now does.

### 4A.2 CP3b — closed

CP3b's task list is discharged and consolidated in `M3_CP3_Closure_Record.md`. Two of its six prose
obligations were never assigned an owning identity and transfer to CP4 (section 4A.3 items D3 and D6).

### 4A.3 CP4 — decomposed into four turns

Reviewed at CP3 closure. **The single-checkpoint CP4 in section 4's table is oversized and is replaced
by the decomposition below.** The reasoning is the same test this project has applied since M1: a
checkpoint should carry one independently testable semantic domain. CP4 as previously written carried
three (topology derivation, region product, disc proof), plus a catastrophic-precondition wiring task,
plus production of two representative witnesses, plus the cumulative ten-criterion exit gate. Every
prior M3 checkpoint that bundled two domains had to split — CP3 into CP3a/CP3b by plan, CP2b out of
CP3a mid-census at real cost. Splitting now is cheaper than splitting later, and under the
per-checkpoint attempt regime it also gives each domain its own 3-attempt budget and its own
mandatory-review ratchet, tied to the domain that is actually failing.

#### `M3-CP4-DEFN` — COMPLETE

Discharged 2026-08-21. All seven required items are frozen in
**`Architecture_M3_CP4_DEFN_Frozen_Definitions.md`**, which is the implementation authority for CP4 and
supersedes the task sketches below wherever the two differ. Its substantive outcomes:

- the embedded graph whose faces are regions is defined (mandatory arcs plus event-cut trace arcs), and
  the **rotation system is reclassified as a CP4a prerequisite** rather than CP4c carried debt — faces
  cannot be computed without it;
- the disc proof is frozen as single boundary walk + interior connectivity + `χ = 1`, claimed
  **necessary and sufficient** with the reasoning stated, with the no-interior-singularity requirement
  separated out as a distinct field-regularity condition rather than folded into the topological claim;
- thirteen rejection reasons, each with named locus fields;
- a new `NetworkRegionId` domain, because the existing `TopologyRegionId` is A0 *source* region
  authority and must not acquire a second meaning;
- identity names and gates frozen at **CP4a 310, CP4b 316, CP4c 322**, with a criterion→identity map;
- **`G4-B001` is resolved as a non-collision** — see section 8 below;
- **B6 is rescoped**: `FieldTransportUnestablished` is a D4 disposition and D0–D4 is M7 work, so M3's
  equivalent is the structural proof that no plan can be produced from an unestablished certificate.

The original scope statement follows for provenance.

Planning/Review only. No product, test, build, package, or runtime; consumes no attempt.

Section 1.1.2 item 1 of this plan records that building a checkpoint against an *undefined* certificate
is the criterion-5 shape and that M1 paid for it twice. CP0 discharged that for the A1
`FieldQuadrangulabilityCertificate` by freezing its construction, its rejection reasons, and an
independent factory-free tamper oracle in the census before CP1 began. **There is no equivalent frozen
definition for the per-region disc-topology proof.** Section 2 criterion 6 and section 3 A2b both
require one; nothing defines it. That is the same unpatched gap, and CP4 must not start code against it.

DEFN must freeze, in writing, before `M3-CP4a-CB`:

1. The **disc-topology proof construction** — what is checked, on what typed inputs, and what
   constitutes a positive proof. State plainly which conditions are sufficient and which are also
   necessary; the A1 certificate's conservative-sufficient framing is the precedent to follow, not to
   quietly exceed.
2. The **typed rejection reasons** for a failed proof, exhaustively, each naming its locus. CP2b's
   diagnosability collapse — 21 nullopt sites folded into two opaque codes — cost three turns of
   review to unwind. Name the loci at design time.
3. An **independent, factory-free tamper oracle** for the proof, structurally independent of the
   production validator, as CP3b's composition oracle is.
4. The **region product's typed ID domain** and its ownership: one writer, no parallel raw
   representation, no proximity or row-number identity.
5. The **provenance of the two representative witnesses** — where the torus-style and mechanical-style
   meshes come from, and what preconditions each fixture asserts about itself at runtime. See the
   witness collision below; this is the item most likely to be underestimated.
6. The **exact frozen identity count and names for each of CP4a, CP4b, and CP4c**, reconciled
   item-by-item against the task lists below. `M3_CP3_Closure_Record.md` section 6 records what
   happens when a plan's prose obligations and its frozen selector are not reconciled: two obligations
   silently ended up with no owning identity and no proof.

### 4A.3a `M3-CP4ab` — CP4a reopened and merged with CP4b — CURRENT

Authored by `M3-CP4b-MANDATORY-INDEPENDENT-REVIEW` after CP4b's third valid RED. The full finding is
Part A of `Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md` — **RETIRED at CP4ab closure into
`M3_CP4ab_Closure_Record.md`; its binding content is inlined in DEFN amendments 1-3** — and this section is
the forward task list. The `M3-CP4a` and `M3-CP4b` sections below are retained for provenance and are
**superseded**.

**Why the split was wrong.** Region derivation and the disc proof are not independent semantic domains.
The proof is a predicate *on* the regions, and the regions are only meaningful if the proof can
adjudicate them. Splitting them placed an accepted predecessor between the two halves; the
accepted-predecessor rule then obliged CP4b to preserve a partition that was itself wrong, and three
attempts were spent failing to do something that should not have been done. `M3-CP4-DEFN` made this
split, and this corrects it.

**What actually went wrong.** Accepted CP4a assigned source faces to regions by container-order seeding
with an arbitrary unclaimed-face fallback, then BFS hop-count nearest-seed-wins. That is three separate
prohibitions in `REORIENTATION_PLAN.md` section 2.1 and this plan's section 7 — order-based ownership
selection, arbitrary subset search, and proximity as graph identity. It went green because a flood fill
is a total partition by construction, and `CoversEverySourceFaceExactlyOnce` asserts only totality,
never that a face's owner is the region enclosing it. That test cannot fail for any input. CP4b's R1/R2
tried to derive ownership honestly from the network cut, which is correct, and were scored against that
manufactured baseline.

**Authority position.** Latest accepted runtime authority reverts to **CP3b, 304/304**. CP4a's
`32540801792 / 96950302793` at 310/310 remains valid evidence of what it ran; it is no longer accepted
authority for region ownership. The 304 predecessor is untouched and stayed green in all three CP4b
gates.

**Gate: 316 = accepted 304 + A1–A6 + B1–B6.** Unchanged in count and in identity names — nothing is
removed to obtain green. A1 and A3 are rewritten to be *falsifiable*, which strengthens the selector.

#### Corrective measures — binding, K1 first

1. **K1 — split the collapsed error code before changing any semantics.** CP4b R2 emits
   `RegionCoversNoSourceFace` at **seven sites for seven distinct conditions**, which is why three
   immutable gates localized nothing and why the R2 report itself lists five subcases it cannot
   distinguish. This is CP2b's diagnosability collapse repeating, against a DEFN section 6.3 that had
   already frozen thirteen locus-bearing codes to prevent it — including
   `RegionSourceFaceUnowned`, `RegionInteriorDisconnected`, `RegionBoundaryArcNotOwnedByNetwork`, and
   `RotationSystemInconsistent`, all available and unused. Land K1 **alone**, with no semantic change,
   so the first diagnostic gate is a pure localization instrument. Every negative asserts the exact
   code; `ASSERT_FALSE(built)` alone is not evidence.
2. **K2 — freeze the ownership contract in writing before implementing it.** One sentence naming which
   source faces a region owns and why, derived from the network cut and nothing else. Prohibited
   inputs, restated so they cannot re-enter: container order, map order, BFS or any distance, arbitrary
   unclaimed-face fallback, A0 `SourceComponentId`/`TopologyRegionId` labels, any proximity measure.
   A region that cannot be given an exact owner is a **typed rejection**, never a fallback.
3. **K3 — remove the component/face count equality precondition.** R2 requires
   `cutComponents.size() == drafts.size()` and aborts construction otherwise. Faces of an embedded
   graph equal complement components only for a cellular embedding of a connected graph — an annular
   face breaks it, and an annular face is exactly what B2 exists to detect. The construction cannot
   require every region to already be a disc while the checkpoint's purpose is to prove disc-ness. A
   count mismatch is a typed outcome with its own code, not a construction abort.
4. **K4 — make A1 and A3 falsifiable and prove they are.** A3 must assert that each source face is
   owned by the region whose boundary **encloses** it, not merely that ownership is total. Both need a
   negative that fails if the ownership rule is replaced by a flood fill. **If the superseded CP4a
   implementation would still pass the rewritten test, the test is still vacuous and is not evidence.**
5. **K5 — do not weaken B1–B5 to reach green.** The disc proof frozen in DEFN section 6 is unchanged
   and remains necessary-and-sufficient. A witness region that legitimately is not a disc must produce
   the typed rejection B2/B3 assert, not a relaxed proof.
6. **K6 — `PR8-R042` closes only on evidence.** It is `AUTHORITY_DOMAIN_CONFLATION` and it is real:
   CP4b conflated "component of the cut" with "face of the graph." It resolves when a valid immutable
   gate shows the five regressed identities green **under the corrected, falsifiable A1/A3**.
7. **K7 — the durable lesson, recorded before implementation.** An immutable green gate certifies that
   the identities in the selector passed. It does not certify that they were capable of failing.

#### Routing correction and the representational finding — `M3-CP4ab-K5-ROUTING-REVIEW`, 2026-08-22

Binding: Part A of `M3_CP4ab_Closure_Record.md` — **RETIRED at CP4ab
closure; its binding content is inlined in DEFN amendment 4.** Decision **Option C**,
an ordered K2R/K3R bundle preceded by one measurement gate.

**Routing corrected.** `RegionCutComponentCountDeficit` routes to **K3, not K5**. The `-> K5` table was
authored inside the K1 turn, which was scoped to diagnosability with no semantic change; assigning
corrective-measure ownership is a planning act and cannot override the binding mandatory Review.
`M3-CP4ab-CB-R1` was right to stop, and stopping consumed nothing. **Durable rule: an implementation
turn may name and localize conditions but may not assign or re-assign corrective families; any routing
table it produces is a hypothesis for the next Review, never a frozen input.**

**The representational finding, which goes beyond F5.** `network_cut_edges(...)` cuts the edges a trace
*crosses*, while ownership is a set of whole `SourceFaceTopologyKey` values — but trace arcs run through
face interiors and a source face is atomic. On the accepted two-ring witness, traces leave the centre
singularity through the edge *opposite* it, so the spoke edges are never cut, the entire fan stays one
cut component, and the rotation walk correctly reports one orbit per sector. `cutComponents.size() ==
drafts.size()` is therefore **unsatisfiable on any witness carrying a singularity port** — not a tuning
accident. That is why three CP4b attempts, the DG, and CB-R1 all stopped in the same place.

**Resolution — fragment ownership.** A region owns face fragments keyed `(SourceFaceTopologyKey, orbit)`:
the portion of one source face lying in one graph face. A face crossed by no trace arc has exactly one
fragment. Every source face's fragments partition it, a **stronger** exact-once rule than whole-face
ownership. This is a derived ownership refinement, not a new mesh — no geometry, no added vertices,
`TriMesh` untouched, `RemeshPipeline.cpp` still frozen. **DEFN section 4.4 is amended.** B1–B5 are
unchanged in content and **B2 becomes reachable for the first time**: a two-walk region now reaches
`validate_single_boundary_walk(...)` instead of aborting construction six hundred lines earlier.

**K2R/K3R supersede the K5 route; K1, K4, K5, K6, K7 are unchanged.** K2R freezes the fragment ownership
contract in writing with the K2 prohibited inputs restated verbatim. K3R deletes both cardinality aborts,
builds fragments from `walk.orbitByDart`, makes orbits primary, re-points
`RegionCutComponentCountDeficit` at the genuine defect (a fragment set that does not partition its face),
and leaves `network_cut_edges(...)` as interior-connectivity evidence rather than the ownership oracle.

**Measure before implementing.** `M3-CP4ab-DG-R1` spends diagnostic 2 of 2 on the existing package
`9478766432` and must emit `drafts.size()`, `cutComponents.size()`, the per-orbit/per-component
breakdown, whether all singular-fan faces landed in one cut component, and the exterior-orbit count. If
the fan did not collapse, the finding is falsified and the work returns to Review. Three CP4b attempts
were spent implementing without measuring; the last diagnostic is spent on the two numbers.

**Falsifiable prediction.** After K2R/K3R the ten identities must stop reporting a count-deficit code —
expect green, or a B1/B2 typed rejection naming a specific region. A third count-deficit appearance
falsifies this finding and returns to Review rather than being patched.

#### Turn sequence

| Turn | Scope | Attempt cost |
|---|---|---|
| `M3-CP4ab-CB` | K1 error-code split, no semantic change | **done** — package `9478766432` |
| `M3-CP4ab-DG` | attempt-free localization | **done** — all ten reds at `RegionCutComponentCountDeficit` |
| `M3-CP4ab-CB-R1` | K5-only edit | **stopped correctly** at the pre-mutation proof; no bytes, no package |
| `M3-CP4ab-K5-ROUTING-REVIEW` | routing correction and representational finding | **done** — no attempt, no diagnostic |
| `M3-CP4ab-DG-R1` | measurement confirming fragment-ownership need | **done** — diagnostic 2 of 2; no attempt |
| `M3-CP4ab-CB-R2` | K2R, then K3R, then K4 | **done** — runtime-free package |
| `M3-CP4ab-TB-R1` | historical immutable acceptance at 316 | **307/316**, then user-reset window to 0/3 |
| `M3-CP4ab-TB-R1-INDEPENDENT-REVIEW` | fragment-complex definition N1-N6 | **done** — no attempt/diagnostic |
| `M3-CP4ab-CB-R3` | N1-N4 fragment-disc/B4 completion | **done** — package `9496035583` |
| `M3-CP4ab-TB-R2` | immutable 316 acceptance | **306/316**, reset-window attempt 1 of 3 |
| `M3-CP4ab-TB-R2-INDEPENDENT-REVIEW` | historical Euler-definition/topology + B3 ordering adjudication | no attempt; no diagnostic |
| `M3-CP4ab-TB-R3` | immutable 316 acceptance | **316/316 ACCEPTED** — attempt 1 of 3 |

#### Budget

The first mandatory review on this work restores three attempts; they belong to `M3-CP4ab`, which
starts at **attempt 1 of 3** with **2 diagnostic gates**. Under the ratchet, a second mandatory review
must rescope, amend the design, or recommend stopping, and a third is a hard stop requiring explicit
user authorization. CP4b's three consumed attempts remain in the record as historical cost. `M3-CP4c`
is split into `-1`/`-2`/`-3` by its TB-R1 review; budgets are abolished.

#### `M3-CP4a` — SUPERSEDED (retained for provenance)

A1. Derive/select the global network topology from the accepted CP3b event graph. Consume it; do not
    reconstruct, weaken, or repair accepted CP3a/CP3b authority.
A2. Publish `GlobalTopologyPlan` regions as closed, immutable, typed products with the ID domain frozen
    by DEFN.
A3. Prove **mandatory-topology preservation**: source boundaries and hard features survive network
    selection and simplification. Reduction may remove redundant traces; it may not alter required
    singularity index/port topology or mandatory boundary/feature edges.
A4. Order/representation invariance: region enumeration order, source-face row order, and container
    order do not change the published plan or its semantic digest.
A5. Equivalent-Z4 relabel invariance, inherited unbroken from CP2b and CP3a. Do not reintroduce a gauge
    dependence on top of an accepted gauge-invariant chain — CP3a already had to split one digest that
    did exactly that.
A6. Publish the **rotation system** (cyclic arc order per node) from exact fan-walk data, never from a
    floating-point angle comparison. It is the input region derivation cannot proceed without.

**Not in CP4a:** disc proof, `FieldTransportUnestablished` wiring, representative witnesses.

**SUPERSEDED — merged into `M3-CP4ab`, section 4A.3a.** A1 and A3 as shipped were unfalsifiable and are rewritten under corrective measure K4.

#### `M3-CP4b` — SUPERSEDED (retained for provenance)

B1. Prove disc topology per emitted region, exactly as frozen by DEFN. A failed proof is a **typed
    rejection**, never a repair and never a downgrade.
B2. Regions explicitly typed as non-disc are representable as such; silence is not a proof.
B3. Tamper negatives against the proof, via the DEFN oracle. Each negative must reach its intended
    seam — a negative that fails earlier proves nothing, which is the failure mode CP2b's diagnostic
    gates existed to expose.
B4. **Rescoped at DEFN.** `FieldTransportUnestablished` is a D4 disposition and the D0-D4 tier is M7
    work; building it in M3 would repeat the M1 criterion-5 defect. The M3 equivalent is structural and
    negative: prove no `GlobalTopologyPlan` can be produced from an atlas whose certificate is not
    `established()`, and that no degraded producer or local substitution routes around it. The atlas
    already rejects with `FieldAtlasBuildErrorCode::UnestablishedAdmissibility`. See DEFN section 7.4.

**SUPERSEDED — merged into `M3-CP4ab`, section 4A.3a.** B1-B6 are unchanged in name and content; corrective measure K5 forbids weakening them.

#### `M3-CP4c` — the cumulative M3 exit gate

> **Superseded as routing, retained as scope.** This subsection states *what* CP4c must deliver. It is
> **not** a task decomposition and was never numbered "4A.3c" — no such section has ever existed in this
> document, though `TODO.md`, the handoff, the TB-R3 report, and the CP4ab closure record all pointed at
> that name. The binding decomposition is **`M3_CP4c_Consolidated_Record.md`**, which also
> records the finding that resizes CP4c: **`GlobalTopologyPlan` is constructed nowhere in
> `src/pipeline/RemeshPipeline.cpp`**, so C1/C2's "…ThroughProductionEntryPath" requires production
> wiring before any witness can be written.

C1. Carry the full retained predecessor selector plus every accepted CP1/CP2/CP2b/CP3a/CP3b/CP4a/CP4b
    contract.
C2. Two **representative topology witnesses through the production M3 entry path** — one
    periodic/torus-style, one feature-bearing mechanical-style — with provenance and self-asserted
    preconditions as frozen by DEFN.
C3. Prove all ten section 2 acceptance criteria on **one** immutable package.
D3. **Carried from CP3b:** candidate rotation-system / face-walk *consistency proof* on produced
    witnesses (identity C3). Note the DEFN correction: **deriving** the rotation system is a CP4a
    prerequisite (identity A2), not CP4c debt — region faces cannot be computed without it. C3 proves
    it; A2 publishes it. Section 2 criterion 5 owns the proof.
D6. **Carried from CP3b:** crossing tamper. `RejectsContactCrossingEventOrIncidenceTamper` covers
    missing-contact and incidence-role tamper; no case tampers a `TraceIntersection`. Section 2
    criterion 9 owns it.

Gate: **322 = 316 + 6 — the M3 exit gate.** Identity names C1-C6 are frozen in the DEFN document section 7.3, and its section 7.5 maps every section 2 criterion to its owning identity. `M3-FULL` remains omitted.

**Not in any CP4 turn:** M4 positive rail scheduling, M5 quotient/chart work, and any production-quality
or resource claim.

#### The witness collision — RESOLVED at DEFN: there is no collision

`G4-B001 / PR8-R034 / G4-R007` fires at the **completion/materializer stage**, downstream of A2b.
`Regression_Root_Cause_Tracker.md:1043` classifies it `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; `:1045`
records "direct torus 0/3 with 241 `LocalSheetMismatch` issues **after 192 quads**"; `:734` locates the
cause in `classify_source_surface_labels(...)` promoting a hard rail into `IsolationSheetId` authority,
which `close_completion_lineage_source_authority(...)` then rejects. The torus reaches trace-network
authority intact — `make_torus_pipeline_fixture()` in `tests/SurfaceCellTransitionQuotientTests.cpp:512`
requires `hasTraceNetwork` and calls `require_produced(...)`, both of which throw on failure.

So CP4c's torus witness stops well before the `G4-B001` seam. It must assert regions and disc proofs
and stop there, must not run to final quad emission, and must claim no `G4-B001` progress. Section 8's
prohibition stands unchanged and `G4-B001` remains an open blocker owned later. Full reasoning is in
`Architecture_M3_CP4_DEFN_Frozen_Definitions.md` section 9.

`G4-B002`'s three produced-witness debts stay with M4 and `G4-B003`'s two stay with M5. M3 discharges
neither.

### 4A.4 Budget under the current regime

`M3-CP4ab` is now **CLOSED / ACCEPTED at 316/316**. Budget bookkeeping in this section is **historical only** — attempt budgets, diagnostic caps, the review ratchet, and the `DG` turn type were abolished on 2026-08-25; the workflow is `CB → TB → (red) → REVIEW+PLAN → CB`.

Closed: CP2b at 292/292 (restored attempt 3), CP3a at 298/298 (attempt 1), CP3b at 304/304 (attempt 1).
Cumulative M3 cost is **21 packages**, reported only.

**Allocate both diagnostic gates to `M3-CP4ab`, and one to CP4c.** Both introduce new witnesses, and the diagnostic
gate is the control that has actually paid for itself: CP3a's red 2/6 diagnostic bought a full round of
semantic evidence and a corrective build for zero acceptance attempts, and CP3a then closed on attempt
1 of 3.

### 4A.5 Trajectory check

Aligned with `DESIGN.md` A1/A2a/A2b and `REORIENTATION_PLAN.md` section 7. **A1 and A2a are complete and
accepted**: A1 transport authority (CP1), branch/interval/port-attachment authority (CP2b),
branch-consistent candidate traversal (CP3a), and typed event incidence with independent composition
validation (CP3b). The `DESIGN.md` composition obligation assigned to `M3-CP3b-TB` is discharged.

**A2b is all that remains**, delivered by the four CP4 turns above. No CP4 turn implements M4+ work and
no CP4 turn repairs an accepted upstream product. The two unowned CP3b obligations are carried into
CP4c against named section 2 criteria, so nothing is dropped by the split.
## 5. Completed checkpoints — consolidated elsewhere

This plan is forward-looking. Completed checkpoint history has been moved out of it:

- **CP0, CP1, CP2** — `M3_CP2_Closure_Record.md`.
- **CP2b** — `M3_CP2b_Closure_Record.md`.
- **CP3a, CP3b** — `M3_CP3_Closure_Record.md`, including the two CP3b obligations that carry into CP4.
- **CP4ab** — `M3_CP4ab_Closure_Record.md`, accepted at the cumulative 316 gate.

Each closure record holds that checkpoint's closure verification, what it delivered and did not claim,
trajectory, cost, root causes, and durable lessons.
- **Exact per-turn evidence** — source SHAs, run/job identities, artifact SHA-256 digests, build
  action counts, package manifests, and immutability flags remain newest-first in `CHANGELOG.md`.
- **Regression history** — `Regression_Root_Cause_Tracker.md` owns resolved `PR8-R038`/`PR8-R039` and resolved stable CP2b history `PR8-R040 / M3-CP2b-R001` plus `PR8-R041 / M3-CP2b-R002`; current stable accounting is **42 / 14 / 28**.
- **Durable lessons** — `Future_Chat_Session_Handoff.md`, resume-critical lessons section.

Current accepted runtime authority is CP4ab source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, immutable TB-R3 `32758293793 / 97530833220`, **316/316**. CP4ab is closed. CP4c-TB-R1 is VALID RED 316/322 and its review split CP4c into **318 / 321 / 322**; exact next is `M3-CP4c-1-CB` under `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review) X0-X5. Attempt/diagnostic budgets and the `DG` turn type are abolished. CP4 implementation authority remains `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` as amended, together with the binding independent-review decisions referenced by the handoff. Historical corrected findings remain historical and must not be reused as live specification; the current binding state is recorded in `Future_Chat_Session_Handoff.md`.

## 6. Test strategy to freeze during CP0

M3 evidence must eventually cover the `DESIGN.md` curve-network matrix:

- **Positive:** all singularity ports owned exactly once; traces terminate at typed events; mandatory source boundary/hard-feature edges retained; disc topology derived.
- **Negative/tamper:** unowned/duplicate port, branch-transport tamper, explicit crossing/contact inconsistency, silent regular-face termination, mandatory-edge deletion, non-disc region proof mismatch.
- **Metamorphic/property:** tracing-order permutation, start-port permutation, source-face row permutation, equivalent quarter-turn branch relabeling.
- **Independent/representative at M3 scope:** at least one periodic/torus-style topology witness and one feature-bearing mechanical-style topology witness through the production M3 entry path. These are M3 topology-network evidence only and do not substitute for later Bunny/Vase product/resource acceptance.

Every acceptance witness must prove its precondition before its target assertion becomes required-green evidence.

`M3-CP3b-TB` owned the composition proof and is **accepted**. Its independent graph sweep checks earliest declared contact, absence of undeclared interior crossings, exactly one typed terminal owner per endpoint, no silent regular-interior stop, and exactly-once port consumption; order-invariance and the contact/event/incidence tamper negatives are proven by sibling identities. **Rotation-system/face-walk consistency and crossing tamper are not proven** and carry into CP4c as items D3 and D6 of section 4A.3. CP4 separately owns selected `GlobalTopologyPlan` regions and final disc certificates.

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

- `G4-B001 / PR8-R034 / G4-R007` remains a later direct-torus product blocker unless M3 evidence independently proves its exact owning seam; M3 must not claim closure by unrelated network green. **DEFN checked this against the tracker and found no collision with CP4c's torus witness:** `G4-B001` fires at the completion/materializer stage, downstream of A2b, and CP4c's witnesses stop at regions and disc proofs. See the DEFN document section 9.
- `G4-B002` and its three produced-witness debts belong to M4.
- `G4-B003` and its two produced nonzero-Z4 debts belong to M5.
- `G4-B004` belongs to M5/M6.
- M7 owns the verifier-assigned `Certified` re-proof of the three M1 structural fixtures.
- Bunny/Vase and calibrated T5 resource/quality acceptance remain later product gates.

Historical stable regression totals entering M3 are **37 events / 14 categories / 23 recurrences**. Produced-witness debt is **5**.
