# RA-213 — Adversarial re-entry of `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` (2026-11-08)

> **Partly superseded (2026-11-08):** [RA-214](Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md) §1 and §7 withdraw §4 of this record (scratch prototype and gate measurement inside a Review) and its "Claude scratch" labels. §1–§3 stand.

**Turn:** `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` re-entered (Review, Claude scratch build). **Subject:** the runtime-free [Vase producer-path Review](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Vase_Phase_Front_Producer_Path_Review_20261108.md") (`a74afce4d`), its decision ("singularity-capable regional phase front") and its successor `M6-CP3-CB102-P13-PHASE-FRONT-APPLICABILITY-RECEIPTS`. **Verdict:** the static veto proof stands. The direction, the successor and the gate attribution do not. **CB102 is withdrawn.** It also corrects two of my own RA-212 claims (§5).

**Evidence base:** product sources byte-identical to HEAD and to compiled CB101 `23e35798…` (`diff -r src include` empty). Scratch build `bld55n` (fallback BigInteger, `ninja -j2`) with env-gated instrumentation only:
- `PROBE_A4`: a per-region producer report in `build_uniform_phase_front_state`, with each `return result;` of the three producers marked by line;
- `PROBE_NOVETO`: bypasses the three singularity guards;
- `PROBE_SIDES`: a census of the network ports, source regions, A2b regions and certificates, A3 schedule per arc, cross-field axes and output meshes.

With the variables unset, the platform-digest lines of Vase, Plane, MultiFaceSeam, CloseSheets and Cylinder are **byte-identical to RA-212's**, so the instrumentation does not perturb. Scratch files are kept as `rev213/SurfaceCellTracing.a4probe.cpp` and `rev213/Acceptance.a4probe.cpp`, with tools in `rev213/tools/`. No repository product or test source is changed.

## 1. What stands

- **S1 — the veto.** `tracing_has_singularities(options)` (`SurfaceCellTracing.cpp:5529`) has no region parameter and is the first decline of all three producers on Vase (`:13336/13337`, `:14146/14148`, `:15448/15450`). This is measured: the `PROBE_A4` decline marks hit exactly those returns for the one Vase region.
- **S2 — the aggregate.** It returns `NotApplicable` with no reason when nothing was produced and `hardFeatureEdges` is empty (`:18589`). That admits the legacy fallback.
- **S3 — legacy.** The legacy fallback, its relief density (O31) and its parity breakpoint insertion are not a production path. The `normalP95` artifact is discharged (CB101, TB85).

## 2. Defects in the reviewed decision

**D1 — evidence was routed through a diagnostic CB and a TB.** The turn was assigned to the Claude scratch track. It ran no probe and deferred "region-local port ownership and post-veto eligibility" to CB102 plus a separate TB, two implementation turns (memory rule: never route evidence through a diagnostic CB/TB). One three-minute scratch run settles both:

| Vase fact (measured) | Value |
|---|---|
| Source-topology regions | **1** (2,404 faces, χ = 1, 1 boundary loop) |
| Hard-feature edges / authoritative rails | **0** / 1 (the boundary) |
| Field singularities | **1** (source vertex 357, index +¼), carrying **3 ports**, all in region 0 |
| Port → region ownership | already a typed field, `FieldAlignedSingularityPort::sourceTopologyRegion`; no containment test or receipt is needed |

CB102's per-region receipt would print one row equal to the global count. Its "mixed-region" fixture cannot reach Vase.

**D2 — wrong abstraction: DESIGN never asks A4 to build across a singularity.** DESIGN §7.2 makes ports into traces, and the faces of the certified cellular embedding become `GlobalTopologyPlan` regions. Each region carries `GlobalTopologyRegionDiscCertificate{interiorSingularityFree, boundarySingularities}`. A4 is "`RegionCellComplex` per region" (§5): the region is the **A2b disc**, and singular ports are disc corners. Measured on Vase:

| A2b/A3 (measured) | Value |
|---|---|
| A2b regions | **3**, all `proves_disc_topology`, all `interiorSingularityFree`; the singularity lies on each boundary |
| Arcs | 148 = **145 Mandatory** (boundary) + **3 Trace** (separatrices from port node 60 to rim nodes 143/144/145) |
| A3 schedule | 187 edges (preferred 188); traces 10/4/9; region sums 70/94/46, all even |

The producers' unit is the **source-topology region**:
- uniform and annulus never read A2b;
- curved-disk reads A2b only on a hard-feature region, and only when one A2b region equals the whole source region (`candidateRows != activeFaceSet → continue`, `:15535–15550`).

No producer can build a source region that A2b **partitions**. A cone always partitions its region by traces, so the veto is a symptom. A "singularity-capable phase front" over a source region re-derives what A2b already certifies. Region-scoping the veto changes nothing for Vase (one region). On a multi-region input it turns `NotApplicable` into aggregate `Rejected UnsupportedSourceSheetTopology` (`anyProduced` plus an unsupported region, `:18589–18606`), which the review did not notice.

**D3 — "removing the veto ... may silently violate" is false on Vase.** With `PROBE_NOVETO`:
- uniform declines `NotApplicable` (non-planar frame, `:13384`);
- annulus declines `NotApplicable` (χ ≠ 0, `:14230`);
- curved-disk returns **`Rejected InvalidBoundedDiskTransport`** (`:16469`), because one gauge cannot be propagated around the cone.

The run fails closed in 1.7 s at `NotProductionReady:tracing`. The veto hides no wrong output. Its real effect is to turn a typed `Rejected` into an unreasoned `NotApplicable`, and that is what admits the legacy fallback for every singular input. There is also an Amendment 19 instance: the three `surfaceCell*PhaseFrontProducerDeclined` flags are set only on the hard-feature `Rejected` path (`RemeshPipeline.cpp:13246–13252`), so Vase reports `declined=000` for producers that did decline.

**D4 — no produced census fixture consumes A3.** RA-212 also missed this. A3 counts against the actual output:

| Fixture (producer) | A3 boundary edges | Output boundary edges | Other A3 arcs |
|---|---:|---:|---|
| Plane (uniform) | 42 | **32** | — |
| MultiFaceSeam (uniform) | 48 | **32** | — |
| CloseSheets (uniform ×2) | 96 | **80** | — |
| Cylinder (annulus) | 64 | 64 | 49 cut arcs, 131 counts, **no counterpart** |

- Uniform declines on hard features and otherwise ignores A3.
- Annulus is periodic and ignores the A2a′ cut.
- Curved-disk consumes A3 only on hard-feature regions, which no census fixture exercises.
- Product validation checks shared intervals only on `HardRail` edges (`SurfaceCellTracing.cpp:9422`).

So §5 A4 ("cells conform exactly to the supplied plan") and §2.1.7 are unverified on every census fixture. A per-disc A4 for Vase must consume the shared trace-arc counts, a contract no current non-hard-feature producer honours or checks.

**D5 — A3's Vase schedule is about 2.6× too fine on the boundary.**
- A2b publishes **one Mandatory arc per source boundary edge**: 145 single-piece arcs, 142 source edges plus 3 trace-endpoint splits.
- Positivity gives each arc ≥ 1, for **164** boundary edges. The metric wants about **62** (rim length 5.4965, mean target 0.0883; source boundary edge 0.042 ≈ 0.47 × target).
- Area 1.7437 / target² ≈ **224** quads.

Any A3-conformant A4 inherits this floor. §7.4 accepts positivity's cost as "some coarse configurations ... excluded". Read as a floor at source boundary resolution, that is not "some". The arc granularity (maximal mandatory chains between topological nodes, versus per source edge) is a DESIGN interpretation the next DEFN must settle.

**D6 — Vase's full-gate expectation contradicts its own field.** Every Review, mine included, missed this.
- Vase is a disk (χ = 1) whose supplied field has one interior +¼ singularity.
- By Poincaré–Hopf the field must turn ¾ of a turn against the rim. Measured: **−270.0°**.
- Rim misalignment has median 22.5° and maximum 44°; **76 %** of rim edges are more than 15° off and 31 % more than 30°.
- Quad-mesh counting: Σ_int(4−v) + Σ_bd(3−v) = 4. With the one prescribed valence-3 vertex, every pure-quad Vase mesh needs **net +3 more irregularity**: either ≥ 3 boundary vertices of valence 2, or ≥ 3 interior valence-3 vertices the field does not prescribe.
- The evaluator's target on a smooth rim is valence 3 (angle ≥ 150°, `SurfaceMeshOptimizer.cpp:1313`). So `boundaryValenceMismatch = 0` and A2b's singularity-free disc interiors cannot both hold.
- Rim-aligned boundary quads also put the field-alignment P95 ≤ 15° gate at risk.

This makes Vase's success criterion a **requirements decision**, taken before any producer work:
- (i) calibrate boundary-valence targets from the field's boundary turning, the way `requiredSingularityValenceTargets` already prescribes interior valence;
- (ii) register Vase's expected tier as D1 `QualityRelaxed` (§2.2) with named gates;
- (iii) supply a boundary-aligned field (interior index sum 1).

## 3. Gate attribution, corrected

| Vase gate (TB85) | Floor for any DESIGN-conformant producer, this field and this A3 | Legacy-specific remainder |
|---|---|---|
| Boundary valence 248 | ≥ 3 (D6), unless (i)/(ii)/(iii) | ≥ 245 |
| Field P95 36.4° | rim band: 76 % of rim edges > 15° from the field (D6) | interior trace and completion geometry |
| Size P5 0.0035 | boundary mean ≈ 0.38 × target while D5 stands | 20× relief-seeded density (O31) |
| Singularity valence 1 | 0: three disc corners give valence 3 by construction | all |
| Angle, warpage, aspect, SJ, nonConvex | none known | all (RA-211/212 census) |

## 4. Realignment and turn sequence

**Direction:** build A4 per **A2b disc**, consuming A3 on every arc it bounds. Shared trace arcs are consumed identically by both discs, and ports are corners. This is DESIGN §5/§7.2/§7.4, not a new "singularity-capable" front. The source-region producers stay valid for their present domain, and the veto stays until the per-disc producer exists. No legacy tuning (O31, P13-n1/2/3) is scheduled.

| Step | Turn | Owner and exit |
|---|---|---|
| 57 | `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` | COMPLETE, re-entered by RA-213; decision revised; **CB102 WITHDRAWN** |
| **58 NEXT** | **`M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER`** | Review, Claude scratch. In order: (1) the Vase success criterion, D6 (i)/(ii)/(iii), with a recommendation, asking the user if a gate changes; (2) the A2b Mandatory-arc granularity (D5): measure A3 with maximal chains and amend DESIGN if adopted; (3) a scratch prototype of one per-disc A4 on Vase (A2a′ face-fragment domain, A3 breakpoints, port corners, interior fill per §4.9), measuring every gate; (4) the scope of A4→A3 conformance verification (D4) and the typed state of the four produced fixtures; (5) freeze **exact** slices: conformance check, disc domain, boundary breakpoints, fill plus registration. Each is compile-only and goes to a full-gate TB. **Exit:** frozen slices, or STOP `M6-CP3-PLAN-P13-A4-A2B-DISC-PRODUCER-STOP` with Vase registered at its measured tier |
| 44 (parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e) | unchanged |

**Implementation agent:** no turn is authorized until step 58 freezes exact patches. Do not open CB102, and do not open step 58 (probe-backed, Claude track).

## 5. Corrections to RA-212 (mine)

- RA-212 §3 called the phase-front producers "A3-consuming". They do not (D4). RA-212's option (a), "extend A4 phase-front coverage to Vase's regions", left "region" ambiguous, and the reviewed decision inherited that ambiguity. The A4 region is the A2b disc.
- RA-212 §2.5's "121 breakpoints on hard rails" are on Vase's **boundary rail**, since Vase has 0 hard-feature edges. They are not shared breakpoints. The governing rule is §5 A4 "conform exactly to the supplied plan" and §2.1.7, not §7.4's shared-breakpoint clause.

## Closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Veto sites, aggregate, mixed-region rejection, A2b and A3 censuses, post-veto dispositions, A3-versus-output counts, rim turning: all measured on the scratch build |
| Non-vacuity | Instrumentation digest-neutral on 5 fixtures; the post-veto run changes Vase's terminal (fallback → `Rejected`), so the probe discriminates |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491/491; 81 deferred; selector497/CP3 unpromoted; no runtime promotion |
| Carried | P13-e, O30b, O31 (legacy only), O32b–e, O33, O27–O29; P13-n1/2/3 legacy-only, not scheduled |
| Product/test source changed | None |
