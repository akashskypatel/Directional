# Directional — Orientation

## DURABLE — DO NOT DELETE, AND UPDATE AT EVERY REVIEW TURN

**This document is durable project authority.** It may be corrected or extended. It must **not** be deleted,
renamed away, collapsed into another document, or replaced by a summary without explicit user authorization.

**Every REVIEW turn must update this file before closing**, so a cold-start agent is never more than one review
behind. The required update covers:

1. the **currency line** below — turn ID and date;
2. **§3 Where we are** — selector authority, stable accounting, checkpoint status;
3. **§4 the witness table** — if any witness's state changed;
4. **§7 Open problems** — re-ordered by current priority, with resolved items removed;
5. **§8 Recurring defect patterns** — if the turn found a new pattern or a new instance of an existing one.

**Keep it substance-only.** No turn workflow, no policies, no checklists, no transport or connector mechanics.
That boundary is what makes this document cheap enough to read first, and it is the reason it exists.

Authority for this rule: user instruction, preserved in `M3_CP4c_Consolidated_Record.md` §6.6 and the
2026-08-29 `M3-CP4c-2-TB-X2-R7-REV` changelog entry.

---

**Purpose.** Get an agent from cold start to useful in one read. This is *substance only*: what the system is,
where it stands, what is broken, and where to look. It deliberately contains **no procedural information** — no
turn workflow, no policies, no checklists, no transport or connector mechanics. Those live in
`Future_Chat_Session_Handoff.md`, `AGENT_POLICY.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`,
`TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md`.

**Currency.** Last updated 2026-08-29 at `M3-CP4c-2-DEFN-R2`; exact next is the bounded diagnostic
`M3-CP4c-2-CB6` under measures AF0–AF4 with AF9 prohibitions, then `CB7` under AG1–AG6. If the head commit is far
ahead, trust
`TODO.md`'s current-focus block and `Future_Chat_Session_Handoff.md`'s next-turn block over this file's
"where we are" section; the architecture and recurring-defect sections age much more slowly.

---

## 1. What the project is

A hard fork of **libdirectional** adding a **quad-remeshing pipeline** built on exact arithmetic. Given a
triangle mesh and a cross field, it produces a pure-quad mesh carrying an explicit, independently verified
guarantee. The distinguishing commitments:

- **Exact arithmetic, no tolerances** in topological decisions. `FieldExactRational` / GMP-backed integers.
  A predicate that needs an epsilon is treated as a design defect, not a tuning problem.
- **Single-writer authority.** Every datum has exactly one producer. Consumers get `const` views or typed IDs.
  Products are immutable once produced; a later stage may not repair an earlier stage's output.
- **Derived, not assumed.** Regions, ports, terminations and certificates are computed and certified, never
  asserted by fiat.
- **Typed failure over silent degradation.** Every stage fails closed with a typed error and a locus.

`DESIGN.md` is the normative architecture. `ROADMAP.md` maps checkpoints to the production-ready exit
(`M8-CP3`).

## 2. Pipeline stages

| Stage | Product | One-line contract |
|---|---|---|
| A0 | `SourceAuthoritySnapshot` | exact source support, typed IDs, topology regions |
| A1 | `FieldTransportAtlas` | per-face cross frame + typed transport across every interior edge; singularities |
| A2a | `FieldAlignedCurveNetwork` | traces from singularity ports + mandatory edges from features/boundaries |
| **A2a′** | **`SurfaceCutGraph`** | **added cuts guaranteeing the network's complement is a disjoint union of discs** |
| A2b | `GlobalTopologyPlan` | regions as faces of the embedded graph, with disc proofs |
| A3 | `GlobalConformityPlan` | — |
| A4 | `RegionCellComplex` per region | — |
| A5 | `SurfaceOccurrenceComplex` | — |
| A6 | `QuotientCertificate` + quad mesh | — |
| A7 | source-attached vertex geometry | — |
| A8 | `VerificationReport` + `OutputDisposition` | independent verifier assigns the tier |
| A9 | logs and public result | — |

A2a′ is new in CP4c-2 and is the current work. Everything from A3 onward is unreached.

**Disposition ladder** (assigned by A8, never asserted by a producer; a run only moves down):
`D0 Certified` → `D1 QualityRelaxed` → `D2 LocallyDegraded` → `D3 Partial` → `D4 DiagnosticOnly`.

## 3. Where we are

**Accepted authority: CP4c-1 at 355/355.** CP4c-0, CP4c-0b and CP4c-1 are CLOSED / ACCEPTED. The accepted
selector is cumulative and each checkpoint's prefix is byte-identical to its predecessor, so `first_red_ordinal`
is comparable across the whole arc.

| selector | SHA-256 |
|---|---|
| accepted 316 prefix | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| accepted 346 prefix | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| accepted 353 prefix | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| accepted 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| CP4c-2 357 prefix (superseded as a gate; retained) | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| CP4c-2 358 (**withdrawn** as a gate; retained) | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |
| **CP4c-2 gate 361 (frozen at DEFN-R2, unselected)** | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |

**All seven values are authority.** The first six were recomputed from bytes at `M3-CP4c-2-TB-X2-R7-REV`,
independently re-derived at `M3-CP4c-2-DOC-R1`, and re-verified at the second `R7-REV`; the 361 value was computed
at `DEFN-R2` when the file was created. The 316/346/353/355 rows derive from
`Architecture_M3_CP4c1_Required_Green_Selector.txt` — `head -316`, `head -346`, `head -353`, and the whole file;
357 and 358 from their own candidate files; 361 from
`Architecture_M3_CP4c2_Required_Green_Selector_361.txt`, whose `head -355` and `head -357` reproduce the accepted
355 and candidate 357 hashes exactly. **Recompute rather than copy**, validate every expected digest as exactly 64
lowercase hex at authoring, and never write one as `PREFIX…SUFFIX` where a value is expected: `PR8` orchestration
defect `R7-ORCH-01` was four hashes expanded back to full length from abbreviations, one of them only 63 characters
long.


**R7 re-proved the full accepted 355/355** on immutable package `9719216316` (run/job `33276039911 / 99162853852`),
with ordinals 305 and 310 both green in the same complete run and immutable pre/postflight green. That closed
`PR8-R043`, `PR8-R044`, and `R7-ORCH-01`. No CP4c-2 gate — 357, 358, 361 — has been run, and no cumulative gate or
benchmark has run; `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

Stable regression accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**;
authoritative M3 packages **64**. Closing a stable event changes its status, never the cumulative count.

**CP4c-2 is open and unaccepted.** It owns the closed/higher-genus A2b gap and criteria **C1** (torus derives
regions) and **C6** (disc proof + mandatory preservation). **C3** (rotation-system/face-walk agreement) is no longer
deferred: DEFN-R2 split it, keeping the torus half in scope and moving the mechanical half to CP4c-3.

**The gate is settled: selector 361, frozen at `M3-CP4c-2-DEFN-R2` under AF5/AG0.** It is candidate 357 plus the
four `SurfaceCutGraph.*` identities, appended so the 355 and 357 prefixes stay byte-identical and `first_red_ordinal`
remains comparable across the whole CP4c arc.

- **357 is superseded**, not wrong: its two `GlobalTopologyPlan` torus identities are retained in 361.
- **358 is withdrawn.** Its sole addition, `RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, binds
  `cp4c_mechanical_fixture()`, and the mechanical witness has no atlas and is out of CP4c-2 scope — a gate may not
  bind a witness its own checkpoint excludes. Criterion **C3** survives: its torus half becomes its own identity
  and enters the gate; the mechanical half moves to CP4c-3.
- **Two of the four appended identities enter the gate red.** That is correct — a required-green selector says what
  must be true for the checkpoint to close, not what happens to pass today.

`selected_gate` is still **NONE** and `gate_execution_authorized` is still **false**: freezing a gate's bytes is not
selecting it.

## 4. The three witnesses — the fastest way to understand the problem

| witness | source | A2a result | current state |
|---|---|---|---|
| **torus** | fixture, closed genus 1, `χ=0`, V/E/F = 72/216/144 | 48 `HardFeature` mandatory edges, 0 singularities, 48 nodes, **0 traces**, 0 events | produces a cut graph **and a topology plan**; actual embedded graph after cuts `V/E/F = 72/76/4`, `χ=0`. Fails later, downstream of A2b, at `tracing` (out of CP4c-2 scope) |
| **prescribed sphere** | fixture, closed genus 0, `χ=2`, V/E/F = 98/288/192, **zero mandatory edges** | **24 traces / 56 events** | **two independent problems.** (a) Its pre-cut actual embedded graph is measured **non-cellular**: `V/E/F = 18/30/18`, `χ=6` against `sourceChi=2`, one component, no excluded boundary orbits — so it genuinely needs cuts, and they will be trace-crossed. (b) The producer never gets there: it fails at A2a′ reporting `CellularityNotEstablished` at source face `25-27-28`, which is a `default:` bucket, **not a cellularity verdict** (§7 item 1) |
| **two-ring** | constructed, disc, `χ=1`, V/E/F = 11/25/15 | 3 traces / 8 events | actual embedded graph `V/E/F = 9/11/3`; the accepted invariance witness, and the **only** witness on which the A2a′ semantic/provenance split is runtime-proved |
| mechanical feature | fixture | no atlas — stops in **A1** at `IncompleteCycleBasis` | belongs to CP4c-3 / C2, **out of scope** |

## 5. The central theorem of CP4c-2

For a graph embedded in a closed surface with every complement component an open disc, Euler gives
`V − E + F = χ`. The torus network has `V = 48`, `E = 48`, `χ = 0`, so `F = 0` — impossible, since the
complement is non-empty. **At least one component is not a disc.**

Stronger and more useful: a disjoint union of closed curves always has `E = V`, so **no disjoint union of closed
curves can ever be a cut graph of the torus.** This is not a defect of the committed fixture and cannot be fixed
by choosing better feature curves. A cut graph of a genus-`g` surface needs vertices of degree ≥ 3 and must
realize a homology basis; a feature/singularity-derived network guarantees neither.

That is why A2a′ exists. `UncutFaceComponentOrbitSeedNotUnique` at `GlobalTopologyPlan.cpp:1741` was **correct
behaviour reporting a missing input** — there was never a bug at that line.

## 6. The normative complex — read this before touching A2a′

Frozen by **DEFN-R1 Amendment 13**. The complex in which cellularity is certified is the **actual embedded
graph** of `FieldAlignedCurveNetwork ∪ cutEdges`:

- **vertices** = network nodes + nodes created by cuts
- **edges** = network arcs + cut arcs
- **faces** = **dart orbits** under the node rotation system

The machinery already exists and must be reused, never reimplemented:

| concept | where |
|---|---|
| arc, dart | `GlobalTopologyArc`, `GlobalTopologyOrientedArc` — `include/directional/geometry/GlobalTopologyPlan.h:33-47` |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` |
| face walk | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` — `src/geometry/GlobalTopologyPlan.cpp:1168-1260` |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` — `:1534-1660` |
| shared authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` — created by CB4, the single owner |

**Two conventions decide correctness and must be derived, not guessed:**

1. **Exterior-orbit exclusion** on surfaces with boundary. The two-ring walks 4 orbits, exactly one exterior →
   `F = 3`. On a closed surface there is no exterior orbit.
2. **Disconnected-graph correction.** The torus's 48 arcs over 48 degree-2 nodes form **four components**;
   unqualified `V − E + F = χ` is false there *before* any cut is considered. Mistaking that for
   non-cellularity is right for the wrong reason.

**Withdrawn:** the whole-source-face / source-edge-barrier partition is **not** cellularity authority. It
survives only as a cut-proposal heuristic and diagnostic provenance, and any publication of it must say so.
Two complexes exist for the two-ring and both satisfy Euler — actual `9/11/3` and proxy `10/11/2` — which is
precisely why self-consistency proves nothing about *which* object was measured.

**Cut admissibility — revised by Amendment 14 (DEFN-R2); the old rule below it is withdrawn.** A cut is a source
edge promoted to a graph arc, and **every source edge that is not already a graph arc is admissible, including one
a trace crosses at an interior point.** Promoting a crossed edge adds one arc per sub-interval between consecutive
crossings and one cut-created node per crossing, and splits the trace arc **in the derived arrangement only**.

The old rule — "a trace-crossed source edge is inadmissible because promoting it would subdivide an immutable
trace" — rested on a premise that is false about this codebase. `build_arcs` already emits **one trace arc per
event**, so a trace is many arcs, not one; it already splits a mandatory source edge at a trace terminal; and the
crossing point is already published exactly by the network as `segments[i].entryPoint`, at a segment position the
subdivision machinery already keys on. Nothing upstream is mutated either way. Amendment 12 forbids A2a′ *repairing*
an upstream product; it never forbade A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**Completeness is therefore proved outright.** The complement of the source 1-skeleton is the open triangles, each
a disc; trace sub-arcs cut those discs into discs; so `network ∪ (source 1-skeleton)` is cellular, a sufficient cut
set always exists, and at most `|E_source|` promotions are ever needed. `NoAdmissibleCutForNonDiscComponent` can no
longer describe a real configuration and is retired; a distinct code reports "the search heuristic made no
progress", and saturation — promoting the component's remaining admissible edges — is the defined, *published*
last resort. It must never fire silently, and is predicted never to fire on the three witnesses.

**The one real gap this opens:** at an edge-locus node, `build_rotation_system` handles only `Mandatory` (at exactly
degree three) and `Trace` rays — a `Cut` ray there is an unhandled shape. A crossing node is two collinear `Cut`
rays plus two `Trace` rays, degree four, and the existing four-sector model generalizes to it.

## 7. Open problems, in priority order

1. **`M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere, and the single most important thing to understand here.**
   The sphere's A2a′ failure reports `CellularityNotEstablished`. **That string is a `default:` case, not a
   verdict.** `SurfaceCutGraph::topology_error` (`src/geometry/SurfaceCutGraph.cpp:50-67`) maps 39
   `GlobalTopologyPlanErrorCode` values onto three: three survive as themselves and **36 collapse into
   `CellularityNotEstablished`**, carrying `sourceFace` through. It is called from exactly two sites, `:240` and
   `:243`, both entering `src/geometry/EmbeddedGraphTopology.cpp` — and across that file's 58 error constructions
   every code that both survives the collapse and carries a `sourceFace` is **`RotationSystemInconsistent`** (44 of
   58; all nine `sourceFace` assignments). R7-5 published `errorSourceFace=25-27-28`, so the sphere took that path.
   Neither call site evaluates cellularity at all — that happens later, at `proves_cellularity()` in the cut loop
   (`:323`) and the `:250` orbit guard. **The sphere never reached a cellularity decision.** A2a′ did not change
   the sphere's old `RotationSystemInconsistent`; it renamed it. Eight turns of planning reasoned about cuts and
   complexes for a mechanism that never ran. Do not repeat that: get the code printed (measure AF0) before
   proposing any fix.
2. **The prescribed sphere genuinely needs cuts — measured, not predicted.** CB6's AF1 read the row R7-3 had
   already published: `V/E/F = 18/30/18`, `c=1`, `χ=6` against `sourceChi=2`, no excluded boundary orbits, with the
   oracle calling `SurfaceCutGraph` zero times. Non-cellular pre-cut, so the seven-turn standing prediction is
   **refuted**. With 24 traces and zero mandatory edges every cut it needs will be trace-crossed — the case
   Amendment 14 exists for. The derived excess `6 − 2 = 4` suggests roughly four extra boundary circles; **AG3 must
   verify that against the per-component records rather than adopt it**.
3. **Amendment 14 is defined and entirely unbuilt.** DEFN-R2 froze trace-crossed cut admissibility and proved
   completeness, but no committed witness currently promotes a trace-crossed edge, so the whole amendment would
   ship unexecuted without a purpose-built fixture (measure AG5). The one code gap is the degree-four edge-locus
   rotation (§6). Owned by `M3-CP4c-2-CB7` under AG1–AG6.
4. **Criterion C3 has been deferred six times** and is now split: a torus-only identity enters gate 361's successor;
   the mechanical half moves to CP4c-3. Owned by AG7.
5. **`M3-CP4c2-TB-X2-R7-CAND-03`** — the D2 localization harness compares the actual embedded graph against the
   **withdrawn** source-edge-barrier proxy, under a helper named `cp4c_producer_rederivation` that is not a
   producer re-derivation, using site labels (`419-`, `437-`, `474-`) that are line numbers in a
   `SurfaceCutGraph.cpp` which is 344 lines long. Its `localizationConsistent=false` is false by construction and
   means nothing about the sphere.
6. **`M3-CP4c2-TB-X2-R7-CAND-01`** — the torus semantic/provenance diagnostic builds its atlas from a locally
   synthesized zero-transport field instead of the production `torus.rawfield`, and fails at that precondition
   before comparing digests. `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` shares the construction,
   is in no selector, and has never run — which is why measure **AD3**'s rationale for hashing the raw
   `face.orbit` index into a *semantic* digest currently has no falsifier.
7. **Torus post-A2b `tracing` failure** — downstream of A2b, out of CP4c-2 scope, tracked and not to be fixed
   here.
8. **Mechanical witness A1 `IncompleteCycleBasis`** — CP4c-3 / C2. It is also why selector 358 was withdrawn (§3).

**The standing prediction is REFUTED and closed.** For seven turns the checkpoint carried "the prescribed sphere's
network is already cellular and needs zero cuts". `M3-CP4c-2-CB6` read the independent oracle row R7-3 had already
published — `V/E/F = 18/30/18`, `χ=6`, `sourceChi=2` — and `V − E + F ≥ χ` with equality iff cellular settles it:
the sphere is **not** cellular pre-cut. It needs cuts, and with 24 traces and zero mandatory edges they will be
trace-crossed. That is what made DEFN-R1 §8.2 live and what Amendment 14 exists to serve. **The evidence had been
sitting unread in a retained artifact the whole time** — see §8's gated-observation family.

## 8. Recurring defect patterns — the highest-value section

Four families account for nearly every CP4c-2 turn that went sideways. Check against these *before* writing a
plan or a fix.

**`RP-01 / AUTHORITY_DOMAIN_CONFLATION` — two authorities for one datum.** Rails from `rails_from_atlas` versus
the pipeline's `authoritativeRails` bit four separate times. A number and the expectation it is compared against
must come from the same authority, and every published record should name the authority it used.

**`RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` — one digest, two domains.** Semantic identity contaminated with
gauge-dependent provenance. Stabilized at CP2b, fixed for the network at CP3a, and reintroduced by A2a′ now.
Semantic and provenance are **two digests**, always.

**Wrong-representation, right-arithmetic.** A computation can be internally flawless and describe the wrong
object. Self-consistency is never evidence that the complex is the right one. `LESSONS.md` 22d/22e: check that
the representation can *express* the answer before debugging the algorithm, and convert every consumer of a
representation or none.

**Product property applied to the representation — the same family, one level up.** DEFN-R1 excluded trace-crossed
cut edges by reasoning "the trace is an immutable product, therefore the arrangement may not subdivide it." True
premise, invalid conclusion: `build_arcs` already emits one trace arc per event, and already splits a mandatory
source edge at a trace terminal, without touching the product. An immutability guarantee constrains the *writer*,
not the *derived view*. Before ruling a representation out on an upstream guarantee, read what the existing
consumers of that representation already do — the same control (`LESSONS.md` 22e) that the R2 error missed.

**Gated observation — the measurement suppressed by its own harness.** Publications gated behind a call that
fails; one error code collapsing several mechanisms with no locus; one witness's failure aborting the loop
before the others publish; a typed error flattened to a bare string. **The witness the design reasoned about is
not the witness that exercises the code** — this bit at ordinal 13, at the C5 torus, and at the sphere. Its most
expensive instance to date is §7 item 1: a `default:` case that assigned a semantic-sounding name to 36 distinct
errors and was believed for eight turns. Related and equally cheap to avoid: an assertion that discards a typed
error it already holds (`ASSERT_TRUE(atlasBuild)` where `atlasBuild.error()` and
`field_atlas_build_error_code_name()` both exist); a diagnostic loop whose per-witness rows are collected and then
summarized down to one row; and a frozen non-gating selector a plan silently declines to run.

**Transcribed constants and abbreviated digests.** A hash copied from prose is not evidence; a hash written as
`PREFIX…SUFFIX` in a table where values belong invites a later reader to reconstruct the middle, and the
reconstruction looks plausible. Four such values reached an executor and one was not even 64 characters.
Recompute from the named file, and validate any expected digest as exactly 64 lowercase hex at authoring time.

A sixth, meta-level: **a result that discharges a premise must be reported as a finding, not left as a field
value.** The torus's `pipelinePlanAvailable=true` — the fact that A2a′ works end to end — sat unremarked in an
evidence table under a "semantic red" verdict.

## 9. Where to look

**Architecture and plan:** `DESIGN.md` (§4.5 grazing, §4.6 motorcycle graph, §7.2 region derivation with
Amendments 12 and 13), `ROADMAP.md`, `REORIENTATION_PLAN.md`.

**Current state:** `TODO.md` current-focus block; `Future_Chat_Session_Handoff.md` next-turn block;
`Regression_Root_Cause_Tracker.md` for every open defect; `CHANGELOG.md` newest-first for how we got here.

**Durable knowledge:** `LESSONS.md` — organized in eight sections; §2 fixtures/witnesses, §4 single authority,
§5 cross-field conventions and §6 gate authoring carry the most reusable content.

**CP4c history:** `M3_CP4c_Consolidated_Record.md` holds the retired per-turn records with their evidence,
review arcs and withdrawn predictions. Closure records: `M1_`, `M2_`, `M3_CP2_`, `M3_CP2b_`, `M3_CP3_`,
`M3_CP4ab_`, `M3_CP4c1_Closure_Record.md`.

**Key source:**

| what | where |
|---|---|
| tracing, grazing transit, termination | `src/geometry/SurfaceCellTracing.cpp`, `include/directional/geometry/SurfaceCellTracing.h` |
| cut graph (A2a′) | `src/geometry/SurfaceCutGraph.cpp`, `include/directional/geometry/SurfaceCutGraph.h` |
| shared embedded-graph authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` |
| region derivation (A2b) | `src/geometry/GlobalTopologyPlan.cpp` |
| pipeline wiring, product snapshots | `src/pipeline/RemeshPipeline.cpp` (~6560-6640) |
| exact arithmetic | `include/directional/numerics/BigInteger.h`, `ENumberGMP.h`, `authority/FieldTransportAtlas.h` |
| the whole test suite | `tests/FieldAlignedCurveNetworkTests.cpp` |

**Witness fixtures:** `benchmarks/fixtures/milestone-g/{torus,sphere_prescribed,mechanical_feature}.{obj,rawfield}`.
The two-ring is constructed in the test file, not a fixture.

## 10. Facts worth not re-deriving

- Sphere: 98 V / 192 F / 288 E, `χ=2`, 8 index-¼ singularities at cube corners, 24 ports, 24 traces, 56 events,
  **zero mandatory edges**. Its pre-cut actual embedded graph is `V/E/F = 18/30/18`, one component, `χ=6` — excess
  4 over `sourceChi=2`, hence non-cellular.
  Of 48 directed trace ends, 42 terminate at singularities; the remaining 6 once circulated forever and are now
  terminated by crash-on-contact.
- Torus: 72 V / 144 F / 216 E, `χ=0`, zero singularities, 48 hard-feature mandatory edges forming (inferred,
  and consistent with the measurements) four loops of twelve edges; four annular complement components.
- Two-ring: actual embedded graph `V/E/F = 9/11/3`; source-edge-barrier proxy `10/11/2`. Both satisfy Euler.
- Torus actual embedded graph **after** cuts: `V/E/F = 72/76/4`, `χ = 0 = sourceChi` — i.e. cuts added 24 vertices
  and 28 edges to the 48/48 pre-cut network.
- `SurfaceCutGraphErrorCode::CellularityNotEstablished` is **not** always a cellularity finding. Via
  `topology_error`'s `default:` it is the bucket for 36 distinct `GlobalTopologyPlanErrorCode` values. Check
  whether the error carries a `sourceFace`: only `topology_error` sets one, so a populated `sourceFace` means the
  failure came from `EmbeddedGraphTopology`, upstream of any cellularity decision.
- Terminal event kinds: `SingularityPortOrigin(0)`, `FirstContact(1)`, `TraceIntersection(2)`,
  `MandatoryBarrierTermination(3)`, `SingularityTermination(4)`, `SingularityPortJunction(5)`,
  `TraceSelfClosure(6)`. The observed terminal union across witnesses is exactly `{2, 3, 4}`.
- Grazing is **edge transit**, not termination — decided on a continuity argument, not on cost data.
- Trace termination is **crash-on-contact** (motorcycle graph), on an exact predicate, with mutual termination
  on a tie; the production arrival priority is `ArcLengthFiltered` with a certified forward error bound.
- GMP/GMPXX linkage is mandatory for every compile; fallback exact arithmetic is not authoritative build
  evidence.
