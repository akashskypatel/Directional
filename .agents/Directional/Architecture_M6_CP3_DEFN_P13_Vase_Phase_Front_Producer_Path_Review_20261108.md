# Vase A4 phase-front producer path — independent Review (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-VASE-PRODUCER-PATH` (Review, runtime-free). Source snapshot SHA `ad8011d7008aa44b6c9ed49d7881aa4dd4d65c6f`, snapshot run `42447920167`, artifact `13604256660`, verified `source.tar.gz` SHA-256 and source SHA. Source program semantics are the CB101 compiled code `23e35798abf0eb3584509c564166ccd97c41cc21`; intervening snapshot commits affect documentation/control only. Primary evidence: RA-212 §2–3, TB85 report, DESIGN §§5, 7.4, repository source and the tracked regression inventory. No new executable probe or build has been run in this Review.

## Decision — extend A4, do not optimize the legacy fallback as the production solution

The immediate Vase `NotApplicable` cause is a **source-wide singularity veto** shared by all three current A4 producer families. It is not an A3 scheduling failure, a failed embedding attempt, or a proved inability of the Vase field to admit a quadrangulation. The evidence supports choosing a source-authoritative **singularity-capable regional phase front**, not preserving the legacy tracing fallback as the product path. This is an architectural direction and a bounded implementation sequence, **not** evidence that a singularity-capable producer already works. Removing the veto alone is forbidden: downstream algorithms presently assume the no-singularity cases and may silently violate singular index, phase, A3 boundaries, or topology.

The precise next action is a **diagnostic-only Code + Build turn** that makes the actual region-local applicability obligations and first declines visible before any semantic A4 extension. No runtime result or new accepted quad product is claimed here. The next Test + Benchmark must independently run that compiled instrumentation; its outcome gates any further producer change. Do not combine those turn boundaries.

## 1. Independent static cause proof

- `src/pipeline/RemeshPipeline.cpp` assigns `tracingOptions.fieldAlignedNetwork` from the checked `FieldAlignedCurveNetwork` product before A4 (around line 12935).
- `src/geometry/SurfaceCellTracing.cpp:5529`: `tracing_has_singularities(options)` returns `!options.fieldAlignedNetwork->singularity_ports().empty()` when typed network authority exists. **There is no region parameter.**
- `FieldAlignedCurveNetwork::singularity_vertices()` at `SurfaceCellTracing.cpp:5285` is computed from `singularityPorts_`, so one typed singularity seed from this network implies at least one port; in the candidate path, `generate_deterministic_surface_seeds` obtains singularity seeds directly from that typed accessor at `SurfaceCellTracing.cpp:10483`.
- RA-212's Vase legacy-path census contains **one Singularity seed** (and 1,131 relief-critical, 284 boundary seeds). Thus the shared typed-network guard is true on that input. The same `options` is passed to every regional attempt; a source-global port is sufficient to veto every region, whether a given region contains the singularity or not.
- `build_uniform_phase_front_for_faces` (`SurfaceCellTracing.cpp:13313/13336`) returns default `NotApplicable` on that guard **before** the planar frame check, A3 hard-rail checks and phase construction.
- `build_periodic_annulus_phase_front_for_faces` (`14132/14146`) returns default `NotApplicable` before annular classification, periodic holonomy or A3 consumption.
- `build_curved_bounded_disk_phase_front_for_faces` (`15434/15448`) also returns default `NotApplicable` **before** source-chart, disk, curvature and hard-rail checks. The name 'curved' does not mean a singularity-capable A4 path.
- `build_uniform_phase_front_state` (`18485` onward) attempts these three in sequence per region. When none produces, and no hard features are present, the aggregate result remains `NotApplicable` with **no owning rejection reason**; the pipeline permits legacy fallback for that state. The current result therefore does **not** establish whether a particular region would satisfy any later geometrical/topological applicability predicate if the veto were absent.

**Scope of proof:** The first decisive veto is established from source and the RA-212 seed census. The exact region membership of the port, each region's χ/boundary/holonomy class, and post-veto predicates were **not observed** in a new Vase instrumented run. Those facts must be recorded, not guessed, before changing producer behavior. This is a diagnostic-authority gap, not permission to ignore topology.

## 2. Legacy fallback and density: independent cause map

The legacy seed producer calls `add_vertices(options.reliefCriticalVertices, ReliefCritical)` and `add_vertices(options.reliefRootVertices, ReliefCritical)` in `SurfaceCellTracing.cpp` around lines 10490–10510 and adds absent relief-region representatives under the same provenance. It does not gate those seeds by A4 region resolution or metric spacing. RA-212's controlled legacy scratch (relief barrier edges retained) measured:

| Input/evidence | Ordinary Vase | Relief seeds withheld in scratch |
|---|---:|---:|
| Seeds | 1,416 (1,131 relief-critical) | 380 (95 adaptive) |
| Trace segments / strands | 5,664 / 30,989 in the seed-trace count | 1,520 / 5,327 |
| Arrangement cells | 26,817 | 1,184 |
| Odd cells / parity splits | 5,931 / 9,079 | 255 / 0 |
| Terminal | AggregateCompletionValidationFailure | BoundaryParityRepair repeated-boundary-node / budget exhaustion |

The differently described 189,462 *trace segments* in TB85 are the emitted geometric trace-segment census, not the 5,664 seed-direction trace count in the scratch table; **do not conflate these units**. The mean target length 0.0883 versus median mesh edge 0.00434 is ≈20.3× linearly finer; the size gate P5 is 0.0035 against ≥0.5. The controlled ablation demonstrates sensitivity to the relief seed mechanism, not proof that the no-relief output is valid or target-sized: it still fails much earlier. Therefore O31 is a primary density driver and determinism obligation on this *legacy* producer, not a general justification to turn relief off on unrelated A4 cases.

The legacy completion/parity path inserts **121 hard-rail breakpoints** and 35 singularity-support breakpoints (RA-212). DESIGN §7.4 gives A3 exclusive authority to publish those shared coordinates and forbids A4 and downstream consumers from inserting, removing, quantizing or reordering them. This is a **second writer**, not a quality-tuning knob. If fallback must be retained temporarily, it is non-authoritative for production acceptance and must preserve the exact A3 schedule; downstream parity mutation cannot serve as an unreviewed fix.

## 3. Every current Vase quality gate, with evidence owner

These are observed on **67,750 informational**, fail-closed fallback quads after CB100/101, not on a verified direct A4 output. Treat causality not independently tested below as a hypothesis, not a proved single culprit.

| Gate (current) | Attribution/owner and residual uncertainty |
|---|---|
| Field alignment P95 36.4° (limit 15°) | Legacy trace/strand survival and completion geometry; layout does not guarantee cross-field alignment. The relative contribution of seeding and final optimization remains unmeasured. |
| Size P5 0.0035 (minimum 0.5) | Measured excess density, with relief-critical seeds an independently isolated upstream driver; required target-sized A4 constructor must use the metric and conform to A3. |
| Angle P5/P95 6.46°/180.8° | RA-211's representation-node breakdown, reflex patch corners and degenerate/sliver completion; CB100 corrected the *metric interpretation*, not geometry. |
| Warpage P95/max 81.6°/166.2° | Legacy completed quad embedding and nonplanarity; CB100 removed both-diagonal measurement artifact; remaining values are still unacceptable. |
| Aspect P95/P99 60.7/286.6 | Density mismatch, sliver cells and completion's edge arrangement; correlation established, per-contributor causal percentages not established. |
| Signed scaled Jacobian min/P5 −1/−0.013 | Invalid/inverted/nonconvex embeddings on the legacy completion path, not a reporting-only artifact. |
| NonConvex 16,812 | Real concave/invalid corner geometry, with representation subdivisions and reflex L-patch model candidates; do not suppress validator. |
| Boundary-valence mismatches 248 | Legacy completed topology/arrangement ownership and boundary interface; no independently isolated owner yet. Preserve source boundary and A3 interface checks. |
| Singularity-valence mismatch 1 | Legacy port-to-completed-valence contract; the source singularity also prevents the current A4 producer from attempting a direct construction. Preserve prescribed index/port valence, not just count. |
| Normal P95 3.74° | **Discharged metric artifact** by CB101 (first-triangle normal was 121.56°); not a remaining failing gate. |

**Non-vacuity:** Plane, multi-face seam, close sheets and cylinder already use A4. Their unchanged hashes cannot falsify a fix to Vase's fallback-only completion. A valid later gate must include the Vase legacy negative control and an independently sourced A4 singularity positive/negative family, with a tampered port budget and an A3 rail mutation adversary. A guard that is merely removed while the new path never produces fails this criterion.

## 4. Bounded next turn and falsifiers (frozen for implementation)

**Next authorized successor:** `M6-CP3-CB102-P13-PHASE-FRONT-APPLICABILITY-RECEIPTS` — Code + Build, compile-only, no production-semantic change.

1. At the same producer selection site, publish **per canonical A2b region** the input region ID/face count, Euler/boundary/holonomy class when already available, typed singularity-port count and IDs in that region, and the first **named** `NotApplicable` reason for uniform/annulus/curved A4. Do not treat an unknown chart mapping as zero ports. Do not invent a floating-point containment test; reuse canonical `SourceTopologyRegions` and port authority.
2. Make the current global veto explicit as `SourceGlobalSingularityVeto` and report both source-wide and scoped port counts. Distinguish disabled/not-attempted, unsupported region, and malformed authority (`Rejected`). Report all three producer declines without modifying which producer would have been selected. Keep the terminal `NotApplicable` and legacy branch unchanged.
3. Introduce a focused **nonvacuous regression source** showing one singularity-free region and one singularity-bearing region in the same source network; verify the diagnostic reports the differing scoped counts and shared global veto while preserving return dispositions. Include a zero-port control and an invalid source/port mapping typed failure if representable; do not manufacture an arbitrary source vertex as a valid chart owner. Test source may be added in this CB; **compile it, do not run it**.
4. Do not modify field transport, A3 schedule, source geometry, producer eligibility, parity repair, quality evaluator, fallback default, selectors or accepted gates. The **next separate TB** must execute the compiled witness on an immutable artifact with Vase on its actual producer path; decide the first eligible singular-front region from those measured receipts before authorizing any behavioral CB.

**Stop conditions:** missing truthful region/port ownership, inability to report a decline without changing selection, changing any existing semantic digest for the frozen fixtures, a producer suddenly accepting Vase, or a false claim that per-region classification proves singularity closure. A negative mutator that does not change the expected receipt is vacuous. On any such outcome return to a Review rather than silently altering producer behavior.

**Deferred, separately owned:** P13-e BunnyRandom port-class mismatch; O30b, O32b–e permutation/portability; O33, O27–O29 resource costs; O31 relief determinism/density if legacy remains; P13-n1/n2/n3 postponed until a target-density legacy positive case is justified; P13-n4 evaluator correction already in CB100/101 and TB85, no further metric patch authorized here. No stable accepted regression loss: **66 events / 17 categories / 49 recurrences, debt 1; CP2 accepted 491/491; selector497, CP3 unpromoted; 81 deferred.**

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No selector modified; `review_check.py boundary` independently checked 39 historical selector SHA256 values against reconstructed HEAD (all PASS), but the exact accepted 491-row prefix was not separately recomputed in this turn. CP2 491/491 remains frozen. |
| Decisive claims independently re-derived | Source-code gate, common option capture, `singularity_vertices()` port derivation, all three early returns and aggregate fallback; numeric density ratio recomputed from RA-212 values. |
| Non-vacuity checked | Identified A4-only fixture digest comparison as vacuous for legacy completion; prescribed typed singular-source and legacy-path controls. |
| Prior obligations discharged/carried | CB100/CB101/TB85 complete per immutable reports; P13-n4 metric artifact corrected; carry P13-e, P13-n1/2/3, O30b, O31, O32b–e, O33, O27–O29. |
| Stable accounting | 66 / 17 / 49, debt 1, accepted CP2 491/491; 81 deferred; selector497/CP3 unpromoted. |
| New candidates/obligations recorded | Regional A4 eligibility receipt gap, source-global singularity veto; carry in tracker and successor. |
| ORIENTATION currency line | Review turn/date amended in proposed documentation patch; remote receipt required. |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 amendments proposed; §4 no witness changed because no runtime occurred. |
| CHANGELOG | Proposed entry in documentation patch; remote receipt required. |
| ROADMAP | No checkpoint transition, so unchanged. |
| Selector manifest | No selector added/accepted, so unchanged. |
| LESSONS | Existing lesson: typed outcomes must retain owning failure and discriminating reachability; no new generic lesson. |
| Consolidation under CLEAN_UP_POLICY | No documents deleted/folded: retained RA-211 and RA-212 encode nonidentical adverse evidence and independent provenance; no superseded safe-to-delete authority established. |
| Successor frozen | Exactly one successor CB102, with source/receiver semantics, negative controls and stop conditions in §4. |
| Turn boundary held | No product/test/fixture/selector/build source changes; no runtime execution. |
| review_check.py boundary | Executed in reconstructed Git snapshot: product/test/fixture/selector checks and all enumerated selector hashes PASS; durable rewrite ancestry SOURCE checks FAIL because the downloaded GitHub snapshot has no original `.git` ancestry. This is an environmental limitation, not a valid full PASS. |
| `STATUS` lifecycle maintained | Entry published; terminal status to be synchronized in final GitHub action. |
| Pushed to origin, branch in sync | Pending remote patch transport and independent postflight read; not claimed. |
