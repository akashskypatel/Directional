# M3 Closure Record — Field-Aligned Curve Network

**Status:** **CLOSED / ACCEPTED** at `M3-CP4c-3-TB48-REV`.
**Reviewed semantic runtime authority:** package113 source `6dae3f6959551f6dcdd81f153aedb5f38411a96b`, selector409 runtime `34409262512 / 102659650326` — **405 PASS / 4 RED / 0 SKIP**, accepted required-green prefix **365/365**, RED `[368,369,374,398]`.
**Runtime artifacts:** result `10126711178` SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`; log `10126711588` SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`.
**Accepted required-green selector entering M4:** **365**, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.
**Stable accounting at closure:** **47 events / 14 categories / 33 recurrences**; produced-witness debt **5**; ownership **300/0/0**; packages **113**.

This is the durable milestone-level closure record for M3. Historical checkpoint and CP4c source records are
reproduced within **§8, Historical M3 record archive**, below. The normative frozen definitions, historical implementation plan, and final TB48 execution report are reproduced verbatim in §9 below. **Frozen definitions remain binding**.

## 1. What M3 required

`DESIGN.md` §14 M3 requires a typed authoritative `FieldAlignedCurveNetwork` derived by combinatorial tracing and a
`GlobalTopologyPlan` that consumes it rather than assuming regions. Acceptance requires singularity-port ownership,
branch-consistent/non-crossing traces, typed terminal events, disc-topology proof for emitted regions, mandatory
network topology under tamper, and tracing/start-port permutation invariance.

## 2. Checkpoint trajectory

M3 closed through the accepted CP1/CP2/CP2b/CP3a/CP3b/CP4ab chain, then the CP4c decomposition:

- **CP4c-0:** exact resolved interval continuation and exact position/direction authority;
- **CP4c-0b:** typed trace termination/contact authority;
- **CP4c-1:** diagnosability and witness/event observability;
- **CP4c-2:** closed/higher-genus actual-embedded-graph `SurfaceCutGraph` and region/disc authority; accepted required-green prefix **365**;
- **CP4c-3:** mechanical closed-surface A1/continuation witness under restored **AU0–AU9**, with selector409 used as a broader audit/report-only execution surface.

### 2.1 CP4c-0's direct whole-gate closure basis

`M3-CP4c-0-TB-R9` **did execute**. Workflow `33079817998` (`M3 CP4c0 TB-R9 Whole-Gate Reproof`) completed
successfully against selector346, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, with
**346/346 PASS** including Q8 criteria **1, 4 and 5**. Retained evidence records workload job `98543736213`, result
artifact `9649625534` / SHA-256 `6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af` and log
artifact `9649626115` / SHA-256 `3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9`.

Later 353/355/365 gates also contain the 346 prefix and remain corroborating cumulative evidence. They are not the
closure basis and M4 has no conditional obligation to reconstruct a supersession argument. The false “TB-R9 never
executed” premise appended during the TB48 independent verification pass is corrected in that record's §13.

The final CP4c-3 independent review is reproduced in §8, Historical M3 record archive, below.

## 3. Why a 405/4 runtime can close M3

The four RED rows are not silently accepted. CP4c-3's frozen exit condition is explicitly **the mechanical witness
under AU0–AU9**, while the checkpoint domain separately lists inherited sphere/quality/fixture debt. The final
mechanical surface is green: 365/365 accepted prefix, 366/367 green, protected 390/393/406/407 non-vacuously green,
full 409-row report-only coverage after first RED, and all exactness/reportability prohibitions preserved.

The final targeted debt inside the closure hygiene path, ordinal370, also becomes PASS on package113 under the frozen
typed `EmptyNetworkOnClosedSurface = 6` plus `sourceFace` locus identity. The four remaining rows retain their own
owners and future schedules:

- 368 prescribed-sphere event-position binding;
- 369 ordinary proposal saturation/quality;
- 374 folded-cone invalid fixture/precondition;
- 398 downstream of 368.

They remain visible and red; they do not redefine M3's frozen exit criterion.

## 4. Final evidence

Package113 is byte-immutable across TB48. Root package authority, selector and harness hashes match the frozen plan;
all 409 identities execute once in fresh processes; selection mismatch and timeout counts are zero; package/source/
execution-view pre/post censuses match; no configure/compile/relink/discovery/repair/mutation/benchmark path runs.

Ordinal370's frozen test constructs an atlas-valid closed torus with a truly empty network and directly asserts the
existing typed error plus a non-empty source-face locus. Static package113 source has exactly the corresponding early
product branch in `SurfaceCutGraph::canonical_candidate()` after binding checks and before cut classification.

## 5. Declared limitations carried forward

M3 closure is not a production-ready claim. It does not discharge:

1. `G4-B002` shared positive rail scheduling or its three produced-witness re-proofs — **M4**;
2. `G4-B003` nonzero periodic Z4 production or its two produced-witness re-proofs — **M5**;
3. the prescribed-sphere 368/398 defect, proposal-quality 369, or folded-cone 374 fixture debt;
4. production-scale/sliver/high-valence/conditioning coverage — `M4-CP-COND` / `M4-CP-SCALE` proposals to be reconciled at M4-DEFN;
5. representative Bunny/Vase quality/resource acceptance, later milestone authority, or M7 disposition re-proof.

## 6. Accounting

Package113/TB48 is promoted as reviewed runtime authority. `M3-CP4c2-TB-X2-R8-CAND-02` and
`M3-CP4c3-TB48-EXEC-CAND-01` close non-stably; closure changes status but does not decrement or add historical
stable counts. Totals remain **47 / 14 / 33**, debt **5**, ownership **300/0/0**, packages **113**.

## 7. Successor (historical status at M3 closure; not a live handoff)

`M4-DEFN` was the immediate milestone successor and is now complete/amended through `M4-DEFN-R1`. M4 has since reached
`M4-CP1-TB1-REV`; current exact next is **`M4-CP1-CB4`**, runtime-free package closure under
`Architecture_M4_CP1_CB4_Code_Build_Plan.md`; M4 definitions remain frozen/amended in
`Architecture_M4_DEFN_Frozen_Definitions.md` with adjudication in `Architecture_M4_DEFN_R1_Definition_Record.md`.

---

## 8. Historical M3 record archive — source text preserved

**Archive scope and supersession.** The seven retired record files listed below are preserved **verbatim** as individual, collapsible historical sections in this single M3 closure record. Their checkpoint verdicts, tables, root-cause evidence, normative-attribution notes, protected folded-document indexes, and historical source/run/artifact citations have not been shortened or reinterpreted. Their contemporaneous “current,” “open,” “next,” or “must remain separate” statements describe their original dates and **do not override the M3 CLOSED / ACCEPTED verdict above or the live handoff**. The source SHA and immutable pre-consolidation Git link in the index resolve any preexisting citations to retired filenames; remaining repository files are deliberately unchanged at user request. Git history retains the exact original blob for each.

This archival merger does not fold, edit, or change the authority of the separately retained `M3_CP4c_Frozen_Definitions.md`, `Architecture_M3_CP4_DEFN_Frozen_Definitions.md`, M3 plans/reports, or byte-frozen selector lineage. The current required-green successor selector remains **365**, not report-only selector409.

| Archive | Retired source path | Role | Original blob SHA | Resolver |
|---:|---|---|---|---|
| 1 | `M3_CP2_Closure_Record.md` | Checkpoint CP2 acceptance | `9dd4a12235fcd2ece8de21ad30d493cfa135f14c` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP2_Closure_Record.md) |
| 2 | `M3_CP2b_Closure_Record.md` | Checkpoint CP2b acceptance | `52b5e753a24db3fb3842023a8a25feffc1e1c628` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP2b_Closure_Record.md) |
| 3 | `M3_CP3_Closure_Record.md` | Checkpoint CP3a/CP3b acceptance | `400ef02bfb6cb630b4acc7ef34f856685d9dd573` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP3_Closure_Record.md) |
| 4 | `M3_CP4ab_Closure_Record.md` | Checkpoint CP4ab acceptance | `2067937ded4f262caf90d87eeddbc2d38cda8956` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP4ab_Closure_Record.md) |
| 5 | `M3_CP4c_Consolidated_Record.md` | CP4c consolidated turn history and protected folded-document index | `8da65ba34e99319ac4b811daf4c5457d98922ef8` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP4c_Consolidated_Record.md) |
| 6 | `M3_CP4c_Current_And_Forward.md` | Historical CP4c current-state/forward ledger | `a7a8cfa86106d79e5cca1b623ee5aaa67e97ddfb` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/M3_CP4c_Current_And_Forward.md) |
| 7 | `Architecture_M3_CP4c3_TB48_Independent_Review_Record.md` | Final independent milestone closure review | `d7fdc12049c3ea333cebf2eb6b0b294b7715024f` | [Exact pre-consolidation source](https://github.com/akashskypatel/Directional/blob/eae672dd8afe5e79055dfac06fa5e84e9b8c2555/.agents/Directional/Architecture_M3_CP4c3_TB48_Independent_Review_Record.md) |

<a id="m3-archive-1"></a>
<details>
<summary><strong>Archived source 1: M3_CP2_Closure_Record.md</strong> — Checkpoint CP2 acceptance</summary>

# M3 CP2 Closure Record — field-aligned curve network product boundary

Date: 2026-08-19 UTC
Status: **CP2 CLOSED / ACCEPTED.** Verified independently at closure.
Accepted authority: source/package `5a284388d360efa4ce1bd37bc584165e1db0157b / 9382182983`,
immutable `M3-CP2-TB-R1` `32300950126 / 96223162140`, **287/287 PASS**.

This is the single consolidated record for M3 CP2. It supersedes the per-turn CP2 plans and
reports, which are retired. Exact per-turn evidence remains in `CHANGELOG.md`; regression history
remains in `Regression_Root_Cause_Tracker.md`; durable lessons remain in
`Future_Chat_Session_Handoff.md`.

## 1. Closure verification

The acceptance claim was verified against source and artifact evidence, not accepted from the
report text.

| Check | Result |
|---|---|
| Immutable gate reached 287/287 with `failedIdentities=[]` | **PASS** — all nine partitions at expected counts |
| Frozen selector unchanged | **PASS** — 287 identities, combined SHA-256 `2caa018998a56a30fd174a525209b58b1af70e0824c4703e4a78dade9a3dcd20`; component digests unchanged from the rejected gate |
| No identity removed, renamed, or made non-gating | **PASS** — `FieldAlignedCurveNetwork.IsInvariantToRailAndSourceFaceOrdering` strengthened in place, not replaced |
| Frozen two-file surface honoured | **PASS** — `5a284388` touches exactly `src/geometry/SurfaceCellTracing.cpp` (+13/-?) and `tests/FieldAlignedCurveNetworkTests.cpp` (+147) |
| Mandatory exact-source pre-package compile ran and was green | **PASS** — `32298525762 / 96215475032` on `directional_core`, `directional_pipeline`, `directional_surface_cell_producer_tests` |
| Immutability flags clean | **PASS** — checkout/rebuild/relink/repair/source/test/fixture mutation, generated discovery, benchmark execution, package mutation all `false`; package and materialized source byte-identical pre/post |
| All 17 previously lost retained identities restored | **PASS** — M1 producer partition returned to **138/138**, including `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary` through the production path |
| Attempt accounting | **PASS** — CP2-R1 succeeded on attempt **1 of 3**; M3 cumulative cost **10 packages**, reported only |

### 1.1 Verified in source, not inferred from the report

- **Production correction present and exactly as specified** — `SurfaceCellTracing.cpp:314-322`
  branches on `rail.closed`: closed requires `sourceEdges.size() >= 3 && |V| == |E|`, open requires
  `|V| == |E| + 1`; the interval index is `(interval + 1) % |V|` for closed and `interval + 1` for
  open. No compatibility projection, synthesized terminal vertex, or weakened rejection was added.
- **The review-audit amendments were implemented, not paraphrased** —
  `tests/FieldAlignedCurveNetworkTests.cpp:414-528` walks a real four-edge boundary loop from
  `baselineMesh.EV`/`EF`, asserts loop closure and full boundary consumption, carries **real mesh
  edge indices**, and asserts `|V| == |E|`, `>= 3` edges, and `front != back`. `rails_from_atlas`
  now derives `sourceEdges` through `source_edge_index(mesh, ...)` rather than a barrier list
  position.
- **The three previously unreachable cross-closure checks are proven positively** — every atlas
  `SourceBoundary`/`HardFeature` barrier resolves to a mandatory edge owned by the rail
  (`MissingMandatoryEdge`), `atlasMandatoryCount == mandatory_edges().size()` closes the converse
  (`ForeignMandatoryEdge`), and each covered edge's kind equals its barrier kind
  (`MandatoryKindMismatch`).
- **Existing open-rail proof retained** — the original source-face-row and rail-container ordering
  invariance assertions remain ahead of the closed-rail addition; cyclic rotation and reversal both
  preserve the semantic digest.

**One documentation defect found and corrected at closure:** the M3 stable-ID mapping table in
`Regression_Root_Cause_Tracker.md` still listed `PR8-R039 / M3-CP2-R001` as `active` while the same
document's narrative recorded it RESOLVED. The table was corrected; no regression history was
removed.

## 2. What CP2 delivers

CP2 establishes the A2a **product boundary** — typed singularity-port and mandatory
boundary/feature graph authority behind a closed `FieldAlignedCurveNetwork` skeleton:

- singularity ports typed and owned exactly once, port count derived from the accepted cross-field
  index, region/component ownership resolved from `SourceTopologyRegions`;
- source boundaries and hard features entering the graph as mandatory edges, cross-closed in both
  directions against the atlas barrier set and kind-checked;
- the canonical closed-rail representation (`|V| = |E|` with modulo wraparound, minimum three
  edges) accepted at the network boundary without a second rail representation;
- order invariance: rail container order, source-face row order, cyclic rotation, and cycle
  reversal all preserve the semantic digest.

**What CP2 does not claim.** No branch-consistent tracing (CP3a), no contact/intersection or
termination incidence (CP3b), no global topology selection or disc proof (CP4), no M4 rail
scheduling, and no production-quality claim.

## 3. Trajectory and cost

| Turn | Outcome |
|---|---|
| `M3-CP2-CB` | Package 9 `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692`, compile/package green, pre-package `32279124852 / 96153441513` |
| `M3-CP2-TB` | **270/287 FAIL** `32289400790 / 96186521474`. CP2 6/6, CP1 A1 6/6, retained M2 258/275; 17 M1-producer reds all `field-aligned-network/InvalidRailGeometry` |
| `M3-CP2-RUNTIME-REGRESSION-REVIEW` | Root cause isolated to `canonical_field_aligned_candidate(...)`; two-file surface frozen; recommended cumulative cap `12 -> 13` |
| `M3-CP2-REVIEW-AUDIT` | Independent review: root cause **upheld** from source; three binding amendments (F1-F3); allocation recommendation superseded by the per-checkpoint attempt budget |
| `M3-CP2-CB-R1` | Package 10 `5a284388d360efa4ce1bd37bc584165e1db0157b / 9382182983`, attempt 1 of 3, pre-package green |
| `M3-CP2-TB-R1` | **287/287 ACCEPTED** `32300950126 / 96223162140`; result/log `9383055423 / 9383056029` |

Cost: **2 packages** (9 and 10). Cumulative M3 through CP2: **10 packages**, reported only —
cumulative ceilings were retired for M3-M8 during this arc in favour of the per-checkpoint
3-attempt budget with a mandatory-review ratchet (`REORIENTATION_PLAN.md` section 5 item 4).

## 4. Root cause and resolution

`PR8-R039 / M3-CP2-R001` — `CYCLIC_TOPOLOGY_LINEARIZATION` (`RP-07`), detection escape `RP-02` —
is **RESOLVED STABLE / RECURRENCE**.

The rail producer intentionally canonicalizes a closed rail: it verifies the repeated terminal
vertex equals the first, then removes it (`src/pipeline/RemeshPipeline.cpp:3579-3583`), so a closed
rail is `|V| = |E|` and its final interval is `back() -> front()`. The CP2 network builder required
`|V| = |E| + 1` for **every** rail and never read `rail.closed`, so it rejected every valid closed
production rail before the wraparound interval could be represented. Because A2a is a hard
production gate, one A2a-local defect fanned out into 17 retained M1-producer regressions.

Resolution does not decrement history: stable accounting remains **39 events / 14 categories / 25
recurrences**; produced-witness debt remains **5**.

## 5. Durable lessons from the CP2 arc

Recorded here as the checkpoint's own record; the general forms live in the handoff's
resume-critical lessons.

1. **A fixture that satisfies a contract's precondition trivially cannot falsify it.** CP2's
   `rails_from_atlas(...)` built one single-edge open rail per barrier, so `|V| == |E|+1` held
   unconditionally and six identities passed a builder that rejected every closed production rail.
   This was the second consecutive M3 checkpoint to ship a vacuously green gate — CP1's A1 fixtures
   were entirely planar where the contract was curvature-sensitive. The fix is procedural: every
   mandatory review now must check the checkpoint's fixtures against the contract's non-trivial
   domain.
2. **"Producer-equivalent setup" is the licence that defeats the check.** Name the shape the
   production producer actually emits and build the fixture in that shape.
3. **When a guard rejects early, every check behind it is unproven, not passing.** Three
   cross-closure checks had never executed on a closed rail; the fix's sufficiency was predicted,
   not evidenced, until the strengthened identity proved them positively.
4. **A representation with one writer and no enforcing reader is latent ambiguity.** All three
   wraparound consumers guard with `closed && back() != front()` and so tolerate both closed
   representations — which is why the diverging consumer stayed invisible until production runtime.
   Carried forward as a design-backlog item in `TODO.md`.
5. **A stop rule renegotiated every time it fires is not a stop rule.** The cumulative-ceiling
   amendment requested during this arc was the fifth; the regime was replaced rather than amended
   again.

## 6. Predecessor checkpoints — condensed

Full per-turn evidence for the following is in `CHANGELOG.md`; these summaries exist so the M3 plan
can remain forward-looking.

- **`M3-CP0-CB`** — authority census and compile only on `f51b7d7fc5b63c9efeeffabdf286a897119d75d9`,
  `32188666437 / 95878012079`, 121/121, `runtimeExecution=false`. It discharged the two open M3
  design obligations (A1 certificate/oracle definition; composition proof assigned to CP3b-TB) and
  split CP3 into CP3a/CP3b. `M3-CP0-TB` was **omitted by explicit user authorization** — an
  omission, never an acceptance. CP0 remains compile evidence only.
- **`M3-CP1`** — A1 field-transport/quadrangulability boundary. **ACCEPTED** on
  `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` by `M3-CP1-TB-R3`
  `32263614534 / 96102598799` at **281/281**. It cost 7 packages across four rejected runtime
  gates and three review turns. `PR8-R038 / M3-CP1-R001` (`AUTHORITY_DOMAIN_CONFLATION`, `RP-01`)
  is resolved: sparse-sparse cycle-basis aggregation retained explicit algebraic zeros that were
  read as semantic cycle support. Two review conclusions during that arc were themselves later
  corrected — the F5 congruence derivation, and the rescope review that declared the congruence
  false in general while omitting `indexMinFromZero` from the matching producer. Both corrections
  are recorded in the handoff's resume-critical lessons; neither is a live design position.

</details>

<a id="m3-archive-2"></a>
<details>
<summary><strong>Archived source 2: M3_CP2b_Closure_Record.md</strong> — Checkpoint CP2b acceptance</summary>

# M3 CP2b Closure Record — canonical branch topology and singularity-port attachment authority

Date: 2026-08-21 UTC
Status: **CP2b CLOSED / ACCEPTED.**
Accepted authority: source/package `1d2417c90970db81f8b49dd6e0961868cac32369 / 9428451548`, immutable `M3-CP2b-TB-R5` `32434684618 / 96633374819`, **292/292 PASS**.

This is the consolidated durable closure record for the inserted M3 CP2b checkpoint. Exact final-gate evidence is retained in `CHANGELOG.md` (retained exact TB-R5 evidence: `32434684618 / 96633374819`, result/log `9430381177 / 9430381560`); chronological attempt evidence remains in `CHANGELOG.md`; regression history remains in `Regression_Root_Cause_Tracker.md`.

## 1. Closure verification

| Check | Result |
|---|---|
| Immutable final gate | **PASS — 292/292**, 292 required / executed / unique |
| Accepted predecessor | **PASS — 287/287** |
| CP2b identities | **PASS — 5/5** |
| Combined selector | **PASS** — SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e` |
| Package/source authority | **PASS** — `9428451548 / 1d2417c90970db81f8b49dd6e0961868cac32369` |
| Package ZIP SHA-256 | **PASS** — `20dc884a38d865f34a14be66780ab7827cead4855a26cf0c1f945cee67131427` |
| Immutability | **PASS** — package and materialized source byte-identical pre/post |
| Runtime boundary | **PASS** — no checkout as semantic authority, rebuild, relink, repair, mutation, discovery, benchmark, CLI/fuzzer, or custom input |
| Final result artifact | `9430381177`, SHA-256 `41292ffef7231ef7010bd416aa6b730fd6022694933bc0c4b538abadb64bf8be` |
| Final log artifact | `9430381560`, SHA-256 `a789a6567c865e119deef69c295894078ce2621f7972912666c726b1b6b886a4` |

## 2. What CP2b delivers

CP2b completes the A1 authority that the CP3a census proved was missing before traversal could be implemented safely:

- canonical per-face branch frames;
- canonical branch-to-boundary pairings / interval authority;
- checked singularity-port starting-branch and exact local source attachment authority;
- reciprocal canonical Z4 branch transport whose integer lift is stored in the unique `[0,3]` representative rather than leaking gauge-dependent raw integer representatives into equality/hashing;
- independently validated branch topology and port attachments, including equivalent-Z4 relabel invariance and strict tamper rejection.

The accepted non-degenerate singularity witness publishes five incidences grouped into three semantic classes. Two incidences may legitimately share a start face and first outgoing carrier when they carry different branches; representative identity therefore includes branch.

**What CP2b does not claim:** branch-consistent traversal/candidate segments (CP3a), contact/intersection/termination graph authority (CP3b), global topology selection/disc proof (CP4), M4 conformity scheduling, or production-quality/resource guarantees.

## 3. Attempt trajectory

The original three-attempt window was exhausted without acceptance:

- attempt 1: source/package `740f0cca2f052d6274a7b24361bd33143f8c11f6 / 9388213803`, corrected immutable gate **285/292**;
- attempt 2: `bcf45fe28468b950987d52119548e06f411e4f19 / 9390283890`, immutable `32324880480 / 96294021816`, **289/292** with predecessor restored 287/287;
- attempt 3: `90c737e11c340061dd0167eaf59fec66afa0c8ba / 9392366234`, immutable `32331037070 / 96311550091`, **287/292**, CP2b 0/5 and predecessor 287/287.

Mandatory Review then restored a fresh three-attempt window and the diagnostic regime was exhausted at 2/2:

- restored attempt 1: R5 package `9416963557`, TB-R3 valid **288/292**, first exact semantic rejection `DuplicateSingularityPortRepresentative`;
- restored attempt 2: R6 package `9422702053`, TB-R4 `32418067075 / 96583693356`, **291/292**, with G1 partition and representative-key correction green; sole red isolated to the independent relabel validator while all direct product invariance checks passed;
- restored attempt 3: R7 package `9428451548`, TB-R5 `32434684618 / 96633374819`, **292/292 ACCEPTED**.

M3 cumulative package count through CP2b is **18**, reported only under the current regime. CP3a owns a fresh independent **3-attempt budget**; its attempt 1 remains unconsumed.

## 4. Root causes closed

`PR8-R040 / M3-CP2b-R001` and `PR8-R041 / M3-CP2b-R002` remain resolved stable recurrences; closure does not erase their historical counts.

Two non-stable CP2b candidates are also closed:

- `M3-CP2b-TB-R1-CAND-02` — architecture/product representative identity was rank-one because it omitted `branch`; corrected to `(startFace, branch, firstOutgoingCarrier)` and runtime-proven by the exact 5-incidence/3-class partition.
- `M3-CP2b-TB-R1-CAND-01` — the independent test oracle conflated raw gauge-dependent matching with canonical published Z4 transport. Product canonicalization was already positively supported by TB-R4. CB-R7 independently re-derived gauge/orientation/mod-4 authority in the oracle and retained `+1` rejection / `+4` equivalence; TB-R5 proves both the relabel positive and strict tamper negative green.

Stable accounting remains **41 / 14 / 27**; produced-witness debt remains **5**.

## 5. Successor boundary

Accepted CP2b becomes the frozen **292-identity predecessor** for CP3a. The prior CP3a census already froze six CP3a contracts, so its successor gate is **298 = 292 + 6** rather than the pre-CP2b provisional 293.

CP3a remains semantically untouched in this closure. The required next turn is the separate static `M3-CP2b-ACCEPTANCE-CLOSEOUT-CP3a-REPLAN`, which must reconcile the old CP3a census/plan against the concrete accepted CP2b authority and freeze the exact bounded Code + Build surface before implementation begins.

## 6. Independent closure verification — 2026-08-21

The acceptance claim was re-derived from source and artifact evidence at closure, not accepted from
the closeout report. **VERIFIED.**

| Check | Result |
|---|---|
| Gate reached 292/292 across ten partitions at exact cardinality | **PASS** — predecessor 287/287, CP2b 5/5; GTest JSON census independently reports 292 tests / 0 failures / 292 unique identities |
| Selector unchanged | **PASS** — CP2b 5 `56f5443c…`, predecessor 287 `2caa0189…`, combined 292 `fc6bfc2b…`, all matching the frozen digests |
| Immutability | **PASS** — no checkout as authority, no configure/compile/rebuild/relink/repair/discovery/benchmark/mutation; package and materialized-source postflight byte-identical; `harness-postflight.txt` PASS |
| **H5 — product frozen** | **PASS, verified from source.** `git diff 9fdb928f…1d2417c9 -- src/ include/` is **empty**. The atlas was genuinely untouched across CB-R7/TB-R5. |
| **One-file surface** | **PASS, verified from source.** The tests diff is exactly `tests/FieldTransportAtlasTests.cpp`, +133/-3. |
| **H1 — re-derivation, not relaxation** | **PASS, verified in source.** `independent_face_gauge(...)` (`tests/FieldTransportAtlasTests.cpp:642-702`) computes the oracle's **own** per-face gauge; `:1316` forms `canonicalLift = sourceMeasurement.matching + firstGauge − secondGauge` from its own measurement; `:1322` applies its own canonical-orientation rule; `:1324` reduces mod 4. **No `rawGauge*` symbol is read anywhere in the tests** — the oracle never reads the product's gauge. |
| **H4 — congruence pinned without pinning representative choice** | **PASS, verified in source** (`:2506-2530`). A `+1` displacement (`++nonEquivalent.forwardLift`) must reject with `NonReciprocalAdjacency`; a `+4` displacement must be **accepted**. |
| **H3 — oracle still strict** | **PASS.** The tamper identity retains specific-code rejections for pairing tamper (`InvalidBranchTopology`), attachment tamper and duplicate identity (`InvalidSingularityPortAttachment`). The correction did not produce a permissive oracle. |
| Part F/G predictions | **CONFIRMED.** 5 incidences / 3 classes / expected 3; the two face-0 incidences share `startFace=(0,1,4)` and carrier `(0,1)`, use branches `2` and `3`, and sit in distinct classes `0` and `1`. |

**Note on the first closure claim.** CP2b was reported closed once before this record existed, when
the TB-R5 gate had been *triggered* but no result was recorded anywhere. That claim was rejected: a
control-plane commit is never runtime evidence, and no closure record was written and no per-turn
document retired until the gate result was supplied. The evidence above is what the second claim
supplied and what this verification checked. The durable rule is in `LESSONS.md` section 1.

</details>

<a id="m3-archive-3"></a>
<details>
<summary><strong>Archived source 3: M3_CP3_Closure_Record.md</strong> — Checkpoint CP3a/CP3b acceptance</summary>

# M3 CP3 Closure Record — A2a field-aligned curve network

Date: 2026-08-21 UTC
Status: **CP3a CLOSED / ACCEPTED at 298/298. CP3b CLOSED / ACCEPTED at 304/304.**

This is the consolidated record for the two halves of A2a. It replaces the retired per-turn CP3a/CP3b
census, plan, build, diagnostic, and test reports. Exact per-turn runtime evidence remains newest-first
in `CHANGELOG.md`; regression adjudication remains in `Regression_Root_Cause_Tracker.md`.

## 1. Closure verification

Both claims were independently verified at closure from source and CI evidence rather than from the
closing reports. What was checked, and what it showed:

| Check | Result |
|---|---|
| Both semantic source SHAs exist as commits on the working branch | PASS |
| Both acceptance runs/jobs exist, `conclusion=success` | PASS |
| Job step lists contain no configure/compile/rebuild step | PASS — artifact-only confirmed structurally, not just by report assertion |
| Trigger SHA on each run matches the report's declared event SHA | PASS |
| CP3b result/log artifact SHA-256 digests match the report | PASS — `c88f8505…` and `18a5cfb0…` both matched exactly |
| The six CP3a and six CP3b identity names exist in source, exactly as frozen | PASS — 12 of 12 |
| `tests/FieldTransportAtlasTests.cpp`, `tests/support/`, `RemeshPipeline.cpp` frozen across CP3a corrective work and all of CP3b | PASS |
| Gate arithmetic 292 + 6 = 298 and 298 + 6 = 304 | PASS |

**Both closure claims are VERIFIED.**

## 2. Accepted immutable authority

| | CP3a | CP3b |
|---|---|---|
| Semantic source | `558a35c67919d54899c53de11dc9c69b6dfc9519` | `611b3f8f3926792baee9d1078d6677d22006a6c4` |
| Immutable package | `9435408599` | `9456073195` |
| Package ZIP SHA-256 | `8d31055edb7fbdbcaed1ad168dc9e1b9e2493d577429d88989589715f6009c94` | `6126acc44121ae6ca05f8b01f075bd26ce72e4f08851c80d09209c2a225a3c31` |
| Acceptance run / job | `32485441510 / 96780835699` | `32515222447 / 96875297990` |
| Result / log artifact | `9447743880 / 9447744442` | `9458599611 / 9458599992` |
| Own selector (6 ids) | `fa9bab1118b80f4727fb1ca7361b2967061d95d8a9e7de667d3648599e3b227b` | `4e9bc4a9697ab86f13a85effccbf20eb3c4debdd11fa4920c4b3213479b0ba8d` |
| Combined selector | 298 at `44dede9235fb53b486e351c02f87d4f8d5044e50ec77df6d7befbf072dfb5a25` | 304 at `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666` |
| Gate | **298/298** | **304/304** |
| Acceptance attempts | **1 of 3** consumed, green | **1 of 3** consumed, green |
| Diagnostic gates | **2 of 2** used (red 2/6, then green 6/6) | none allocated, none used |

Both gates recorded zero failures, `generatedDiscovery=false`, and byte-identical package/materialized-source
postflight.

## 3. What each half delivered

**CP3a — branch-consistent combinatorial tracing into candidate segments.** Traversal *consumes*
accepted CP2b branch topology and never re-derives frames, gauge, or interval classification. Each
candidate trace seeds from a typed port attachment's checked start face and starting branch; each
per-face step selects its outgoing interval combinatorially from the face pairing; each adjacency
crossing updates branch identity only through atlas-owned typed transport; mandatory barriers are
recognized before crossing and terminate the segment.

**CP3b — typed first-contact / intersection / termination event graph.** Events carry typed kinds
(`SingularityPortOrigin`, `FirstContact`, `TraceIntersection`, `MandatoryBarrierTermination`) with
typed incidence roles. Crossings become graph nodes at declaration time. An independent test-only
composition oracle validates the graph without calling the production validator.

**Neither claimed:** global topology selection, region emission, disc proof, M4 scheduling, or repair
of any accepted upstream product.

## 4. The CP3a arc — one red diagnostic, one corrective build, accepted first try

CP3a's first package `9432965083` was runtime-free; its attempt-free diagnostic came back **red 2/6**.
Independent review classified the four reds into two causes and authorized corrective measures J1–J6.
The corrected package went green **6/6** on the second and final diagnostic (`32463985548 / 96716645034`),
then accepted at 298/298 on acceptance attempt 1. The diagnostic-gate mechanism did exactly what it was
added to do: it bought two rounds of semantic evidence for zero acceptance attempts.

Two findings drove the correction, and both are worth keeping:

**The one-ring witness was topologically incapable of the contract it was asked to prove.** CP3a's plan
directed reuse of the accepted CP2b skew-fan witness on the reasoning that it was already proven
non-degenerate through a green gate. That reasoning was wrong, and the review that produced it was mine.
In a one-ring fan every edge opposite the singular vertex is a boundary edge, so multi-face traversal
cannot occur on that mesh at all — the non-vacuity requirement was unsatisfiable by construction. Being
green in a *previous* checkpoint's gate says the witness was adequate for *that* contract, not this one.
The fix was a genuine two-ring skew disc (11 vertices, 15 faces) whose singular-fan opposite carriers are
interior, and — critically — a runtime `ASSERT` in the fixture that *every* singular-fan opposite carrier
is interior, so the same mistake cannot be made silently again.

**One digest was carrying two semantic domains.** The network's semantic digest folded in the full
`field_transport_atlas_hash`, which is gauge-dependent. That made a *semantic* identity vary under a
consistent per-face Z4 relabel of the same physical field. The fix split the two roles: the digest now
consumes `branch_topology().semantic_digest()` (gauge-invariant), while the full atlas hash is retained
separately for binding/provenance verification. The accepted negative asserts both halves explicitly —
that the branch-topology digest is *equal* across a gauge relabel while the raw atlas hash *differs*.

## 5. The CP3b arc — accepted first try, no diagnostic needed

CP3b needed no diagnostic gate and consumed one acceptance attempt. Its only pre-package friction was a
compile-only defect (`std::vector::resize` on an intentionally non-default-constructible element type,
repaired to iterator `erase`) and a control-plane glob collision. Both are resolved compile-only /
orchestration and non-stable.

CP3b carried the CP3a fixture lesson forward without being told to: every one of its six identities
establishes that the thing it is about to assert on actually exists — a non-null event of the required
kind, at least two distinct incident traces, more than two events before reversing them — before
asserting any property of it. This is the first M3 checkpoint authored with non-vacuity guards built in
from the start rather than added after a red gate.

## 6. Carried debt — two plan obligations have no owning identity

The frozen six-identity CP3b selector is **narrower than plan section 4A.2's six-item obligation list**.
Everything the six identities assert is real and non-vacuous, and the gate is legitimately green. But two
named obligations were never assigned an identity, so nothing proves them:

1. **Rotation-system / face-walk consistency** (section 4A.2 item 5). The independent oracle checks five
   of the six named sweep properties — earliest declared contact, no undeclared interior crossing,
   exactly one terminal owner per trace, exactly-once port consumption, and terminal-kind agreement with
   barrier presence. It performs **no** rotation-system or face-walk check. Order-invariance is covered
   by a sibling identity.
2. **Crossing tamper** (section 4A.2 item 6). `RejectsContactCrossingEventOrIncidenceTamper` tampers a
   missing contact event and an incidence role. No case tampers a `TraceIntersection` crossing.

Neither is grounds to reopen an accepted green gate. Both transfer to CP4, which is the M3 exit gate and
must prove the section 2 criteria anyway — criterion 5 (structural cleanliness) and criterion 9
(independent/tamper evidence) are the criteria that own them. They are listed in the CP4 task list and in
`TODO.md` so they cannot be lost.

The general point is already in `LESSONS.md` section 6: a plan's prose obligation list and its frozen
selector are two different artifacts, and only the second one is enforced. Reconcile them item-by-item
before freezing, not after.

## 7. Cost and accounting

- CP3a: 2 packages (`9432965083`, `9435408599`), 2 diagnostic gates, 1 acceptance attempt.
- CP3b: 1 package (`9456073195`), 0 diagnostic gates, 1 acceptance attempt.
- Cumulative M3 packages: **21**, reported only — the per-checkpoint attempt regime gates on attempts,
  not on package count.
- Stable regression accounting is unchanged at **41 events / 14 categories / 27 recurrences**. Every
  CP3a and CP3b candidate (`M3-CP3a-DG-CAND-01/02`, `M3-CP3a-TB-CAND-01..04`, `M3-CP3b-CB-CAND-01/02`,
  `M3-CP3b-TB-CAND-01..04`) is resolved and non-stable; none is a product regression.
- Produced-witness debt is unchanged at **5** (3 → M4 via `G4-B002`, 2 → M5 via `G4-B003`).

Eight of the twelve resolved candidates across these two checkpoints were **orchestration/transport**
failures, not semantic ones — malformed YAML, permission ceilings, base64/gzip corruption, changed-path
guards missing untracked files. They consumed no acceptance attempts and produced no runtime, but they
did consume real turns. That ratio is itself the signal: at this point the control plane is a larger
source of lost turns than the mathematics is.

## 8. Trajectory

**A2a is complete and accepted.** A1 transport authority (CP1) plus branch/interval/port-attachment
authority (CP2b) plus branch-consistent candidate traversal (CP3a) plus typed event incidence and
composition validation (CP3b) together satisfy the `DESIGN.md` A2a requirement. No checkpoint
implemented M4+ work and no checkpoint repaired an accepted upstream product.

**A2b remains, and it is CP4's** — topology-plan derivation, plus the cumulative M3 exit gate. The CP4
decomposition and its four sub-checkpoints are in
`Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` section 4A.3.

</details>

<a id="m3-archive-4"></a>
<details>
<summary><strong>Archived source 4: M3_CP4ab_Closure_Record.md</strong> — Checkpoint CP4ab acceptance</summary>

# M3 CP4ab Closure Record — global topology plan and per-region disc authority

Date: 2026-08-24 UTC
Status: **`M3-CP4ab` CLOSED / ACCEPTED at 316/316.**

This is the consolidated closure record for the merged CP4a/CP4b checkpoint after the mandatory rescope. It does not replace the binding DEFN amendments or independent-review decisions; it records what was finally accepted, what it proves, and what remains for CP4c.

## 1. Closure verification

| Check | Result |
|---|---|
| Accepted semantic source is the CB-R11 package source | PASS — `157bf784a9cdd2765018206ae0ac26729ed7a584` |
| Immutable package identity/digest preserved | PASS — `9527801615`, `a8e03a21…54557` |
| Package manifest before/after runtime | PASS — 27/27 both times |
| Five packaged source-status snapshots | PASS — all empty |
| Exact source archive before/after runtime | PASS — `498cbb58…ab157`, unchanged |
| Frozen predecessor selector | PASS — 304 unique at `c05a4c43…b666` |
| Frozen CP4ab selector | PASS — 12 unique at `7e7e32f1…34ec` |
| Cumulative selector | PASS — 316 unique at `601ce2b6…0193c` |
| Accepted predecessor surface | PASS — 304/304 |
| CP4ab surface | PASS — 12/12 |
| Cumulative acceptance gate | **PASS — 316/316** |
| Configure/build/relink/repair/discovery in TB-R3 | PASS — none executed |
| Source/test/fixture/selector/package mutation in TB-R3 | PASS — none |

**Closure claim: VERIFIED.**

### 1a. Independent verification, 2026-08-24

The table above is the closing turn's self-report. It was re-verified independently against GitHub's
API and the repository, not accepted as written.

**From the GitHub Actions API:**

| Check | Result |
|---|---|
| Run `32758293793` exists, is "Agent M3 CP4ab TB-R3 Execution", on the working branch | PASS — `conclusion: success` |
| Result artifact `9531769503` digest | PASS — `sha256:1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`, exact match |
| Log artifact `9531770393` digest | PASS — `sha256:cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`, exact match |
| Package `9527801615` provenance | PASS — it is `m3-cp4ab-cb-r11-result-32747790694`, digest `sha256:a8e03a21…54557`, exact match |

**From the job log of `97530833220`** (the machine JSON emitted by the run itself):
`gate.required=316 / executed=316 / failures=0`; `acceptedPredecessor 304/304/0`; `cp4ab 12/12/0`;
`orchestrationErrors=0`; `configure/build/relink/repair/generatedDiscovery` all `false`;
`sourceMutation/testMutation/fixtureMutation/selectorMutation/packageMutation` all `false`;
`package_zip_post_sha256` and `source_archive_post_sha256` equal to their preflight values;
`manifest_post_count=27`; `sourceCommit=157bf784a9cdd2765018206ae0ac26729ed7a584`.

**From the accepted source tree at `157bf784`** — the check that matters most, because a green gate
proves the package passed, not that it implements what the binding Review required. All four V-series
semantic corrections are present:

| Measure | Verified at |
|---|---|
| V1 — `validate_single_boundary_walk` hoisted above `region_orbit` inside `build_region_certificates`, both call sites covered | `GlobalTopologyPlan.cpp:2440` before `:2444`; defensive call retained at `:2115` |
| V2 — canonical candidate hoisted once, ownership comparison under the id+boundary guard that keeps B3 green | `GlobalTopologyPlan.cpp:2686-2747`, guard variable `canonicalRegionBoundaries` |
| V4 — B4 Euler identity excludes exterior orbits | `tests/FieldAlignedCurveNetworkTests.cpp:1896-1900`, subtracts `partition->exteriorOrbits.size()` |
| V5 — B4 publishes a typed failure reason instead of a bare bool | `IndependentDiscProofResult independent_disc_proof_oracle(...)` at `:1879`; test prints `embedded_graph_chi` at `:2398` |

**Independent verdict: the closure claim is correct.** The gate is real, the artifacts are the ones
named, the package is the one built from the accepted commit, and the accepted source implements the
binding corrective measures rather than merely passing.

### 1b. Consolidation defect found and repaired at closure review

The closing turn retired **34** CP4-era per-turn documents (~6,300 lines) into this record. The
retirement itself is sound — the content that remained load-bearing had already been inlined into
`Architecture_M3_CP4_DEFN_Frozen_Definitions.md` amendments 1–12, which were re-read and confirmed
self-contained. Two defects were introduced and are repaired at this review:

1. **Twelve normative attribution lines in DEFN, and two in the M3 Code + Build Plan, cited retired
   documents without saying they were retired.** A future agent following `binding)` would find no
   file. Each is now annotated as retired-provenance; no amendment content changed.
2. **Every current routing pointer named "section 4A.3c", which has never existed.** CP4c's content
   was the `#### M3-CP4c` subsection of §4A.3 — a scope statement, not a decomposition. Routing now
   points at `M3_CP4c_Consolidated_Record.md`.

### 1c. Final CP4ab per-turn report retirement — 2026-08-31

`M3_CP4ab_Closure_Record.md` was the last remaining CP4ab
per-turn report. It is now retired into this closure record; its authoritative acceptance facts were already
represented in §§1–2 and are unchanged. The remaining non-duplicated provenance from that report is retained here:

- schema validation run/job `32758229076 / 97530617094` passed before acceptance execution;
- the frozen selector hashes were predecessor 304 `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`,
  CP4ab 12 `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`, and cumulative 316
  `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- the package source archive was materialized without stripping its recorded root layout, the known plane fixture
  was present, and fresh pre/post-runtime extractions were byte-identical with zero-byte source diffs;
- the report recorded one process-only ordering miss: connector schema discovery preceded the mandatory tool-use
  policy read, but no repository inspection, runtime, semantic mutation, or acceptance authority was affected.

The retired report's exact bytes remain recoverable from Git history. No current or future authority points to it.

## 2. Accepted immutable authority

- semantic source: `157bf784a9cdd2765018206ae0ac26729ed7a584`
- immutable package: `9527801615`
- package ZIP SHA-256: `a8e03a2181ab4ce2de7386d6b38d66cd361a739f21aa33dde6091a6a2fa54557`
- source archive SHA-256: `498cbb586c8b5dd1d49c3442364b9483d9f04e6d999432a93e72caa9cb4ab157`
- compile/package run/job: `32747790694 / 97497441516`
- acceptance run/job: `32758293793 / 97530833220`
- acceptance result artifact: `9531769503`, SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`
- execution log artifact: `9531770393`, SHA-256 `cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`
- cumulative gate: **316/316 PASS**
- acceptance cost: **1 of 3**, green
- final diagnostic cost before acceptance: **1 of 2**

## 3. What CP4ab delivers

CP4ab establishes the production A2b global topology-plan layer on the accepted A1/A2a network authority:

1. regions are faces of the embedded network graph rather than an unrelated source-face partition;
2. the published rotation system is consistent with typed network events;
3. every source face has exactly one canonical region owner under the reviewed fragment model;
4. mandatory source boundary and hard-feature topology is preserved;
5. region authority is invariant to enumeration order and equivalent branch relabeling;
6. every emitted region carries a checked disc certificate with a single boundary walk, connected fragment interior, correct bounded-surface Euler relation, and no forbidden interior singularity;
7. independent test authority recomputes the disc proof rather than mirroring the production validator;
8. ownership, boundary-walk, Euler/interior-singularity, certificate, network-binding, and unestablished-transport tamper surfaces reach typed owning validators.

The accepted corrections preserve the binding K2R/K3R fragment ownership, reviewed fragment adjacency, pinch rejection, fan-anchored port order, and validation ordering. The final B4 oracle uses the bounded-surface relation with exterior orbits excluded rather than the withdrawn capped-surface formula.

## 4. What CP4ab does not claim

CP4ab does **not** close M3. It does not add or accept the two representative CP4c witnesses, does not prove the six C identities, and does not run the 322 exit gate. It also does not repair or claim progress on downstream `G4-B001`, `G4-B002`, `G4-B003`, or `G4-B004` product blockers.

CP4c remains responsible for:

- **wiring `GlobalTopologyPlan` into the production entry path** — established at this review and not
  previously recorded anywhere: `GlobalTopologyPlan` is constructed **nowhere** in
  `src/pipeline/RemeshPipeline.cpp`. A2a is wired (`:6587`, published at `:6604-6605`); A2b is not, and
  no product slot for it exists. C1/C2's "…ThroughProductionEntryPath" is therefore not satisfiable
  today by fixtures alone;
- the periodic/torus-style production M3 witness;
- the feature-bearing mechanical-style production M3 witness;
- carried CP3b rotation-system/face-walk consistency and crossing-tamper obligations;
- the six frozen C1–C6 identities;
- the cumulative **322 = 316 + 6** M3 exit gate.

CP4c's decomposition is `M3_CP4c_Consolidated_Record.md`.

## 5. Regression closure

`PR8-R042 / M3-CP4b-R001` (`RP-01 / AUTHORITY_DOMAIN_CONFLATION`) is **RESOLVED STABLE** at this gate. The same accepted-predecessor A identities that had regressed are green under the cumulative 316 acceptance surface. Focused DG evidence alone did not close the event; TB-R3 does.

Stable accounting remains **42 events / 14 categories / 28 recurrences** and produced-witness debt remains **5**. Resolution changes status, not historical event totals.

## 6. Cost and trajectory

The merged checkpoint required multiple review/correction arcs because the original CP4a/CP4b split, whole-component ownership, fragment-disc proof, Euler reduction, singularity-port ordering, barrier terminus representation, validation ordering, and independent-oracle boundary arithmetic each had to be corrected without weakening the frozen acceptance contracts.

Final cumulative M3 package count is **34** at CP4ab closure. The final accepted package is CB-R11 `9527801615`; TB-R3 consumes acceptance attempt 1/3 and no new package. The final reset diagnostic window consumed one gate at DG-R6.

With CP4ab accepted, A2b's region/disc-authority portion is complete. The exact next bounded turn is `M3-CP4c-CB`; CP4c has its own untouched 3-attempt budget and its planned diagnostic gate.

---

## Folded document index — DURABLE, DO NOT DELETE

The 35 per-turn CP4ab documents below were folded into this closure record in an earlier consolidation. On **2026-09-03** every remaining reference to them across the project was redirected here, so their names no longer appear as live pointers. This index keeps the mapping legible; the full text of each remains in git history (`git log --diff-filter=D -- .agents/Directional/<name>`).

- `Architecture_M3_CP4ab_CB_R5_Package_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_CB_R7_Precondition_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R8_S0_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R8_S0_Static_Precondition_Stop_Report.md`
- `Architecture_M3_CP4ab_DG_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4ab_DG_R2_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R3_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R3_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R3_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R4_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R4_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R4_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R5_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R5_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R5_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R6_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_R10_Terminal_Zero_Cell_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R11_Validation_Ordering_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R2_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R2_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R3_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R4_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R5_Instrumentation_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R6_Static_Authority_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R9_Mandatory_Arc_Split_Code_Build_Report.md`
- `Architecture_M3_CP4ab_TB_R1_Independent_Review.md`
- `Architecture_M3_CP4ab_TB_R2_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4ab_TB_R2_Independent_Review.md`
- `Architecture_M3_CP4ab_TB_R2_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_TB_R3_Artifact_Only_Test_Benchmark_Report.md`

</details>

<a id="m3-archive-5"></a>
<details>
<summary><strong>Archived source 5: M3_CP4c_Consolidated_Record.md</strong> — CP4c consolidated turn history and protected folded-document index</summary>

# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the `M3-CP4c` family. Completed or superseded per-turn plans, reports,
review records, and diagnostic selector records are folded into this file once they are no longer required for
current or future work. Normative definitions, frozen selector lineage, current review authority, and the active
CP4c-3 gate remain separate. For execution authority, use `Future_Chat_Session_Handoff.md` and `TODO.md`.

**Current state — see `M3_CP4c_Current_And_Forward.md`.** Since 2026-09-03 this record holds **history only**.
As of `M3-CP4c-3-TB47-REV`, CP4c-2 is CLOSED / ACCEPTED and CP4c-3 remains OPEN.
**TB47/package112/selector409 is promoted runtime authority** — **404 PASS / 5 RED / 0 SKIP**, accepted 365/365,
ownership 300/0/0. Stable accounting is 47 events / 14 categories / 33 recurrences, debt 5, packages 112. Exact
next is runtime-free **`M3-CP4c-3-CB54`** under
`Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md`.

Current/future CP4c authority intentionally remains outside this history record:

- `Architecture_M3_CP4c3_TB47_EXEC_Report.md` — current runtime report;
- `Architecture_M3_CP4c3_TB47_Independent_Review_Record.md` — current review authority;
- `Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md` — single exact next-turn plan;
- `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
  `Required_Green_Selector_Manifest.md`, and every byte-frozen `Required_Green_Selector_*.txt`;
- durable closure/architecture/tracker/lesson records cited by those current authorities.

All other superseded CP4c-3 per-turn files with no live current/future dependency are folded below and retired from
the working tree. Git history remains the exact-byte recovery source for every retired file.

`DESIGN.md` §7.2/§7.2.1 remains architecture authority. Current status, regression accounting, workflow lessons, and
orientation context remain in `Future_Chat_Session_Handoff.md`, `TODO.md`,
`Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, `LESSONS.md`, and `ORIENTATION.md`.

The retained selector lineage is intentional. DEFN-R2 AG0 requires superseded/withdrawn selector files to remain
historical authority, and CP4c-3 verifies frozen prefix continuity. Current hashes remain recorded in the durable
selector table below.

| Authority | SHA-256 |
|---|---|
| accepted 355 prefix | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| accepted 365 prefix | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| CP4c-3 selector 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| CP4c-3 selector 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **CP4c-3 selector 373** | **`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`** |
| **CP4c-3 selector 374 (gate)** | **`d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`** |
| CP4c-3 selector 375 (diagnostic) | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` |
| **CP4c-3 selector 376 (TB9 execution / identity 376 diagnostic)** | **`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`** |
| **CP4c-3 selector 377 (TB10/TB11 execution; frozen prefix)** | **`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`** |
| **CP4c-3 selector 378 (TB12 execution / diagnostic projection)** | **`86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`** |
| **CP4c-3 selector 379 (TB13 execution / frozen prefix)** | **`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`** |
| **CP4c-3 selector 380 (TB14 execution)** | **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`** |
| **CP4c-3 selector 381 (TB15 execution / frozen prefix)** | **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`** |
| **CP4c-3 selector 382 (TB16 execution / current selector)** | **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`** |

## 2. Checkpoint closure record

| Checkpoint | Closed responsibility | Accepted result |
|---|---|---|
| **CP4c-0** | exact resolved continuation and grazing | **346/346 CLOSED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival | **353/353 CLOSED** |
| **CP4c-1** | observability, diagnosability, non-vacuous terminal events | **355/355 CLOSED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | **365/365 CLOSED** |
| **CP4c-3** | mechanical witness / field-aligned continuation plus inherited CP4c-2 debts | **OPEN; TB47/package112 is reviewed runtime authority at 404 PASS / 5 RED, accepted 365/365. Ordinal367 recovery is closed; exact next is runtime-free CB54 for ordinal370 AK5 typed rejection.** |

### 2.1 CP4c-0

Continuation requires exact entry position plus barycentric direction. Branch labels are face-gauge-local; cross-face semantics use published transport/lift. Grazing is exact `Inflow/Tangent/Outflow`; edge transit is used when both adjacent faces drive along the carrier; no tolerance decides topology.

### 2.2 CP4c-0b

The initial termination theory was withdrawn. The accepted S0–S8 contract is exact crash-on-contact with fixed arrival priority and canonical tie handling; arithmetic guards are backstops, not semantic policy.

Accepted authority: source `93059089881c8715a168a61968a8d6874ee1a670`, GMP package `9671190795`, package SHA-256 `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`, T5 run/job `33136084757 / 98736295227`, selector **353** SHA-256 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, final **353/353 PASS**. Non-gating U3/U4 census was **4/4 PASS** with zero gate credit. The prescribed sphere publishes 24 traces.

### 2.3 CP4c-1

C4/C5 closed the diagnosability and event-non-vacuity surface: tampered trace-intersection crossing data is rejected; every produced trace ends at exactly one actually produced typed terminal event; required terminal kinds are non-vacuously represented without forbidding lawful frozen kinds.

Accepted authority: source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`, GMP package `9675666067`, package SHA-256 `63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`, TB-R5 run/job `33161644741 / 98817323175`, selector **355** SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, final **355/355 PASS**. Observed terminal-kind union was exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}`. The torus lawfully contributes zero trace/event kinds; the mechanical witness remained outside CP4c-1 reach at `IncompleteCycleBasis`.

### 2.4 CP4c-2 accepted result

A2a′ `SurfaceCutGraph` is the certified pre-region authority. On the closed genus-1 torus it converts a non-cellular network to a certified cellular embedding with **28 cut edges**; A2b derives **4** regions; and the independent oracle reconciles the actual graph exactly: `V/E/F = 72/76/4` and `76 − 48 = 28` selected cut edges. Cellularity is certified over the **actual embedded graph** (Amendment 13), trace-crossed source edges are admissible cuts with proved completeness (Amendment 14), semantic and provenance identities are distinct, and enumeration invariance is explicitly proved. Criteria **C1**, **C3**, and **C6** are green.

Accepted authority:

- semantic/test source: `57444781af7bdc460e38cc68930a9a8c8199eeea`
- GMP package **67**: artifact `9736088354`
- package SHA-256: `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`
- packaged source archive SHA-256: `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`
- R10 run/job: `33331453506 / 99310594268`
- R10 result artifact: `9737796927`, SHA-256 `b02022367785d6a4790549ad127bff69f831404b6ea525f426b707794f71649b`
- R10 diagnostic artifact: `9737797177`, SHA-256 `0a374b6b240877049eacfec2c70be944c39ce3cc4e5a6c461c358a1b206e78c8`
- selector **365** SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- final gate: **365 executed / 365 PASS / no first red**
- immutable pre/postflight: PASS; configure/compile/relink/repair/generated-discovery/source/test/fixture/selector/package mutation and benchmark execution all false.

CP4c-2 deliberately does **not** claim more than that accepted gate. The prescribed sphere still reaches `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28` before cut selection, and its independent pre-cut actual-graph oracle is non-cellular (`V/E/F = 18/30/18`, `chi=6` versus `sourceChi=2`). Amendment 14's ordinary trace-crossed proposal path was proved structurally unreachable because `traceCrossed` remained in the proposal barrier set, leaving saturation as the only promotion path (`R10-CAND-01`). The zero-node/zero-arc closed-surface behavior was also unresolved at CP4c-2 closure (`R8-CAND-02`). All three were explicitly transferred to CP4c-3 rather than silently treated as green.

## 3. CP4c-2 consolidated turn history

### 3.1 Amendment 12 — certified pre-region authority

A2a′ was introduced as a certified cut-graph authority before A2b region derivation. Repair/re-cutting after `GlobalTopologyPlan` regions exist remains forbidden. This moved topology reconciliation to the only permitted stage where a cut can legitimately change region topology.

### 3.2 Amendment 13 — actual embedded graph, not a proxy

R5 falsified the whole-source-face/source-edge-barrier partition as cellularity authority: proxy arithmetic could be internally self-consistent while certifying the wrong object. Amendment 13 makes the **actual embedded graph of `FieldAlignedCurveNetwork ∪ cutEdges`** normative. Graph/cut nodes are vertices, graph/cut arcs are edges, and dart orbits under the node rotation system are faces. Source-edge barriers remain proposal/diagnostic provenance only. The shared implementation authority is `EmbeddedGraphTopology.{h,cpp}`; the still-binding conventions live in DEFN-R1 §§4/5/7/9.

### 3.3 Semantic/provenance correction, CB5, and R7 re-proof

R6 exposed representation-dependent semantic identity. `candidate_hash` retains gauge-dependent `atlasDigest` for provenance/tamper rejection, while semantic identity excludes it.

CB5 semantic source `755485865a7cf9c485d754f22b82a41ee151824b` produced package **64**, artifact `9719216316`, SHA-256 `acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, packaged source archive `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`, compile run `33267732093`, with GMP/GMPXX, `28/28` manifest PASS, and `runtimeExecution=false`.

A first R7 orchestration attempt stopped before runtime because prose contained fabricated abbreviated selector hashes. The durable correction is that selector authority is the committed bytes and hashes are always recomputed as full 64-lowercase-hex values. Corrected R7 run/job `33276039911 / 99162853852` consumed package 64, re-proved **355/355 PASS**, and produced result artifact `9721564203` (SHA-256 `a854e562facfd616f9f61eddf653dc9e5814c3b932661993b2b2861b2bdab8db`) and log artifact `9721564377` (SHA-256 `8edd56072491aa4267e3cd0d2c0942b0910a3e5a01f15e6bc21164bd0fbef3ec`). The run was immutable and artifact-only.

The then-frozen non-gating diagnostic selector contained exactly one identity, `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`. R7 ran four other diagnostics without executing that frozen identity or documenting a rationale. This became the durable lesson that a frozen non-gating selector is authority: every listed identity must run or be explicitly justified.

### 3.4 Sphere re-localization and CB6 definition stop

`SurfaceCutGraph::topology_error` was found to collapse 36 upstream `GlobalTopologyPlanErrorCode` values into `CellularityNotEstablished`; the sphere producer code was therefore not itself a cellularity verdict.

CB6 obeyed the frozen-definition trigger and stopped before implementation, compile, package, or runtime. From retained R7 result artifact `9721564203`, the independent actual-graph oracle reported `V=18, E=30, F=18, c=1, chi=6, sourceChi=2, excludedBoundaryOrbits=0`, `complex=actualEmbeddedGraph`, and `surfaceCutGraphCallsInsideOracle=0`. The prescribed sphere is genuinely **non-cellular pre-cut** while the producer also fails earlier through lossy error translation. Stable accounting stayed **44 / 14 / 30**, debt **5**, packages **64**.

### 3.5 Amendment 14 and CB7

DEFN-R2 proved the prior exclusion of trace-crossed source edges was based on a false representation premise. `build_arcs` already emits trace arcs at published event boundaries; subdivision occurs only in the derived arrangement, not in the immutable network. Amendment 14 therefore admits every non-network source edge as a cut, uses exact canonical crossing order, subdivides trace/cut arcs at published crossings, generalizes the edge-locus rotation system, and proves completeness through a source-1-skeleton saturation fallback.

CB7 semantic source `4f0f3ca74a88ba260a20c019437bc4995f2056e0` implemented that scope and froze selector **365**. Build-transport source `1230621baff6d04fb20df3b1bf48903cd65b5d69` differed only by the verified Eigen mirror transport at the same gitlink. Compile run/job `33287281975 / 99192562149` produced package **65**, artifact `9724864897`, SHA-256 `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`, packaged source archive `3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544`, with all standard targets linked against GMP/GMPXX and no runtime.

### 3.6 R8 witness defect and CB8

R8 consumed package 65. Accepted **355/355** and ordinals **356–358** passed, then ordinal **359** failed before enumeration comparison because its baseline `SurfaceCutGraph::make(...)` returned false; ordinals 360–365 were correctly not run under first-red hard stop. Result artifact `9725240893` (SHA-256 `056a3597183d6bb40d84038db164c0b8e0d2daea1f05468afc270dcd464a5229`) and log `9725241013` recorded an immutable artifact-only run.

Independent review classified `R8-CAND-01` as a **witness-construction / authority-surface mismatch**, not a product regression: the ordinal-359/361 test-local rail authority did not use production `authoritativeRails`, and related source authority fields were incomplete. Stable totals therefore did not change.

CB8 corrected only those witness identities and typed test helpers; no product implementation changed. Semantic/test source `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`, transport source `997d215e9ce0502f4a10afc62d08b2cd1fb3b037`, compile run/job `33292137782 / 99205507393`, package **66** artifact `9726295440`, package SHA-256 `1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`, packaged source archive `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`. Build was GMP/GMPXX, runtime-free, manifest `28/28 PASS`.

### 3.7 R9 product red and CB9 correction

R9 run/job `33319911575 / 99279955697` consumed package 66, re-proved accepted **355/355**, passed **356–362**, and first-red hard-stopped at **363** with `InvalidCutGraphBinding`. Result/log artifacts were `9734625006 / 9734625165`. Static review proved the crossing producer was correct: exact `ExactUnitParameter` ordering, coincident crossings rejected rather than merged, and every sub-arc emitted in canonical `first()→second()` direction.

The defect was downstream A2b consumption of Amendment 14. A selected trace-crossed source edge legitimately owns multiple derived Cut sub-arcs, but region binding still required exactly one. Review also found a second stale consumer: the region-certificate `boundaryVertices` skip list over-inserted whole-source-edge endpoints, suppressing the interior-vertex ownership check. `R9-CAND-01` was therefore a genuine non-stable product defect while CP4c-2 was still unaccepted.

CB9 semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` corrected **exactly those two stale consumers**, added the requested fragment/orbit diagnostics, annotated the already-proved ordinal-359 semantic-digest rationale, and made typed-error helpers stop before `built.value()` fall-through. Compile-only run `33325344311`, prepackage job `99294371782`, package job `99294619815`, produced package **67** artifact `9736088354` with the accepted hashes listed in §2.4. No selector, error enum, sphere correction, crossing producer, benchmark, or unrelated product behavior changed.

### 3.8 R10 execution and independent closure review

R10 consumed immutable package 67 directly. Preflight validated package/source hashes, `28/28` internal manifest, GMP/GMPXX evidence, executable modes, selector hashes/cardinality/uniqueness, and exact identity resolution. The required-green selector executed one identity per fresh process and finished **365/365 PASS** with no first red. Ordinals 356–365 all passed, including first execution of 364 and 365.

Three frozen non-gating diagnostics executed: **2 PASS / 1 RED**. The prescribed-sphere scope publisher remained report-only red; cut-graph failure localization and the actual embedded-graph cellularity oracle passed. Ordinal 363 published **50** `fragment_reconciliation` rows and **128** `cut_edge_orbit_evidence` rows. AH6 showed `ordinary_proposal_selected_trace_crossed_edge=no` and `saturation_used=yes`; exact selected edge/locus/promoted count were not observable from the frozen test output.

R10-REV accepted the execution as valid, audited the CB8→CB9 conversion line by line, **closed `R9-CAND-01`**, opened `R10-CAND-01` as a non-stable quality/coverage debt, retained the sphere's two independent issues, and carried `R8-CAND-02` forward. It then **CLOSED / ACCEPTED CP4c-2 at 365/365**. Stable accounting remained **44 / 14 / 30**, debt **5**, packages **67**.

## 4. CP4c-3 carry-forward summary

This section is navigation only; `M3_CP4c_Frozen_Definitions.md` Part IV and
`M3_CP4c_Frozen_Definitions.md` Part VI remain normative. Current measured runtime authority is
`Architecture_M3_CP4c3_TB16_Artifact_Only_Test_Benchmark_Report.md`; current build/package authority is CB19/package 87.

### `M3-CP4c-3-TB16` — current measured runtime boundary

Artifact-only TB16 consumed immutable package **86** / source `a01016ca59314232526c8b1222c96235856ace6d` / selector **382**. Run/job `33709721203 / 100506452813`; result/log artifacts `9876548209` (`573f8eacf7de1ac993cfd2a4ef440514e2acb3bd6d0a85f322ac280bfec0b89f`) / `9876548556` (`2d0cd2ab4ff4068293d0a2bb8449d0119fa03014a93cb561575d1da7a55cb75b`). All 382 identities ran one-per-fresh-process. A temporary exact-`[ OK ]` summary parser repeated TB14's reporting-only bug; immutable exit codes and terminal logs reconstruct the authoritative ledger to **374 PASS / 8 RED**, accepted 1-365 **365/365 PASS**, true reds 366/367/368/369/370/371/372/374, corrected ledger SHA-256 `7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`. No semantic rerun occurred.

Ordinal 366 clears the edge-25-31 `EdgeTraceSecondaryRankInvalid` frontier and reaches region construction, now failing `RegionTraceSourcePortCarrierNotAdmissible` at source face `(9,11,17)`. Selectors 380/381/382 pass. Complete mechanical attempt-0 rotation now publishes; with unchanged network incidence/TB12's retained five-ray census and selector-382 collision-free contact-relative rank ordering, the v47 obligation is discharged and TB11-CAND-01 / TB12-REV-CAND-01 / TB15-CAND-01 close. The new `M3-CP4c3-TB16-CAND-01` owns the region-building surface pending static adjudication. Pre/post package census is identical at `606d193e3641ec68114c5616d41bd0e8e43207756f79ae50356ce973c1be10db`; no benchmark/build/repair/mutation occurred. Stable accounting remains 44/14/30, debt 5, packages 83. Exact next: independent `M3-CP4c-3-TB16-REV` BQ0-BQ8.

### `M3-CP4c-3-TB15` — prior measured runtime boundary

Artifact-only TB15 consumed immutable package **85** / semantic source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4` / selector **381** with no rebuild or repair. Run/job `33700074471 / 100477303760` executed all 381 identities one-per-fresh-process for **372 PASS / 9 RED**; accepted ordinals **1-365 remain 365/365 PASS** and first red **366** remains `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid` at source edge `25-31` / face `(25,30,31)`, attempt 0 / zero cut edges. CB17's typed instrumentation identifies the exact branch as **`SourceVertexFallbackUnbound`** with source vertex 35, arc 19 / trace 5 / Reverse / `[0,5)`, outgoing carrier `25-31`, contact index 2, no incoming/other carrier, and a complete three-ray census. Result/log artifacts are `9873244271` / `9873244582`; immutable package postflight is unchanged. TB15-REV then proved the incidence valid, the fallback datum wrong, and the absolute corner-rank latent defect; it froze CB18 BP0-BP9. Stable accounting remains 44 / 14 / 30, debt 5, packages 82.

### `M3-CP4c-3-CB19` — current build/package boundary

CB19 final semantic source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e` implements TB16-REV BR0–BR9 without Directional runtime. A shared `is_terminal_slit()` predicate makes a trace's last no-barrier segment non-material in both region-building loops before fragment-count, touched-edge or orbit-evidence mutation. `resolve_carrierless_corner_binding()` binds through the current segment's exact `entryPoint.source_support()`, fails closed unless it is a vertex of the selected face, and keeps `trace->sourceVertex` only as the first-segment consistency rule. The fragment invariant is explicitly `k real trace chords -> k+1 fragments`, with a terminal slit contributing zero. Complete trace-segment incidence is attached at the emitter and survives projection through `SurfaceCutGraphError`/production diagnostics. The independent fragment oracle mirrors the same contract; compiled observations cover a non-first carrier-less segment whose entry corner differs from the trace origin and a terminal slit with zero real-chord contribution. These witnesses are compiled but intentionally unexecuted until TB17.

Selectors 380/381/382 remain byte-frozen; selector 382 SHA-256 is `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`, accepted prefix 365 is `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, and no selector 383 was created. Authoritative eight-target GMP/GMPXX compile `33761967427 / 100670323823` is GREEN: result artifact `9895999746` (Actions digest `71b268f187b39ce547648c27543913e8fdef0bb1087eaaeca0d2948ce020c990`) and log `9896000247` (`767a9802e82e696aa714e9ca483813df253835a6132d9ec34e3b4a0e89b2c707`). Immutable package **87** run/job `33763450567 / 100675268847` is GREEN: artifact `9896472535` (Actions digest `78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770`), inner tar `015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48`, packaged source `f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a`, 27 fixtures and preserved executable modes. Package attempt `33763246701` failed only because its orchestration referenced the accepted 365 selector under the CP4c-3 filename; the corrected retry reused the same immutable compile artifact. `selected_gate=NONE`, `gate_execution_authorized=false`, `runtimeExecution=false`, `packageRepair=false` throughout. Stable **44 / 14 / 30**, debt **5**, semantic packages **84**. Exact next: artifact-only `M3-CP4c-3-TB17` on package 87 / selector 382 under BR9.

### `M3-CP4c-3-CB18` — prior build/package boundary

CB18 final semantic source `a01016ca59314232526c8b1222c96235856ace6d` implements TB15-REV BP0-BP9. In `edge_locus_secondary_rank`, the carrier-less fallback now uses the selected segment's exact far-end boundary support (entry for Reverse, exit for Forward) through `FieldBoundaryPoint::source_support()` and accepts only a vertex support that is a corner of the selected face. Its corner rank is contact-relative, `1 + 2*((corner + 2 - contactIndex) mod 3)`; the `contactIndex == 2` case recovers the shipped ordering. An unbindable far end remains typed `SourceVertexFallbackUnbound`. The carrier branch and excluded topology/collision/vertex-locus paths are unchanged. Compiled witnesses pin the previously successful singularity-start cases for contact indices 0/1/2, the positive Reverse vertex-entry case, the typed negative, fallback/carrier ordering, and ordinary two-carrier regression.

Selector **381** remains byte-frozen. Selector **382** is 381 plus exactly `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`, SHA-256 `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`. Authoritative eight-target GMP/GMPXX compile `33706268720 / 100495948544` is green; result/log artifacts `9875350611` (`cc2935716ecf7022fda6c120f0ef6313e60df553d34d7354b587e47ee9663d3a`) / `9875350974` (`ea39d44a9196e47934cb3ff626633c3031a2c607c542ef5e34298cc6665328f5`). Immutable package **86** run/job `33707299159 / 100499114323` is green: artifact `9875664940` (`8c98b134a527db87b83852de175288a320a158405d22867d95ba986cf68cbef8`), log `9875665222` (`fe86b4f391d731eb629461e1d79cb3b9543f1bab968fa922c1f8a0deb9565d28`), inner tar `125d2851164d7af62f90a3ff6ad8f360076a651c8575b655acac59fb50b9e9e7`, packaged source `c96446f169959c56f3c536c7fe711df6f7741d679cbd1413cc7c464838a659e8`, 57/57 manifest, 27 fixtures and six executable modes. Final packaging used direct artifact-ZIP extraction after an orchestration-only mode-loss attempt; no package repair and no Directional runtime occurred. TB16 has since runtime-proved accepted **365/365**, cleared the edge-rank frontier, and discharged the v47 obligation; package 86 remains the immutable TB16 runtime package but is superseded as build/package authority by CB19/package 87. Stable **44 / 14 / 30**, debt **5**, semantic packages **83**.

### `M3-CP4c-3-CB17` — prior build/package boundary

CB17 final source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4` adds diagnostic-only typed exits for `edge_locus_secondary_rank`, preserves the failing incidence, and publishes a bounded production edge-locus ray census without changing rank/topology semantics. Selector **381** is selector 380 plus one compiled witness, SHA-256 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`. Authoritative eight-target GMP/GMPXX compile `33697315308 / 100468915978` is green. Immutable package **85** artifact `9872426500` has Actions digest `6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`, inner tar `98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`, packaged source `cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`. No runtime executed. Packages advance to 82; accepted authority remains 365/365. Exact next: artifact-only TB15 on selector 381.

### `M3-CP4c-3-TB14` — prior measured runtime boundary

Artifact-only TB14 consumed immutable package **84** / selector **380** from source `6808c090f2dd229a48550d758f459bfd156da4b6`. After a local-host partial attempt was classified infrastructure-only, the user authorized a complete replacement on GitHub Actions. Run/job `33689875040 / 100445977571` completed all 380 fresh selector processes plus the retained non-gating diagnostic with no repository timeout. Result/log artifacts are `9869697113` (`a96d8ff82b467c0cfd89c1437fc0a146461ab18d4850e04515acc562070b975a`) / `9869697543` (`5e961520a3844d5b01ab77d4b85b5117c4124bfa03d4993812270e4563deb5f2`). A temporary exact-line `[ OK ]` parser mislabeled passing rows but preserved raw exit codes/logs; corrected immutable evidence is **371 PASS / 9 RED**, accepted 1-365 **365/365 PASS**, first red 366. Corrected ledger SHA-256 is `0b42866471ce0ad5939ab2d3c2d5c82f4efebb93c0a56ca7a60e295fad07397b`; no semantic rerun was used to repair reporting.

Ordinal 366 clears TB13's vertex-10 `VertexTracePortOrdinalInvalid` and now fails at source edge `25-31` / face `(25,30,31)` with `EdgeTraceSecondaryRankInvalid`, attempt 0 / zero cut edges / 450 candidates. Selector 379 PASSes; selector 380 REDs only at its final production assertion on the same new frontier. The old v47 collision remains absent, but complete attempt-0 rotation does not publish, so the five-ray v47/distinct-rank conjunction remains open. 368/369/370/374 retain prior owners; 371/372 inherit the new mechanical upstream stop. Package postflight is immutable. Stable accounting remains 44/14/30, debt 5, packages 81. Exact next: `M3-CP4c-3-TB14-REV` BM0-BM8.

### `M3-CP4c-3-CB16` — prior build/package boundary

CB16 final source `6808c090f2dd229a48550d758f459bfd156da4b6` adds the exact source-vertex corner fallback last in the Forward vertex-ray second-point chain and separates secondary-parameter failure from legacy port/ordinal failure. Eight-target GMP/GMPXX compile `33682499470 / 100422188581` is green. Immutable package **84** artifact `9867334959` has Actions SHA-256 `67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`; inner tar `8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`; selector 380 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`. TB14 now provides its runtime disposition; accepted authority remains 365/365.

### `M3-CP4c-3-TB13` — prior measured runtime boundary

Artifact-only TB13 consumed immutable package **83** / selector **379** from source `a2fd98eaa015ff5872890bb1945cf4e9e9493615`. Run/job `33671968437 / 100387569925`; result/log artifacts `9862995609` (`d7da71ea122a20225e6e3e7b9f2534fd3a7d8c1b1401ebc64b5f1191eb21bb8b`) / `9862996106` (`b9a6288472f0ec204f93aa0f209b457c365e4c8ecf98e166c100c99bb3f6caf4`). All 379 identities ran in fresh processes: **371 PASS / 8 RED**; accepted 1-365 green, first red 366, and selector 379 PASS. The old v47 `RotationRayOrderKeyCollision` is absent at ordinal 366, but production now fails earlier at source vertex 10 / face `(8,10,11)` under `VertexTracePortOrdinalInvalid`, attempt 0 / zero cut edges. Because that earlier failure prevents publication of the v47 five-ray census and former-pair secondary ranks, the TB11 closure conjunction is not satisfied. Package source reuses the new reason for both legacy port validation and exact secondary-parameter failure, so exact cause is underdetermined and owned by `M3-CP4c-3-TB13-REV` BK0-BK8. Package postflight is immutable; accepted authority 365/365, accounting 44/14/30, debt 5, packages 80.

### `M3-CP4c-3-CB15` — prior build/package boundary

CB15 final source `a2fd98eaa015ff5872890bb1945cf4e9e9493615` replaces vertex-locus origin-port ordinal ordering with exact locus-relative within-wedge rank and keeps exact coincidence fail-closed. Eight-target GMP/GMPXX compile `33667287957 / 100372314673` is green. Immutable package **83** artifact `9861269273` has Actions SHA-256 `1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`; inner tar `c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`; selector 379 `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`. TB13 now provides its runtime disposition; accepted authority remains 365/365.

### `M3-CP4c-3-TB12` — prior measured runtime boundary

Artifact-only TB12 consumed package **82** / selector **378** with no rebuild or repair. Run/job
`33657062615 / 100338185825`; result/log artifacts `9857275334`
(`085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`) / `9857276091`
(`89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`). All 378 selector identities ran in
fresh processes: **370 PASS / 8 RED**, accepted 1-365 green, first red 366. The retained collision pair is arc
20/trace 6/Forward/origin vertex 47 versus arc 23/trace 9/Reverse/origin vertex 71; both have
`(primary,secondary)=(3,0)` in face `(45,46,47)` / fan slot 1. The full fan census contains five rays and is not
truncated. Unmeasured `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are absent. Selector 378 PASSes
production diagnostic projection; the separate mechanical diagnostic ran once with zero gate credit. Package
postflight is immutable. The simplest duplicate-incidence identity case is falsified, but valid coincident/tie
semantics versus invalid/stale provenance or witness/precondition remains semantically unadjudicated. Exact next is
`M3-CP4c-3-TB12-REV` under BI0-BI7; accepted authority 365/365, accounting 44/14/30, debt 5, packages 79.

### `M3-CP4c-3-CB14` — prior build/package boundary

CB14 executed TB11-REV **BH0–BH9** as a **diagnostic-only** Code + Build turn. Final source
`71ece3ca184e90858d9222fb014b37c16d292294` retains both colliding rotation rays with typed key operands,
arc/trace/face identity, orientation, fan slot, and origin-port ordinal/source-vertex evidence; publishes a bounded
keyed-fan census; and prevents unmeasured certification counters from rendering as observed zeros. It also compiles
a production-renderer synthetic same-sector witness and the mechanical ordinal-366 diagnostic assertion. No
collision/order/incidence/rotation/cut semantics or fixtures changed.

Selector **377** remains byte-frozen at
`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`. Selector **378** is exactly 377 plus one
non-gating diagnostic identity, SHA-256 `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`.
Authoritative compile run/job `33653092570 / 100324843819` passed all eight standard targets with GMP/GMPXX and no
runtime. Immutable package **82** was frozen by run/job `33653737897 / 100327139865`: artifact `9855841174`
(Actions SHA-256 `4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`), inner tar
`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`, packaged source
`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`, 27 fixtures and six executables.

CB14 changes no acceptance: accepted authority remains **365/365**, CP4c-3 OPEN, stable **44 / 14 / 30**, debt
**5**, semantic packages **79**. Its diagnostic owner is discharged by TB12 runtime; package 82 remains current
build/package authority.

### `M3-CP4c-3-TB11` — prior measured runtime boundary

Artifact-only TB11 consumed package **81** / selector **377** with no rebuild or repair. Run/job `33611378451 / 100187075757`; 377 fresh processes produced **369 PASS / 8 RED**, with accepted 1–365 green and first red 366. Ordinal 366 now publishes `RotationRayOrderKeyCollision`, source vertex 47, certification attempt 0 / zero cut edges, 450 cut candidates, zero non-disc components and zero remaining admissible edges. Static package source maps the reason uniquely to `build_rotation_system` after key construction/sort and before final CCW rotation publication. The one non-gating diagnostic independently re-derived the same reason/stage and has zero gate credit. Package postflight is immutable. 367/371/372 remain upstream-blocked; 368/369/370/374 retain prior ownership. Exact next is `M3-CP4c-3-TB11-REV` under BG0–BG7; accepted authority 365/365, accounting 44/14/30, debt 5, packages 78.

### `M3-CP4c-3-TB10` — prior measured runtime boundary

Artifact-only TB10 consumed package **80** / selector **377** without rebuild or repair. Run/job
`33584653692 / 100106147126`, result artifact `9829700900`
(`2e7d978dd3ad2a5f0667ef3eed15c291ed8c7b91bb7e2d323557a8bc40763572`), log artifact `9829701136`
(`89f445c5934c3493ccf966e39f0c106c8418719a32c5d206055cafa932cce17d`). All 377 identities ran in fresh
processes: **369 PASS / 8 RED**. Ordinals 1–365 remain green; ordinal 366 is first red at
`CellularityNotEstablished/origin=RotationSystemInconsistent`. The old seed-47/singularity-5 terminal-ownership
condition is absent and identity 377 passes at v36 / `BarrierAbsorbed` / node 7, closing
`M3-CP4c3-TB9-REV-CAND-01`. The new `M3-CP4c3-TB10-CAND-01` is a production-projection diagnostic gap: the
cut-graph error carries the rotation-system subreason/locus but the pipeline failure string omits it. 367/371/372 are
upstream-blocked by that same mechanical stop; sphere 368, saturation 369, ordinal 370 and folded-cone 374 retain
their prior independent dispositions. Immutable postflight passed. Accepted authority stays **365/365**, stable
**44 / 14 / 30**, debt **5**, semantic packages **77**. Exact successor: independent
`M3-CP4c-3-TB10-REV` under BE0–BE7.

### `M3-CP4c-3-CB12` — prior build/package boundary

CB12 executed TB9-REV **BD0–BD9** as a product correction. Exact source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15` carries explicit singularity port policy into terminal ownership.
`BarrierAbsorbed` arrivals resolve the singularity's already-created network node by support vertex; `Emit` retains
its existing port-owned path. Missing barrier node fails closed with a distinct condition. A compiled mechanical
witness derives v36, its `BarrierAbsorbed` singularity, network node and mandatory-barrier incidence and covers both
negative missing-node and positive node-owned termination cases.

Selectors 374/375/376 are unchanged. Selector **377** is selector 376 plus exactly
`ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`, SHA-256
`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`. Compile run/job
`33581576670 / 100096794713` passed all eight required targets with GMP/GMPXX and no runtime. Package run/job
`33582280392 / 100098880900` froze immutable package **80**, artifact `9828786744`, inner tar
`4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`, packaged source
`026a8b1efa2dc85fe2b474e0e64657bf8f997aee5b49f274c7c0c69d279fd18a`.

At the CB12 boundary, authority stayed **365/365**, CP4c-3 OPEN, stable **44 / 14 / 30**, debt **5**, semantic
packages **77**; `M3-CP4c3-TB9-REV-CAND-01` remained active pending TB10. TB10 has since consumed package 80,
closed that candidate, and moved the first red to `M3-CP4c3-TB10-CAND-01`.

### `M3-CP4c-3-CB11` — prior build/package boundary

CB11 executed TB8-REV **BB0–BB9** diagnostic-only. Final semantic/evidence source
`803300698289e0d0f629eaa878add1aebc7193c1` carries the trace-scoped network-error group, exact values,
published-edge/face authority, and a typed discriminator for all twelve `InvalidNetworkTerminalOwnership` emission
conditions through the production failure DTO/renderer. It also moves ordinal 329's losslessness guarantee to the
production projection and adds witnesses for both statically surviving ownership sites. The `terminalContact`
fall-through is diagnosed but deliberately unchanged.

Selector 374 and 375 hashes remain byte-frozen. Selector **376** is selector 375 plus exactly one diagnostic identity,
`ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection`, SHA-256
`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`.

The first compile exposed an anonymous-namespace linkage defect in the diagnostic wrapper; a one-site linkage-only
correction produced final source `803300…`. Authoritative compile run/job `33573956609 / 100073749252` passed all
eight required targets with GMP/GMPXX and no runtime. Result/log artifacts are `9825961944 / 9825962219`.
Runtime-free package run/job `33574167362 / 100074416093` froze immutable package **79**, artifact `9826005253`, inner
tar `dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99`, packaged source
`61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6`.

No acceptance changes in CB11: authority stays **365/365**, CP4c-3 OPEN, stable totals **44 / 14 / 30**, debt **5**,
semantic packages **76**. `M3-CP4c3-TB8-REV-CAND-01` closes at implementation/build scope;
`M3-CP4c3-TB8-CAND-01` remains active until TB9 names the firing site.

### `M3-CP4c-3-TB9` — prior runtime boundary

TB9 consumed immutable package **79** in run/job `33575920177 / 100079784804`. Result artifact `9826689980`
(`abea3172c6515bbf5b6fdede5abe96ae6086724299d014201ce3ff020016b68d`) and log artifact `9826690247`
(`c92be7d59ecfb963eb225099737ed99efcb169244bfaa4c9519a1a98967cd648`) are authoritative. Immutable
pre/postflight PASSed, static source mapping resolved every selector identity to exactly one packaged executable, and
all prohibited build/repair/discovery/mutation/benchmark flags remained false.

Selector 376 re-proved **365/365** accepted authority. Ordinal 366 remains first red at edge `36-38`, face
`(36,38,39)`, branch 2, but the production renderer now adds
`networkErrorCondition=SingularityTerminationPortOwnershipMismatch`, `traceSeedVertex=47`,
`traceSeedSingularity=5`, and five exact branch-2 history rows with `traceHistoryTruncated=false`. This resolves the
TB8 two-site ambiguity to `append_field_aligned_singularity_termination` and excludes the finalize/contact fall-through
as this first-red emitter. The old `publishedFaceCount` token is gone; the actual published-face collection is empty.

Report-only 367–375 is **2 PASS / 7 RED**: 373 and 375 pass; 367/371/372 share the mechanical ownership blocker;
368 sphere, 369 saturation, 370 empty-network, and 374 folded-cone dispositions remain unchanged. Diagnostic 376
PASSes with zero gate credit, runtime-closing `M3-CP4c3-TB8-REV-CAND-01`. `M3-CP4c3-TB8-CAND-01` stays active/gating
at the named singularity-terminal site; TB9-REV must determine which internal guard disjunct/invariant owns the
failure before any correction. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **76**.

### `M3-CP4c-3-TB8` — prior runtime boundary

TB8 consumed immutable package 78 from semantic source `e2b59295c9920db5685239c2da188858839fa94f` in run/job
`33561723204 / 100035596811`. Result artifact `9821602279`
(`e9858ac5194646f888a193937e52cc504aa36a6940d79904b36f70c059026a62`) and log artifact `9821602943`
(`1f41626b53642bb30a00bcaafbbc3993d09870c20c2ffc15f2224670ecc65239`) are authoritative. Immutable pre/postflight
PASSed with all build/repair/mutation/benchmark flags false.

Selector 374 re-proved **365/365** and first-reds at ordinal 366 with
`InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;publishedFaceCount=0`, proving CB10
cleared the earlier source-vertex-11 seed stop while exposing a new later masking locus. Vertex 30 remains unreached.
Report-only 367–374 is **1 PASS / 7 RED** with the sphere/saturation/370/374 dispositions unchanged and 373
synthetically green. Diagnostic 375 PASSes separately with zero gate credit; together with green 328/329 it closes
the TB7 radial-arrival and TB7-REV audit/rendering defects, but not the general non-flat exact-fallback/budget class.

`M3-CP4c-3-TB1` consumed immutable package **68** (`9739919234`) directly in run/job
`33340448381 / 99335020672`. Result artifact `9740416876` has SHA-256
`713d4e6853adde54e17738d6d25e5a310a5f88ff8e4232abf67bb73c7a8cbdc0`; log artifact `9740417020` has
SHA-256 `8302f6ae50a8d5d29f92952aed0f144eb78bda3f070612f3dec67a63701debc0`. Immutable pre/postflight passed,
package/source were unchanged, and no configure/compile/relink/repair/generated-discovery/benchmark/mutation occurred.

The frozen 367 selector re-proved the accepted **365/365** prefix, then first-red hard-stopped at ordinal **366**:
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`. Required result:
**366 executed / 365 PASS / 1 RED**; ordinal 367 was not executed after the red.

Phase-1 measurements are now concrete:

- mechanical A1: `IncompleteCycleBasisReason=CycleTransportAdjacencyMissing`;
- mechanical locus: region `0`, source edge `0-3`, `fieldTransportAdjacencyExists=false`;
- mechanical AK2 row: `V/E/F=152/450/300`, χ=2, boundary loops=0, genus=0, interior local vertices=152,
  expected cycles=152, cycle rows=152, cycle curvatures=152, inner adjacencies=450;
- prescribed sphere: `RotationSystemInconsistent → TraceEventPositionInvalid` after source topology, atlas and network
  succeed (24 traces / 56 events);
- frozen non-gating diagnostics all executed report-only: torus retains a valid cut graph/global plan before the
  existing downstream tracing failure; mechanical and sphere reproduce the measured AK1–AK3 causes.

Inherited CP4c-2 dispositions remain explicit:

- `M3-CP4c2-TB-X2-CAND-04`: still active/non-stable, now localized by AK3 to `TraceEventPositionInvalid`; the
  independent pre-cut non-cellularity evidence remains separate.
- `M3-CP4c2-TB-X2-R10-CAND-01`: cause established; corrective remains proposal-heuristic-only, using per-face trace
  chords; Amendment 14 certification is not reopened.
- `M3-CP4c2-TB-X2-R8-CAND-02`: decided; an empty closed-surface network must fail closed with an appended typed
  `SurfaceCutGraphErrorCode`.
- `M3-CP4c3-DEFN-CAND-01`: no longer diagnostically ambiguous; TB1 measured
  `CycleTransportAdjacencyMissing`, and the independent review now owns AK6 corrective interpretation.

### `M3-CP4c-3-TB1-REV` adjudication (measures AL0–AL9)

Review record: `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md`. TB1's execution is **ACCEPTED** as a valid
semantic red; the working tree is byte-identical to the packaged semantic source, and CB1 delivered AK1–AK3 exactly
as specified — additive, enumerated, no mapping changed and no enum value renumbered.

- **`M3-CP4c3-DEFN-CAND-01` → CAUSE ESTABLISHED.** Edge `0-3` is a `HardFeature` **barrier** by elimination over
  `FieldTransportAtlas::make`'s four adjacency buckets. It entered the cycle basis because
  `build_source_topology_regions` skips hard-feature edges when flood-filling regions and **skipping an adjacency
  disconnects nothing unless the edges separate** — region 0 is all 300 faces with `boundaryLoops=0`, so the edge
  stayed interior to the local mesh and the walk demanded an adjacency the atlas deliberately withheld. The region
  decomposition and the traversability classification **disagree about the same edge**. Region 0 is a sphere
  (`χ=2`, genus 0, no boundary) and every closed curve on a sphere separates, so the feature set necessarily
  contains at least one **open arc**; the torus escapes only because its four hard-feature loops **do** separate it.
  The corrective is a normative choice (**A** cut the local mesh along the arc, recommended; **D** typed fail-closed
  as the frozen fallback; **C** giving barrier edges an adjacency is **prohibited**) owned by `M3-CP4c-3-DEFN-R1`.
- **`M3-CP4c2-TB-X2-CAND-04` → ACTIVE / ONE LEVEL SHORT.** `TraceEventPositionInvalid` is itself a two-way collapse
  in `trace_event_position` — `positions.empty()` (a binding defect) versus `positions.size() > 1` (an ambiguity) —
  needing **opposite** fixes, plus a widening second pass that can manufacture the ambiguous case. Ambiguity is a
  suspicion, not a finding. **AL3** measures it; **AL4** forbids designing across it. Phase 2 is **not** authorized
  for this witness.
- **The two measured causes share no locus** (A1 `FieldTransportAtlas` versus A2a′ `EmbeddedGraphTopology`), so
  phase 2 opened for the mechanical witness alone and the inherited items remain independently workable under
  **AL6**.
- **`M3-CP4c3-TB1-ORCH-01`** is closed but **escalated**: its 63-hex digest is the third `R7-ORCH-01` occurrence, so
  **AL8** moves the 64-lowercase-hex validation into the orchestration payload authoring path.
- `LESSONS.md` **64** added: *when instrumenting a collapsed error, check whether the reason you are adding is
  itself a collapse before declaring the layer done.*

Stable accounting remains **44 / 14 / 30**, debt **5**, packages **68**; TB1 added **+0 events / +0 recurrences**.

### `M3-CP4c-3-DEFN-R1` — Amendment 15 (measures AM0–AM9)

Record: `M3_CP4c_Frozen_Definitions.md` Part V. Normative record: `DESIGN.md` §7.2.1
**Amendment 15**. Definition, review and planning in one turn under the standing cadence; no runtime, no compile,
no packaging, no gate execution, and no product/test/fixture/selector byte changed.

**Decision.** A region's face set and its published `euler_characteristic()` / `boundary_loop_count()` describe the
**uncut** source complex and are unchanged. A1 derives its tangent bundle, cycle basis and index quantities from
the region's **transport domain** — the region **cut along** `B(R) = { e ∈ hardFeatureEdges : both incident faces
∈ R }` — in A1's **derived local mesh only**. Option C stays prohibited; option D is the frozen fallback with a
declared trigger and the stated cost that C2 cannot then close.

**Two theorems, both forced by construction rather than observed:** `B(R)` is the entire defect class, because a
source-boundary edge and a region-/component-crossing edge each have at most one incident face in `R` and are
already local boundary edges, while a traversable edge has an adjacency — and isolation seams are traversable by
design, so they are **not** barriers; and the cut never disconnects, because a region *is* a connected component
of the face graph built without barrier edges, from which it follows that no subset of `B(R)` separates `R` and
that on a `χ=2, b=0` region every barrier component is a tree.

**Endpoint rule and arithmetic.** `copies(v)` = connected components of `star(v) ∖ B(R)` = `d_B(v)` interior,
`d_B(v) + 1` on the boundary, so an open arc's **tip is not duplicated** but becomes a boundary vertex; the result
is a manifold with boundary and `set_mesh` re-derives every count. `χ(R_cut) = χ(R) − χ(B) + ∂`, verified against
four independent cases. Mechanical witness: `χ' = 2 − c`, `b' = c`, genus 0, `interiorVertices' = 152 − |V(B)|`,
`innerAdjacencies = 450 − |B|`, cycle-matrix rank deficiency unchanged at **1**. Because `dual_cycles` indexes
columns into inner edges only, a barrier can never again raise `CycleTransportAdjacencyMissing`.

**Three costs, all required work:** replace (never delete) the local-mesh-versus-region cross-check with the cut
identity; disclose the move from the closed index equality to the weaker boundary-corrected branch; and make the
interior-singularity binding fail closed. The last opens **`M3-CP4c3-DEFN-R1-CAND-01`** — a pre-existing latent
gap at HEAD, not introduced here but made reachable by the cut — and is recorded as `LESSONS.md` **65**.

Gate **367** stays frozen and unselected; the append point 367 → **370** (AL7) → **373** (Amendment 15's three
identities) is defined but executed at CB2's freeze. Accounting unchanged, **+0 events / +0 recurrences**.

The exact next turn is **`M3-CP4c-3-CB2`** — Code + Build under **AM0–AM9**, runtime-free, GMP/GMPXX linked.

### `M3-CP4c-3-TB2` — orchestration-invalid fixture-root stop

TB2 consumed immutable package **69** and reproduced the complete artifact/source/GMP/selector preflight. The frozen
373 selector then began one identity per fresh process: ordinals **1–40** selected exactly once and exited green.
Ordinal **41**, `MilestoneGP26.PrescribedSphereSingularitiesMatchRecoveredValence`, selected once but threw before
product adjudication because it could not open
`/home/runner/work/Directional/Directional/benchmarks/fixtures/milestone_g_manifest.json`.

The manifest is present in the immutable packaged source. The harness lacked sibling/bin `test-data`, so
`TestFixturePaths` fell back to the producer binary's compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR`; the local
artifact-only execution materialized the packaged source elsewhere. This is **`M3-CP4c3-TB2-ORCH-01`**, not a
semantic product red. Because 41 Directional processes had already run, the frozen TB2 plan forbids an in-turn
corrected-root restart. Ordinals **42–373 were not executed**, so no CP4c-3 checkpoint-local runtime conclusion can
be drawn.

Postflight re-proved package SHA, **28/28** manifest, source archive, selector 373, executable mode and source-tree
immutability; no configure/compile/relink/repair/generated-discovery/benchmark or source/test/fixture/selector/package
mutation occurred. Stable accounting is unchanged at **44 / 14 / 30**, debt **5**, packages **69**.

**Superseded within the same turn.** The user authorized a fixture-only correction; package **70** (artifact
`9744461475`) relocated the exact immutable fixture tree from the packaged source archive into the sibling
`test-data` root the binary probes first, and run `33355714664` re-executed selector 373 from ordinal 1. The record
below is retained because it is where the packaging defect was first observed; the authoritative TB2 result is the
valid semantic red at ordinal 366.

### `M3-CP4c-3-TB2-REV` — Amendment 16 (measures AN0–AN9)

Record: `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md`. Normative record: `DESIGN.md` §7.2.1
**Amendment 16**. Review, definition and planning in one turn; no runtime, no compile, no packaging, no gate
execution, and no product/test/fixture/selector byte changed.

- **Execution ACCEPTED.** Selector 373 was recomputed from committed bytes and all six predecessor prefixes (355,
  357, 361, 365, 367, 370) reproduce exactly; the working tree is byte-identical to packaged source
  `005512f20ed56edc793f4d6505f3d2b4c2999c71`. The package-70 substitution is accepted as *relocation of already
  immutable bytes*, with one qualification: `semanticBinariesUnchanged=true` is self-reported and the two manifests
  (28 vs 55 entries) are not comparable line for line, so per-binary digests must be published (**AN2**).
- **Amendment 15 confirmed effective at runtime.** The mechanical witness advanced past `IncompleteCycleBasis`, and
  ordinals **1–365** are green, so the cut regressed nothing in the accepted gate.
- **New cause established by elimination:** `MissingSingularityBranchTransport` — `build_singularity_attachments`
  demands a branch transport on every radial edge of a **globally closed** one-ring fan, while `branchTransports`
  excludes every barrier by construction. **Proved pre-existing and merely unmasked**: CB2's diff to that file
  begins at old line 842, leaving `build_branch_transports`, `ordered_incident_fan` and
  `build_singularity_attachments` untouched.
- **Amendment 16** generalizes 15 to every A1 derivation that walks transport, prohibits supplying a barrier with a
  branch transport, and replaces a closed ring with the fan of one component of `star(v) ∖ B(R)`. It leaves the
  **port-emission policy** open pending AN1's census; **AN4** forbids designing across it.
- **Owned:** measure AM2 scoped its consumer audit by *symbol* rather than by *assumption*, so a faithful search
  could not have found this consumer. `LESSONS.md` **66**; **AN8** requires naming a consumer that holds the
  assumption without touching the changed data structures. `LESSONS.md` **67** records that per-site error
  instrumentation buys exactly one turn of visibility.
- **`M3-CP4c3-TB2-ORCH-01` reopened and reclassified** as a build/packaging contract defect owned by **AN3**: the
  binary's compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` fallback makes fixture resolution depend on the
  runner's directory layout.
- **Still unproved:** ordinals 367–373 never executed, so Amendment 15's three self-checks and AM1's barrier
  decomposition remain unmeasured and every DEFN-R1 prediction is unverified.

Exact successor: **`M3-CP4c-3-CB3`** — Code + Build under **AN0–AN9**, runtime-free, GMP/GMPXX linked.

### `M3-CP4c-3-CB3` — Amendment 16/P2 build green, package 71 portable

CB3 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source
`93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`. Static AN1 measurement found 8 prescribed +1 mechanical
singularities, 4 barrier-incident; all four are degree-2 `InteriorArc` facts with two cut-star components. Mechanical
`B(R)` is a four-component forest (`n=16, m=12, c=4, χ(B)=4`), while the prescribed sphere has zero active
barrier-incident singularities. Those facts select Amendment 16 **P2**: slit-bound barrier singularities are
`BarrierAbsorbed` and emit no singularity ports; no branch transport is ever created across a hard feature.

The atlas now publishes barrier-singularity census/classification and complete failure loci through pipeline
diagnostics. `build_singularity_attachments` skips the illegal closed-fan derivation for absorbed facts, and the
field-aligned producer respects the explicit port policy. The assumption audit also found
`canonical_field_aligned_candidate`, which independently assumed every singularity emitted `4-index` ports. No
sphere-specific correction was made and ordinals 367–373 remain frozen/unexecuted.

AN2 independently rehashes package 69/70 and proves all six binaries byte-identical. AN3 removes the compile-time
absolute `DIRECTIONAL_TEST_SOURCE_DIR` authority. Package **71** / artifact `9750235004`
(`bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`) carries 27 immutable fixtures under
`test-data/benchmarks/fixtures`; source archive SHA-256 is
`fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`. Run/job
`33370966957 / 99421816569` compiled all eight standard targets with GMP/GMPXX, source clean, build exit 0, and
`runtimeExecution=false`; package-fixtures job `99423544681` proved the manifest, fixture contract, and binary-byte
invariance. Stable accounting stays **44 / 14 / 30**, debt **5**; authoritative semantic package accounting becomes
**70**. Exact successor: artifact-only `M3-CP4c-3-TB3` on package 71 with selector 373.


### `M3-CP4c-3-TB3` — blocked before runtime by executable-mode package contract

TB3 is **COMPLETE / BLOCKED — PRE-RUNTIME / NO SEMANTIC VERDICT**. Run/job `33399144281 / 99510922630` consumed exact
package **71** (`9750235004`, `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`) and re-proved its complete internal manifest, semantic source
`93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, and package-relative fixture payload. Before ordinal 1, all six
packaged test/benchmark executables were mode `0644`; policy forbids `chmod`, repacking, repair, or replacement
compilation inside artifact-only TB. Result/log artifacts are `9760518962` (`ec5bc5cccb99e38e4ce77533478c5864e756735b3511575d843bbafb328f4677`) and `9760519355`
(`b803c9f81df4a5acbea642860d88f8c61f3df8f13d2204cf836344f6efb1016d`). Selector execution is **0/373** and all runtime/build/mutation flags remain false.

`M3-CP4c3-TB3-ORCH-01` is **RESOLVED / PACKAGE CONTRACT CORRECTED / NON-STABLE**. TB3-REV traced package-71 mode loss to `actions/download-artifact@v4`; CB4-PKG then consumed raw artifact 9750227619 without replacement compilation and produced immutable package **72** in run/job `33411346157 / 99551438549`. Artifact `9765247195` has Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`; inner `package72.tar.gz` is `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`. Independent clean extraction verifies the 55-entry manifest, semantic source/archive, GMP boundary, exactly 27 fixtures, and all six frozen binary hashes at mode `0755`. No Directional runtime or semantic mutation occurred. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.

### `M3-CP4c-3-TB3-R1` — valid semantic red at vertex-transit sector resolution

Mode-preserving package **72** enabled the first valid TB3 semantic execution. Run/job `33416686424 / 99568970224` passed immutable package/tar/source/GMP/fixture/binary-mode/selector preflight, then executed ordinals 1–365 as **365/365 PASS** and first-red at ordinal **366** `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` with `NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`. First-red semantics left 367–373 unexecuted. Result/log artifacts are `9767376410` (`7f2c9492d2dae96dfcf1732c320e772be05538a3552ce6a673bd83eb9189824e`) and `9767376976` (`492d19f1e08fd339f130a07dfcf891a3b7bbaaf537483fb54af6e9b96095ad72`); immutable postflight passed and all prohibited build/repair/mutation flags remained false.

The old `MissingSingularityBranchTransport` locus is cleared: atlas partition diagnostics are emitted and the mechanical witness reaches network construction. Static source localizes the new code to `resolve_field_vertex_transit`, which walks transported `(face,branch)` states around the hit vertex and requires exactly one `direction_in_vertex_sector` candidate. The production exception drops the typed network error's source vertex/face/branch/candidate-face details, so runtime does not reveal whether candidate cardinality is zero or greater than one, nor whether the failing arrival is `FaceInterior` or `EdgeTransit`. New non-stable gating candidate `M3-CP4c3-TB3-R1-CAND-01` is therefore routed to independent review, not patched inside TB. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.



### `M3-CP4c-3-CB5` — typed failure locus and immutable package 73

CB5 implements AP1/AP2 diagnostics only on source `2d22ef293363058cfdca96d01158a93d2c0200f8`. Atlas, field-aligned-network, surface-cut-graph and
global-topology-plan errors retain a shared typed locus; the network locus additionally carries arrival mode,
candidate cardinality/faces, `BarrierAbsorbed`, barrier incidence/degree and transport-star component count.
AP8 independently found cut-graph and global-topology typed-loss sites. No transit/product semantic correction
landed, selector 373 is unchanged, and no Directional runtime executed; M1/M2/M3 remain unadjudicated.

Full eight-target GMP compile `33433309655 / 99623694545` is green. Package-only run `33433718709 / 99625035344` produced
mode-preserving package **73** artifact `9773591345`, inner tar `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`, with 27 package-relative fixtures and
six `0755` executables. AP6 carries into TB4 as a separate report-only 367–373 pass after the gate first-red verdict,
with zero gate credit.

### `M3-CP4c-3-TB4` — valid semantic red with exact transit locus; AP6 diagnostics measured

Artifact-only TB4 on immutable package **73** is authoritative at run/job `33436492493 / 99634138202`. Package/source/GMP/27-fixture/six-`0755`/selector preflight and immutable postflight passed. The semantic gate re-proved ordinals **1–365 = 365/365 PASS** and first-red at ordinal **366**. CB5's typed locus now identifies `VertexTransitSectorUnresolved` at source vertex **30**, arrival face `(24,30,32)`, branch **1**, region 0, `FaceInterior`, with exactly **two** candidate faces `(25,30,31)` and `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`. This falsifies M1's zero-candidate prediction and direct M3's barrier-absorbed-vertex prediction, but does not prove M2's singular-holonomy premise.

After the gate verdict was fixed, AP6 executed ordinals **367–373** once report-only with zero gate credit: **1 PASS / 6 RED**. 368 reproduces the sphere's `RotationSystemInconsistent → TraceEventPositionInvalid` at trace 2/event 30; 369 reaches its intended assertion with `saturationUsed=true`; 370 stops earlier at `atlasBuild=false`; 371/372 are blocked by the same mechanical network red; 373 passes its synthetic barrier-arc singularity-binding contract. Result/log artifacts are `9774693166` (`056f86df2e387391227bcf52f59ba932dd64a5d02923a8ff688cd8e315ff8a7e`) / `9774693946` (`d2acc62037d0bce07ef98bb77a7cb42ee90758d8b72477d9d8516da2fa0afcb6`). Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **71**. Exact successor is independent `M3-CP4c-3-TB4-REV`; no unchanged TB retry or semantic correction precedes review.

### `M3-CP4c-3-CB6` — Amendment 17 one-datum election and package 74

CB6 implements the TB4-REV Amendment-17 correction at final semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`: vertex continuation election captures one arrival-face incoming
direction, transports that same geometric datum through the reachable fan, re-expresses it per face, and applies
the unchanged exact half-open sector predicate. Candidate-cell `pairing.direction` values are retained only as
diagnostics; published signed-lift branch transport remains separate authority. The audit channel records both
directions, transport path, composed quarter-turn and sector outcomes per reachable state.

CB6 also exposes ordinal 370's existing typed atlas-build error/locus without repairing its witness and publishes
`NoCarrierMatch / SourceEdgeUnavailable` for the prescribed-sphere no-source-edge diagnostic path without changing
sphere semantics. An independent same-pattern audit found per-cell representative/sector testing in
`FieldTransportAtlas.cpp` singularity-port incidence construction; it was intentionally left untouched. Synthetic
ordinal 373 remains partial evidence until the mechanical witness proves `unboundSingularityCount=0`.

The first compile-only attempt found one mechanical C++ access defect (`DomainResult<SourceVertexId>`); the sole
correction was `rowVertex.value()`. Corrected GMP/GMPXX compile run/job `33445894845 / 99664857496` is green with
`runtimeExecution=false`; raw result/log artifacts are `9778128771` / `9778129236`. Mode-preserving package **74**
from `33446658075 / 99667201075` is artifact `9778267541`, outer SHA-256
`bad0ade74ff8e47c9937013c0fcc3f1084272c66eda35a2db60800ff7b6b767d`, inner tar
`c8d5167652ea95504252f5adb4d1dc5d9f463a4dfacfb7e5e11bd086fe935d8e`, source archive
`5afa250d0dd8e003b91e7e5f887e3eed8658f16faa6754722bf8a2dd37a1c931`, with 27 package-relative fixtures and
six `0755` executables. Selector 373 remains unchanged. Stable accounting remains **44 / 14 / 30**, debt **5**;
semantic packages advance **71 → 72**. Exact successor is artifact-only `M3-CP4c-3-TB5`.


### `M3-CP4c-3-TB6-REV` — Amendment 17 still violated; CB8 frozen

Independent review re-established package 75 / TB6 authority and corrected one durable evidence-ID error: the TB6
result artifact is **`9782227361`**, SHA-256
`e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`. The semantic TB6 result is unchanged:
365/365 accepted prefix green, first red 366 at regular vertex 30, report-only 367–373 = 1 PASS / 6 RED.

Static reconstruction proves CB7 fixed the CB6 float round-trip but not Amendment 17. Atlas `signedLift` rotates the
branch label, after which the target face's `nextPairing->direction` is stored as `incomingDirection`; election is
therefore still one exact local representative per cell. Candidate faces row 41 and row 208 have disjoint branch-
vector families in the committed raw field, so their elected representatives are necessarily distinct under every
gauge permutation. The missing runtime rows are a separate projection defect: resolver
`FieldAlignedCurveNetworkError::vertexTransitStates` retains them, while `network_failure_locus` /
`SurfaceCellFailureLocusDiagnostics` drops them.

The CB7 minimal witness is adjudicated as an omitted future gate-authority action: selector 373 stays immutable;
CB8 must strengthen the same identity and append it as ordinal 374 in a new required-green selector. Repaired ordinal
370 is a genuine independent product red owned by `SurfaceCutGraph::canonical_candidate` and is deferred from CB8.
Sphere and saturation remain deferred. Stable accounting stays **44 / 14 / 30**, debt **5**, semantic packages
**73**. Exact successor: **`M3-CP4c-3-CB8`**, Code + Build only, runtime-free.

### `M3-CP4c-3-CB8` — architectural stop, unchanged source build-green

CB8 audited semantic source `0d943f95b42e49813060399e83a1e4180e8348f6` and triggered AW1 before semantic
editing. The atlas has exact face-local `FieldBranchBoundaryPairing::direction` values plus branch correspondence by
quarter-turn/`signedLift`, but no exact/certified transform for one arbitrary ray across a general non-coplanar fan.
`SourceChartTransitionGraph` is topological only; the available physical transport path is floating/tolerance-based.
No product/test/fixture/selector byte changed and selector 374 was not created. The unchanged source remained GMP
build-green in run `33467212874`, result/log artifacts `9785279716 / 9785279945`, `runtimeExecution=false`; no new
semantic package was produced. Exact successor was independent CB8-REV.

### `M3-CP4c-3-CB8-REV` — one ray frozen; deeper vertex-star definition required

Independent review upholds the stop and chooses the primitive datum: one exact arrival-anchored ray written once by
A2a branch continuation. A target face's branch representative is not a projection of that ray, and an upstream
owner does not eliminate the need to derive the owner exactly. The correct reference problem is an arrival-anchored
intrinsic development of the source-vertex fan. Current GMP rationals are not a general construction type for
non-coplanar hinge unfolding, while current source has no exact algebraic/direct predicate with certified fallback.
More fundamentally, the design has not defined what a developed gap or overlap means on a non-flat star. Amendment
21 therefore forces a definition step before implementation: those outcomes must become typed exact states, not
face order, tolerance, hidden seam, or invented topology.

Authority remains minimal: A1 owns branch topology; A2a will own one seed and one derived vertex-star
owner/non-owner certificate from A0 geometry + A1 topology. Mechanical vertex 30 remains the falsifier of the old
per-cell mechanism, but no exact owner is guessed before the geometry is frozen. `M3-CP4c3-TB6-CAND-01` remains
active downstream at the production DTO. Selector 373 stays byte-frozen; selector 374 is blocked until an exact
non-coplanar witness fails under `incomingDirection = nextPairing->direction`. Stable totals stay **44 / 14 / 30**,
debt **5**, semantic packages **73**. Exact successor: **`M3-CP4c-3-DEFN-R2`**, combined Definition + Review/Plan,
measures AX0–AX9 in `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md`.

## 5. High-value reversals retained

- Face-local branch labels are not cross-face semantic identity; use published transport/lift.
- Tangency is a ratio, not excluded by large direction magnitude.
- Source-edge-barrier partitions are not cellularity authority; the actual embedded graph is normative.
- Self-consistent arithmetic can certify the wrong semantic object.
- Accepted-prefix red is a detection boundary, not proof the latest change caused the defect.
- Semantic and provenance digests are distinct authorities.
- Unexecuted diagnostics are unknown, not green; frozen non-gating selectors must be executed in full or explicitly justified.
- Sphere `CellularityNotEstablished` was a lossy producer bucket; an independent oracle separately proved pre-cut non-cellularity.
- A stage is not covered merely because accepted tests transitively reach it; gate membership must be explicit.
- Trace-crossed source edges are admissible cuts because arrangement subdivision does not mutate the immutable network.
- Cut completeness is proved by saturation with the source 1-skeleton.
- A test-local reconstruction of production authority is not equivalent to consuming the production authority.
- When a representation changes from one arc per source edge to multiple sub-arcs, every consumer must be re-derived by intent; fixing the producer alone is insufficient.

### Consolidated on 2026-09-08 at `M3-CP4c-3-DEFN-R8`

The completed `Architecture_M3_CP4c3_TB42_Independent_Review_Record.md` (**212 lines**) was folded after its durable
conclusions were promoted into Part XII, Current/Forward, ORIENTATION, TODO, tracker, handoff and changelog.
Historical content retained here: TB42 was mechanically valid and promoted; its EC7 row proved a healthy 226-face /
9-component uncut census wholly disjoint from the 10-face terminal region (0 overlap), with no locator and a benign
9-row owner guard. The review therefore classified the defect as a **domain mismatch**, not emptiness/lookup/guard
failure, and required a static definition turn rather than more measurement. Part XII now resolves that requirement
and freezes CB48. Fold accounting advances from **134 documents / 25,676 lines** to **135 documents / 25,888
lines**. Git history remains exact-byte recovery authority for the retired review record.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB43-REV`

Mandatory REVIEW consolidation. Durable TB42 runtime facts are retained in this record, the tracker, CHANGELOG and
Git history before the superseded TB42 EXEC report is folded. TB43 is the current runtime report and remains live.
The already-consumed TB43 artifact-only plan is retrospectively indexed here because TB43 closeout retired it
between REVIEW turns.

| Folded/indexed document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB42_EXEC_Report.md` | 78 | superseded runtime authority — selector409 398 PASS / 11 RED, accepted 365/365, package107; its domain-mismatch measurement led to Part XII and is now superseded by promoted TB43 |
| `Architecture_M3_CP4c3_TB43_Artifact_Only_Test_Benchmark_Plan.md` | — | retrospectively indexed consumed evidence contract — frozen package108/selector409 Part XII falsifier discharged by promoted TB43; exact bytes remain in Git history at `f604b3e10fe2` |

**Folded here:** 1 currently retained document, **78 lines**. **Running total: 136 documents, 25,966 lines.** The
retrospective TB43 plan index is accounting-neutral because the file was already retired between REVIEW turns and
was not part of the 135-document retained fold count.

**Retained as current authority:** `Architecture_M3_CP4c3_TB43_EXEC_Report.md` (promoted runtime, package108,
402 PASS / 7 RED, accepted 365/365), `Architecture_M3_CP4c3_TB43_Independent_Review_Record.md` (current review),
`Architecture_M3_CP4c3_CB49_Code_Build_Plan.md` (single exact next-turn plan), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record and every byte-frozen selector.

**Review conclusion retained here.** Part XII is runtime-proved and its protected candidate is closed. 366/367 are
root-caused to predicate drift between `build_regions()` and `build_fragment_corner_incidence()`: the latter drops
every final no-barrier segment while region ownership drops only same-orbit/non-separating cases. Existing Part VIII
and Part XI authority decide a bounded CB49 correction; no new definition is required.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB44-REV`

Mandatory REVIEW consolidation. Durable TB43/CB49/TB44-plan facts are preserved in this record, the TB44 review record, tracker, ORIENTATION, current/forward state and CHANGELOG before superseded per-turn documents are folded. TB44 EXEC remains the current runtime-authority report; TB44-REV remains the current review record; CB50 is the single retained next-turn plan.

| Folded/indexed document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB43_EXEC_Report.md` | 161 | superseded runtime authority — package108/selector409 402 PASS / 7 RED, accepted 365/365; Part XII recovered and 366/367 retained the owner-missing locus |
| `Architecture_M3_CP4c3_TB43_Independent_Review_Record.md` | 232 | superseded review authority — promoted TB43, root-caused separation-predicate drift, froze CB49 and restored TB44 timeout control |
| `Architecture_M3_CP4c3_CB49_Code_Build_Plan.md` | 131 | consumed build plan — align only the corner-incidence separation predicate and preserve graph/region/partition/selector semantics |
| `Architecture_M3_CP4c3_CB49_Code_Build_Report.md` | 195 | consumed build report — package109 compile-green, exact source `cf969597...`, GMP/GMPXX, runtime-free; CB49 old-locus correction later runtime-advanced in TB44 |
| `Architecture_M3_CP4c3_TB44_Artifact_Only_Test_Benchmark_Plan.md` | 273 | consumed evidence contract — package109/selector409 full gate with restored per-identity timeout; raw result promoted by TB44-REV |

**Folded here:** 5 documents, **992 lines**. **Running total: 141 documents, 26,958 lines.** Exact bytes remain recoverable from Git history.

**Review conclusion retained here.** TB44/package109 is promoted at 398 PASS / 11 RED, accepted 365/365. CB49 is not reverted: its exact owner-missing locus disappeared. The next product defect is whole-face aggregation of carrierless rays that already carry exact source-corner authority. The four protected census identities still prove their producer predicates; their RED is a shared test helper broadening R8.3 current-region evidence to a source-face failure raised before the region loop. Existing Part VIII/Part XI/Part XII decide CB50; no DEFN-R9. Stable accounting remains 47 / 14 / 33, debt 5, packages 109.

### Consolidated on 2026-09-09 at `M3-CP4c-3-TB46-R1-REV`

Mandatory REVIEW consolidation. TB46-R1/package111 is promoted as current semantic runtime authority. The review
adjudicates ordinal367 as a recurrence of the DEFN-R3.4-disproved local-fragment/global-owner injectivity
assumption, closes protected 390/393/406/407 success-path observability as runtime-proved, retains the five carried
RED owners, and freezes CB53 as the single next plan.

The following **8 live superseded documents / 1,040 lines** were folded after their durable facts were preserved:

| folded document | lines | role / verdict preserved |
|---|---:|---|
| `Architecture_M3_CP4c3_CB51_Code_Build_Report.md` | 123 | consumed package111 Code + Build report |
| `Architecture_M3_CP4c3_CB52_Orchestration_Correction_Plan.md` | 67 | consumed runtime-free control-plane correction plan |
| `Architecture_M3_CP4c3_CB52_Orchestration_Correction_Report.md` | 121 | consumed preflight/failure-containment proof; generic harness remained byte-identical |
| `Architecture_M3_CP4c3_TB45_EXEC_Report.md` | 150 | superseded package110 runtime report, 399/10 historical authority |
| `Architecture_M3_CP4c3_TB45_Independent_Review_Record.md` | 262 | superseded review authority; CB51 measures and TB44 EG10.3 disposition preserved |
| `Architecture_M3_CP4c3_TB46_Artifact_Only_Test_Benchmark_Plan.md` | 108 | consumed initial package111 artifact-only contract |
| `Architecture_M3_CP4c3_TB46_EXEC_Report.md` | 121 | orchestration-invalid 0/409 attempt; no semantic ledger |
| `Architecture_M3_CP4c3_TB46_R1_Artifact_Only_Test_Benchmark_Plan.md` | 88 | consumed re-execution contract that produced current TB46-R1 evidence |

One additional plan was retired between REVIEW turns and is retrospectively indexed here without changing the
folded-document running total:

| retrospectively indexed document | lines | role / verdict preserved |
|---|---:|---|
| `Architecture_M3_CP4c3_CB51_Code_Build_Plan.md` | 157 | consumed TB45-REV successor plan; exact bytes at commit `104b631f01cd5a1be0c5369fb5a8a743651f5bce`, deletion visible in `e91c192fcaecd04eb859430945ca8e8fd04962da` |

**Running consolidation total:** prior **146 documents / 27,829 lines** + this review's **8 / 1,040** =
**154 documents / 28,869 lines**. The retrospective index is accounting-neutral.

**Review conclusion retained here.** Package111 is promoted at 403/6, accepted 365/365. DEFN-R3.4 already forbids
the ordinal367 equality assumption: distinct global face-walk owners may be fewer than local fragments, while an
over-count remains invalid. CB53 changes only the independent oracle's `!=` guard to `>`. Protected
390/393/406/407 are runtime-proved on `PlanFrontier`; 368/369/370/374/398 retain separate owners. Stable accounting
stays 47 / 14 / 33, debt 5, packages 111.

### Consolidated on 2026-09-09 at `M3-CP4c-3-TB45-REV`

Mandatory REVIEW consolidation. TB45/package110 is promoted as current semantic runtime authority. Durable TB44,
CB50 and consumed TB45-plan facts are preserved in this record, the TB45 review record, tracker, ORIENTATION,
Current/Forward, TODO and CHANGELOG before superseded per-turn documents are folded. TB45 EXEC remains the current
runtime-authority report; TB45-REV is the current review record; CB51 is the single retained next-turn plan.

| Folded/indexed document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB44_EXEC_Report.md` | 179 | superseded runtime authority — package109/selector409 398 PASS / 11 RED, accepted 365/365; root-caused by TB44-REV |
| `Architecture_M3_CP4c3_TB44_Independent_Review_Record.md` | 287 | superseded review authority — promoted TB44, root-caused source-corner fan and typed terminal-subject defects, plus EG10.3 audit obligation |
| `Architecture_M3_CP4c3_CB50_Code_Build_Plan.md` | 130 | consumed build plan — bounded source-corner fan + terminal-subject helper corrections |
| `Architecture_M3_CP4c3_CB50_Code_Build_Report.md` | 114 | consumed compile/package report — package110 exact source `46554ef2...`, GMP/GMPXX, 28/28 manifest, runtime-free |
| `Architecture_M3_CP4c3_TB45_Artifact_Only_Test_Benchmark_Plan.md` | 161 | consumed artifact-only evidence contract — package110/selector409 full gate; raw result promoted by TB45-REV |

**Folded here:** 5 documents, **871 lines**. **Running total: 146 documents, 27,829 lines.** Exact bytes remain
recoverable from Git history.

**Review conclusion retained here.** TB45/package110 is promoted at 399 PASS / 10 RED, accepted 365/365. Ordinal366
proves the CB50 source-corner fan correction moved the intended locus. Ordinal367's later `FragmentPartition` stop
is a stale independent-oracle unconditional terminal-slit skip; the oracle must use its independently derived
forward/reverse orbit equality. Protected 390/393/406/407 now fail only because their fixture requires the
mechanical plan to fail even though it succeeds; Part XII remains historically runtime-proved by TB43, while CB51
must make the existing producer frontier census observable on successful plans and preserve the corruption
negatives. TB44 EG10.3 is explicitly settled: the syntactic terminal-slit trace census is intentional, while the
failure-only fragment-incidence evidence must retain separating terminal segments. Stable accounting remains
47 / 14 / 33, debt 5, packages 110.

## 6. Historical retirement

All files below are historical-only after consolidation. Their exact bytes remain recoverable from Git history; current/future authority does not depend on them except where selector lineage is explicitly retained in §1.

### 6.1 Retired on 2026-08-29

- `Architecture_M3_CP4c_Required_Green_Selector.txt`
- `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`
- `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`
- `Architecture_M3_CP4c0_Required_Green_Selector.txt`
- `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`
- `Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`
- `Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c0b_Required_Green_Selector.txt`
- `Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c1_Required_Green_Selector.txt`
- `M3_CP4c0b_Closure_Record.md`
- `M3_CP4c1_Closure_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`

### 6.2 Retired by this 2026-08-30 consolidation

The durable facts from these superseded per-turn records are preserved in §§3–4 and in the normal project accounting records. They are removed rather than retained as parallel authority:

- `Architecture_M3_CP4c2_CB5_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB6_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB7_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB8_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB9_Code_Build_Report.md`
- `Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R8_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Report.md`

Historical per-turn CP4c records retired in earlier consolidation rounds remain represented here, in `CHANGELOG.md`, and in Git history; they are not resurrected.

### 6.3 Retired by the 2026-08-31 consolidation

`Architecture_M3_CP4c3_CB1_Code_Build_Report.md` is the only additional CP4c per-turn record that became
historical after the prior consolidation. Its durable AK1–AK3 outcome and measured successor evidence are already
preserved in §4 and the retained TB1/review authorities. The non-duplicated compile/package provenance retained from
CB1 is:

- instrumentation commit `014c7f7f8d6984518cf5c81156a10d3e06298349`; corrected semantic source
  `48dd011c4aa689a245b74527ed9df0900ada9bf3`;
- the first compile-only run `33338011871` failed because `FieldAtlasRegionCycleBasisDiagnostics` was
  default-constructed despite its non-default-constructible `TopologyRegionId`; the only correction was aggregate
  initialization with `region.id()`;
- authoritative compile/package run/job `33338642383 / 99330058374`, package **68**, artifact `9739919234`,
  package SHA-256 `127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`, packaged source archive
  SHA-256 `f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`, compile-log artifact
  `9739919468` SHA-256 `2074a5d2035dd84fe62ad424a8d95dfebe7af219f520f9f07e062af57ade21cd`, internal manifest
  **28/28 verified**;
- build used `DIRECTIONAL_ENABLE_GMP=ON`, linked both GMPXX and GMP, reported `exactArithmeticBackend=GMP`,
  and executed no compiled binary.

The CB1 report's exact bytes remain recoverable from Git history and no current/future authority depends on the file.

### 6.4 Retired by the 2026-09-03 user-authorized consolidation

The user explicitly requested consolidation of every `*_M3_CP4c_*` historical document that no longer relates to current or future work. A dependency-closure audit started from the current/frozen CP4c definitions and selectors plus `Future_Chat_Session_Handoff.md`, `TODO.md`, `ORIENTATION.md`, `DESIGN.md`, `REORIENTATION_PLAN.md`, `LESSONS.md`, `ROADMAP.md`, and `Regression_Root_Cause_Tracker.md`, then followed references transitively through retained CP4c authorities. **Only files outside that live dependency closure were retired.**

Retired Code + Build evidence/plans (15):
  - `Architecture_M3_CP4c3_CB10_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB11_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB12_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB13_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB14_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB15_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB16_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB2_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB3_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB5_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB6_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB7_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB8_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB8_Independent_Review_Plan.md`
  - `Architecture_M3_CP4c3_CB9_Code_Build_Report.md`

Retired Test + Benchmark / review evidence (28):
  - `Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB11_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB11_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB13_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB13_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB1_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB3_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB3_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB5_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB5_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB6_Independent_Review_Plan.md`
  - `Architecture_M3_CP4c3_TB6_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB7_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB7_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB8_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB8_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB9_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB9_Artifact_Only_Test_Benchmark_Report.md`

Their durable semantic, runtime, build/package, reversal, and selector-lineage facts are already deduplicated in §§4-5 and the durable `CHANGELOG.md`; exact historical bytes remain recoverable from Git history. No frozen definition, selector, then-current TB15 runtime evidence/review authority, CP4c-2 closure authority, or transitive dependency of a live durable document was removed.

### 6.5 Durable ORIENTATION authority

`ORIENTATION.md` is **DURABLE** and is not historical CP4c debris. Every REVIEW turn must update its currency line, current position, witness table when changed, open problems in priority order, and recurring-defect section when a new pattern or instance is found. It must not be deleted, renamed away, or collapsed into another document without explicit user authorization.

## 7. Resume pointer

After the durable start-of-turn checklist, load current authority from:

1. `ORIENTATION.md` — read first;
2. `Future_Chat_Session_Handoff.md`;
3. `TODO.md`;
4. `Architecture_M3_CP4c3_TB46_R1_EXEC_Report.md` — promoted package111 runtime evidence;
5. `Architecture_M3_CP4c3_TB46_R1_Independent_Review_Record.md` — current review authority;
6. `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md` — exact next plan;
7. `M3_CP4c_Frozen_Definitions.md` — especially DEFN-R3.4 and DEFN-R4.1;
8. `Regression_Root_Cause_Tracker.md`;
9. this consolidated record only when historical lineage is required.

**Exact next:** **`M3-CP4c-3-CB53` — test-authority correction, Code + Build, runtime-free, GMP/GMPXX linked.**
Change only the independent fragment-count oracle's final two-sided `!=` rejection to the frozen one-sided `>`
over-count rejection. Preserve CB51 terminal separation, independent orbit derivation, selector409 and all product,
fixture and carried-RED authority.

---
## Folded document index — DURABLE, DO NOT DELETE
Consolidated on **2026-09-03** at `M3-CP4c-3-TB17-REV`. The 35 per-turn plans, reports and review records
listed below were folded into this record: their conclusions are carried by this file, by
`Regression_Root_Cause_Tracker.md` (candidate adjudications), by `LESSONS.md` (durable lessons) and by
`ORIENTATION.md` (recurring patterns and facts). **Their full text is retained in git history** — recover any
of them with `git log --diff-filter=D -- .agents/Directional/<name>` and `git show <sha>^:<path>`.

This index exists so that citations elsewhere still resolve. `CHANGELOG.md`, this record and
`Regression_Root_Cause_Tracker.md` cite these filenames as statements about past turns; those citations were
deliberately **not** rewritten, because they describe what a turn produced at the time. Look the name up here.

**Not folded, and still live authority:** every `Required_Green_Selector_*.txt`, the current `M3-CP4c-3-TB17`
report and review record, `M3_CP4c_Current_And_Forward.md`, and the normative definitions — which were
themselves consolidated on 2026-09-03 into `M3_CP4c_Frozen_Definitions.md`, carrying all six source documents
**verbatim** with a citation map from the former filenames.

| Folded document | Lines | Recorded verdict or title |
|---|---:|---|
| `Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md` | 330 | M3-CP4c-2 TB-X2-R10 Independent Review Record |
| `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` | 312 | M3-CP4c-3 TB1 Phase-1 Independent Review Record |
| `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md` | 417 | M3-CP4c-3 TB2 Independent Review Record |
| `Architecture_M3_CP4c3_TB3_R1_Artifact_Only_Test_Benchmark_Report.md` | 100 | **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366** |
| `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md` | 87 | **FROZEN NEXT-TURN PLAN / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB4_Artifact_Only_Test_Benchmark_Report.md` | 139 | **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366; AP6 DIAGNOSTIC PASS COMPLETE** |
| `Architecture_M3_CP4c3_TB4_Independent_Review_Plan.md` | 115 | **FROZEN NEXT-TURN PLAN / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB4_Independent_Review_Record.md` | 396 | M3-CP4c-3 TB4 Independent Review Record |
| `Architecture_M3_CP4c3_TB5_Independent_Review_Plan.md` | 89 | M3-CP4c-3-TB5 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB5_Independent_Review_Record.md` | 473 | M3-CP4c-3 TB5 Independent Review Record |
| `Architecture_M3_CP4c3_TB7_Independent_Review_Plan.md` | 122 | M3-CP4c-3-TB7 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` | 567 | M3-CP4c-3-TB7 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_CB8_Code_Build_Plan.md` | 204 | M3-CP4c-3-CB8 Code + Build Plan — Exact Single-Authority Vertex Transit |
| `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md` | 305 | **COMPLETE / CB8 ARCHITECTURAL STOP UPHELD / DEEPER DEFINITION REQUIRED / NO SUCCESSOR CB AUTHORIZED** |
| `Architecture_M3_CP4c3_TB8_Independent_Review_Plan.md` | 123 | M3-CP4c-3-TB8 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB8_Independent_Review_Record.md` | 426 | TB8 is a **valid semantic red**. The ordinal-366 first red is classified **BA2 category 3 — |
| `Architecture_M3_CP4c3_TB9_Independent_Review_Plan.md` | 133 | M3-CP4c-3-TB9 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB9_Independent_Review_Record.md` | 441 | TB9 is a **valid semantic red**. Ordinal 366 is classified **BC2 category 1 — a genuine product |
| `Architecture_M3_CP4c3_TB10_Independent_Review_Plan.md` | 123 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` | 388 | M3-CP4c-3-TB10 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_TB11_Independent_Review_Plan.md` | 72 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB11_Independent_Review_Record.md` | 404 | TB11 is a **valid semantic red**. The ordinal-366 collision is **not adjudicable from the retained |
| `Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md` | 112 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB12_Independent_Review_Record.md` | 344 | TB12 is a **valid semantic red**, and the root cause is now **proved**: BI2 alternative **2** — two |
| `Architecture_M3_CP4c3_TB13_Independent_Review_Plan.md` | 119 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB13_Independent_Review_Record.md` | 371 | TB13 is a **valid semantic red**, and the condition TB13 called underdetermined is **determined here |
| `Architecture_M3_CP4c3_TB14_Independent_Review_Plan.md` | 134 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB14_Independent_Review_Record.md` | 335 | TB14 is a **valid semantic red**. CB16's correction worked and pushed the rotation past **every vertex |
| `Architecture_M3_CP4c3_TB15_Artifact_Only_Test_Benchmark_Report.md` | 103 | **COMPLETE / VALID SEMANTIC RED / BRANCH DISCRIMINATED / NON-STABLE** |
| `Architecture_M3_CP4c3_TB15_Independent_Review_Plan.md` | 96 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB15_Independent_Review_Record.md` | 355 | TB15 is a **valid semantic red** and CB17's diagnostics resolve it. The incidence is **valid**; the |
| `Architecture_M3_CP4c3_TB16_Artifact_Only_Test_Benchmark_Report.md` | 98 | **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / V47 RE-PROVED / NON-STABLE** |
| `Architecture_M3_CP4c3_TB16_Independent_Review_Plan.md` | 66 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` | 364 | M3-CP4c-3-TB16 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_TB17_Independent_Review_Plan.md` | 67 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |

**Total folded:** 35 documents, 8330 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB18-REV`

The first application of the standing REVIEW-turn consolidation rule
(`CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn", user-authorized 2026-09-03). Each document's
durable facts were verified present in `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB17_Artifact_Only_Test_Benchmark_Report.md` | 94 | superseded runtime authority - TB17 375/8 red at selector 382; facts carried by the TB18 report |
| `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md` | 340 | superseded review authority - BRQ0-BRQ8; falsified the fragment equality, named the owner class, froze CB20/BS0-BS9 |
| `Architecture_M3_CP4c3_CB20_Code_Build_Report.md` | 80 | consumed build report - **COMPLETE / DIAGNOSTIC-ONLY / COMPILE GREEN**; BS0-BS9 disposition carried by the TB18-REV record |
| `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` | 101 | consumed evidence contract - the six BS9 discriminators; their dispositions carried by the TB18 report and the TB18-REV record |

**Total folded this turn:** 4 documents, 615 lines. **Running total:** 39 documents, 8945 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB19-REV`

Second application of the standing REVIEW-turn consolidation rule. Each document's durable facts were verified
present in `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` | 148 | superseded runtime authority - TB18 375/8 at selector 383; superseded by the TB19 report |
| `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` | 366 | superseded review authority - BT0-BT9; falsified the fragment equality, proved shared ownership legitimate, froze CB21/BU0-BU9, retired BS9-5 |
| `Architecture_M3_CP4c3_CB21_Code_Build_Report.md` | 173 | consumed build report - the one-sided fragment-owner correction; BU0-BU9 disposition confirmed by TB19 and carried by the TB19-REV record |
| `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md` | 191 | consumed evidence contract - discriminators D1-D6; dispositions carried by the TB19 report |
| `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md` | 112 | consumed binding review plan - measures CR0-CR8, all discharged in the TB19-REV record |

**Total folded this turn:** 5 documents, 990 lines. **Running total:** 44 documents, 9935 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB20-REV`

Third application of the standing REVIEW-turn consolidation rule. Each document's durable facts were verified
present in `Architecture_M3_CP4c3_TB20_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` | 337 | superseded review authority - CR0-CR8; proved the frontier locus an iteration artifact, kept the torus case separate, froze CB22/BV0-BV9 |
| `Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md` | 131 | consumed binding review plan - measures CW0-CW9, all discharged in the TB20-REV record |

| `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md` | 215 | superseded runtime authority - TB19 376/8 at selector 384; **retired by `M3-CP4c-3-TB20`'s stale-evidence cleanup (`ce9e6ad5`), indexed here at TB20-REV** |
| `Architecture_M3_CP4c3_CB22_Code_Build_Report.md` | 135 | consumed build report - the seed-state discriminator and component census; **retired by `M3-CP4c-3-TB20`'s stale-evidence cleanup (`ce9e6ad5`), indexed here at TB20-REV** |

**Total folded this turn:** 4 documents, 818 lines — 2 folded by this review, plus 2 that `M3-CP4c-3-TB20`'s
stale-evidence cleanup had already retired without an index entry. **Running total:** 48 documents, 10753 lines.

*A Code + Build or Test + Benchmark turn's stale-evidence cleanup does not write this index; the next REVIEW turn
indexes anything it retired, so a filename retired between reviews still resolves here.*

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB38-REV` — nothing folded, and why

Mandatory REVIEW consolidation. **No document was folded, and that is the correct outcome**, because the usual
trigger — a new runtime authority superseding the old — did not occur:

- **`M3-CP4c-3-TB38` was not promoted.** It broke the accepted prefix, so
  `Architecture_M3_CP4c3_TB37_EXEC_Report.md` **remains the current valid semantic runtime authority** and
  `Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md` is retained with it.
- `Architecture_M3_CP4c3_TB37_Independent_Review_Record.md` is the adjudication **of the still-current
  authority**, and its CZ0–CZ6 derivation remains live even though the Part X clause it froze is withdrawn. Folding
  the review of the current authority while keeping that authority would leave the ledger incoherent.
- `Architecture_M3_CP4c3_CB42_Code_Build_Report.md` is the build that produced the current package 102.
- `Architecture_M3_CP4c3_CB43_Code_Build_Report.md` is **retained deliberately**: it is the provenance for the
  regression, and it records that CB43 implemented Part X faithfully. Discarding it would leave the impression
  that the implementation was at fault. `Architecture_M3_CP4c3_TB38_EXEC_Report.md` and its plan are the evidence
  CB44 must work from.

**Running total unchanged: 113 documents, 22,254 lines** (the last folding turn was `M3-CP4c-3-TB37-REV`, which
folded 4 documents / 730 lines).

**Definition-authority note.** **`DEFN-R6.4` is withdrawn** — the whole-face criterion `χ = V_total − E_total + F
= 1` is refuted on the torus fixture and cost accepted ordinals 356/357/362. **`DEFN-R6.3` — the counted complex —
is the live question**, exactly as Part X §9's own falsifier predicted. R6.1, R6.2, R6.5, R6.6 and R6.7 stand,
with R6.7 amended in practice by `LESSONS.md` 155: a proof obligation must carry a **non-emptiness condition**.

### Consolidated on 2026-09-07 at `M3-CP4c-3-DEFN-R6` — nothing folded, and why

Mandatory REVIEW consolidation performed (`DEFN` absorbs REVIEW + PLAN). **No document was folded**, and that is
the correct outcome rather than an omission:

- `M3-CP4c-3-DEFN-R6` was **authored in place** as **Part X** of `M3_CP4c_Frozen_Definitions.md`, per the standing
  practice since Part VII, so it created no per-turn document to retire.
- `Architecture_M3_CP4c3_TB37_EXEC_Report.md` remains the **current valid semantic runtime authority** — DEFN-R6
  ran no runtime and did not displace it — and
  `Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md` is the contract that produced it.
- `Architecture_M3_CP4c3_TB37_Independent_Review_Record.md` is the review DEFN-R6 consumes and **extends** at its
  CZ6 — Part X adds the second premise site the review did not have — so it is retained for its provenance.
- `Architecture_M3_CP4c3_CB42_Code_Build_Report.md` is the build that produced the current package and carries the
  grep proving no accepted identity asserts `RegionEulerCharacteristicNotOne`.

Consolidation is a preservation procedure, not a reduction target. **Running total unchanged: 113 documents,
22,254 lines** (the last folding turn was `M3-CP4c-3-TB37-REV`, which folded 4 documents / 730 lines).

**Definition-authority note.** The operative CP4c-3 definitions are now **Part VI together with Parts VII, VIII,
IX and X**; Part IX-A amends Part IX without overriding it, and **Part X supersedes Part IX §5 (DEFN-R5.5) only**,
replacing its measurement-only disposition with the decided Euler criterion. Part X also **withdraws Part IX-A
§A.2's implication that the cancellation premise itself fails** — the premise is correct about the boundary, and
the defect is the misclassification of interior barrier edges.

### Consolidated on 2026-09-07 at `M3-CP4c-3-TB37-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB37_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in CZ0–CZ6 of the
TB37 review record:** the promotion evidence, the artifact proof that CB42 changed no behaviour, the seven
independent checks on `D = 48`, the decomposition `(20 − 20) + (16 − 12)` that locates the defect in interior
barrier edges, and the whole-face rounding caveat.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB36_Independent_Review_Record.md` | 245 | superseded review authority - CY0-CY6. Promoted TB36, proved Part IX's provenance relation in both directions, showed the CX5 census was taken in the wrong domain, and **derived the identity chi_true = X + B_int - 47** that this turn resolved. Its two pre-measurement predictions both landed |
| `Architecture_M3_CP4c3_TB36_EXEC_Report.md` | 185 | superseded runtime authority - TB36, 402 PASS / 7 RED on selector 409, accepted 365/365, package101 |
| `Architecture_M3_CP4c3_TB36_Artifact_Only_Test_Benchmark_Plan.md` | 170 | consumed contract |
| `Architecture_M3_CP4c3_CB41_Code_Build_Report.md` | 130 | consumed build report - CX0-CX8. Implemented the derived provenance relation and the first (network-domain) Euler census; superseded as package authority by CB42 |

**Folded here:** 4 documents, 730 lines. **Running total: 113 documents, 22,254 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB37_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 402 PASS / 7 RED, accepted 365/365, package102),
`Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB37_Independent_Review_Record.md` (this review and the frozen DEFN-R6 scope),
`Architecture_M3_CP4c3_CB42_Code_Build_Report.md` (**the build that produced the current package**, and the grep
proving no accepted identity asserts `RegionEulerCharacteristicNotOne`), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md` (**Part IX operative, amended by Part IX-A; Part X appends next**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not a document.

### Consolidated on 2026-09-07 at `M3-CP4c-3-TB36-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB36_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in CY0–CY6 of the
TB36 review record:** the promotion evidence, the two-directional runtime proof of Part IX's provenance relation,
the domain mismatch between the CX5 census and the χ computation, the measured boundary shape, and the derivation
of **χ_true = X + B_int − 47**.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB35_Independent_Review_Record.md` | 251 | superseded review authority - CW0-CW5. Established the face-walk single-walk guarantee from source and froze DEFN-R5. Its §2.4 framing of the Euler result as a **second, independent finding** was already withdrawn by Part IX-A §A.2 and is now runtime-superseded |
| `Architecture_M3_CP4c3_TB35_EXEC_Report.md` | 154 | superseded runtime authority - TB35, 402 PASS / 7 RED on selector 409 with the accepted prefix restored to 365/365 |
| `Architecture_M3_CP4c3_TB35_Artifact_Only_Test_Benchmark_Plan.md` | 151 | consumed contract |

**Folded here:** 3 documents, 556 lines. **Running total: 109 documents, 21,524 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB36_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 402 PASS / 7 RED, accepted 365/365, package101),
`Architecture_M3_CP4c3_TB36_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB36_Independent_Review_Record.md` (this review and the frozen CY6 measure),
`Architecture_M3_CP4c3_CB41_Code_Build_Report.md` (**the build that produced the current package**, and the static
audit proving ordinals 312/409 byte-identical), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md` (**Part IX operative, amended by Part IX-A**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not a document.

### Consolidated on 2026-09-07 at `M3-CP4c-3-DEFN-R5` — nothing folded, and a divergence resolved

Mandatory REVIEW consolidation performed (`DEFN` absorbs REVIEW + PLAN). **No document was folded**, and that is
the correct outcome rather than an omission:

- `M3-CP4c-3-DEFN-R5` was **authored in place** as **Part IX** of `M3_CP4c_Frozen_Definitions.md`, per the standing
  practice since Part VII, so it created no per-turn document to retire.
- `Architecture_M3_CP4c3_TB35_EXEC_Report.md` remains the **current valid semantic runtime authority** — DEFN-R5
  ran no runtime and did not displace it — and
  `Architecture_M3_CP4c3_TB35_Artifact_Only_Test_Benchmark_Plan.md` is the contract that produced it.
- `Architecture_M3_CP4c3_TB35_Independent_Review_Record.md` is the review DEFN-R5 consumes and **corrects** — Part
  IX-A §A.2 withdraws its "second, independent finding" framing of the Euler result — so it is retained for its
  provenance, exactly as Part VIII retained the TB31 record it corrected.

**Divergence resolved.** `M3-CP4c-3-DEFN-R5` was executed **twice concurrently** and produced two Part IX drafts.
The Drive-patch execution's draft is **authoritative and unmodified**; the second execution's draft was **not**
merged into it. Only the three findings it contributed that Part IX does not carry were preserved, as
**Part IX-A**, which amends without overriding. The rejected draft's construction-time provenance rule is recorded
there **because it was wrong in a load-bearing way** — it would have re-broken accepted ordinal 312 through the
copy the synthetic negatives perform — and that reasoning is worth more preserved than discarded. `LESSONS.md`
148.

Consolidation is a preservation procedure, not a reduction target. **Running total unchanged: 106 documents,
20,968 lines** (the last folding turn was `M3-CP4c-3-TB35-REV`, which folded 4 documents / 753 lines).

**Definition-authority note.** The operative CP4c-3 definitions are **Part VI together with Parts VII, VIII and
IX**, each superseding the earlier where they conflict; **Part IX-A amends Part IX without overriding any of it.**

### Consolidated on 2026-09-06 at `M3-CP4c-3-TB35-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB35_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in §§1–3 of the
TB35 review record:** the restored accepted prefix, ordinal 409's re-aimed oracle, the `ClosedBeforeEnd`
discriminator outcome, the ownership census `300 / 0 / 0`, and the **source proof that a plan region's boundary is
a face-walk orbit**.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB34_Independent_Review_Record.md` | 278 | superseded review authority - CV0-CV6. Recorded this checkpoint's **first accepted-green loss** and its stable event, reverted CU4, and named the authority-domain conflation. **Its stable event stands**; its refutation of `TB33-REV-CAND-01` is **reconciled** rather than upheld - that reading was right about the synthetic region and wrong as a general statement |
| `Architecture_M3_CP4c3_TB34_EXEC_Report.md` | 197 | superseded runtime authority - TB34, 400 PASS / 9 RED on selector 409 with **accepted 364/365**; the run that caught the regression on its first execution |
| `Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md` | 157 | consumed contract |
| `Architecture_M3_CP4c3_CB40_Code_Build_Report.md` | 121 | consumed build report - CV2 restored the rejection **with** its typed reason and CV3 re-aimed ordinal 409 at the reachable shape; both discharged at TB35 |

**Folded here:** 4 documents, 753 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB35_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 402 PASS / 7 RED with the accepted prefix restored to 365/365),
`Architecture_M3_CP4c3_TB35_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB35_Independent_Review_Record.md` (this review and the frozen DEFN-R5 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative; DEFN-R5 appends as Part
IX**), `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not a document.

### Consolidated on 2026-09-06 at `M3-CP4c-3-TB34-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB34_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in §§1–4 of the
TB34 review record:** ordinal 312's verbatim failure, the `ClosedBeforeEnd` / `RegionEulerCharacteristicNotOne`
pair on 366/367, ordinal 409's unconstructible-fixture message, and the ownership census `300 / 0 / 0`.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB33_Independent_Review_Record.md` | 294 | superseded review authority - CU0-CU6. Discharged every CT measure and recorded the cleanest RED set of the checkpoint, but its **§3.1/§3.2 derivation is refuted**: the `current == start` disjunct is load-bearing, accepted ordinal 312 encodes it, and the certificate argument conflated certified faces with plan regions. **CU4 is reverted; CU5 is upheld** |
| `Architecture_M3_CP4c3_TB33_EXEC_Report.md` | 144 | superseded runtime authority - TB33, 401 PASS / 7 RED on selector 408, accepted 365/365; the last run before the accepted prefix broke |
| `Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md` | 181 | consumed contract |
| `Architecture_M3_CP4c3_CB39_Code_Build_Report.md` | 65 | consumed build report - it implemented CU4/CU5/CU6 faithfully. **The defect was in the frozen measure, not the implementation** |

**Folded here:** 4 documents, 684 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB34_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 400 PASS / 9 RED with accepted prefix **364/365**),
`Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB34_Independent_Review_Record.md` (this review and the frozen CB40 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not a document.

### Consolidated on 2026-09-06 at `M3-CP4c-3-TB33-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB33_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in §§1–3 of the
TB33 review record:** the ownership census `300 / 0 / 0`, the **nine-component unique-seed** publication, the
absence of both retired codes from 408 logs, the stage-labelled frontier detail, and the second ledger-hash
collision.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB32_Independent_Review_Record.md` | 326 | superseded review authority - CT0-CT7. Upheld both DEFN-R4 falsifiers, found CS3 unmet and DEFN-R4.5 under-specified, and named the back-fill, ledger-digest and harness-relabelling defects. **All five CT measures are now discharged** |
| `Architecture_M3_CP4c3_TB32_EXEC_Report.md` | 117 | superseded runtime authority - TB32, 397 PASS / 11 RED on selector 408, accepted 365/365; the run whose ledger hash collided with TB31's |
| `Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md` | 170 | consumed contract |
| `Architecture_M3_CP4c3_CB38_Code_Build_Report.md` | 113 | consumed build report - stage labels, the justified cleared-stage outcome for four witnesses, the failure-detail digest, and the turn-agnostic harness; every measure verified against TB33 evidence |

**Folded here:** 4 documents, 726 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB33_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 408 at 401 PASS / 7 RED, accepted 365/365 — and the first report carrying verbatim failure
transcription for every RED focused ordinal), `Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB33_Independent_Review_Record.md` (this review and the frozen CB39 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh` is the instrument, not a document.

### Consolidated on 2026-09-06 at `M3-CP4c-3-TB32-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB32_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in §§1–2 of the
TB32 review record:** the ownership census `300 / 0 / 0`, the component-0 fingerprint `189 / 1 / Unique / [0]`, and
the fact that **neither `UncutFaceComponentOrbitSeedNotUnique` nor `TraceArcDoesNotSeparateItsSides` appears in any
of the 408 raw logs**.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` | 293 | superseded review authority - CR0-CR8. Closed the seed frontier, diagnosed the fragment-key guard, and froze DEFN-R4. Its §2.2 line-number inference was corrected by DEFN-R4, and its CAND-01 is now **closed / runtime-proved** |
| `Architecture_M3_CP4c3_TB31_EXEC_Report.md` | 118 | superseded runtime authority - TB31, 397 PASS / 11 RED on selector 408, accepted 365/365; the run whose ledger hash TB32 later reproduced byte-for-byte |
| `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md` | 247 | consumed contract |
| `Architecture_M3_CP4c3_CB37_Code_Build_Report.md` | 90 | consumed build report - CS1/CS2/CS3-letter/CS5, each verified in source by TB32-REV: the guard retired with the ownership contract recorded at the site, frontier evidence annotated at two loci, four failure-code assertions removed, selector 408 byte-unchanged |

**Folded here:** 4 documents, 748 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB32_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 408 at 397 PASS / 11 RED, accepted 365/365),
`Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB32_Independent_Review_Record.md` (this review and the frozen CB38 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Never folded:** the artifact-only harness scripts are the instrument, not documents.

### Consolidated on 2026-09-06 at `M3-CP4c-3-DEFN-R4` — nothing folded, and why

Mandatory REVIEW consolidation performed (`DEFN` absorbs REVIEW + PLAN). **No document was folded**, and that is
the correct outcome rather than an omission:

- `M3-CP4c-3-DEFN-R4` was **authored in place** as **Part VIII** of `M3_CP4c_Frozen_Definitions.md`, per the
  standing practice since Part VII, so it created no per-turn document to retire.
- `Architecture_M3_CP4c3_TB31_EXEC_Report.md` is the **current runtime authority** and
  `Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` is the review DEFN-R4 consumes and **corrects** at its
  §2.2 — neither is superseded.
- `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md` is the contract that produced the current
  runtime authority and is retained with it.

Consolidation is a preservation procedure, not a reduction target; there was nothing whose durable facts needed a
new home this turn. **Running total unchanged: 98 documents, 19,494 lines.** *(Advanced to 102 documents, 20,242 lines at `M3-CP4c-3-TB32-REV`; 106 documents, 20,968 lines at `M3-CP4c-3-TB33-REV`.)*

**Definition-authority note.** The operative CP4c-3 definitions are now **Part VI together with Parts VII and
VIII**, each superseding the earlier where they conflict. Part VIII withdraws TB31-REV's description of
`(face, orbit)` as a *fragment identity* and replaces it with the **ownership map** reading.

### Consolidated on 2026-09-06 at `M3-CP4c-3-TB31-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB31_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **The certified-owner census
`300 / 0 / 0` and the closing component-0 fingerprint `189 faces / seedCount 1 / Unique / [0]` are preserved in
§§1–2 of the TB31 review record.**

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB30_Independent_Review_Record.md` | 313 | superseded review authority - CQ0-CQ8. Found ownership total at 300/300, diagnosed the frozen rule as applied at one of two sites, and reclassified ordinal 398 off the ownership frontier. Its `M3-CP4c3-TB30-REV-CAND-01` is **runtime-proved and closed**, and **both its stated falsifiers were checked and neither reproduced** |
| `Architecture_M3_CP4c3_TB30_EXEC_Report.md` | 102 | superseded runtime authority - TB30, 401 PASS / 7 RED on selector 408, accepted 365/365 |
| `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` | 177 | consumed contract |
| `Architecture_M3_CP4c3_CB36_Code_Build_Report.md` | 162 | consumed build report - **the second application of the frozen separating-arc rule**, one guard plus a comment correction, runtime-proved at TB31: component 0 collapsed from 3 seeds to a unique `[0]` |

**Folded here:** 4 documents, 754 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB31_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 408 at 397 PASS / 11 RED, accepted 365/365),
`Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` (this review and the frozen DEFN-R4 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

**Never folded:** the artifact-only harness scripts are the instrument, not documents.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB30-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB30_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **CB34's CN7 transcription and
CB35's CO7 transcription are both preserved in §§1–4 of the TB30 review record** — including the three numbers that
close the certifier half of the frontier, `established=300 / unavailable=0 / conflicting=0`, and ordinal 398's
prescribed-sphere failing locus.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB29_Independent_Review_Record.md` | 319 | superseded review authority - CO0-CO8. Diagnosed both new REDs as test authority from the test source; **both diagnoses are confirmed verbatim by the transcribed failing assertions** |
| `Architecture_M3_CP4c3_TB29_EXEC_Report.md` | 99 | superseded runtime authority - TB29, 399 PASS / 9 RED on selector 408, accepted 365/365; the first runtime after a product correction on this frontier |
| `Architecture_M3_CP4c3_TB29_Artifact_Only_Test_Benchmark_Plan.md` | 169 | consumed contract |
| `Architecture_M3_CP4c3_CB34_Code_Build_Report.md` | 245 | consumed build report - **the separating-arc barrier correction**, seven lines, runtime-proved at TB29; carried the CN7 census transcription that decided the CL6 dichotomy |
| `Architecture_M3_CP4c3_CB35_Code_Build_Report.md` | 280 | consumed build report - the two test-authority repairs and the **CO7 transcription that recorded `established=300 / unavailable=0 / conflicting=0`** and every RED ordinal's failing assertion text |

**Folded here:** 5 documents, 1,112 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB30_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 408 at 401 PASS / 7 RED, accepted 365/365),
`Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_TB30_Independent_Review_Record.md` (this review and the frozen CB36 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

**Never folded:** the artifact-only harness scripts are the instrument, not documents.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB29-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB29_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. CB34's §4 **CN7 census
transcription is preserved in §2 of the TB29 review record**, and CB34's report is retained rather than folded so
the full 46-row transcription stays readable.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md` | 253 | superseded review authority - CN0-CN8. Adjudicated the control run, restated the frozen correction verbatim, and authorized CB34; the correction it carried is now **implemented and runtime-proved** |
| `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` | 86 | superseded runtime authority - TB28-R3, 400 PASS / 7 RED on selector 407, accepted 365/365. **The control run** that settled the TB28-R2 false green and restored the accepted-prefix statement |
| `Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` | 241 | consumed contract - the first plan to require per-identity routing and per-row selection proof |
| `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` | 144 | consumed build report - CL6/CL7 crossed-face and partition-identity publication; superseded as package authority by CB34 |
| `Architecture_M3_CP4c3_CB33_Code_Build_Report.md` | 130 | consumed build report - the orchestration correction that repaired identity routing and selection proof without recompiling, deliberately preserving the control |

**Folded here:** 5 documents, 854 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB29_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 408 at 399 PASS / 9 RED, accepted 365/365),
`Architecture_M3_CP4c3_TB29_Artifact_Only_Test_Benchmark_Plan.md`,
`Architecture_M3_CP4c3_CB34_Code_Build_Report.md` (**the package under test and the retained CN7 transcription**),
`Architecture_M3_CP4c3_TB29_Independent_Review_Record.md` (this review and the frozen CB35 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_tb28_r3_harness.sh` and its TB29 successor are the instrument, not documents.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB28-R3-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. The frozen
separating-arc barrier correction was **restated verbatim** in §7 of the review record before its source document
was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` | 275 | superseded review authority - CM0-CM9. Rejected TB28-R2 as orchestration-invalid on a provable contradiction, and **discharged CL8 by freezing the separating-arc barrier correction**, which is restated in the TB28-R3 review record and applied at CB34 |
| `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` | 132 | superseded runtime authority - TB27-R1, 399 PASS / 7 RED on selector 406, accepted 365/365. Deliberately retained through TB28 because TB28-R2 was rejected; **validly superseded by TB28-R3**, which reproduced its ledger exactly |
| `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` | 114 | **rejected attempt** - `407 PASS / 0 RED` on an unchanged ownership path, orchestration-invalid, no semantic credit. Its rejection and reasons are preserved here, in the tracker and in the folded TB28 review record |
| `Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` | 136 | consumed contract - superseded by the R3 plan, which added per-identity routing and selection proof |

**Folded here:** 4 documents, 657 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 407 at 400 PASS / 7 RED, accepted 365/365),
`Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` (the contract it executed),
`Architecture_M3_CP4c3_CB33_Code_Build_Report.md` and `Architecture_M3_CP4c3_CB32_Code_Build_Report.md`,
`Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md` (this review and the restated frozen correction),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

**Never folded:** `tools/m3_cp4c3_tb28_r3_harness.sh` is the instrument, not a document. It is product-adjacent
evidence and a reviewer must be able to read it rather than a summary of it.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB28_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` | 319 | superseded review authority - CL0-CL9. Recorded the refutation of its own predecessor's all-bridges prediction, confirmed the partition mismatch, and set the **CL8 hard stop rule**, which is **discharged** by §4 of the TB28 review record |
| `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` | 172 | consumed build report - CK8/CK9 serialization and partition identity; superseded as package authority by CB32 |

**Folded here:** 2 documents, 491 lines.

**Retained deliberately, and not as "superseded":**
`Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` is **the current valid semantic runtime
authority**, because `M3-CP4c-3-TB28-R2` was rejected as orchestration-invalid. It must not be folded until a valid
successor runtime exists. `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` is retained as
**invalid-attempt provenance** and `Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` as the frozen
contract TB28-R3 re-executes; `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` is the package under test.

**Also retained as current authority:** `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` (this review, the
frozen correction and the CB33/TB28-R3/CB34 sequence), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every
`Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` | 343 | superseded review authority - CK0-CK9. Its two load-bearing claims are **runtime-confirmed** (an incidence count is not a separation; the census described a different object). Its §1.2 static all-bridges prediction is **refuted** - arcs 14 and 22 separate |
| `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md` | 93 | superseded runtime authority - TB26-R1, 397 PASS / 8 RED on selector 405, accepted 365/365; the ledger the CK measures were frozen against |
| `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md` | 220 | superseded runtime authority - TB25-R1, 393 PASS / 10 RED on selector 403; retained one turn longer as the `established=74 / unavailable=226` baseline, now carried by the TB27 review record and this index |

**Folded here:** 3 documents, 656 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` (this review and the frozen CB32 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB26-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB26_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` | 344 | superseded review authority - CJ0-CJ9; diagnosed the starved seed rule, closed `M3-CP4c3-TB21-CAND-01` as ill-formed, and froze CB30. CJ7/CJ8/CJ9 are runtime-proved at TB26-R1; **CJ6's censuses are superseded as inadmissible about the failing component** - they are computed on the certifier's partition |
| `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` | 96 | consumed build report - publication survives ownership failure, `proves_embedded_cellularity()` introduced, conflict census added; superseded as package authority by CB30 |
| `Architecture_M3_CP4c3_TB26_Independent_Review_Intake.md` | 36 | consumed task brief - the seven mandatory review questions and stop rules for this review; its first premise (that `interiorArcs=4` selects the separating-arc horn) was **declined with reasons** in §1 of the review record |

**Folded here:** 3 documents, 476 lines.

**Noted:** `M3-CP4c-3-CB30` has no retained standalone Code + Build report. Its package authority
(`9957324848`) is carried by the TB26-R1 report and the CHANGELOG. A successor CB should restore the per-turn build
report so the package under test has a first-class provenance document.

**Retained as current authority:** `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime and current package provenance**),
`Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` (this review and the frozen CB31 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB25-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` | 370 | superseded review authority - CH0-CH9; found the ordering defect behind seven REDs, withdrew DEFN-R3.1's publication-not-computation clause, and froze CB28. CH6/CH7 are runtime-proved at TB25-R1 (384/385 recovered); **CH8's conflict census is superseded as vacuous** - it reads only established owners |
| `Architecture_M3_CP4c3_CB27_Code_Build_Report.md` | 128 | consumed build report - published the owner map, fixed ordinal 397, replaced 393 in place, made fixture resolution fail closed; superseded as package authority by CB28 |

**Indexed retrospectively under clause 3**, having been retired by `M3-CP4c-3-TB25-R1`'s stale-evidence cleanup
between reviews:

| Retired document | Verdict it carried |
|---|---|
| `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` | superseded runtime authority - TB24, 389 PASS / 12 RED on selector 401, accepted 365/365; the ledger TB24-REV adjudicated |
| `Architecture_M3_CP4c3_TB25_Artifact_Only_Test_Benchmark_Plan.md` | consumed evidence contract - the frozen TB25 execution boundary and its four-branch interpretation contract, preserved verbatim in the TB25-R1 report and applied by TB25-REV |
| `Architecture_M3_CP4c3_CB29_Code_Build_Report.md` | consumed control-only report - the pre-runtime harness correction after TB25's selector-injection failure; runtime-proved by TB25-R1 and closed as `M3-CP4c3-TB25-ORCH-01` |

**Folded here:** 2 documents, 498 lines, plus 3 retrospectively indexed.

**Retained as current authority:** `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` (this review and the frozen CB30 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB24-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB24_Independent_Review_Record.md`, `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
**before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` | 213 | superseded runtime authority - TB23-R1, 389 PASS / 8 RED on selector 397, accepted 365/365; the corrected execution view that proved CB26's harness fix. Superseded by TB24 on selector 401 |
| `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` | 269 | superseded review authority - CE0-CE8; confirmed the harness fix, proved certified ownership absent from the published contract, and froze DEFN-R3, which DEFN-R3 discharged |
| `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md` | 131 | consumed evidence contract - the frozen TB24 execution boundary and discriminators D1-D6; fully executed and reported by TB24-EXEC, adjudicated by this review |

**Folded here:** 3 documents, 613 lines. Every durable fact each carried is retained above, in the TB24 review
record, or in the tracker.

**Retained as current authority:** `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` (**authoritative
semantic runtime**), `Architecture_M3_CP4c3_CB27_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` (this review and the frozen CB28 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB23-R1-REV`

Seventh application of the standing REVIEW-turn consolidation rule, including retrospective indexing of the **five**
per-turn files `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup retired between reviews. Durable facts were verified
present in `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` before folding.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` | 264 | superseded review authority - CC0-CC8; upheld the orchestration-invalid classification, located the harness defect and froze CB26/CD0-CD8, which CB26 discharged (folded by this review) |
| `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` | 112 | superseded runtime authority - TB22 387/6 at selector 393. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` | 115 | consumed build report - the certificate-face diagnostics; CA1 partially met, CA2 met, CA3 satisfiable. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_CB26_Code_Build_Report.md` | 111 | consumed build report - the control-plane orchestration correction; confirmed at TB23-R1. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` | 200 | consumed evidence contract - re-executed by TB23-R1. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` | 100 | invalid-attempt provenance - orchestration-invalid, no semantic ledger. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |

**Total folded this turn:** 6 documents, 902 lines — 1 folded by this review, plus 5 retired by
`M3-CP4c-3-TB23-R1` without an index entry. **Running total:** 98 documents, 19494 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` (review and the frozen DEFN-R3 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB23-REV`

Sixth application of the standing REVIEW-turn consolidation rule. **No document was retired between reviews**, so
nothing needed retrospective indexing. Only one document was superseded — consolidation is not a quota, and the
TB22 report, the CB25 build report, the frozen TB23 plan and the TB23-EXEC report are all **retained** because each
remains live authority for the orchestration correction and its re-execution.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` | 326 | superseded review authority - BZ0-BZ8; proved both CB24 measurements vacuous and froze CB25/CA0-CA9, which CB25 statically discharged |

**Total folded this turn:** 1 document, 326 lines. **Running total:** 58 documents, 12481 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` (**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` (the package under re-execution), `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` (the frozen plan), `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` (invalid-attempt provenance), `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` (this review and the frozen CB26 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB22-REV`

Fifth application of the standing REVIEW-turn consolidation rule, including retrospective indexing of documents a
CB or TB turn retired between reviews. Durable facts verified present in
`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`LESSONS.md` and `CHANGELOG.md` **before** folding.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` | 330 | superseded review authority - BX0-BX8; withdrew the non-cellularity conclusion and froze CB24/BY0-BY9, whose BY3/BY4 wording TB22-REV found underspecified |
| `Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md` | 80 | consumed binding review plan - measures BZ0-BZ8, all discharged in the TB22-REV record |
| `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` | 142 | superseded runtime authority - TB21 384/7 at selector 391. **Retired by `M3-CP4c-3-TB22`'s stale-evidence cleanup (`4207907c`), indexed here at TB22-REV** |
| `Architecture_M3_CP4c3_CB24_Code_Build_Report.md` | 88 | consumed build report - the projection diagnostics; **TB22-REV proved both of its measurements vacuous**. Retired by `M3-CP4c-3-TB22`'s stale-evidence cleanup (`4207907c`), indexed here at TB22-REV |

**Total folded this turn:** 4 documents, 640 lines — 2 folded by this review, plus 2 retired by
`M3-CP4c-3-TB22` without an index entry. **Running total:** 57 documents, 12155 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` (review and the frozen CB25 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB21-REV`

Fourth application of the standing REVIEW-turn consolidation rule, including the retrospective indexing of
documents a CB or TB turn retired between reviews. Each document's durable facts were verified present in
`Architecture_M3_CP4c3_TB21_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Report.md` | 160 | superseded runtime authority - TB20 380/8 at the 388-identity selector; superseded by the TB21 report |
| `Architecture_M3_CP4c3_TB20_Independent_Review_Record.md` | 336 | superseded review authority - CW0-CW9; measured the Multiple branch, authorized the 371/372 decoupling, and reached a non-cellularity conclusion **withdrawn at TB21-REV** |
| `Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md` | 89 | consumed binding review plan - measures BX0-BX8, all discharged in the TB21-REV record |
| `Architecture_M3_CP4c3_CB23_Code_Build_Report.md` | 88 | consumed build report - the Euler census diagnostics; BW0-BW9 confirmed by TB21. **Retired by `M3-CP4c-3-TB21`'s stale-evidence cleanup (`8396f23c0`), indexed here at TB21-REV** |
| `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Plan.md` | 89 | consumed evidence contract - discriminators D1-D6; dispositions carried by the TB21 report. **Retired by `M3-CP4c-3-TB21`'s stale-evidence cleanup (`8396f23c0`), indexed here at TB21-REV** |

**Total folded this turn:** 5 documents, 762 lines — 3 folded by this review, plus 2 retired by
`M3-CP4c-3-TB21` without an index entry. **Running total:** 53 documents, 11515 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` (review and the frozen CB24 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB39-REV`

Mandatory REVIEW consolidation. TB39 is promoted, so TB37 ceases to be current runtime authority; TB38's rejected
runtime/review chain and the consumed TB39 execution plan are now historical. Durable facts were preserved first in
`Architecture_M3_CP4c3_TB39_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md`, `Required_Green_Selector_Manifest.md` and `CHANGELOG.md`.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md` | 194 | consumed TB37 artifact-only contract; TB37 is superseded as runtime authority by promoted TB39 |
| `Architecture_M3_CP4c3_TB37_EXEC_Report.md` | 197 | superseded runtime authority — selector409 402/7, accepted365/365, package102; colour vector later restored exactly by TB39 |
| `Architecture_M3_CP4c3_TB37_Independent_Review_Record.md` | 207 | superseded review authority — CZ0–CZ6; established whole-face +1 vs reduced -3 mechanical discrepancy and opened the counted-complex candidate |
| `Architecture_M3_CP4c3_TB38_Artifact_Only_Test_Benchmark_Plan.md` | 150 | consumed TB38 contract implementing the DEFN-R6.4 trial |
| `Architecture_M3_CP4c3_TB38_EXEC_Report.md` | 145 | rejected historical runtime — 395/14, accepted362/365; source of the one stable RP-01 event retained in accounting |
| `Architecture_M3_CP4c3_TB38_Independent_Review_Record.md` | 244 | superseded review authority — DA0–DA7; blamed DEFN-R6.4, withdrew its universal criterion, froze CB44 restoration/non-vacuous measurement |
| `Architecture_M3_CP4c3_TB39_Artifact_Only_Test_Benchmark_Plan.md` | 225 | consumed TB39 restoration/non-vacuity contract; discharged by promoted TB39 |
| `Architecture_M3_CP4c3_CB42_Code_Build_Report.md` | 135 | superseded package102 build authority; diagnostics-only behavior preservation proved by TB37 |
| `Architecture_M3_CP4c3_CB43_Code_Build_Report.md` | 112 | superseded package103 build authority; faithful implementation of DEFN-R6.4, whose regression remains historical evidence |

**Folded here:** 9 documents, **1,609 lines**. **Running total: 122 documents, 23,863 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB39_EXEC_Report.md` (current semantic runtime),
`Architecture_M3_CP4c3_CB44_Code_Build_Report.md` (current package104 build authority),
`Architecture_M3_CP4c3_TB39_Independent_Review_Record.md` (current review), and
`Architecture_M3_CP4c3_DEFN_R7_Definition_Plan.md` (single exact next-turn plan), together with durable definitions,
indexes and every byte-frozen selector.

**Definition-authority note.** This review does not edit normative Part X in place. It establishes that
DEFN-R6.3/R6.4 cannot remain the region-disc authority and freezes `M3-CP4c-3-DEFN-R7` to append the replacement
contract. Until that definition is written, current runtime evidence remains TB39's restored reduced rejection at
366/367; no proxy is silently promoted by documentation cleanup.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB42-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB42_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in ED0–ED7:** the
promotion evidence, the EC7 measurement row (226 / 9 / 9, locator `none`, 0-of-10), the refutation of the
empty-partition candidate, the confirmation of the domain mismatch, and the reading of the `UncutComponent` early
return as a domain guard written as a stage check.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB41_Independent_Review_Record.md` | 236 | superseded review authority — EC0-EC7. Promoted TB41, confirmed the content-anchor repair, reframed 390/393/406/407 as a never-executed oracle, and froze the EC7 measurement that TB42 answered |
| `Architecture_M3_CP4c3_TB41_EXEC_Report.md` | 202 | superseded runtime authority — TB41, 398 PASS / 11 RED, accepted 365/365, package106 |
| `Architecture_M3_CP4c3_CB46_Code_Build_Report.md` | 157 | consumed build report — the content-anchor repair and the locator broadening; both adjudicated, the first confirmed and the second shown correct but insufficient |
| `Architecture_M3_CP4c3_TB42_Artifact_Only_Test_Benchmark_Plan.md` | 137 | consumed evidence contract — the frozen TB42 gate, discharged by the TB42 EXEC report |

**Folded here:** 4 documents, 732 lines. **Running total: 134 documents, 25,676 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB42_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 398 PASS / 11 RED with accepted 365/365 on package107, and the EC7 measurement rows
that DEFN-R8 must reason from), `Architecture_M3_CP4c3_TB42_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB47_Code_Build_Report.md` (**the build that produced the current package**),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part XI operative, amended by Part XI-A**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Definition-authority note.** Part XI and Part XI-A are unchanged. **Part XII appends next**, and its subject is
not the binding but the **domain of the uncut-component frontier census** and what a `RegionCertification` failure
must publish instead.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB41-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB41_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in EC0–EC7:** the
promotion reasoning, the content-anchor census with its four oriented anchors, the reframe of 390/393/406/407 as a
never-executed oracle, and the three verified facts that rule out the locator/guard/annotation explanations.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB40_Independent_Review_Record.md` | 212 | superseded review authority — EB0-EB7. Diagnosed the orbit-label defect, priced the stable event, and froze the content-anchor repair that TB41 confirmed |
| `Architecture_M3_CP4c3_TB40_EXEC_Report.md` | 42 | superseded runtime evidence — package105, 394 PASS / 15 RED, accepted 361/365; never promoted |
| `Architecture_M3_CP4c3_CB45_Code_Build_Report.md` | 179 | consumed build report — implemented the Part XI binding correctly; its deliberate retention at TB40-REV has served its purpose now that TB41 proved the binding |
| `Architecture_M3_CP4c3_TB41_Artifact_Only_Test_Benchmark_Plan.md` | 160 | consumed evidence contract — the frozen TB41 gate, discharged by the TB41 EXEC report |

**Folded here:** 4 documents, 593 lines. **Running total: 130 documents, 24,944 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB41_EXEC_Report.md` (**the valid semantic runtime
authority**, selector 409 at 398 PASS / 11 RED with accepted 365/365 on package106),
`Architecture_M3_CP4c3_TB41_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB46_Code_Build_Report.md` (**the build that produced the current package**, and the record
that CB46's locator broadening was correct in itself), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md` (**Part XI operative, amended by Part XI-A**),
`Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

**Definition-authority note.** Part XI and Part XI-A are **unchanged and further confirmed**: the content anchor
answers Part XI-A §A.1's complaint that the face certificate carried nothing content-derived by which an
independent consumer could identify a face. `M3-CP4c3-TB40-REV-CAND-01` is **CLOSED** on that basis.

### Consolidated on 2026-09-08 at `M3-CP4c-3-TB40-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB40_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded. **Preserved in EB0–EB7:** the
four-row census and its reading as a permutation, the two enumerations and their exact sites, the blind arc-count
control, the unverifiable orbit label, and 366/367's advance.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_CB45_Code_Build_Plan.md` | 207 | consumed build contract — EA0-EA9 plus the Part XI-A amendments; discharged by the CB45 report and adjudicated at TB40 |
| `Architecture_M3_CP4c3_TB40_Artifact_Only_Test_Benchmark_Plan.md` | — | consumed evidence contract — the frozen TB40 gate, discharged by the TB40 EXEC report |

**Retained as current authority:** `Architecture_M3_CP4c3_TB39_EXEC_Report.md` (**the valid semantic runtime
authority** — TB40 was not promoted), `Architecture_M3_CP4c3_TB40_EXEC_Report.md` (the regressed ledger and the
decisive census, which CB46 must work from), `Architecture_M3_CP4c3_TB40_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB45_Code_Build_Report.md` (**retained deliberately** — it is the provenance for the
regression and records that CB45's binding lookup was correct, so discarding it would leave the impression the
implementation was at fault), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part XI
operative, amended by Part XI-A**), `Required_Green_Selector_Manifest.md`, this record, and every
`Required_Green_Selector_*.txt`.

**Definition-authority note.** Part XI is **unchanged and confirmed**: TB40 proved the binding is a bijection onto
certified disc faces with matching arc counts. Part XI-A's reading is reinforced a third way — the face
certificate's `orbit` is meaningful only inside the producer's own enumeration, so an independent consumer cannot
verify **which** face a certificate holds. `M3-CP4c3-TB40-REV-CAND-01`.

### Consolidated on 2026-09-08 at `M3-CP4c-3-DEFN-R7`

Mandatory REVIEW consolidation for the Definition turn. Part XI now carries the normative replacement contract, so
the TB39 review record and consumed DEFN-R7 plan are historical. Their durable findings were preserved first in
Part XI, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, `CHANGELOG.md` and
the frozen successor plan.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB39_Independent_Review_Record.md` | 203 | superseded review authority — promoted TB39, established upstream actual-embedded-face ownership, ordered DEFN-R7 |
| `Architecture_M3_CP4c3_DEFN_R7_Definition_Plan.md` | 125 | consumed definition contract — R7.1–R7.9 discharged into normative Part XI and frozen CB45 EA0–EA9 |

**Folded here:** 2 documents, **328 lines**. **Running total: 124 documents, 24,191 lines.**

**Retained as current authority:** `Architecture_M3_CP4c3_TB39_EXEC_Report.md` (current semantic runtime),
`Architecture_M3_CP4c3_CB44_Code_Build_Report.md` (current package104 build authority until CB45),
`M3_CP4c_Frozen_Definitions.md` Part XI (current Definition/Review authority), and
`Architecture_M3_CP4c3_CB45_Code_Build_Plan.md` (single exact next-turn plan), together with durable indexes and every
byte-frozen selector.

### Consolidated on 2026-09-09 at `M3-CP4c-3-TB46-R1-REV` — folded-index entry

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_CB51_Code_Build_Report.md` | 123 | consumed package111 Code + Build report |
| `Architecture_M3_CP4c3_CB52_Orchestration_Correction_Plan.md` | 67 | consumed runtime-free orchestration correction plan |
| `Architecture_M3_CP4c3_CB52_Orchestration_Correction_Report.md` | 121 | consumed control-plane preflight/failure-containment report |
| `Architecture_M3_CP4c3_TB45_EXEC_Report.md` | 150 | superseded package110 runtime report — 399/10 historical evidence |
| `Architecture_M3_CP4c3_TB45_Independent_Review_Record.md` | 262 | superseded TB45 review authority |
| `Architecture_M3_CP4c3_TB46_Artifact_Only_Test_Benchmark_Plan.md` | 108 | consumed initial package111 artifact-only contract |
| `Architecture_M3_CP4c3_TB46_EXEC_Report.md` | 121 | orchestration-invalid 0/409 attempt; no semantic ledger |
| `Architecture_M3_CP4c3_TB46_R1_Artifact_Only_Test_Benchmark_Plan.md` | 88 | consumed re-execution contract |

**Total folded this review:** 8 documents, 1,040 lines. **Running total:** 154 documents, 28,869 lines.

**Retrospective, accounting-neutral index:** `Architecture_M3_CP4c3_CB51_Code_Build_Plan.md` — 157 lines,
consumed successor plan already retired between reviews; exact bytes at
`104b631f01cd5a1be0c5369fb5a8a743651f5bce`, deletion visible in
`e91c192fcaecd04eb859430945ca8e8fd04962da`.

**Retained as current authority:** `Architecture_M3_CP4c3_TB46_R1_EXEC_Report.md`,
`Architecture_M3_CP4c3_TB46_R1_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md`,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
`Required_Green_Selector_Manifest.md`, this record, and every byte-frozen selector.

### Consolidated on 2026-09-09 at `M3-CP4c-3-TB47-REV` — folded-index entry

Mandatory REVIEW consolidation. TB47/package112 is promoted as current semantic runtime authority and the prior
TB46-R1 runtime/review pair is historical. Durable facts were preserved first in the TB47 review record,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, `CHANGELOG.md`, `TODO.md` and
the frozen CB54 plan.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB46_R1_EXEC_Report.md` | 186 | superseded runtime authority — package111 403 PASS / 6 RED, accepted 365/365 |
| `Architecture_M3_CP4c3_TB46_R1_Independent_Review_Record.md` | 197 | superseded review authority — package111 promotion, ordinal367 stale-oracle diagnosis, CB53 freeze |

**Folded this review:** 2 documents, **383 lines**. **Running total: 156 documents, 29,252 lines.** Exact bytes remain
recoverable from Git history.

**Retrospective, accounting-neutral index for documents retired between reviews:**

| Retired document | Lines | Recorded role |
|---|---:|---|
| `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Plan.md` | 96 | consumed test-authority successor plan; CB53 implemented it |
| `Architecture_M3_CP4c3_CB53_Independent_Fragment_Count_Oracle_Code_Build_Report.md` | 213 | consumed package112 compile authority; TB47 runtime-proved its correction |
| `Architecture_M3_CP4c3_TB47_Artifact_Only_Test_Benchmark_Plan.md` | 196 | consumed immutable package112/selector409 execution contract; TB47-EXEC discharged it |

**Retained as current authority:** `Architecture_M3_CP4c3_TB47_EXEC_Report.md`,
`Architecture_M3_CP4c3_TB47_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md`, `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every byte-frozen selector.

### Consolidated on 2026-09-09 at `M3-CP4c-3-TB48-REV` — folded-index entry

Mandatory REVIEW consolidation. TB48/package113 is promoted as reviewed semantic runtime authority; ordinal370 is runtime-proved corrected; the AU0–AU9 mechanical-witness exit criterion is MET; CP4c-3 and M3 close. Durable facts are preserved in `Architecture_M3_CP4c3_TB48_Independent_Review_Record.md`, `M3_Closure_Record.md`, `Architecture_M3_CP4c3_TB48_EXEC_Report.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, `CHANGELOG.md`, ROADMAP and the M4 definition plan.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB47_EXEC_Report.md` | 148 | superseded runtime authority — package112 404/5, accepted 365/365 |
| `Architecture_M3_CP4c3_TB47_Independent_Review_Record.md` | 252 | superseded review authority — package112 promotion and CB54 freeze |
| `Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md` | 138 | consumed AK5 product-correction build contract |
| `Architecture_M3_CP4c3_CB54_Code_Build_Report.md` | 103 | consumed package113 compile/build authority; TB48 runtime-proved it |
| `Architecture_M3_CP4c3_TB48_Artifact_Only_Test_Benchmark_Plan.md` | 132 | consumed immutable package113/selector409 execution contract |

**Folded this review:** 5 documents, **773 lines**. **Running total: 161 documents, 30,025 lines.** Exact bytes remain recoverable from Git history.

**Retained as final/current M3 authority:** `Architecture_M3_CP4c3_TB48_EXEC_Report.md`, `Architecture_M3_CP4c3_TB48_Independent_Review_Record.md`, `M3_Closure_Record.md`, `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every byte-frozen selector. M4 successor authority now lives in `Architecture_M4_DEFN_Frozen_Definitions.md`, `Architecture_M4_DEFN_R1_Definition_Record.md`, and `Architecture_M4_CP1_CB3_Code_Build_Plan.md`.


---

### Final M3 closure reconciliation — 2026-09-09

M3/CP4c is CLOSED / ACCEPTED. Package113/TB48 is reviewed semantic runtime authority at 405 PASS / 4 RED over
selector409, accepted prefix 365/365. `M3-CP4c-0-TB-R9` has direct whole-gate closure evidence — run/job
`33079817998 / 98543736213`, 346/346 PASS including Q8 criteria 1/4/5 — correcting the later independent review
amendment's erroneous statement that the turn never ran. Final closure authority is `M3_Closure_Record.md`; current M4
work must not reopen CP4c on that refuted premise.

</details>

<a id="m3-archive-6"></a>
<details>
<summary><strong>Archived source 6: M3_CP4c_Current_And_Forward.md</strong> — Historical CP4c current-state/forward ledger</summary>

# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-09** at `M3-CP4c-3-TB48-REV` independent closure review.

**Reviewed semantic runtime authority is package113 / TB48 / selector409 audit:** **405 PASS / 4 RED / 0 SKIP**, accepted **365/365**, RED `[368,369,374,398]`, ownership **300 / 0 / 0**. Semantic source `6dae3f6959551f6dcdd81f153aedb5f38411a96b`; result/log artifacts `10126711178 / 10126711588`.

Ordinal370 is CLOSED / RUNTIME-PROVED / NON-STABLE. The AU0–AU9 mechanical-witness exit condition is MET. **CP4c-3 and M3 are CLOSED / ACCEPTED.** Stable accounting remains **47 / 14 / 33**, debt **5**, packages **113**.

**M4-DEFN is COMPLETE / AMENDED through `M4-DEFN-R1`; M4-CP1 has reached TB1 review. Exact next: `M4-CP1-CB4`**, runtime-free package closure under `Architecture_M4_CP1_CB4_Code_Build_Plan.md`; current review is `Architecture_M4_CP1_TB1_Independent_Review_Record.md`, solver adjudication remains `Architecture_M4_DEFN_R1_Definition_Record.md`, and normative M4 definitions remain in `Architecture_M4_DEFN_Frozen_Definitions.md`.

## 1. Where the checkpoint stands

**M3-CP4c-3 is CLOSED / ACCEPTED at `M3-CP4c-3-TB48-REV`; M3 is CLOSED / ACCEPTED.** Package113/source `6dae3f6959551f6dcdd81f153aedb5f38411a96b` and TB48 run/job `34409262512 / 102659650326` are promoted reviewed semantic runtime authority: **405 PASS / 4 RED / 0 SKIP** over selector409, accepted required-green **365/365**, RED `[368,369,374,398]`, ownership **300/0/0**.

Ordinal370 is runtime-proved corrected under the frozen `EmptyNetworkOnClosedSurface = 6` plus non-empty `sourceFace` identity. `M3-CP4c2-TB-X2-R8-CAND-02` and `M3-CP4c3-TB48-EXEC-CAND-01` are closed non-stably. Protected 390/393/406/407 remain non-vacuously green through `PlanFrontier`; selector409 executed fully report-only after first RED. The AU0–AU9 mechanical-witness exit criterion is MET.

The remaining REDs 368/369/374/398 remain separate carried owners. Their existence is not the frozen CP4c-3 exit condition and they are not silently accepted. Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**, packages **113**.

The accepted required-green predecessor entering M4 is selector365, SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Selector409 remains final M3 audit authority.

### 1.1 AU0–AU9 mechanical-witness exit criterion — CLOSED

The restored historical AU0–AU9 requirements remain durable below. TB48-REV confirms every one remains MET. Their exact provenance is in the consolidated record and the TB48 independent review record; future M4 work must not reopen them merely because the final audit surface retains separately owned RED rows.

| Measure | Durable requirement | Final disposition |
|---|---|---|
| **AU0** | Preserve selector authority/predecessor lineage; no selector mutation; no unauthorized gate execution. | **MET.** Selector365 remains accepted; selector409 stays byte-frozen final audit evidence. |
| **AU1** | Every transit producer exit reportable; no empty seed/walk mislabeled as sector election. | **MET.** Mechanical continuation advanced with typed/reportable authority. |
| **AU2** | No float-derived datum reaches exact transit topology; exact atlas branch transport authoritative. | **MET.** Exact transit authority remains accepted. |
| **AU3** | Exact Amendment-17 transit/election measurement; equal elected exact directions are a review stop. | **MET.** The falsifier did not recur and the mechanical witness advanced. |
| **AU4** | No election redesign before AU3 evidence. | **MET historically.** |
| **AU5** | Audit float-derived topological decisions and unreportable producer exits. | **MET; resulting exactness/reportability rules remain binding.** |
| **AU6** | Localize prescribed-sphere binding owner without leaking its fix into the bounded mechanical turn. | **MET.** Sphere 368 remains separately owned. |
| **AU7** | Repair only invalid ordinal370 witness/contract so closed empty-network behavior is measurable; never weaken `NonIntegralCycleLift`. | **MET.** Package113 ordinal370 is PASS under the frozen typed error+locus contract. |
| **AU8** | Full report-only pass over every remaining ordinal after first RED, zero gate credit, preserving minimal witness evidence. | **MET.** TB48 executes 409/409 exactly once; accepted gate remains 365/365. |
| **AU9** | Preserve prohibitions: no float topology, hidden exits, election/tolerance shortcuts, barrier/atlas weakening, sphere-fix leakage, amendment reopening, enum renumbering, selector change, or report-only gate credit. | **MET.** TB48/CB54 evidence shows no such movement. |

## 2. TB41 mechanical evidence — accepted repair recovered, protected frontier correction did not

- **Accepted prefix restored on package106:** 365/365 PASS. The four TB40 `RP-05` oracle losses
  311/314/356/357 all PASS after CB46 replaced foreign ordinal comparison with canonical oriented boundary content.
- **The anchor census is non-vacuous:** 356/357 each emit four region rows with unique oriented anchors,
  `upstreamMatchCount=1`, matching region/certificate arc counts, disc=true and field=true. Orbits 0/1 may remain
  transposed because orbit ordinal is not the independent identity.
- **Binding falsifiers remain live:** 312/315/409 PASS.
- **Protected frontier surface remains broken:** 390/393/406/407 all RED at the same frozen
  `regionFrontierComponentCount > 0`, actual 0. CB46's terminal-enum decoupling was insufficient.
- **Missing-fragment measurement is sharper:** 366/367 publish `sourceFace=10,11,79`,
  `regionOwningFragmentOrbit=1` and 74 owner rows. The named face has 3 local fragments, 3 owners, expected 3,
  deficit 0, so the missing owning fragment is relational rather than a simple face-level count shortage.
- **Preserved controls:** 404/408 PASS; ownership 300/0/0; retired
  `RegionEulerCharacteristicNotOne`, `RegionInteriorDisconnected`, `TraceArcDoesNotSeparateItsSides`, and
  `UncutFaceComponentOrbitSeedNotUnique` are absent from all raw logs.
- **Carried:** 368/369/370/374/398 remain under their established separate owners.

TB41-REV adjudicated these facts and promoted TB41 without stable repricing.

## 3. The frontier, proved from source

`build_regions` creates each draft as `RegionDraft{orbit, walk.orbits[orbit]}` (`GlobalTopologyPlan.cpp:986`),
moves that boundary into the region unmodified (`:1450`), and elsewhere *identifies* a region by
`walk.orbits[orbit] == region.boundary` (`:379`). The orbit itself is built by following `successor[current]` until
it returns to `start`, then `canonicalize_cycle`, which only **rotates**
(`EmbeddedGraphTopology.cpp:1746–1774`).

**So a plan region's boundary is an ordered single closed walk by construction, and may revisit nodes** — which
bridges, cut vertices and this fixture's ten terminal slits routinely produce.

- **On a plan region, `ClosedBeforeEnd` is always a false rejection.**
- **On a synthetic boundary — ordinals 312 and 409 — it is the only check that catches a genuine multi-walk.**
- **The defect is that `validate_single_boundary_walk` cannot see provenance.** `ArcChainBroken` and
  `WalkNotClosed` are unaffected and stay in force for all boundaries.

This **reconciles** TB33-REV and TB34-REV: each was right about the input it read, and nothing recorded which
guarantee a boundary carried.

**Still unknown:** `RegionEulerCharacteristicNotOne`, seen at TB34 once the rejection was bypassed, is a
**separate** question — χ over a walk that may revisit nodes — and this review does not decide it.

## 3.1 What TB36 settled — the provenance contract works, in both directions

Ordinals 366/367 **advanced past** `ClosedBeforeEnd`, publishing `regionBoundaryProvenance=FaceWalkOrbit`. CX8's
falsifier was that a stop there would refute DEFN-R5.2/R5.3; it did not stop there, so **the derived provenance
relation is runtime confirmed**.

The complementary negative held too. Ordinals **312 and 409 stayed PASS**, and both build their boundary by taking
`plan.validation_candidate()` — a **copy of a real plan region** — and then mutating it
(`tests/FieldAlignedCurveNetworkTests.cpp:3247–3253`, `:3276–3279`). The mutated boundary matches no authoritative
orbit, resolves to `Unguaranteed`, and is still rejected. **A stored construction-time flag would have survived
that copy and suppressed both rejections** — so this is the runtime disproof of the competing DEFN-R5 draft, exactly
as Part IX-A §A.1 predicted. `M3-CP4c3-TB35-REV-CAND-01` is **CLOSED / RUNTIME PROVED**.

## 3.2 What TB36 did not settle, and why the frozen measurement could not

DEFN-R5.5 froze a census to test the premise at `GlobalTopologyPlan.cpp:2099–2100` — that the boundary terms cancel
from χ. **The census was implemented in the wrong domain.**

- χ counts a **sub-mesh of whole source triangles**: faces are partitioned one-per-region (`:1400–1433`),
  `edgeCount` counts **source edges** (`:1847–1860`), `interiorVertices` holds **source vertices** (`:2048–2094`).
- CX5 counts the **network graph**: `std::set<authority::NetworkArcId>` and `std::set<authority::NetworkNodeId>`
  (`:2122–2123`), and a network arc may be a **trace segment** — a chord through face interiors that is not a
  source edge at all (`:1905`, `:1934`, `:1951`).

So `regionBoundaryDistinctArcCount = regionBoundaryDistinctNodeCount = 22` is a fact about a **different curve**,
and it is not evidence that `V_boundary == E_boundary`. Two further caveats: `regionBoundaryNodeOccurrenceCount` is
assigned the same expression as `regionBoundaryArcOccurrenceCount` (`:2142` vs `:2120`), so eight fields carry at
most six independent values; and 366/367 share one failure-detail digest on `regionBoundaryOrbit=0` — **one datum,
two witnesses**. `LESSONS.md` 150.

## 3.3 The identity that decides the frontier

Two things do follow from the census.

**The boundary's shape is now measured.** 40 arc occurrences over 22 distinct arcs with 22 distinct nodes gives
`V − E = 0`, so the network boundary is connected with exactly one independent cycle: a **4-arc cycle carrying an
18-arc tree** (`18·2 + 4·1 = 40`), matching `regionBoundaryRepeatedNodeOccurrenceCount=18`. That is the bridge and
terminal-slit structure Part IX predicted, now measured.

**And the open question reduces to one integer.** Every source face is a triangle
(`EmbeddedGraphTopology.h:25–32`), so 250 faces give exactly **750 face-edge incidences**. With `B_int` = barrier
edges having **both** incident faces in the region (skipped at `:1848–1850`) and `X` = sub-mesh vertices excluded
from `interiorVertices`:

> **χ_true = X + B_int − 47.**

The published `χ = 100 − 353 + 250 = −3` follows from `X + B_int = 44`, in which case the cancellation premise
holds and **the region is genuinely not a disc**. A disc requires `X + B_int = 48`, in which case **the premise is
false by exactly 4**. **These are mutually exclusive: the certificate cannot both cancel its boundary terms and
certify discs.** Neither term is published, and both sit in loops that already exist.

The first place to look is `B_int`: a barrier edge with both faces inside the region is **interior** to the
sub-mesh, yet `:1848–1850` drops it from `E_int` and `:1919`/`:1925`/`:1947` push its endpoints into
`boundaryVertices`, which `:2048–2051` then excludes from `V_int`. A terminal slit is exactly such an edge, and
this fixture publishes ten. **This review names that suspicion; it does not conclude it.**

## 3.4 TB37 decided it — the region is a disc and the certificate's arithmetic is wrong by 4

TB36-REV reduced the frontier to one integer. CB42 published the terms; TB37 measured them.

```text
X (excluded vertices)          = 36  =  0 mesh-boundary + 20 boundaryVertices + 16 allOwned
B_int (interior barrier edges) = 12
sub-mesh boundary              = 20 edges / 20 vertices
V_total / E_total / F / chiFull = 136 / 385 / 250 / 1
reduced certificate             = 100 / 353 / 250 / −3
```

**`D = X + B_int = 48`**, so `χ_true = 48 − 47 = 1` — and the direct count agrees, `136 − 385 + 250 = 1`. Every
cross-check closes, **including two TB36-REV predicted before the numbers existed**: `E_one = 44 − 2·B_int = 20`
matches `regionSubmeshBoundaryEdgeCount`, and `2(E_int + B_int) + E_one = 750 = 3F`.

**The region is a genuine triangulated disc, and the certificate rejects it.**

### The diagnosis is sharper than "the premise is false"

> `(V_total − V_int) − (E_total − E_int) = 36 − 32 = (20 − 20) + (16 − 12) = 0 + 4`

**The cancellation premise is correct about the actual boundary** — the sub-mesh boundary proper cancels, 20
against 20, exactly as `GlobalTopologyPlan.cpp:2097–2098` claims. The whole error is the residual: the certificate
additionally drops **12 interior barrier edges** from `E_int` (`:1848–1850`) and **16 further vertices** from
`V_int` via `allOwned`, and those exclusions do not balance.

**A barrier edge with both incident faces in the region is an interior cell**, not a boundary one — a terminal
slit is precisely that, and this fixture publishes ten. The defect is that the certificate's notion of "boundary"
is the **network's barrier set** rather than the sub-mesh's actual boundary. `LESSONS.md` 153.

This closes `M3-CP4c3-TB34-REV-CAND-03`, open since TB34, and decides `M3-CP4c3-TB36-REV-CAND-01`.

### What it does not settle

Both formulas count the **whole-face** sub-mesh (`:2168–2177`), while the region the plan built is bounded by a
network walk that includes **trace chords through face interiors**; a trace-cut face is assigned wholly to one
region (`:1405`, `:1432`). So `chiFull = 1` certifies the **rounding**, not the traced region. The correction is
still bounded — `V_int`, `E_int` and `F` are already whole-face quantities, so it fixes arithmetic over the object
already counted — but that must be stated normatively. New candidate `M3-CP4c3-TB37-REV-CAND-01` (ACTIVE /
ARCHITECTURAL, non-blocking).

## 3.5 What DEFN-R6 froze — Part X

Part X supersedes **Part IX §5 only**; every other Part IX clause and all of Part IX-A stand.

- **R6.1 — the cancellation premise is NOT the defect.** The sub-mesh boundary cancels exactly, 20 edges against
  20 vertices. **Part IX-A §A.2's implication that the premise itself fails is withdrawn**, along with the DEFN-R5
  draft claim that a pinch stops the boundary terms cancelling. A correction aimed at the premise would have been
  aimed at the wrong thing — worth recording, because two turns nearly were.
- **R6.2 — interior barrier edges are interior cells.** A mandatory or cut edge with **both** incident faces in
  the region is an interior cell of the certified complex. Dropping 12 of them from `E_int` (`:1848–1850`) against
  16 vertices from `V_int` via `allOwned` (`:2048–2094`) is the whole 4-point error. A terminal slit is exactly
  such an edge; this fixture has ten.
- **R6.3 — the certified complex is the whole-face source sub-mesh** of `region.sourceFaces` (faces partitioned,
  `:1405`/`:1432`). **`χ = 1` is a claim about that rounding**, not about the traced region, whose boundary
  includes trace chords through face interiors. Non-blocking, stated so it cannot be silently assumed.
- **R6.4 — the criterion is `χ = V_total − E_total + F = 1`**; the reduced form is withdrawn. For a connected
  compact surface with boundary `χ = 2 − 2g − b`, so `χ = 1` with `sourceFacesConnected` and
  `boundaryWalkCount == 1` is a disc. `proves_disc_topology()` keeps its shape.
- **R6.5 — the withdrawn premise has TWO sites.** `GlobalTopologyPlan.cpp:2097–2098` **and**
  `include/directional/geometry/GlobalTopologyPlan.h:91–93`, whose `vertexCount` comment repeats it verbatim.
  TB37-REV named only the first; the header site was found by this turn. Deleting one re-seeds the assumption —
  which is how it survived from TB34 to TB37. `LESSONS.md` 154.
- **R6.6 — do not repurpose `vertexCount`/`edgeCount`.** `edgeCount` is incremented in the loop that builds
  `neighbors` for the connectivity BFS behind `RegionInteriorDisconnected` (`:1847–1860`, BFS `:1862–1873`, check
  `:1874`). The sub-mesh totals are **new fields**, so the published triple explains the published χ.
- **R6.7 — the equivalence carries a proof obligation.** Reduced and full agree iff **`X = E_one + B_int`**; the
  measured region violates it by 4 (`36` vs `20 + 12`). **CB43 may not assume it anywhere.**

## 3.6 TB38 refuted DEFN-R6.4, and the fault is the definition's

CB43 implemented Part X **exactly as frozen** — hoisted the sub-mesh accumulation, added the total fields, computed
χ from them, deleted **both** premise comments, did not repurpose `vertexCount`/`edgeCount`, did not touch region
construction, extended the semantic digest. **`DEFN-R6.4` is what cost the accepted prefix.**

### The measurement

```text
torus region (356/357/362/367, detail d976514d…):
    X = 24   E_one = 24   B_int = 1
    V_total/E_total/F = 24/48/24   → chiFull    = 0
    V_int  /E_int  /F =  0/23/24   → chiReduced = 1
mechanical region (TB37, ordinals 366/367):
    X = 36   E_one = 20   B_int = 12  → chiReduced = −3, chiFull = 1
```

Cross-checks close on the torus: `E_both = 48 − 24 = 24`, `E_int = 24 − 1 = 23`,
`2·E_both + E_one = 72 = 3F`.

| Fixture | `X − E_one − B_int` | χ_reduced | χ_full |
|---|---:|---:|---:|
| mechanical | **+4** | −3 | **1** |
| torus | **−1** | **1** | 0 |

> **Opposite signs. Neither formula is correct on both fixtures**, and DEFN-R6 had exactly one fixture's numbers.
> `LESSONS.md` 156.

### Why the reduced form wins on the torus

That region is 24 triangles, 24 vertices, 48 edges, 24 boundary edges and **zero interior vertices** — a
one-triangle-wide closed band, χ = 0, an **annulus**. It has exactly **one** interior barrier edge, and the reduced
form drops it. Removing one edge raises χ by 1, opening the annulus into a disc. **That is topologically what the
trace along that edge does** — so where the reduced form drops interior barrier edges it is modelling the cut
correctly, and where it additionally drops 16 vertices against 12 edges via `allOwned` on the mechanical fixture it
over-removes.

### The real defect is older than Part X

`certificate.faceCount = fragments.size()` is one entry per `region.sourceFaces` element, so **F counts whole faces
even where a trace splits one**. Meanwhile `V_int`'s `allOwned` exclusion only has meaning if that face is
**split**, and `E_int`'s barrier exclusion is the cut.

> **The certificate has always mixed the whole-face rounding with a partial model of the traced region.**

Part X resolved that mixture toward whole faces; TB38 refutes it. **The third complex — the traced/split region,
using the `fragmentCorners` ownership map DEFN-R4 established — has never been computed.** `DEFN-R6.4` is
**withdrawn**; **at TB38-REV, `DEFN-R6.3` became the live question**, exactly as Part X §9's own falsifier said it would be. TB39-REV now resolves that question toward the upstream actual-embedded face authority.

### The safeguard discharged over an empty set

DEFN-R6.7 required a per-region equivalence proof on every accepted fixture and explicitly refused the hand-wave
excuse. It produced **zero rows**: `emit_region_euler_certificate_diagnostics` is correctly placed before the χ
test but guarded by `if (diagnostics != nullptr)`, non-null only under `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1`
(`GlobalTopologyPlan.cpp:86–89`, `:2460–2462`), which the accepted identities never set. The verifier reported
`accepted_euler_arithmetic_ok=true` over the empty table. **Part X named the check, its four identities and the
inadmissible excuse — and never said how many rows must exist.** `LESSONS.md` 155. It also blocks naming which
region drives ordinal 366's `RegionInteriorDisconnected`.

### Ordinal 366 is the predicted advance, not a regression

The mechanical region passed χ under the full count and certification reached a stage never previously executed.
Part X's falsifier called this "a new frontier, not a regression of this one". Ordinals 390/393/406/407 fail the
frozen `regionFrontierComponentCount > 0` assertion (`FieldAlignedCurveNetworkTests.cpp:4364`, actual 0) purely
because the plan now stops where no frontier annotation is attached — a **DEFN-R4 pattern recurrence**.

## 3.7 DEFN-R7 freezes the actual-embedded face binding

TB39 remains current semantic runtime authority: package104, selector409 **402 PASS / 7 RED**, accepted **365/365**,
RED `[366,367,368,369,370,374,398]`. DEFN-R7 is static and changes no runtime accounting: **46 / 14 / 32**, debt
**5**, packages **104**.

Part XI now supersedes DEFN-R6.3/R6.4 as the region-disc contract. Exact source inspection establishes the binding
constructively: `SurfaceCutGraph::certify_actual_embedded_graph()` and `GlobalTopologyPlan::canonical_candidate()`
both call `build_embedded_graph_topology(...)` on the same source/network/cut edges; A2a′ publishes one face
certificate per non-exterior orbit; A2b drafts one region per non-exterior orbit; `region_orbit()` re-derives the
current region's orbit by exact ordered boundary equality. The downstream region certificate therefore consumes the
matching upstream face certificate rather than re-proving topology over `region.sourceFaces`.

The current `sourceFacesConnected`, reduced/full V/E/F and Euler fields are removed from disc-topology authority.
`RegionEulerCharacteristicNotOne` and `RegionInteriorDisconnected` are retired as A2b disc-theorem producers; pinch
checking cannot override A2a′. Field regularity remains a separate A2b proof. Support arithmetic can survive only as
domain-explicit diagnostics. `regionChiFull` is frozen to mean whole-source-face Euler if retained; assigning the
reduced value is forbidden.

The checked candidate seam remains load-bearing: copied candidates must re-derive boundary→orbit→upstream-face
binding. This preserves 312/409. Ordinal315 moves its tamper target from proxy Euler to the consumed face binding;
311/314 and produced-witness proof helpers assert the exact 1:1 producer/consumer relation. Selector409 stays
byte-frozen.

**TB40-EXEC then exercised immutable package105.** That mechanically valid runtime was semantically RED: accepted 311/314/356/357 and protected 390/393/406/407 regressed; its independent TB40-REV subsequently established that 356/357 exposed a foreign-label oracle defect rather than a production binding defect. See §3.9.

## 3.8 Part XI-A — what the bound certificate actually proves

A verification pass over the delegated TB39-REV/DEFN-R7 work **upheld Part XI** and verified its structural claims
from source: both stages call `build_embedded_graph_topology(...)` with identical arguments
(`GlobalTopologyPlan.cpp:2500–2502`, `SurfaceCutGraph.cpp:863`), share `exterior_boundary_orbits(...)`
(`:869`, `:866`), and publish one face certificate per non-exterior orbit (`:883`) against one region draft per
non-exterior orbit (`:986`). **The 1:1 correspondence is real.**

**But the certificate carries no per-face evidence.**

- **A.1** — `discTopologyEstablished` is the **same value on every non-exterior face**: `discEmbeddingEstablished`,
  computed once at `SurfaceCutGraph.cpp:879` as
  `graphComponents == sourceComponentCount && exterior.size() == *boundaryLoops && graphEuler == sourceEuler`, and
  stamped identically at `:883`. **The binding stays sound** — that is the standard cellularity criterion, which
  *is* the theorem that every non-exterior face is a disc — but the authority is **complex-level**, and a face
  certificate is that authority restricted to one orbit, not an independent observation about it.
- **A.2** — `boundaryWalkCount` is the **literal `1U`**, so Part XI §2 item 6's `boundaryWalkCount == 1` conjunct
  **cannot fail** and is **withdrawn as evidence**. It is correct-by-construction (Part IX DEFN-R5.1), which is
  precisely why it carries no information. **The `LESSONS.md` 155 failure mode, inside the contract written to
  prevent it.**
- **A.3** — CB45 must publish the complex-level inputs **once per complex** rather than one bit per region; ordinal
  315's tamper target must **vary** (`orbit` or `boundaryArcCount`); and **a census whose every row carries the
  same value for the field under test is not a measurement.** `LESSONS.md` 157.

Part XI's decisions, consumer inventory, tamper contract and CB45 boundary are otherwise unchanged.

## 3.9 TB40 confirmed the binding and refuted the oracles

**The binding works.** TB40's census, on accepted ordinals 356/357, publishes 4 regions against 4 face
certificates:

```text
region 0: derivedOrbit=0  certificateOrbit=1  upstreamMatchCount=1
region 1: derivedOrbit=1  certificateOrbit=0  upstreamMatchCount=1
region 2: derivedOrbit=2  certificateOrbit=2  upstreamMatchCount=1
region 3: derivedOrbit=3  certificateOrbit=3  upstreamMatchCount=1
```

Everything DEFN-R7.1 asserts **holds**: `upstreamMatchCount == 1` on every row, the map injective, boundary-arc
counts matching, `discTopologyEstablished=true` and `fieldRegularity=true` throughout, and the complex row
published once per Part XI-A §A.3 — a **non-empty, non-uniform** census, so R7.7 is discharged.

**Only the orbit label disagrees.** `derivedOrbit` and `certificateOrbit` index **two different enumerations of
one partition**: production numbers orbits by **dart index** (`EmbeddedGraphTopology.cpp:1742`), inherited by both
A2a′ and A2b from the shared builder; the test oracle numbers them by **sorted-incidence order** —
`std::set<Incidence> all` (`tests/FieldAlignedCurveNetworkTests.cpp:1871`) iterated at `:1880`. Orbits 0 and 1
transpose.

**CB45's lookup is correct** (`faceCertificate.orbit == owningOrbit`, exactly one match, arc count, disc). The
defect is entirely in four re-aimed assertions — 311 at `:3254`, 314 via
`IndependentDiscProofClause::PublishedCertificate`, 356/357 in the census. **`ORIENTATION.md` §8 already carries
the rule: never match two partitions by index.** And the arc-count check did not catch it, because regions 0 and 1
have equal arc counts — **a control insensitive to the case under test is not a control.** `LESSONS.md` 158.

**The label cannot be checked independently.** `SurfaceCutGraphFaceCertificate` publishes only `orbit`,
`boundaryWalkCount`, `boundaryArcCount`, `discTopologyEstablished` (`SurfaceCutGraph.h:53–63`). An independent
consumer can verify the **bijection**; it cannot verify **which face** a certificate holds. Third way the bound
certificate carries less evidence than its name suggests. `M3-CP4c3-TB40-REV-CAND-01`.

**366/367 advanced** off both retired proxies to `RegionSourceFaceOwningFragmentMissing` at `RegionCertification` —
Part XI §10 prediction 4 confirmed, and **a new frontier, not a regression** (`M3-CP4c3-TB40-REV-CAND-02`).
**390/393/406/407 regress on `regionFrontierComponentCount == 0` for the second consecutive turn** — the DEFN-R4
pattern, now permanent because the codes that carried the annotation are retired by design.

**312, 409 and 315 PASS.** No sticky construction-time binding, and 315 tampers `actualEmbeddedFace.orbit`, a field
that **varies** — Part XI-A §A.3's tamper amendment was honoured.

## 3.10 TB41 — the anchor repair worked, and the frontier oracle never had a subject

**EB7.1 discharged.** Ordinals 311/314/356/357 PASS. CB46 replaced the orbit-ordinal comparison with a **content
anchor** — `canonical_cycle_anchor`, the canonical oriented arc of the boundary cycle — carried on the certificate
and independently re-derived by the oracle:

```text
region 0: independent=(arc 0, Reverse)  certificate=(arc 0, Reverse)  orbit=1  upstream=1  arcs=26/26  disc=true
region 1: independent=(arc 0, Forward)  certificate=(arc 0, Forward)  orbit=0  upstream=1  arcs=50/50  disc=true
region 2: independent=(arc 12, Reverse) certificate=(arc 12, Reverse) orbit=2  upstream=1  arcs=50/50  disc=true
region 3: independent=(arc 24, Reverse) certificate=(arc 24, Reverse) orbit=3  upstream=1  arcs=26/26  disc=true
```

Three things worth stating: **the transposition is still there** (region 0 ↔ orbit 1) **and is now correctly a
non-event**, confirming the TB40 diagnosis; the anchor is **non-uniform and orientation-sensitive** — `arc 0`
appears in both orientations — so **EB7.4 is discharged**; and arc counts now differ across rows (26/50/50/26), so
that control is no longer blind as it was at TB40. **EB7.3 preserved**: 312/315/409 PASS, binding untouched.

**EB7.2 failed, and the reframe matters more than the failure.** 390/393/406/407 all guard
`expect_later_region_frontier_evidence` (`tests:4411`) behind an `UncutComponent` early return (`:11910`,
`:12122`, `:14943`, `:14987`). For the whole checkpoint the stage *was* `UncutComponent`, so **the oracle never
executed** — those identities were green **by not asserting**. The pipeline advancing to `RegionCertification` ran
it for the first time, and it found `regionFrontierComponentCount = 0`.

> **That is an assertion reaching its subject for the first time, not a behaviour loss.** There is no previous
> behaviour of this oracle to restore. `LESSONS.md` 160.

**CB46's correction was right and could not have worked.** It properly changed `region_frontier_components`
(`GlobalTopologyPlan.cpp:667–706`) from `if / else if` to three independent `if`s. But all three locators resolve
through one object, `frontier.partition.componentByFace`. Verified from source: the guard
`component < ownerConsistency.components.size()` is **benign** (`CertifiedSourceFaceOwnerConsistency.h:38–44`
fills one row per partition component); `RegionBuildSuccess{std::move(regions), frontier, …}` (`:1505`) carries the
**real** frontier; and the annotation **is** applied on the certification path (`:2418–2420`).

**Two live candidates, neither statically decidable:** the partition may be **empty** — built over `unlabeledFaces`
(`:1341–1353`), with `:1338` calling it "only a consistency guard" now that ownership is total at 300/300 — or the
failing object may be **outside its domain**, since `RegionSourceFaceOwningFragmentMissing` fires only on a
**labelled, trace-cut** face (`:2020–2028`) which `unlabeledFaces` excludes by construction.

> **CB46 corrected which locator is consulted without establishing that the censused set is non-empty** — the
> third consecutive turn with that shape, after DEFN-R6.7's empty table and Part XI's uniform-bit census.
> `LESSONS.md` 159.

**366/367** remain at `RegionSourceFaceOwningFragmentMissing`, now publishing `regionOwningFragmentOrbit` —
measured as EB7.6 required, not corrected.

## 3.11 TB42 measured it: the census is disjoint from the failing object

CB47 was diagnostics-only and **proved it by artifact** — TB42's ledger SHA-256 is identical to TB41's
(`5b1e663e…`) while the failure-detail digest changed (`f2b3cb59…` vs `82b7a0e8…`). The oracle was not re-hidden
and 390/393/406/407 stayed RED, exactly as EC7.4 required.

The EC7 row, published identically on all four protected identities:

```text
unlabeledFaceCount                       = 226
frontierPartitionComponentCount          =   9
ownerConsistencyRowCount                 =   9
regionFrontierLocator                    = none
regionFrontierLocatorSurvivedGuard       = none
failure source face in partition         = false
failing-region source faces              =  10
failing-region source faces in partition =   0
```

This settles TB41-REV's EC3 completely:

- **"The partition is empty" is REFUTED** — 226 unlabelled faces across 9 components.
- **"The failing object is outside the domain" is CONFIRMED, and is stronger than stated.** Not just the face:
  **the entire failing region is absent**, all 10 of its source faces being labelled.
- **The guard analysis is confirmed** — `ownerConsistencyRowCount == frontierPartitionComponentCount == 9`, the
  one-row-per-component relation predicted from `CertifiedSourceFaceOwnerConsistency.h:38–44`. The guard is benign
  and was never reached.
- **No locator resolved**: `uncutFaceComponent` unset; `sourceFace` misses because the face is labelled; the region
  sweep misses because all 10 faces are labelled; the single-component fallback cannot fire at 9 components.

> **The census subject exists and is disjoint from the failing object — a domain mismatch, not an empty set, not a
> locator bug, not a guard bug.**

**The identities' names disclose the domain they were written for.** 390
`UncutFaceComponentBoundaryOrbitAttribution…`, 406 `UncutComponentCensusNamesThePartitionItDescribes…`, 407
`InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions`, 393
`MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual`. The uncut-component partition covers
**unlabelled faces by construction** (`GlobalTopologyPlan.cpp:1341–1353`). **The `UncutComponent` early return was
the domain guard, expressed as a stage check** — the pipeline advancing to `RegionCertification` removed the
**precondition**, not the guard. `LESSONS.md` 161.

Ordinal 407's name spans **both partitions**, placing these four inside the long-open two-partitions-of-one-mesh
problem (§7). The successor should decide them together or say why they are separable.

## 3.12 DEFN-R8 decided it — Part XII makes census applicability a domain relation

`M3-CP4c-3-DEFN-R8` is complete as a **static definition turn**. Part XII is now normative and discharges
ED7.1–ED7.7 without runtime, compile, selector mutation or stable repricing.

The decisions are:

- the uncut-component census describes exactly the `P_U` partition of faces whose `fragmentOrbits` are
  absent/empty, with the existing `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` barriers;
- a failure subject is classified against that domain as `Inside | Outside | Partial | Unresolved`; stage names are
  chronology only and may never stand in for domain membership;
- a later `RegionCertification` failure owns **region/fragment evidence**, not `P_U`; for
  `RegionSourceFaceOwningFragmentMissing` the missing evidence is the complete deterministic owner-orbit set for
  the failing source face plus exact membership of `regionOwningFragmentOrbit`;
- ordinals 390/393/406/407 remain census-owned and must exercise their producer-side oracle even when the terminal
  region is `Outside`; each must also reject a deliberately corrupted copy of same-domain census data;
- `M3-CP4c3-TB26-REV-CAND-04` is adjudicated: the plan and certifier partitions are lawfully distinct; the defect
  was cross-domain substitution, not their difference;
- `M3-CP4c3-DEFN-R3-CAND-01` is separable and remains architectural/non-gating. CB48 must not unify either embedded
  graph builder or partition.

The frozen unchanged surface is accepted **365/365**, ordinals **311/312/314/315/356/357/404/408/409**, selector
409 bytes, Part XI/Part XI-A, `region_orbit`, the content anchor, `P_U`, region construction, ownership,
`fragmentCorners`, `fragmentOrbits`, cut selection and A2a′ cellularity semantics. 366/367 remain owned by the
missing-fragment relation; Part XII adds observation only.

### TB43 review adjudication — Part XII recovered; 366/367 owner is predicate drift

TB43 consumed immutable package108 unchanged and measured selector409 at **402 PASS / 7 RED / 0 SKIP**, accepted
**365/365**, RED `[366,367,368,369,370,374,398]`. Independent TB43-REV promotes it as current semantic authority.

390/393/406/407 are now **semantically recovered**: their deterministic receipts prove the producer-owned `P_U`
predicate executed, `terminalSubjectRelation=Outside`, the same-domain corruption was rejected, and the
RegionCertification evidence branch ran. `M3-CP4c3-TB40-EXEC-CAND-02` is CLOSED / RUNTIME-PROVED / NON-STABLE.

366/367 remain RED at `RegionSourceFaceOwningFragmentMissing`: expected orbit 1 is absent from complete present set
`[2,3]` despite local fragment/owner/expected counts 3/3/3. Source re-derivation resolves the owner. The
`FragmentCornerIncidence` projection unconditionally skips every final segment with no `terminalBarrier`, but
`build_regions()` skips that class only when its certified forward/reverse face-walk sides are the same orbit. A
separating terminal event can therefore create region ownership without the corresponding corner-owner row. This
is **ownership-projection predicate drift**, not a missing region, count deficit, `P_U` defect or new topology
definition.

Existing Part VIII R4.1/R4.2 and Part XI/Part XI-A decided the correction. **CB49 is now COMPLETE / COMPILE-GREEN /
RUNTIME-FREE.** `build_fragment_corner_incidence()` skips a terminal no-barrier segment only when the already-derived
certified sides have `forwardOrbit == reverseOrbit`; distinct-orbit terminal sides are retained. The three known
separation-rule sites now agree and no new derivation was introduced.

CB49 package109 artifact `10081938891` compiles exact source
`cf969597bda5c49e734b98db0c0165b421c4ee12` with GMP/GMPXX, 28/28 package checksums and
`runtimeExecution=false`.

### TB44 execution intake — mechanically valid raw evidence, review pending

TB44 run/job `34295565963 / 102291328376` consumed package109 unchanged and measured selector409 at
**398 PASS / 11 RED / 0 SKIP**, accepted **365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`.
Result/log artifacts are `10083047547 / 10083047938`; selector identity is unchanged; all package/source/execution-view
censuses match pre/post; timeout count is 0 under the restored 180-second per-identity control.

The direct CB49 old-locus falsifier is mechanically satisfied: 366/367 no longer publish
`RegionSourceFaceOwningFragmentMissing` and instead reach `RotationSystemInconsistent / FragmentCornerSourceCornerMismatch`
at source face `10,11,79`. Protected 390/393/406/407 are now RED, but each still proves the Part XII `UncutCensus`
predicate executed, terminal subject `Outside`, same-domain corruption rejection, and RegionCertification evidence branch.
Their common immediate assertion surface is false `region_fragment_owner_relation_is_valid(locus)` plus missing
`regionFrontierFailureRegionSourceFaceCount`.

This is raw EXEC intake only. TB43/package108 remains promoted semantic runtime authority; stable accounting remains
47 / 14 / 33, debt 5, packages 109. **Exact next is independent `M3-CP4c-3-TB44-REV`**. No new runtime or compile is
authorized before review adjudication.

### TB44 review adjudication — promoted; whole-face ray bucket and terminal-evidence helper root-caused

Independent TB44-REV promotes package109/selector409 at **398 PASS / 11 RED**, accepted **365/365**. The exact CB49 old owner-missing locus is gone, so CB49 stands.

366/367 now fail because `build_fragment_corner_incidence()` stores exact `sourceCorner` per `RayCut` but groups all carrierless rays under one `raysByFace[sourceFace]`, sorts the whole bucket, and rejects any ray whose source corner differs from the first. The failing face is a valid 3-fragment / 3-owner, two-chord, non-crossing local arrangement. Existing Part VIII authority therefore requires per-`(sourceFace, sourceCorner)` fan validation and set-wise publication, not a whole-face single-corner chain.

390/393/406/407 still prove Part XII's producer-owned census predicates and same-domain corruption rejection. Their RED is the region-only helper: `build_fragment_corner_incidence()` fails before `build_region_certificates()` enters `for (const auto &region : regions)`, so no current region exists. R8.1 names the source face as the failure subject; R8.3 requires region/fragment evidence only when a current region exists. CB50 fixes this test-authority applicability without weakening the producer oracle.

Stable accounting remains 47 / 14 / 33, debt 5, packages 109. Five carried RED owners remain unchanged.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB47-EXEC-CAND-01` | **CLOSED / RUNTIME-PROVED TEST-AUTHORITY CORRECTION RECOVERY / NON-STABLE** — package112 ordinal367 PASSes under the normative high-side-only rule; +0 stable event / +0 recurrence. |
| `M3-CP4c3-TB40-EXEC-CAND-01` | **RUNTIME RECOVERED IN TB41 / STABLE RP-05 EVENT RETAINED** — 311/314/356/357 PASS under unique content-derived anchors; historical event remains counted. |
| `M3-CP4c3-TB40-EXEC-CAND-02` | **CLOSED / RUNTIME-PROVED / NON-STABLE** — TB43 proves 390/393/406/407 execute the producer-owned `P_U` predicate, classify the terminal subject `Outside`, and reject same-domain corruption. |
| `M3-CP4c3-TB40-REV-CAND-02` | **CLOSED THROUGH TB45 / NON-STABLE** — CB49 fixed separation, CB50 fixed per-source-corner grouping, and TB45 ordinal366 PASSes with the old mismatch absent. |
| `M3-CP4c3-TB44-EXEC-CAND-01` | **CLOSED / PRODUCT CORRECTION RUNTIME-ADVANCED / NON-STABLE** — the CB50 source-corner mismatch is gone; TB45's later ordinal367 oracle surface is owned separately. |
| `M3-CP4c3-TB44-EXEC-CAND-02` | **CLOSED / TEST-AUTHORITY CORRECTION ADVANCED / NON-STABLE** — typed source-face/current-region handling compiled in CB50; TB45 then exposed the distinct success-path observability precondition. |
| `M3-CP4c3-TB45-EXEC-CAND-01` | **CLOSED / CB51 CORRECTION RUNTIME-ADVANCED / NON-STABLE** — TB46-R1 moves ordinal367 beyond `FragmentPartition` to the distinct `FragmentCountRule` surface. |
| `M3-CP4c3-TB45-EXEC-CAND-02` | **CLOSED / RUNTIME-PROVED SUCCESS-PATH OBSERVABILITY / NON-STABLE** — TB46-R1 390/393/406/407 PASS through `PlanFrontier`, execute real Part XII predicates, and reject same-domain corruption. |
| `M3-CP4c3-TB41-REV-CAND-01` | **CLOSED / RUNTIME-PROVED / NON-STABLE** — TB43 publishes the complete owner-orbit set and expected-orbit membership required by Part XII; it served its diagnostic purpose. |
| `M3-CP4c3-TB38-EXEC-CAND-01` | **RESOLVED AT CURRENT RUNTIME / STABLE EVENT RETAINED** — CB44/TB39 recover the lost greens; the TB38 `RP-01` event remains in 46 / 14 / 32. |
| `M3-CP4c3-TB38-EXEC-CAND-02` | **CLOSED / RUNTIME-PROVED / NON-STABLE** — TB39 emits 513 non-empty rows and all five equations hold. Arithmetic proof is now non-vacuous; it does not select a semantic proxy. |
| `M3-CP4c3-TB31-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the guard is retired and the authorized merge causes no downstream failure; `TraceArcDoesNotSeparateItsSides` appears in none of the 408 raw logs. |
| `M3-CP4c3-TB31-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — 390/393/406/407 PASS with selector 408 byte-unchanged and nothing they legitimately own relaxed. |
| `M3-CP4c3-TB31-REV-CAND-03` | **CLOSED / IMPLEMENTED** — frontier evidence publishes at both annotation sites. Its **over-reach** is carried forward as `M3-CP4c3-TB32-REV-CAND-01` rather than left inside a closed candidate. |
| `M3-CP4c3-TB32-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — 366/367 publish `regionFrontierFailureStage=RegionCertification` and their detail bytes contain **no legacy `uncutFaceComponent*` fields**. |
| `M3-CP4c3-TB33-REV-CAND-01` | **RECONCILED** — recorded refuted at TB34-REV, which was right about the synthetic region and wrong as a general statement. Superseded by `M3-CP4c3-TB35-REV-CAND-01`. |
| `M3-CP4c3-TB34-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the rejection is restored; ordinal 312 PASS and the accepted prefix is 365/365. |
| `M3-CP4c3-TB34-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 409 re-aimed at the constructible shared-start shape and PASSes its oracle. |
| `M3-CP4c3-TB34-REV-CAND-03` | **CLOSED** — open since TB34, now diagnosed to the cell: the region is a disc (`chiFull=1`) and the certificate drops 12 interior barrier edges against 16 vertices, netting −4. |
| `M3-CP4c3-TB35-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — TB36 advanced 366/367 past `ClosedBeforeEnd` on `FaceWalkOrbit` while 312/409, which mutate a **copy** of a real region, stayed PASS on `Unguaranteed`. Part IX's derived relation is confirmed in both directions. |
| `M3-CP4c3-TB36-REV-CAND-01` | **REOPENED** — "the region is a disc" holds for the mechanical region under the **whole-face** reading only, and TB38 refutes that reading as a general criterion. Subsumed by `TB37-REV-CAND-01`. |
| `M3-CP4c3-TB37-REV-CAND-01` | **IMPLEMENTED IN CB45 / TB40 RAW FALSIFIER OBSERVED / REVIEW PENDING / RP-01** — 356/357 observe derived orbits 0/1 consuming certificate orbits 1/0; review owns classification/correction. |
| `M3-CP4c3-TB34-EXEC-CAND-01` | **NEW / HARD-FALSIFIER INTAKE / NON-STABLE** — accepted-prefix ordinal 312 regresses to RED: expected `RegionBoundaryNotSingleWalk`, observed `RotationSystemInconsistent`, no arc locus. Review owns product/test classification. |
| `M3-CP4c3-TB34-EXEC-CAND-02` | **NEW / HARD-FALSIFIER INTAKE / NON-STABLE** — new gating ordinal 409 is RED before its intended `ArcChainBroken` oracle because `disjointRegions` construction fails. Review owns fixture/product discrimination; EXEC may not weaken the gate. |
| `M3-CP4c3-TB32-REV-CAND-02` | **CLOSED / RUNTIME PROVED and vindicated on the same run** — the failure-detail digest table now separates runs; TB33's ledger hash collided with TB30's. |
| `M3-CP4c3-TB32-REV-CAND-03` | **CLOSED / RUNTIME PROVED** — the harness is turn-agnostic and `baseline-authority.txt` records the executing run. |
| `M3-CP4c3-TB30-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING** — the plan-side interior-arc census is a projection of the certifier's rows, so an arc that still cuts the plan's component but has left the certifier's uncut census is invisible to it. Not blocking CQ7. |
| `M3-CP4c3-TB27-REV-CAND-01` | **CORRECTED / RUNTIME-PROVED** — CB34's separating-arc barrier rule excludes the crossed faces and preserves equal-orbit slits; ordinal 408 passes on all three properties. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. |
| `M3-CP4c3-TB26-REV-CAND-04` | **ADJUDICATED BY DEFN-R8 / DISTINCT DOMAINS LAWFUL** — plan `P_U` and certifier domains may differ; cross-domain substitution is prohibited; no unification in CB48. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED FOR THE FAILING OBJECT** — the certifier component contains two separating arcs, but it is not the 191-face failing plan component. **TB28-R2 supplied no admissible evidence about it.** CL8 is nonetheless discharged: the correction is frozen and does not depend on this being decided first. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **SEPARABLE / ACTIVE ARCHITECTURAL / NON-GATING** — duplicated actual-embedded topology construction remains debt; CB48 did not unify builders or partitions. |
| `M3-CP4c3-TB24-REV-CAND-02` | **ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — earlier vacuous diagnostic surfaces remain historical architectural debt; ordinal393's current contract itself is runtime-proved. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **CLOSED / RUNTIME-PROVED PRODUCT CORRECTION / NON-STABLE** — package113 ordinal370 PASSes the frozen typed error+locus identity; TB48-REV closes the candidate without stable repricing. |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |


---

## 5. Settled facts a successor must not reopen

- **An A2b plan region and its matching A2a′ certified face are the same topology object under the exact orbit
  binding frozen by DEFN-R7.** A2a′ and A2b rebuild the same deterministic actual embedded graph from the same
  source/network/cut edges; the region boundary equals one non-exterior face-walk orbit and consumes that orbit's
  `SurfaceCutGraphFaceCertificate`. `region.sourceFaces` is support/provenance and may not re-certify the face.
  `RegionBoundaryNotSingleWalk` remains a synthetic/current-candidate binding validator; region-support Euler is not
  the disc theorem.
- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are REFUTED, and the question is closed as ill-formed.** Do not re-pose it. The successor question is whether component 0 lies in a single certified face — asked about the object, not about a rule.
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- **Certified source-face ownership is TOTAL: 300 established / 0 unavailable / 0 conflicting**, and the plan's
  component 0 has a **unique** seed `[0]` over 189 faces. **The seed frontier opened at TB19 is CLOSED.** Do not
  re-open it.
- **A bridge arc's two darts legitimately share an orbit.** `FragmentCornerIncidence` is an **ownership map**, so a
  bridge chord's single merged entry is correct; the guard rejecting it was an internal inconsistency, since the
  same function's ray path already accepts equal orbits.
- **Call order comes from callers, not line numbers.** The retired guard is downstream of the seed guard.
- **Neither `UncutFaceComponentOrbitSeedNotUnique` nor `TraceArcDoesNotSeparateItsSides` occurs anywhere in the
  current run.** Both stages are cleared; do not cite either as a live surface.
- **The ledger digest is a pass/fail fingerprint, not a semantic one.** It has now collided twice — TB32 with
  TB31, TB33 with TB30. Use the failure-detail digest table, artifact digests and censuses to distinguish runs.
- **A boundary walk may pass through its own start node.** Ten terminal slits guarantee it here; the certificate
  independently establishes all six faces as discs with residual 0.
- **Ownership is total and unique across all nine plan components.** Do not re-open it.
- **A witness pinned to a terminal failure code reds on every forward step.** 404 and 408 survived two corrections
  because they assert publication and completeness instead.
- **Ordinal 398 is not an ownership gate.** It fails on the prescribed sphere. **366 and 367 are the frontier.**
- **The 191-face component genuinely spans certified faces 0, 1 and 3.** Arcs 14 `(0/1)` and 22 `(0/3)` cross it.
  The seeds `[0,1,3]` at 81/1/1 are the true geometry, and **the seed guard was right to fail**. Do not re-pose
  this as an attribution defect.
- **TB22's minority edges `10-79` and `29-35` are edges of those two arcs' terminal-slit faces.** The thread from
  TB20 is closed.
- **A witness that asserts a defect is still present will pass vacuously and then block the fix.** Ordinal 404
  proved this at a cost of one turn.
- **Never match two partitions by component index.** Ordinal 390 proved this at a cost of one turn.
- **A green gate that contradicts an unchanged product is invalid evidence.** TB28-R2's `407 PASS / 0 RED` is
  rejected and may never be quoted as a gate result. TB28-R3 settled it by reproducing the baseline exactly on the
  same artifact.
- **A control run beats a clever measurement.** Change one variable, compare against a known baseline, and do not
  recompile — a new package is a second changed variable.
- **The product correction is FROZEN** — the separating-arc barrier rule. It is not to be re-derived, re-opened,
  widened or narrowed by any successor review.
- **Two of four certifier interior arcs SEPARATE** — arc 14 `(0,1)`, arc 22 `(0,3)`; arcs 20 and 24 are `(0,0)`.
  An arc separates iff its dart orbits differ. Do not re-derive this from the terminal-slit flag: a per-segment
  property does not classify an arc.
- **`matchesFailingComponent=false` is runtime-proved.** Never quote a certifier-census number as evidence about
  the 191-face failing plan component.
- **The plan's domain is contained in the certifier's**, with the same barrier families; the 23-face difference is
  the faces carrying a direct certified read, which the plan excludes and then cannot find as seeds.
- **A diagnostic gated on the success of the thing it diagnoses can never fire on the case it was built for.**
  D3 proved this at a cost of one full turn.
- **Relocating a derivation adds no information.** CB27 moved ownership into the certifier — the right authority —
  and got `[0,1,3]` at `(0,1,2)`, the same answer as before.
- **384/385 recovered at TB25-R1; 389/390 recovered at TB26-R1 after their contracts were narrowed to identity-owned evidence.** No accepted behaviour was lost.
- **An incidence count is not a separation.** `interiorArcs=4` says four arcs touch the component; it says nothing
  about whether any of them separates certified faces. Only the per-arc dart-orbit pair does.
- **There are two partitions, not one.** The plan's is over faces with no fragment orbits; the certifier's is over
  faces not crossed by a trace. Never quote a number from one as evidence about the other.
- **A census over established values is vacuous where nothing is established.** CH8's `rowCount=0` proved this at a cost of one turn.
- **Only arcs separate certified faces.** An uncut component whose interior no arc meets lies in exactly one certified face. This is a proof, not a measurement.
- **TB27 runtime refutes the claim that all four certifier interior arcs are bridges:** arcs 14 and 22 have
  different forward/reverse orbits; arcs 20 and 24 have equal orbits. This fact is scoped to the certifier
  `NotTraceCut` partition.
- **The failure and census partitions are runtime-proved different:** ordinal406 publishes
  `matchesFailingComponent=false`. Never transfer certifier component counts/arcs to the failing plan component.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

M3/CP4c is closed and no longer the live planning family. `M4-DEFN` is complete/amended through `M4-DEFN-R1`. Resume at **`M4-CP1-CB3`** under
`Architecture_M4_CP1_CB3_Code_Build_Plan.md`, entering from accepted selector365 and the reviewed M4 definitions. Do not
reopen CP4c, use selector409 as the M4 accepted predecessor, or revive the refuted claim that CP4c-0 TB-R9 never ran.

</details>

<a id="m3-archive-7"></a>
<details>
<summary><strong>Archived source 7: Architecture_M3_CP4c3_TB48_Independent_Review_Record.md</strong> — Final independent milestone closure review</summary>

# M3-CP4c-3-TB48 Independent Review Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / PACKAGE113 PROMOTED / ORDINAL370 CLOSED / CP4c-3 CLOSED / M3 CLOSED / M4-DEFN FROZEN
**Turn:** `M3-CP4c-3-TB48-REV`
**Boundary:** independent REVIEW + PLAN; evidence/static only; no Directional runtime or compile
**Date:** 2026-09-09
**Runtime evidence reviewed:** TB48 run/job `34409262512 / 102659650326`
**Immutable evidence source:** `6dae3f6959551f6dcdd81f153aedb5f38411a96b`, package113 artifact `10125000895`, selector409

## 1. Decision

**Decision: `approved_with_amendments`.**

TB48 is mechanically valid and package113/TB48 is promoted as the current reviewed semantic runtime authority:

- **405 PASS / 4 RED / 0 SKIP** over selector409;
- accepted required-green prefix **365/365 PASS**;
- RED `[368,369,374,398]`;
- all 409 identities selected and executed exactly once in ordinal order, one fresh process per identity;
- zero selection mismatches and zero timeouts;
- package/source/execution-view pre/post censuses are equal;
- all configure/compile/relink/discovery/repair/mutation/benchmark flags are false;
- ownership remains **300 established / 0 unavailable / 0 conflicting**.

The amendments are documentary/routing corrections, not reinterpretation of raw evidence: distinguish the frozen
**M3 accepted required-green boundary (365)** from CP4c-3's broader 409-identity audit surface, apply the already
restored AU0-AU9 mechanical-witness exit criterion, and correct the stale M4 entering baseline from 322 to 365.

## 2. Primary-evidence verification

Independent review re-opened the retained TB48 result/log artifacts and verified their provider/download hashes:

- result `10126711178`, SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`;
- log `10126711588`, SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`.

`semantic-summary.txt` records 409 total, 405 PASS, 4 RED, accepted 365/365 and exactly `[368,369,374,398]` RED.
`execution-boundary.txt` records runtime started/completed, preflight/execution-view verification true,
`orchestration_failure=false`, `selection_integrity=true`, timeout 0 and every prohibited build/repair/mutation flag
false. `immutability.txt` records all three pre/post censuses equal. Artifact authority is package113 with the exact
frozen SHA-256 `e5fb50f92bbf4c4ffae5afeb203d6738490f6410b3a7e49245607e1b2e7835e9`; selector409 is 409 rows with LF SHA-256
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

No evidence gap prevents adjudication.

## 3. Ordinal370 — targeted product correction is runtime-proved and closes

Ordinal370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` selected exactly once and PASSed.
The frozen identity independently establishes a closed torus, an atlas-valid empty rail/network construction, then
requires `SurfaceCutGraph::make` to fail with existing `EmptyNetworkOnClosedSurface = 6` and a non-empty
`sourceFace` locus.

Static package113 source matches that contract exactly in `SurfaceCutGraph::canonical_candidate()`: after
source/atlas/network binding validation and before mandatory-edge/trace classification, a truly empty network
(`nodes`, `mandatory_edges`, `candidate_traces`) queries exact source boundary-loop authority; malformed topology
remains `NonManifoldSource`; a closed non-empty source returns code 6 with deterministic first-source-face locus.
No selector/test/fixture/enum/certifier/proposal change is involved.

Therefore:

- `M3-CP4c3-TB48-EXEC-CAND-01` is **CLOSED / RUNTIME-PROVED PRODUCT-CORRECTION RECOVERY / NON-STABLE**;
- `M3-CP4c2-TB-X2-R8-CAND-02` is **CLOSED / RUNTIME-PROVED PRODUCT CORRECTION / NON-STABLE**;
- stable accounting changes by **+0 events / +0 recurrences** because the candidate was never accepted authority and
  its closure is a status change, consistent with the tracker convention.

## 4. Four remaining REDs remain separate carried owners

The raw red list is not the CP4c-3 exit condition. Each remaining red reproduces a previously classified surface:

1. **368** — prescribed sphere, `M3-CP4c2-TB-X2-CAND-04`: `RotationSystemInconsistent -> TraceEventPositionInvalid`,
   trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. The sphere semantic fix remains separately governed.
2. **369** — `M3-CP4c2-TB-X2-R10-CAND-01`: ordinary trace-crossed proposal still requires saturation. This is the
   separately owned proposal-quality/coverage surface.
3. **374** — `M3-CP4c3-TB7-CAND-02`: folded-cone identity still fails its atlas precondition because the hand-authored
   flat-star field is invalid on the non-flat star. Its future correction is test-fixture authority, not M3 closure.
4. **398** — prescribed-sphere owner-map identity remains downstream of 368 because the cut graph is absent.

No new failure surface appears, no owner is merged, and none of these four may be repaired by weakening M3's
accepted authority. They remain open under their existing future owners.

## 5. Protected controls remain non-vacuous

Ordinals 390/393/406/407 all PASS through the successful `PlanFrontier` evidence branch. Their runtime receipts say
`branch=UncutCensus`, `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`,
`terminalSubjectBranch=PlanFrontier`, and `planFrontierEvidenceBranchExecuted=yes`; supporting BW3/owner-map/
partition/interior-arc evidence is non-empty. Ordinal385 publishes **300/0/0** ownership. Accepted/protected 307,
367, 404, 408 and 409 also PASS.

This rules out a vacuous recovery and confirms CB54 did not bypass Part XII or accepted-prefix authority.

## 6. CP4c-3 exit criterion and formal closure

The retained ROADMAP explicitly states: **“CP4c-3 closes on the mechanical witness under AU0–AU9, unchanged.”**
`M3_CP4c_Current_And_Forward.md` restores AU0–AU9 in durable form and adjudicates each measure MET. TB48 preserves
that state and adds the last required evidence-hygiene step after CB54:

- accepted 365/365 remains green;
- mechanical ordinals 366/367 are green;
- protected 390/393/406/407 remain non-vacuously green;
- all 409 rows execute report-only after first RED with zero gate credit;
- exactness/reportability and all AU9 prohibitions remain intact;
- CB54's sole targeted product change, ordinal370, is now runtime-proved without collateral movement.

**Formal `M3-CP4c-3` state is therefore CLOSED / ACCEPTED.** The four carried REDs do not falsify its exit condition;
continuing to chase them inside CP4c-3 would violate the checkpoint's own frozen ownership and `LESSONS.md` 167.

## 7. M3 milestone closure

CP4c-3 was the final remaining M3 checkpoint. With it closed, the `DESIGN.md` §14 M3 acceptance surface is complete:

- typed singularity-port ownership and branch-consistent/non-crossing tracing were established by the earlier M3
  checkpoints and retained accepted prefix;
- typed network termination is accepted through CP4c-0b;
- actual embedded-graph region/disc proof authority is accepted through CP4ab/CP4c-2;
- mandatory topology/tamper and permutation controls remain green;
- CP4c-3 supplies the closed mechanical witness and its exact/reportable continuation evidence under AU0–AU9.

**M3 is CLOSED / ACCEPTED.** The durable M3 closure record is `M3_Closure_Record.md`.

The accepted required-green selector entering M4 remains **365**. Selector409 is the final CP4c-3 execution/audit
surface and remains retained byte-for-byte; its four carried reds are not silently promoted or deleted.

## 8. Promotion and accounting

Package113/TB48 supersedes TB47/package112 as reviewed semantic runtime authority. Stable totals remain **47 events /
14 categories / 33 recurrences**; produced-witness debt remains **5**; ownership remains **300/0/0**; accepted
package count is **113**. Closing non-stable ordinal370 changes status, not historical counts.

## 9. Mandatory REVIEW consolidation

Durable facts from the superseded documents below are preserved first in this review, `M3_Closure_Record.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, `CHANGELOG.md`, ROADMAP and
the M4 definition plan. Their exact bytes remain recoverable from Git history.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB47_EXEC_Report.md` | 148 | superseded runtime authority — package112 404/5, accepted 365/365 |
| `Architecture_M3_CP4c3_TB47_Independent_Review_Record.md` | 252 | superseded review authority — package112 promotion and CB54 freeze |
| `Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md` | 138 | consumed AK5 product-correction build contract |
| `Architecture_M3_CP4c3_CB54_Code_Build_Report.md` | 103 | consumed package113 compile/build authority; runtime-proved by TB48 |
| `Architecture_M3_CP4c3_TB48_Artifact_Only_Test_Benchmark_Plan.md` | 132 | consumed immutable package113/selector409 execution contract |

**Folded this review: 5 documents / 773 lines. Running total: 161 documents / 30,025 lines.** No intervening
per-turn document had already been retired outside the prior folded index.

Retained current family authority after consolidation is exactly `Architecture_M3_CP4c3_TB48_EXEC_Report.md`, this
review record, `M3_Closure_Record.md`, `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
`M3_CP4c_Consolidated_Record.md`, `Required_Green_Selector_Manifest.md`, every byte-frozen selector, and the single
successor plan `Architecture_M4_DEFN_Definition_Plan.md`.

## 10. Exact successor

**Exact next: `M4-DEFN` — definition/review-plan, runtime-free.**

`Architecture_M4_DEFN_Definition_Plan.md` freezes its scope. M4-DEFN must reconcile the currently proposed
conditioning/scale checkpoints with the global-conformity CP1–CP4 decomposition, freeze the schedule product and
its rejection vocabulary/oracle/witness provenance, carry the three `G4-B002` produced-witness debts, and issue the
first M4 Code + Build plan. It may not run Directional runtime or compile and may not reopen accepted M3 authority.

## 11. Integrity confirmation

- Production code changed: **no**.
- Test or benchmark logic changed: **no**.
- Build configuration changed: **no**.
- Selector bytes changed: **no**.
- Directional tests or benchmarks executed in review: **no**.
- Compile/build executed in review: **no**.
- Review decision is based on retained primary TB48 evidence plus static package113/source inspection.

---

## 12. Verification-pass addenda (static, appended after adjudication)

A verification pass re-derived §§1–11 from source and from the retained record. **The M3 closure is upheld.** One
reconciliation is required before the record is self-consistent.

### 12.1 — confirmed, including the TB47-REV obligation

- **AU0–AU9 were restored in durable form and adjudicated per criterion**, not asserted in bulk:
  `M3_CP4c_Current_And_Forward.md` §1.1 carries all ten with an individual MET disposition and its basis. This is a
  full discharge of the TB47-REV requirement that the exit condition be answered *by criterion* rather than
  deferred, and the restoration requirement in the same obligation.
- **Ordinal 370 is runtime-proved** against the frozen `EmptyNetworkOnClosedSurface = 6` **plus** the non-empty
  `sourceFace` locus, so the TB47-REV **zero-producers → exactly one** criterion is satisfied in the strong form:
  the code now has a producer *and* an identity that reaches it.
- **The four remaining REDs are genuinely separately owned** and the closure record says so explicitly rather than
  absorbing them.
- **`ROADMAP.md` was updated in this turn** — status line and M3 row are current. The TB47-REV note about adding it
  to the consolidation's standing-doc set was acted on.

### 12.2 — the record still contains one open checkpoint inside the closed milestone

§7 states *"CP4c-3 was the final remaining M3 checkpoint."* The retained roadmap does not agree:

> `ROADMAP.md:70` — **`M3-CP4c-0`** … **Contract complete.** … **Closes on a green `M3-CP4c-0-TB-R9`** against Q8
> criteria **1, 4, 5**.

`M3-CP4c-0-TB-R9` was **never executed** — the last references to it in `CHANGELOG.md` are all forward-looking
*"Exact next"* lines. `M3_Closure_Record.md` §2 lists CP4c-0 in the trajectory but **never states the basis on which
it closed**, and `M3_CP4c_Current_And_Forward.md` does not mention it at all.

**So the record as it stands shows a closed milestone containing a checkpoint that awaits a gate turn nobody
intends to run.** That is not a small inconsistency at the moment a milestone is declared complete.

**The reconciliation is available and almost certainly correct, but it must be written, not inferred.** CP4c-0's
gate was **346**. The roadmap states its own rule: *"Gate arithmetic is cumulative — every checkpoint carries the
full accepted predecessor selector plus its own frozen identities."* Therefore

> **346 ⊂ 353 (CP4c-0b) ⊂ 355 (CP4c-1) ⊂ 365 (CP4c-2, accepted).**

Every CP4c-0 identity lies inside the accepted prefix that has been green continuously since CP4c-2, so `TB-R9` —
which would have executed gate 346 — was **superseded by three later gates closing green on strict supersets of
it**. Acceptance is carried by cumulative inclusion, not by the turn that was never run.

**Required, and bounded:** record that basis in `M3_Closure_Record.md` and retire the stale `TB-R9` instruction, so
no future reader finds an open checkpoint under a closed milestone. **If the inclusion argument does not hold — if
any CP4c-0 identity is absent from 365, or Q8 criteria 1/4/5 assert something no later gate re-executes — then M3
closure is premature and must be reopened.** That check is cheap and belongs to `M4-DEFN` before it consumes the
365 baseline.

This review **does not** reopen M3: the argument is sound on the roadmap's own stated arithmetic, and every other
closure condition verifies. It requires the basis be recorded and confirmed. `LESSONS.md` 168.

### 12.3 — accounting and promotion confirmed

Accepted held at **365/365** with **405 PASS / 4 RED**; ordinal 370's closure is non-stable and changes status, not
counts. Totals remain **47 / 14 / 33**, debt **5**, packages **113**. Promotion of TB48 / package113 follows the
operative rule. **The accepted required-green selector entering M4 is 365**, and selector409 is retained byte-frozen
as the final CP4c-3 audit surface with its four carried reds neither promoted nor deleted.


---

## 13. M4-DEFN correction to verification-pass §12.2

**Correction date:** 2026-09-09
**Authority:** primary GitHub Actions run inventory plus retained `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`
and `M3_CP4c_Consolidated_Record.md`.

Verification-pass §12.2's statement that `M3-CP4c-0-TB-R9` “was never executed” is **factually incorrect**. The gate
was executed as workflow **`33079817998`**, `M3 CP4c0 TB-R9 Whole-Gate Reproof`, and completed successfully. Retained
evidence records workload job `98543736213`, selector346 SHA-256
`20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, and **346/346 PASS**, including Q8 criteria
1, 4 and 5. CP4c-0 therefore has direct whole-gate acceptance evidence.

The later 353/355/365 strict-prefix inclusion remains true and is useful corroboration, but it is not a substitute or
supersession basis for an unrun gate because the premise that the gate was unrun is false. The conditional instruction
in §12.2 to re-check inclusion before M4 consumes selector365 is retired. **M3 remains CLOSED / ACCEPTED; this
correction changes no runtime result, selector, package, stable count or milestone decision.**

Durable corrected closure basis: `M3_Closure_Record.md` §2.1 and `M3_CP4c_Consolidated_Record.md`.

</details>

---

## 9. Preserved M3 normative definitions, implementation plan, and execution evidence

**Source relocation; no normative retirement.** Original frozen-definition documents remain **binding**, including their internal amendment precedence and conflict-resolution rules. The plan and final execution report remain historical implementation provenance and primary runtime evidence, respectively. Existing M3 closure/acceptance verdicts are unchanged. The four source files below are reproduced verbatim; the original Git blob SHAs and permanent URLs preserve old-path provenance. Former document paths mentioned within the reproduced text resolve to these sections. All byte-frozen selector files remain separate and unchanged.

| # | Source document | Authority | Original blob SHA | Original Git source |
|---:|---|---|---|---|
| 1 | [`Architecture_M3_CP4_DEFN_Frozen_Definitions.md`](#m3-preserved-1) | BINDING FROZEN DEFINITIONS | `b80e0b33b5c1e229d3dd632089ec7157ac371b45` | [Original](https://github.com/akashskypatel/Directional/blob/198a4b620c8d710b8528868ba9164a8a75b43077/.agents/Directional/Architecture_M3_CP4_DEFN_Frozen_Definitions.md) |
| 2 | [`M3_CP4c_Frozen_Definitions.md`](#m3-preserved-2) | BINDING FROZEN DEFINITIONS | `3a5b3109b74bb42567cef0de52d0483ff8782e89` | [Original](https://github.com/akashskypatel/Directional/blob/198a4b620c8d710b8528868ba9164a8a75b43077/.agents/Directional/M3_CP4c_Frozen_Definitions.md) |
| 3 | [`Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`](#m3-preserved-3) | HISTORICAL IMPLEMENTATION PLAN | `64b3f6638ad057eb6688e2c0de7ad4a684881607` | [Original](https://github.com/akashskypatel/Directional/blob/198a4b620c8d710b8528868ba9164a8a75b43077/.agents/Directional/Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md) |
| 4 | [`Architecture_M3_CP4c3_TB48_EXEC_Report.md`](#m3-preserved-4) | PRIMARY EXECUTION EVIDENCE | `1042626e50c04ae7198309454939a6012f359d4a` | [Original](https://github.com/akashskypatel/Directional/blob/198a4b620c8d710b8528868ba9164a8a75b43077/.agents/Directional/Architecture_M3_CP4c3_TB48_EXEC_Report.md) |

<a id="m3-preserved-1"></a>
<details>
<summary><strong>Architecture_M3_CP4_DEFN_Frozen_Definitions.md</strong> — BINDING FROZEN DEFINITIONS</summary>

# Architecture M3 CP4-DEFN — Frozen Definitions for A2b Topology-Plan Derivation

Date: 2026-08-21 UTC
Turn type: **Planning / Review only.** No product, test, build, package, or runtime. Consumes no
acceptance attempt.
Status: **FROZEN, WITH TWELVE AMENDMENTS.** Sections 2–9 remain normative for `M3-CP4ab` and `M3-CP4c`
and may change only by an explicit plan update.

> **Retired-provenance note (added 2026-08-24 at CP4ab closure review).** Each amendment below names the
> independent review that authored it. Those per-turn review documents were **retired into
> `M3_CP4ab_Closure_Record.md`** when CP4ab closed; the files no longer exist. This was verified safe:
> every amendment inlines the content it froze, so **this document is self-contained and remains the
> implementation authority for `M3-CP4c`.** The citations are provenance only — do not go looking for
> the files, and do not treat a missing file as missing authority. Historical narrative for the retired
> documents is in `CHANGELOG.md`; the accepted outcome is in `M3_CP4ab_Closure_Record.md`.

**Amended 2026-08-22 by `M3-CP4b-MANDATORY-INDEPENDENT-REVIEW` (Part A of
`Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md` — RETIRED at CP4ab closure, binding):**

1. **The CP4a/CP4b split made by this document is withdrawn.** They are one checkpoint, `M3-CP4ab`,
   at the unchanged gate **316**. Region derivation and the disc proof are not independent semantic
   domains — the proof is a predicate on the regions — and splitting them put an accepted predecessor
   between the two halves, which obliged CP4b to preserve a partition that was wrong. Section 7.1 and
   7.2 remain correct as *identity definitions*; only their allocation to separate checkpoints is
   withdrawn. Section 7.3 (CP4c) is unchanged.
2. **Section 7.1 identities A1 and A3 as implemented were unfalsifiable and must be rewritten**
   under corrective measure K4. `CoversEverySourceFaceExactlyOnce` asserted only that ownership is
   total, which a flood fill guarantees by construction; it never asserted that a face's owner is the
   region whose boundary encloses it. Any rewrite that the superseded CP4a implementation would still
   pass is still vacuous.
3. **Section 6.3's rejection vocabulary is binding, not advisory.** The original thirteen
   locus-bearing codes remain frozen. CP4b emitted `RegionCoversNoSourceFace` at seven sites for
   seven distinct conditions and three immutable gates consequently localized nothing. Corrective
   measure K1 therefore extends that vocabulary by four condition-specific codes where no existing
   code can truthfully carry the required locus, and reuses an existing code only where its frozen
   meaning and locus match. The split lands alone, before any semantic change.

**Amended again 2026-08-22 by `M3-CP4ab-K5-ROUTING-REVIEW` (Part A of
`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

4. **Section 4.4 is amended.** A region is one face of the embedded graph and owns the set of **face
   fragments** it covers, where a fragment is the portion of one source face lying in one graph face,
   keyed `(SourceFaceTopologyKey, orbit)`. The prior wording — "plus the set of source faces it
   covers" — is **withdrawn as inconsistent with the product**: mandatory arcs run along source edges
   but **trace arcs cross face interiors**, and a source face is atomic, so whole-face ownership cannot
   express a graph face. On the accepted two-ring witness the entire singular fan collapses into one
   cut component while the rotation walk correctly reports one orbit per sector, which is why
   `cutComponents.size() == drafts.size()` is not merely self-referential but **unsatisfiable** on any
   witness carrying a singularity port. Under fragment ownership every source face's fragments
   partition it, which is a *stronger* exact-once rule than the withdrawn one. Ownership is derived only
   from the embedded network cut and oriented boundary evidence. The following inputs remain prohibited:
   **no container/map order; no BFS/distance/proximity; no arbitrary unclaimed-face fallback; no A0
   `SourceComponentId`/`TopologyRegionId`; no unsigned whole-trace support; no repair path.**

**Amended again 2026-08-23 by `M3-CP4ab-TB-R1-INDEPENDENT-REVIEW` (Part A of
`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

5. **"Computes on fragments" is made exact.** Amendment 4 said the disc proof "now computes on
   fragments" without defining fragment adjacency or the meaning of `V`, `E`, `F` for a fragment
   complex. That under-specification is why `build_region_certificate(...)` was left computing on whole
   source faces and whole source edges, and why `M3-CP4ab-TB-R1` returned nine reds at
   `RegionInteriorDisconnected`. Review section 5 supplies the missing definitions and is normative:
   - **barrier vs crossing** — a mandatory `Boundary`/`HardFeature` edge is a true barrier; a trace
     crossing is a *subdivision point* that removes no interval and blocks no adjacency by itself.
     `network_cut_edges(...)` conflates the two and must no longer gate adjacency;
   - **fragment adjacency** — `(F1, o1)` and `(F2, o2)` sharing source edge `e` are adjacent **iff `e`
     is not mandatory and `o1 == o2`**. Fully combinatorial; no geometry, no interval ordering;
   - **Euler characteristic** — **WITHDRAWN, see amendment 6.** This clause froze `χ = F − E_int`,
     which is mathematically wrong for any region containing an interior source vertex;
   - **pinch rejection** — fragments sharing a 0-cell but no 1-cell are a typed rejection with its own
     frozen code and both source-face loci.

**Amended again 2026-08-23 by `M3-CP4ab-TB-R2-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

6. **Amendment 5's Euler clause is WITHDRAWN and replaced.** `χ = F − E_int` is valid only when the
   fragment-dual graph is acyclic — it silently assumes the very property it was meant to test. The
   faces around an interior source vertex of valence `n` form an `n`-cycle in that dual graph, giving
   `F − E_int = 0` for a patch that is unambiguously a disc. Computed on the accepted CP3a two-ring
   witness this turn: `F − E_int = −5` where the true `χ = 1`. `M3-CP4ab-TB-R2`'s nine-identity
   `RegionEulerCharacteristicNotOne` baseline is therefore a **false rejection**; the regions are
   genuine discs.

   **The correct reduction is `χ = V_int − E_int + F`**, where `V_int` counts source vertices strictly
   interior to the region, `E_int` counts source-edge pieces strictly interior to it (one per adjacent
   fragment pair under amendment 5's adjacency rule), and `F` counts fragments. The boundary terms
   cancel because `V_bd = E_bd` for a single closed walk with no pinch — both preconditions are already
   validated upstream, and that dependency is what licenses dropping them. Verified this turn on two
   glued triangles (1), a pentagon fan (1), a hexagon fan (1), and the whole two-ring witness (1).

   A source vertex is **interior** iff it is incident to a fragment of the region, is not an endpoint of
   any **mandatory** arc on the region's boundary, and is not the `sourceVertex` of a singularity port
   whose trace arc lies on that boundary. `FieldAlignedCurveNetworkNode::sourceVertex` must **not** be
   used for this — section 3.2 records that for a contact node it is an arbitrary face vertex.

   Amendment 5's other three clauses — barrier vs crossing, fragment adjacency, and pinch rejection —
   are **unaffected and proven correct** by TB-R2, which cleared `RegionInteriorDisconnected`.

**Amended again 2026-08-23 by `M3-CP4ab-CB-R6-STATIC-AUTHORITY-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

7. **Fragment-corner incidence is defined, and needs no carrier-contact order.** Amendment 6 requires
   `V_int`, which requires knowing which fragment of a cut face carries each source corner. That is now
   frozen, and it is derivable from existing accepted authority — **no earlier product is reopened**:

   - **Taxonomy.** A source face carries at most **one full chord**: `field_aligned_first_trace_contact`
     (`SurfaceCellTracing.cpp:496-527`) terminates any later trace entering an occupied face. The sole
     exemption is two first-segments sharing a face, singularity, and source vertex, which is how a face
     comes to hold several rays from one origin.
   - **Terminal segments are slits, not cuts.** The trim at `:608-613` retains the contacting segment,
     so its non-optional `outgoingCarrier` names an edge the trace never reaches. A segment of a trace
     whose `terminalBarrier` is unset ends inside its face; **its `outgoingCarrier` must never be treated
     as a chord exit.** A slit does not separate and does not change corner incidence.
   - **One chord.** The chord separates the corner **shared by `incomingCarrier` and `outgoingCarrier`**
     from the other two. Total and unambiguous in a triangle.
   - **Co-facial rays at a shared origin — orbit-side chaining.** Walk the oriented fan around the vertex
     via `build_vertex_fan_slots(...)` carrying a running orbit label. A non-mandatory fan edge does not
     end the sector; a mandatory arc does; and inside a face holding *k* rays the next ray is **the
     unique one carrying the running label on a side**, crossing it advancing the label to its other
     side. The rays' intra-wedge order is never read — it is forced by orbit-label chaining. Uses only
     `walk.orbitByDart` and the oriented fan; no ID, no container position, no coordinate, no distance.
   - **Residual ambiguity is a typed rejection.** If two or more candidate rays carry the running label,
     the reconstruction is genuinely ambiguous: emit a frozen condition-specific code with the
     `SourceVertexId`, `SourceFaceTopologyKey`, and competing `NetworkArcId` loci. **Never break the
     tie.** Ordering by `TraceId`, `NetworkNodeId`, arc ID, segment index, container order, source row,
     or Euclidean position is prohibited — all are the arbitrary carrier order section 2.1 forbids.

   If that rejection ever fires, the ordered-contact relation must be owned by **A2a (the CP3b event
   graph)** — never by A2b, which would create a second writer for contact authority — under the exact
   re-proof boundary in the Review's section 8.

**Amended again 2026-08-23 by `M3-CP4ab-CB-R7-PRECONDITION-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding and superseding amendment 7's order source):**

8. **Amendment 7's `orbitByDart` order source is WITHDRAWN as circular; its chord/slit facts remain.**
   `walk.orbitByDart` is computed *after* `build_rotation_system(...)`, and the current rotation breaks a
   co-facial-ray tie with `trace`/`arc`/`orientation` identifiers. It therefore cannot independently
   prove or reconstruct the ray order that created those orbits.

   - **Single writer:** A1 `FieldTransportAtlas` owns the missing singularity-ray order because
     `build_singularity_attachments(...)` already owns the `TriMesh`, deterministic ordered fan,
     canonical branch directions, branch-class partition, elected representatives, and published
     `FieldSingularityPortAttachment::localSlot`.
   - **`localSlot` semantic:** for one singularity, slots `0..valence-1` are the strict
     **fan-anchored counter-clockwise order of elected port representatives**. Equivalent-Z4 relabeling
     must preserve the published slot assignment. A non-strict/ambiguous order is an A1
     `AmbiguousBranchTopology` rejection, never an ID/container/source-row tie-break.
   - **Transport:** A2a `FieldAlignedSingularityPort::ordinal` carries that A1 slot unchanged; A2a is not
     a second writer and does not invent a contact ordinal.
   - **A2b rotation:** co-facial singularity trace rays consume the transported ordinal as semantic
     secondary order *before* face walking. Only after this is true may `walk.orbitByDart` be consumed
     for fragment-corner assignment.
   - **Corner facts retained from amendment 7:** a real one-chord segment separates the corner shared by
     its distinct incoming/outgoing carriers; a last segment with unset `terminalBarrier` is a slit and
     its retained `outgoingCarrier` is not a chord exit.
   - **No A2b ambiguity code is frozen by amendment 7.** Its Q2/Q4 combination was internally
     inconsistent because Q2 prohibited public-header changes while Q4 required a new public code and
     plural arc loci. Ordering failure belongs to the A1 writer instead.

   This reopens the **semantics** of the existing A1 port slot and therefore requires re-proof of the
   accepted CP2b/CP3a/CP3b surface on the successor package. No identity is removed or weakened.

**Amended again 2026-08-23 by `M3-CP4ab-DG-R3-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

9. **Amendment 6's interior-vertex rule is CORRECTED: it omitted the mesh boundary.** DG-R3 measured
   `V_int=2 E_int=6 F=6 chi=2` for region 2/orbit 3 and `V_int=1 E_int=1 F=2 chi=2` for B3 — both off by
   exactly **+1** in `V_int`. The over-counted vertex on the two-ring witness is **outer-ring vertex 6, a
   mesh-boundary vertex** (`make_cp3a_two_ring_skew_disc` asserts `isBoundaryVertex != 0` for `6..10`).
   `E_int` and `F` are correct: a fragment-dual graph with `F = 6`, `E_int = 6` has cycle rank 1, so
   exactly one interior vertex is possible.

   **The rule text and its own verification table disagreed.** The TB-R2 Review computed `V_int` as *all
   source vertices minus mesh-boundary vertices* in every verified case, then froze the rule in terms of
   arcs on the region's walk. Those coincide only when every mesh-boundary edge touching a region appears
   as a mandatory arc on that region's own walk.

   **Corrected rule.** A source vertex is interior to a region iff **all** of:
   - **(a) it is not a mesh-boundary vertex** — no incident source edge has `incidentFaces.size() == 1`.
     **This clause is new and is the fix.** Derive it combinatorially from `SourceTopologyIndex`: no
     `TriMesh`, no `isBoundaryVertex`, no geometry, no public widening;
   - (b) it is not the `sourceVertex` of a singularity port whose trace arc lies on the region's boundary;
   - (c) it is not an endpoint of a mandatory arc on the region's boundary — still required, because it
     catches interior hard-feature rails that (a) does not;
   - (d) every fragment incident to it belongs to this region.

   A **mesh-boundary vertex's fan is a half-disc**, so the existing "every incident face owned" test is
   satisfiable while the vertex still lies on the region's topological boundary. That test cannot detect
   this case and must not be tightened in place of clause (a).

   **Ownership and walk must also be proven consistent.** Region 2 reaches outer-ring vertex 6 yet
   records **no mandatory boundary endpoints**, which is contradictory. Add a typed rejection: if any
   owned fragment lies in a face incident to a mesh-boundary edge, that edge's mandatory arc **must**
   appear on that region's boundary walk. Without it, clause (a) would make χ come out to 1 while
   ownership and the walk still disagreed — a green gate over an unfixed defect.

   Amendments 5, 7, and 8 are **unaffected and proven reached** by DG-R3:
   `RegionInteriorDisconnected` and `RegionCutComponentCountDeficit` are both absent, and the R7
   cyclic-order sanity checks are 3/3 PASS.

**Amended again 2026-08-24 by `M3-CP4ab-CB-R8-S0-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

10. **Section 4.1's arc definition is CORRECTED: mandatory arcs must be split at trace terminal points.**
    Section 4.1 defined the arc set as *"one mandatory arc per `FieldAlignedMandatoryEdge`"* while
    subdividing trace arcs at every incident event node. That asymmetry was never justified and is the
    defect `M3-CP4ab-CB-R8` stopped on.

    A trace terminating at a barrier has `terminalBarrier` set and reaches a point **interior** to that
    mandatory edge. That point is a genuine 0-cell: it separates the edge's two pieces into two different
    graph faces. With the edge unsplit, the whole arc lands in at most one orbit's walk and is absent
    from the other's — which is exactly why region 2 / orbit 3 owns fragments in faces incident to
    boundary edges `(6,7)` and `(6,10)` yet records `mandatory_boundary_endpoints=[]`.

    **Corrected definition.** A mandatory edge carrying `k` trace terminal points yields **`k + 1` arcs**,
    one per piece between consecutive 0-cells (edge endpoint or terminal node). Each piece keeps the
    parent edge's `SurfaceCellRailKind` and provenance to the originating `FieldAlignedMandatoryEdge`, so
    identity A4's mandatory-edge preservation still sees every mandatory edge. `k = 0` is unchanged.

    **The terminal node is a real graph node** of degree 3 — the incoming trace arc and the two mandatory
    pieces. Without it the rotation and face walk cannot turn onto the boundary, which is the mechanism
    by which the boundary arcs were lost.

    **`k = 1` needs no ordering**: the two pieces run from each edge endpoint to the terminal point, and
    each piece's owning region is given by the terminating trace's dart orbit on that side. **`k ≥ 2` is
    a typed rejection** with the `SourceEdgeTopologyKey` and competing `TraceId` loci — never an
    identifier or coordinate tie-break. If it is ever genuinely needed, the order belongs with amendment
    8's A1 authority, not A2b. On the accepted witness `k ≤ 1` everywhere.

    ~~**This correction is A2b-local.** The arc set is built in `GlobalTopologyPlan.cpp` from already
    published authority (`terminalBarrier`, `FieldAlignedMandatoryEdge`, `incidentFaces`, and the trace
    darts' orbits). **The CP3b product is not reopened.**~~ — **WITHDRAWN by amendment 11.** The terminal
    0-cell this rule splits at is not published by A2a, so the rule is not A2b-local. Everything else in
    amendment 10 stands.

    This is the third instance of one class — source faces atomic (fixed by amendment 4), non-mandatory
    edges atomic in adjacency (fixed by amendment 5), mandatory edges atomic in the arc set (this
    amendment). Amendment 9's `V_int` mesh-boundary exclusion and its companion ownership/walk
    consistency rejection remain required and are applied **after** this correction, at which point the
    consistency check is expected to be satisfiable rather than firing.

**Amended again 2026-08-24 by `M3-CP4ab-DG-R4-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

11. **Amendment 10's A2b-locality claim is WITHDRAWN; A2a must publish every trace terminus as a real
    0-cell.** Amendment 10 assumed the interior barrier-contact node already existed. It does not. A2a
    binds both the `FirstContact` and the `MandatoryBarrierTermination` event to `mandatory->firstNode`
    (`SurfaceCellTracing.cpp:657-669`) — an **endpoint** of the mandatory edge — so CB-R9's correct
    endpoint rejection (`GlobalTopologyPlan.cpp:374-381`) fires on every barrier-terminating trace.
    Amendment 10's arc rule, `k + 1` piece count, degree-3 terminus, parent-edge provenance, and typed
    `k ≥ 2` rejection are all **retained**. Only the locality claim is wrong.

    **(a) A trace never exits through a vertex.** A2a's transport loop has exactly one exit primitive and
    it returns a `SourceEdgeTopologyKey` (`field_aligned_outgoing_carrier`, `SurfaceCellTracing.cpp:257-282`);
    termination occurs when that carrier is mandatory (`:385-390`). The terminus is therefore an interior
    point of the mandatory edge **by construction of A2a's own model**, and can never be an endpoint.
    Substituting an endpoint is prohibited.

    **(b) A2a is the single writer of network 0-cells, and already owns the mechanism.**
    `field_aligned_append_contact_node(...)` (`:528-537`) is already used for the trace/trace contact case
    (`:614-615`) and the loop-closure case (`:688`). The barrier case is the sole exception. Publishing the
    terminus introduces **no coordinate, no barycentric parameter, no ordinal, and no proximity test** —
    the node's `SourceVertexId` remains the placeholder frozen by section 3.2, and the locational datum
    (`sourceEdge = terminalBarrier`) is already on both events. A2b may **not** mint the node: `A2`
    requires `plan.rotation_system().size() == network.nodes().size()`
    (`tests/FieldAlignedCurveNetworkTests.cpp:1957`), and `build_node_loci` / `build_rotation_system`
    enumerate `network.nodes()` (`GlobalTopologyPlan.cpp:506`, `:774`).

    **(c) The edge locus is the frozen home of an interior terminus, and its cyclic order already exists.**
    `NodeLocus::edge` (`GlobalTopologyPlan.cpp:495-498`) is assigned to any node that is neither a
    singularity-port node nor a mandatory endpoint, from its events' `sourceEdge` (`:545-570`). The
    edge-locus rotation branch already requires exactly **two mandatory rays and degree three**
    (`:897-909`) and orders the three darts strictly — `primary 0` toward the second endpoint, `primary 2`
    toward the first (`:938-950`), the trace ray at `2·sideRank + 1` (`:983-986`) — with no identifier,
    container, or coordinate tie-break. That branch is **dead code under the current A2a product**. No
    further order authority is required at `k = 1`, and none may be invented.

    Note that `build_node_loci` discards a node's `sourceEdge` when the node already has a vertex locus
    (`:554`); this is exactly how the endpoint substitution destroys the terminus location.

    **(d) The global cellularity identity is not an oracle for terminus placement.** Publishing a terminus
    adds **+1 node and +1 arc**, so `V_g − E_g + F_g` is invariant
    (`tests/FieldAlignedCurveNetworkTests.cpp:1818-1826`). B4 is structurally blind to this defect, which
    is why CP3b's 304/304 accepted it. Terminus questions are settled by ownership and walk membership
    (A1, A3, B1) only — never by Euler.

    **(e) The re-proof surface is exactly one accepted constant.** `EXPECT_EQ(5U, network.nodes().size())`
    (`tests/FieldAlignedCurveNetworkTests.cpp:471`) becomes **8**. `validate_field_aligned_candidate` is
    recompute-and-compare (`SurfaceCellTracing.cpp:1144-1301`) and every digest assertion is relative, so
    both track the producer automatically. No accepted assertion binds the terminal node's identity.
    CP3b is reopened to that one constant plus a strengthening of
    `PublishesTypedFirstContactAndTerminationEvents` requiring the terminal node to differ from both
    endpoints. The CP4ab gate stays **316**.

**Amended again 2026-08-24 by `M3-CP4ab-DG-R5-INDEPENDENT-REVIEW`
(`M3_CP4ab_Closure_Record.md` — RETIRED at CP4ab closure, binding):**

12. **Structural inputs must be validated before any consumer derives from them, and global cellularity
    on a bounded source surface must exclude the exterior orbits.** Two independent rules, both proven
    from DG-R5.

    **(a) Validation ordering.** No derived quantity — orbit election, fragment-corner incidence, χ, or a
    region certificate — may be the first authority to reject a defect in its own input. A candidate's
    structural inputs (per-region single closed boundary walk, canonical arc/rotation/boundary equality,
    canonical fragment ownership) are validated first; consumers run only on inputs already proven
    well-formed. Three instances of the violation are on record: `region_orbit` shadowing the
    interior-singularity check (fixed by the P4 hoist; B3 green), certificate χ shadowing canonical
    fragment ownership (A5), and `region_orbit` shadowing `validate_single_boundary_walk` (B2). The
    product's own comment at `GlobalTopologyPlan.cpp:2373-2374` names the single-walk validation as the
    reason χ's boundary terms cancel, while that validation is evaluated after the path that consumes it.
    Both open instances are **product** defects; neither tamper may be weakened to recover an expected
    enum, and no error code may be added or relaxed for them.

    **(b) Global cellularity on a surface with boundary.** A combinatorial dart-orbit face walk yields the
    faces of the graph embedded in the **closed** surface obtained by capping each source boundary
    component. For a source surface `S` with `b` boundary components the frozen identity is therefore

        V_g − E_g + F_g^interior = χ(S),   with F_g^interior = F_g^all − b

    equivalently `V_g − E_g + F_g^all = χ(S) + b`. `F_g^interior` is the region count. The independent B4
    oracle compares the all-orbits count against `χ(S)` and is wrong by exactly `b` on every bounded
    witness — `9 − 11 + 4 = 2 ≠ 1` on the two-ring disc after CB-R10, and `6 − 8 + 4 = 2 ≠ 1` before it,
    so the defect predates and is independent of the terminal-0-cell correction. The exterior orbits are
    already derived lawfully and geometry-free from `SurfaceCellRailKind::Boundary`
    (`tests/FieldAlignedCurveNetworkTests.cpp:1647-1652`); they must be excluded, never approximated by a
    constant, an orientation heuristic, or a geometric test. Amendment 11(d) is unaffected: the terminal
    0-cell correction remains Euler-neutral under either form.

    **(c) An independent oracle must publish a typed failure reason.** A bare boolean turns a red into a
    search and costs a diagnostic to localize. This applies to B4 and to any future independent oracle
    admitted to a gate.

Section 6's disc proof is unchanged in *content* and now computes on fragments as defined above, with χ
computed by amendment 6 as corrected by amendment 9, and corner incidence/order authority by
amendment 8; identity B2
(`RejectsRegionWithMultipleBoundaryWalks`) becomes reachable for the first time, because a two-walk
region is now representable and reaches the validator instead of aborting construction.

Sections 3, 5, 6, 8, and 9 are unaffected and were not contradicted by anything CP4a, CP4b, or CP4ab
found.

Incoming accepted authority: CP3b source/package `611b3f8f3926792baee9d1078d6677d22006a6c4 / 9456073195`,
immutable `M3-CP3b-TB` `32515222447 / 96875297990`, **304/304**. Accepted combined selector SHA-256
`c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`.

## 1. Why this turn exists, and how to read this document

CP4 was a single checkpoint carrying three semantic domains plus witness production plus the cumulative
M3 exit gate. It is now four turns (this one plus CP4a/CP4b/CP4c). Two things had to be frozen before
any CP4 code could be written, and both are now settled here:

- the **per-region disc-topology proof had no definition** — plan section 2 criterion 6 and section 3
  A2b both require one and nothing defined it, which is the undefined-certificate shape plan section
  1.1.2 records M1 paying for twice;
- **CP4c's required torus witness appeared to collide with the open `G4-B001` blocker.** Section 9
  resolves this from the tracker and the source: **there is no collision.**

This document assumes no prior familiarity with the codebase. Every type, file, line, enum value, and
fixture named below was read at its cited location during this turn. Where a name in the existing code
means something *different* from what a CP4 reader would expect, that is called out explicitly rather
than left to be discovered.

**Three things in the accepted code will mislead you if nobody says them out loud.** Read section 3
before designing anything.

## 2. What A2b is, in one paragraph

CP3a/CP3b published a `FieldAlignedCurveNetwork`: singularity ports, mandatory boundary/hard-feature
edges, candidate traces, and a typed event graph. Geometrically that product is an **embedded graph
drawn on the source mesh**. A2b's job is to take the faces of that embedded graph and publish them as
`GlobalTopologyPlan` regions, each with a proof that it is a topological disc, such that M4 can later
schedule one shared rail sequence over them. A2b selects and derives; it never repairs the network.

## 3. Three facts about the accepted code that are not obvious

### 3.1 `TopologyRegionId` already exists and is NOT the CP4 region

`include/directional/authority/AuthorityIds.h:208` defines
`using TopologyRegionId = SemanticId<detail::TopologyRegionTag>;`, and it is used throughout
`SurfaceCellOwnership.h`, `PatchDescriptor.h`, `FlowRepStrands.h`, `RemeshPipeline.h`, and inside the
accepted CP3 product (`FieldAlignedSingularityPort::sourceTopologyRegion`,
`FieldAlignedCandidateTrace::sourceTopologyRegion`, `FieldAlignedMandatoryEdge::sourceTopologyRegions`).

**That is A0 *source* topology-region authority** — a partition of the source mesh by
`build_source_topology_regions(...)`, barriered by hard features. It is an **input** to CP4, not the
thing CP4 produces.

CP4's regions are faces of the *network* graph. They are a different semantic domain and **must get
their own ID type**. Do not reuse `TopologyRegionId`, and do not add a second meaning to it — that
would be exactly the single-authority violation plan section 7 lists as a stop condition. Section 5
gives the exact new-ID recipe.

### 3.2 A contact node's `sourceVertex` is a placeholder, not a location

`src/geometry/SurfaceCellTracing.cpp:528-535`, `field_aligned_append_contact_node(...)`:

```cpp
const std::size_t nodeIndex = candidate.nodes.size();
const auto node = authority::NetworkNodeId::from_index(
    static_cast<std::int64_t>(nodeIndex), nodeIndex + 1U);
if (!node) return std::nullopt;
candidate.nodes.emplace_back(node.value(), sourceFace.vertices().front());
```

`FieldAlignedCurveNetworkNode` (`SurfaceCellTracing.h:141-150`) carries exactly two fields — a
`NetworkNodeId` and a `SourceVertexId`. For a **contact** node that `SourceVertexId` is
`sourceFace.vertices().front()`: an arbitrary vertex of the face the contact happened in. It is not
where the contact is. Two distinct contacts in the same source face receive **distinct
`NetworkNodeId`s but identical `sourceVertex` values.**

Consequence, and this is binding: **CP4a must never use `FieldAlignedCurveNetworkNode::sourceVertex` to
locate, order, or identify a contact node.** Doing so silently merges distinct junctions and produces
wrong region boundaries with no error anywhere.

The information you actually need is on the **event**, not the node.
`FieldAlignedNetworkEvent` (`SurfaceCellTracing.h:265-283`) carries `node`, `kind`, `sourceFace`, an
optional `sourceEdge`, and `incidences`. Build all locational reasoning from events.

### 3.3 `FieldAlignedNetworkEventKind::SingularityTermination` is declared and never produced

`SurfaceCellTracing.h:243` declares `SingularityTermination = 4`. A repository-wide search over
`src/`, `include/`, and `tests/` finds **exactly one occurrence — that declaration.** Nothing produces
it and nothing tests it.

This matters because plan section 2 criterion 5 requires that every trace terminate at a typed event
"(existing trace, boundary, hard feature, **singularity**)". A trace that runs into another
singularity currently has no representable terminal kind that is actually emitted. This is a real
unowned obligation, not a cosmetic one, and section 7 assigns it to CP4c identity C5.

## 4. The embedded graph whose faces become regions

This is the definition CP4a implements. It is frozen.

### 4.1 Arcs

The graph's arcs are of exactly two kinds, and no others:

1. **Mandatory arcs** — one per `FieldAlignedMandatoryEdge` in `network.mandatory_edges()`
   (`SurfaceCellTracing.h:285-308`). Each already carries a `NetworkEdgeId`, its
   `SourceEdgeTopologyKey`, its `SurfaceCellRailKind` (`Boundary` or `HardFeature`), and its two
   endpoint `NetworkNodeId`s. These are the source boundaries and hard features.
2. **Trace arcs** — obtained by cutting each `FieldAlignedCandidateTrace`
   (`SurfaceCellTracing.h:215-236`) at every event node incident to it. A trace from its origin port to
   its first contact is one arc; from that contact to the next is the next arc; and so on to its
   terminal. A trace with no interior contact contributes exactly one arc.

Trace arcs are **new** typed objects. Do not overload `NetworkEdgeId`, which is already the mandatory
edge's domain.

### 4.2 Nodes

Nodes are exactly `network.nodes()`. Every node is either a singularity-port origin node or an event
node; both already exist in the accepted product. CP4 adds no nodes and merges none. Subject to §3.2,
identify nodes only by `NetworkNodeId`.

**Amendment 11 qualifies this.** "CP4 adds no nodes" remains binding for **A2b** — `GlobalTopologyPlan`
must never mint a `NetworkNodeId`. It is **not** a statement that A2a's published node set is complete:
A2a does not publish a 0-cell for a barrier terminus, and amendment 11 requires it to. The node set grows
in **A2a**, upstream of this section.

### 4.3 The rotation system — a CP4a prerequisite, not deferred debt

To compute the faces of an embedded graph you need, at every node, the **cyclic order of its incident
arcs** in the surface's orientation. That is the rotation system. Faces are then the orbits of the
"next arc clockwise after the reversal" permutation — the standard face-walk.

`M3_CP3_Closure_Record.md` section 6 recorded rotation-system/face-walk consistency as CP3b debt and
placed it in CP4c. **That placement was wrong and is corrected here:** it is not a nice-to-have proof
obligation that can wait for the exit gate, it is the input CP4a cannot compute regions without.
CP4a must **derive and publish** the rotation system (identity A2); CP4c separately **proves it on
produced witnesses** (identity C3). Both are needed; they are not duplicates.

Derive the rotation at a node from source-attached data only:

- for a mandatory arc, from its `SourceEdgeTopologyKey` and the incident `SourceFaceTopologyKey`s;
- for a trace arc, from the incident segment's `sourceFace`, its `outgoingCarrier` /
  `incomingCarrier`, and — where a face is crossed — its `entryTransport`
  (`FieldAlignedCandidateTraceSegment`, `SurfaceCellTracing.h:194-213`).

Order arcs around a node by walking the source fan of the node's incident faces. Do **not** order them
by any floating-point angle: this project has four recorded instances of geometry-derived fixture
degeneracy, and an angle comparison here would be a fifth waiting to happen. The fan walk is exact
integer/topological work.

### 4.4 Regions

A **region** is one face of that embedded graph: a cyclic boundary walk of arcs, plus the set of source
faces (`SourceFaceTopologyKey`) it covers. Every source face belongs to exactly one region — this is
CP4a identity A3, and it is the coverage property everything downstream relies on.

## 5. The region product and its ID domain

### 5.1 The new ID

Add a `NetworkRegion` domain following the existing pattern exactly. In
`include/directional/authority/AuthorityIds.h`:

1. add `NetworkRegion,` to `enum class AuthorityDomain` (currently at `:23-46`), appended **after
   `QuotientClass`** so no existing enumerator's value changes;
2. add, in `namespace detail` beside `NetworkEdgeTag` (`:128-130`):
   ```cpp
   struct NetworkRegionTag {
     static constexpr AuthorityDomain domain = AuthorityDomain::NetworkRegion;
   };
   ```
3. add, beside `NetworkEdgeId` (`:217`):
   ```cpp
   using NetworkRegionId = SemanticId<detail::NetworkRegionTag>;
   ```

`SemanticId` (`:158-201`) has a deleted default constructor and is constructed only through
`from_index(value, extent)` / `from_domain_index(domain, value, extent)`, both returning
`DomainResult<SemanticId>`. `index()` is a representation projection and is never a semantic identity.
Do a domain-typed arc ID the same way if you add one.

### 5.2 The product

`GlobalTopologyPlan` has **zero occurrences** in `src/`, `include/`, and `tests/` — verified this turn.
It is genuinely new.

- Header: `include/directional/geometry/GlobalTopologyPlan.h`
- Source: `src/geometry/GlobalTopologyPlan.cpp`, registered in `CMakeLists.txt` in the
  `src/geometry/...` block (alphabetically it sits just after `src/geometry/FlowRepStrands.cpp`; the
  block runs from about `CMakeLists.txt:165`) so it builds into `directional_core`.

Follow the accepted `FieldAlignedCurveNetwork` shape exactly, because it is the idiom every M3 gate has
accepted and because CP4b's negatives depend on it:

- a mutable `GlobalTopologyPlanCandidate` struct that is explicitly **not** authority, exposed solely
  so tamper negatives have a seam — mirror the comment at `SurfaceCellTracing.h:310-315`;
- `static ... make(...)` building from accepted inputs, and
  `static ... make_from_candidate(...)` accepting a candidate — **construction is the only validation
  seam**;
- a `...BuildResult` class exposing `has_value()`, `explicit operator bool()`, `value()`, `error()`
  (mirror `FieldAlignedCurveNetworkBuildResult`, `SurfaceCellTracing.h:421-444`);
- an error struct carrying a code **plus optional loci** — mirror `FieldAlignedCurveNetworkError`
  (`:130-139`), which carries `sourceVertex`, `sourceEdge`, `rail`, `singularity`;
- `validation_candidate()` returning a round-trippable candidate;
- `source_digest()`, `network_digest()`, `semantic_digest()`.

### 5.3 The digest split is mandatory and is not optional style

CP3a lost a diagnostic round to exactly one defect here, and the fix is now accepted behaviour:
`src/geometry/SurfaceCellTracing.cpp:1351-1364` feeds
`fieldTransportAtlas.branch_topology().semantic_digest()` (gauge-invariant) into the semantic digest
while keeping `authority::field_transport_atlas_hash(...)` (gauge-**dependent**) as a separate binding
digest.

`GlobalTopologyPlan` must do the same one level up: its `semantic_digest()` consumes the network's
`semantic_digest()`, **never** its `atlas_digest()`. Fold provenance into a separate binding field.
If you fold a gauge-dependent value into semantic identity, identity A6's relabel-invariance assertion
will fail and you will spend an attempt rediscovering a solved problem.

## 6. The disc-topology proof — frozen construction

### 6.1 What is proven

A region is a **topological disc** iff, over the region's closure:

1. its **boundary is a single closed walk** — exactly one boundary component;
2. its covered source faces are **connected** through source adjacencies that no network arc crosses;
3. its **Euler characteristic is 1**, computed as `χ = V − E + F` over the region's covered source
   faces, the source edges incident to them, and the source vertices incident to those, with boundary
   incidences counted once per the boundary walk;
4. it contains **no singularity in its interior** — every `FieldSingularityId` reachable in the region
   lies on its boundary walk.

### 6.2 Sufficient *and* necessary — say so, and say why

The A1 `FieldQuadrangulabilityCertificate` deliberately claims only a **conservative sufficient**
holonomy witness (`FieldQuadrangulabilityWitnessKind::ClosedShenSufficient`,
`FieldTransportAtlas.h:54-57`; plan section 3 A1 states the gcd condition is not claimed necessary).
**Do not copy that hedge here.** Conditions 1–3 are necessary *and* sufficient for a compact connected
surface-with-boundary to be a disc; that is a theorem, not a heuristic, and the inputs are exact
integer combinatorics on the source mesh with no tolerance anywhere.

Condition 4 is different and must be labelled honestly. A cone point is still *topologically* a disc.
Condition 4 is not part of the topological claim; it is the additional **field-regularity** requirement
that makes a region quadrangulable. State it in the code and in the report as a separate named
requirement, not as part of the disc proof, or the certificate will be attesting to two things under
one name — the single-authority defect that cost CP2b and CP3a a round each.

### 6.3 Rejection reasons — exhaustive, each naming its locus

CP2b lost three turns of review to a diagnosability collapse: 21 distinct `nullopt` sites folded into
two opaque codes while the product was already carrying the locus fields it discarded. Do not repeat
it. Freeze this enum, and populate every locus listed:

| Code | Locus fields to populate |
|---|---|
| `RegionBoundaryNotSingleWalk` | region, the arc starting the second boundary component |
| `RegionInteriorDisconnected` | region, the two `SourceFaceTopologyKey`s that do not connect |
| `RegionEulerCharacteristicNotOne` | region, computed `χ`, and the `V`/`E`/`F` counts |
| `RegionContainsInteriorSingularity` | region, `FieldSingularityId`, `SourceVertexId` |
| `RegionCoversNoSourceFace` | region |
| `RegionSourceFaceUnowned` | `SourceFaceTopologyKey` |
| `RegionSourceFaceMultiplyOwned` | `SourceFaceTopologyKey`, both `NetworkRegionId`s |
| `RegionBoundaryArcNotOwnedByNetwork` | region, arc |
| `MandatoryEdgeNotOnAnyRegionBoundary` | `NetworkEdgeId`, `SourceEdgeTopologyKey` |
| `RotationSystemInconsistent` | `NetworkNodeId`, the arc whose successor is wrong |
| `InvalidNetworkBinding` | — (network digest mismatch) |
| `InvalidSourceBinding` | — (source digest mismatch) |
| `InvalidRegionCertificateBinding` | region (tampered/absent certificate) |
| `EmbeddedGraphHasNoInteriorFace` | a `NetworkArcId` on the walked embedded graph (all walked faces classified exterior) |
| `RegionCutComponentCountDeficit` | the first `NetworkRegionId` graph face for which no distinct network-cut component exists under the current K1-only construction |
| `RegionBoundaryEvidenceMissing` | region |
| `RegionElectedCutComponentEmpty` | region |

The four final rows are the K1 extensions explicitly authorized by the mandatory independent Review.
They distinguish conditions for which the original thirteen cannot be used without inventing a locus
or overstating what has been proved. In particular, an all-exterior face walk does not identify a
wrong rotation successor, so it is not `RotationSystemInconsistent`; a region with no boundary-side
evidence does not establish a particular unowned source face, so it is not
`RegionSourceFaceUnowned`. `RegionBoundaryArcNotOwnedByNetwork` is used for an oriented trace dart
with no side component, `RegionInteriorDisconnected` carries two source-face representatives when
boundary evidence conflicts across cut components, and `RegionCoversNoSourceFace` is reserved for
candidate validation where a concrete region actually has an empty `sourceFaces` set.

Add a `..._error_code_name(...)` free function returning the enumerator's exact spelling, mirroring
`geometry::field_aligned_curve_network_error_code_name(...)` used at
`src/pipeline/RemeshPipeline.cpp:6595`. Every CP4 test that expects a rejection must assert the
**exact code**, and diagnostic-gate output must print it. A test that only asserts `ASSERT_FALSE(built)`
tells a reviewer nothing about which guard fired — `LESSONS.md` section 3 opens with exactly this.

### 6.4 The independent oracle — factory-free, test-only

Mirror what CP3b did and what its accepted gate proved (`tests/FieldAlignedCurveNetworkTests.cpp`,
`independent_trace_event_composition_oracle`, around `:1060-1180`): a **test-only** function that
recomputes the answer from the published product and **never calls the production validator**.

For CP4b the oracle must, from the published arcs, rotation system, and region membership alone:

1. re-walk the faces independently and check the walk it obtains matches the published regions;
2. recompute `χ` independently from the source-face/edge/vertex incidences;
3. independently confirm one boundary component and interior connectivity;
4. compare its verdict against each published region certificate.

Keep it in `tests/FieldAlignedCurveNetworkTests.cpp` or a new `tests/GlobalTopologyPlanTests.cpp`. If
you add a new test file it **must** be added to `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES` in
`cmake/DirectionalTests.cmake:69-83`, or the identities will not be built and the gate will silently
run fewer tests than the selector names.

## 7. Frozen identities, counts, and gates

Six identities per checkpoint, matching the accepted CP1/CP2/CP2b/CP3a/CP3b rhythm. **These names are
frozen.** If implementation shows a name no longer describes its contract, correct it in planning and
re-freeze — never rename inside a Code + Build turn.

### 7.1 `M3-CP4a` — gate **310 = accepted 304 + 6**

| | Identity |
|---|---|
| A1 | `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` |
| A2 | `GlobalTopologyPlan.PublishesRotationSystemConsistentWithNetworkEvents` |
| A3 | `GlobalTopologyPlan.CoversEverySourceFaceExactlyOnce` |
| A4 | `GlobalTopologyPlan.PreservesMandatoryBoundaryAndHardFeatureEdges` |
| A5 | `GlobalTopologyPlan.RejectsForeignNetworkBindingOrTamperedRegionOwnership` |
| A6 | `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` |

File surface: `AuthorityIds.h`, `GlobalTopologyPlan.h`, `GlobalTopologyPlan.cpp`, the test file,
`CMakeLists.txt`, `cmake/DirectionalTests.cmake`. **`src/pipeline/RemeshPipeline.cpp` is frozen for
CP4a and CP4b** and enters the surface only at CP4c.

### 7.2 `M3-CP4b` — gate **316 = 310 + 6**

| | Identity |
|---|---|
| B1 | `GlobalTopologyPlan.ProvesDiscTopologyForEveryEmittedRegion` |
| B2 | `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks` |
| B3 | `GlobalTopologyPlan.RejectsRegionWithWrongEulerCharacteristicOrInteriorSingularity` |
| B4 | `GlobalTopologyPlan.IndependentDiscProofOracleAgreesWithPublishedCertificates` |
| B5 | `GlobalTopologyPlan.RejectsTamperedDiscProofCertificate` |
| B6 | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan` |

### 7.3 `M3-CP4c` — the M3 exit gate, **322 = 316 + 6**

| | Identity |
|---|---|
| C1 | `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` |
| C2 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` |
| C3 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` |
| C4 | `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` |
| C5 | `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` |
| C6 | `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` |

C3, C4, and C5 are the previously-unowned obligations. C4 and C5 are named on
`FieldAlignedCurveNetwork` rather than `GlobalTopologyPlan` because they test the CP3b product; that is
deliberate and is not a scope violation — CP4c is the cumulative exit gate and owns section 2's
criteria wherever they live.

### 7.4 B6 — read this before implementing it, it is the easiest way to lose the checkpoint

Plan section 4A.3 B4 says "represent A1 certificate failure as the architecture's
`FieldTransportUnestablished` catastrophic precondition rather than deferring it to M4."

`FieldTransportUnestablished` is a **D4 catastrophic disposition** in `DESIGN.md` section 2.3's closed
enumerated set. **The disposition tier machinery (D0–D4) is M7 work and does not exist yet.** M1
criterion 5 was authored in terms of a disposition tier scheduled for M7 and made M1 unclosable by
construction; `LESSONS.md` section 6 opens with that lesson. Do not build D4 machinery in M3.

What already exists: `FieldTransportAtlas::make(...)` **already rejects** an unestablished field, with
`FieldAtlasBuildErrorCode::UnestablishedAdmissibility` (`FieldTransportAtlas.h:73`, raised at
`src/authority/FieldTransportAtlas.cpp:1674` and `:1730`), and
`FieldQuadrangulabilityCertificate::established()` (`FieldTransportAtlas.h:204`) is the published
predicate.

So the M3-scope obligation is **structural and negative**, not a disposition implementation: prove
there is **no path** by which a `GlobalTopologyPlan` is produced from an atlas whose certificate is not
established, and that no degraded producer or local substitution exists to route around it. That is
what B6 asserts, and it is fully provable today. Record in the CP4b report that the D4 *tier* remains
M7's, with this named as the M3 equivalent — the handoff's standing rule that earlier milestones use
the equivalent stated in their own gate.

### 7.5 Section 2 criterion → identity map

This table is the point of the whole exercise. `M3_CP3_Closure_Record.md` section 6 records that CP3b's
prose obligation list and its frozen selector were never reconciled, so two obligations ended up with
no owning identity and a green gate proved neither. Nothing in a green result reports what the selector
forgot to ask. **Before freezing each CP4 package, re-walk this table and confirm every row still has a
live owner.**

| Plan section 2 criterion | Proven by |
|---|---|
| 1. Field precondition explicit at A1 | accepted CP1 + **B6** |
| 2. Singularity ports typed and complete | accepted CP2 |
| 3. Mandatory topology first-class | accepted CP2 + **A4**, **C6** |
| 4. Tracing branch-consistent | accepted CP3a |
| 5. Network geometry structurally clean | accepted CP3b + **C3**, **C5** |
| 6. Topology regions derived, disc proof per region | **A1**, **A3**, **B1**–**B5**, **C6** |
| 7. Reduction preserves required topology | **A4**, **C6** |
| 8. Metamorphic invariance | accepted CP2/CP3a/CP3b + **A6** |
| 9. Independent/tamper evidence | accepted CP3a/CP3b + **A5**, **B4**, **B5**, **C4** |
| 10. Frozen predecessor green | the 322 selector as a whole |

## 8. Witnesses — provenance and self-asserted preconditions

### 8.1 Reuse; do not author

Both representative witnesses **already exist as committed fixtures**, verified this turn:

- `benchmarks/fixtures/milestone-g/torus.obj` + `torus.rawfield`
- `benchmarks/fixtures/milestone-g/mechanical_feature.obj` + `mechanical_feature.rawfield`

`tests/TestFixturePaths.h:66` provides `directional::tests::benchmark_fixture_path(...)`.

More usefully, `tests/SurfaceCellTransitionQuotientTests.cpp:512-541` already contains
`make_torus_pipeline_fixture()`, which reads that fixture and drives it through the **production entry
path** `directional::pipeline::remesh_from_raw_cross_field(...)` with
`fallbackPolicy = SurfaceCellFallbackPolicy::Fail` and `allowSourceGridRecovery = false`, then requires
`result.surfaceCellContext.hasTraceNetwork`. Its `read_rawfield(...)` helper is at `:261`. That file is
in the **same CMake target** as `FieldAlignedCurveNetworkTests.cpp`
(`cmake/DirectionalTests.cmake:69-83`), so the pattern is directly reusable.

Copy that pattern for both witnesses. Do not hand-author a torus.

### 8.2 Preconditions each fixture asserts about itself

This is the control that broke the four-checkpoint degenerate-fixture streak, and it is binding. The
accepted CP3a fixture is the model: `tests/FieldAlignedCurveNetworkTests.cpp:304-330`,
`make_cp3a_two_ring_index_one_field(...)`, asserts at runtime that **every** singular-fan opposite
carrier is interior — the exact capability the previous witness silently lacked — plus that there is
exactly one interior singularity after filtering boundary rows, and that an independently reconstructed
index equals the producer's.

Each CP4c witness must assert, before any target assertion becomes required-green evidence:

1. the network published **at least one region with more than one covered source face** — otherwise
   region derivation is vacuous;
2. **at least two distinct regions exist** — otherwise coverage and boundary-sharing prove nothing;
3. for the torus: **genus is actually 1**, from the source Euler characteristic, and at least one
   region boundary uses a non-trivial cycle — otherwise the "periodic/torus-style" claim is unearned;
4. for the mechanical witness: **at least one `SurfaceCellRailKind::HardFeature` mandatory edge exists
   and lies on a region boundary** — otherwise "feature-bearing" is unearned;
5. the quadrangulability certificate is `established()`.

`LESSONS.md` section 2 now states the general rule directly: a witness proven adequate for one
checkpoint's contract is not thereby adequate for the next one's, and a non-vacuity requirement is only
as good as the check that the witness can satisfy it. CP3a's plan directed reuse of the CP2b fan on the
strength of a green gate; every edge opposite that fan's singular vertex is a boundary edge, so the
required multi-face traversal was unsatisfiable on that mesh by construction. Re-derive capability
against **CP4's** contract, and encode the result as a runtime assertion.

## 9. The `G4-B001` collision — resolved, no collision

**Finding: CP4c's torus witness does not touch the `G4-B001` seam. It is not an M3 exit prerequisite.**

This was checked against the tracker and the source rather than assumed:

- `Regression_Root_Cause_Tracker.md:1043` classifies `PR8-R034 / G4-R007` as
  `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; `:1045` records the authority as "direct torus 0/3 with 241
  `LocalSheetMismatch` issues **after 192 quads**".
- `:734` locates the root cause precisely: the production path calls
  `classify_source_surface_labels(..., hardFeatureRailEdges, ...)` and publishes its `localSheetByFace`
  as `sourceFaceSheets`; the supplied barrier set terminates local-sheet adjacency, so a hard rail is
  incorrectly promoted into `IsolationSheetId` authority, and
  `close_completion_lineage_source_authority(...)` then rejects the opposite-side chart with
  `LocalSheetMismatch`.

That is **completion/materializer-stage** work — isolation sheets, chart lineage closure, and quad
emission. It is downstream of A2b topology planning. The evidence that the torus reaches trace
authority intact is that `make_torus_pipeline_fixture()` requires
`result.surfaceCellContext.hasTraceNetwork` and calls `require_produced(...)`, both of which throw on
failure, and that fixture is in an accepted, currently-building test target.

So the first of the three options section 4A.3 posed is the true one: **the M3 topology-network witness
exercises a path that stops before the `G4-B001` seam.** CP4c's witnesses must therefore assert
regions and disc proofs and **stop there** — they must not run to final quad emission, and CP4c must
not claim any `G4-B001` progress. Plan section 8's prohibition on claiming its closure by unrelated
network green stands unchanged, and `G4-B001` remains an open product blocker owned later.

Record this reasoning in the CP4c report so the question is not re-litigated.

## 10. Budget and cadence

> **ABOLISHED 2026-08-25 by user authorization.** The attempt budget, the diagnostic-gate cap, the
> mandatory-review-on-third-red ratchet, and the **`DG` turn type** no longer exist. The workflow is
> `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing and mandatorily routes to review. The
> text below is retained as historical context only and must not be treated as live procedure. See
> `Future_Chat_Session_Handoff.md` "Turn workflow" and
> `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review).

Each of CP4a, CP4b, CP4c holds its own **3-attempt budget** (one attempt = one complete
Code + Build → immutable TB pair) with its own mandatory-review ratchet and its own cap of 2
diagnostic gates. This DEFN turn consumes nothing.

**Allocate a diagnostic gate to CP4a and to CP4c.** Both introduce new witnesses, and the diagnostic
gate is the control that has demonstrably paid for itself: CP3a's red 2/6 diagnostic bought a full
round of semantic evidence and a corrective build for zero acceptance attempts, and CP3a then closed
on attempt 1 of 3. CP4b consumes accepted CP4a authority and reuses its witness, so it may go straight
to acceptance.

Cumulative M3 cost stands at **21 packages**, reported only. Stable accounting is **41 / 14 / 27** and
produced-witness debt is **5**; this turn changes neither.

## 11. Standing stop conditions specific to CP4

Stop and return to Review rather than patching around any of these:

- a second writer appears for region or topology-plan authority;
- `TopologyRegionId` acquires a second meaning, or CP4 regions are represented by raw indices or
  parallel arrays instead of `NetworkRegionId`;
- a region's disc proof is repaired, downgraded, or retried rather than typed-rejected;
- rotation order is decided by a floating-point angle comparison rather than an exact fan walk;
- a gauge-dependent digest is folded into `GlobalTopologyPlan::semantic_digest()`;
- CP4 mutates, weakens, or reconstructs accepted CP3a/CP3b product or test authority;
- D0–D4 disposition machinery is introduced in M3 (see 7.4);
- a witness cannot satisfy a non-vacuity requirement and the requirement is weakened rather than the
  witness replaced.

## 12. Exact successor

Exact next is **`M3-CP4a-CB`** — Code + Build only, under sections 4, 5, and 7.1 of this document.
Author the product and the six frozen A-identities, hold the file surface in 7.1, run the mandatory
pre-package compile, create one immutable package, and stop. `runtimeExecution=false`. Package creation
consumes no attempt. Its successor is the attempt-free `M3-CP4a-DG`.

Do not begin CP4a inside this planning turn.

</details>

<a id="m3-preserved-2"></a>
<details>
<summary><strong>M3_CP4c_Frozen_Definitions.md</strong> — BINDING FROZEN DEFINITIONS</summary>

# M3 CP4c — Frozen Definitions

**Purpose — DURABLE, DO NOT DELETE.** This is the single normative definitions document for the `M3-CP4c` family.
It carries the **complete, unaltered text** of the six original frozen-definition documents, consolidated on
**2026-09-03** at `M3-CP4c-3-TB17-REV`, followed by later definition revisions authored directly in this durable
authority. Nothing in Parts I–VI was summarized, shortened or reworded; Parts VII onward are the original authored
text of their definition turns.

**Supersession.** Within each checkpoint the revisions supersede in order — `DEFN` → `DEFN-R1` → `DEFN-R2`. The
earlier revisions are retained because `DESIGN.md` and the regression tracker cite the amendment lineage directly,
and because an amendment's provenance is part of its authority. **The operative definitions for CP4c-2 are Part
III; for CP4c-3 they are Part VI together with Parts VII, VIII, IX, X, XI and XII, each superseding the earlier
where they conflict. Part IX-A amends Part IX without overriding any of it; **Part X supersedes Part IX §5 (DEFN-R5.5)**
while leaving every other Part IX clause in force; **Part XI supersedes Part X's DEFN-R6.3 and DEFN-R6.4 as region
disc-topology authority** — Part X's measurements, domain findings and withdrawn-assumption record remain evidence
— **Part XI-A amends Part XI without overriding any of its decisions**, correcting what its face certificate
proves; and **Part XII adds the census-domain authority** (`DEFN-R8`), which changes nothing in Part XI or XI-A and
retires only the stage-name domain guard.** Where an earlier part conflicts with a later revision of the same checkpoint,
the later revision governs.

This file is normative authority, not history. History lives in `M3_CP4c_Consolidated_Record.md`; current state and
the forward plan live in `M3_CP4c_Current_And_Forward.md`.

## Citation map

Citations written against the former filenames resolve here:

| Former document | Now |
|---|---|
| `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` | Part I — M3-CP4c-2 DEFN |
| `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` | Part II — M3-CP4c-2 DEFN-R1 |
| `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` | Part III — M3-CP4c-2 DEFN-R2 |
| `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md` | Part IV — M3-CP4c-3 DEFN |
| `Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md` | Part V — M3-CP4c-3 DEFN-R1 |
| `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` | Part VI — M3-CP4c-3 DEFN-R2 |
| *(no prior file — authored in place)* | **Part VII — M3-CP4c-3 DEFN-R3** |
| *(no prior file — authored in place)* | **Part VIII — M3-CP4c-3 DEFN-R4** |
| *(no prior file — authored in place)* | **Part IX — M3-CP4c-3 DEFN-R5** |
| *(no prior file — authored in place)* | **Part IX-A — DEFN-R5 reconciliation amendment** |
| *(no prior file — authored in place)* | **Part X — M3-CP4c-3 DEFN-R6** |
| *(no prior file — authored in place)* | **Part XI — M3-CP4c-3 DEFN-R7** |
| *(no prior file — authored in place)* | **Part XI-A — DEFN-R7 evidentiary amendment** |
| *(no prior file — authored in place)* | **Part XII — M3-CP4c-3 DEFN-R8** |

Section numbering inside each part is unchanged, so a citation such as "`…_DEFN_R2_…` §Amendment 22" reads as "Part VI §Amendment 22". Full text of the originals also remains in git history.

---

## Part I — M3-CP4c-2 DEFN

*Source document: `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN — Frozen Definitions: closed-surface cut-graph authority for A2b

> ## SUPERSEDED IN PART — read this first
>
> **`M3-CP4c-2-DEFN-R1` (2026-08-29) withdraws §5.4's construction guidance.** The whole-source-face /
> source-edge-barrier partition is **no longer cellularity authority**; it survives only as a cut-proposal
> heuristic and diagnostic provenance, and every publication of it must say so. The normative complex is the
> **actual embedded graph** of `FieldAlignedCurveNetwork ∪ cutEdges`, represented by the arc / dart / rotation /
> face-orbit machinery A2b already contains. See `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`,
> **Amendment 13**.
>
> **§§5.1–5.3 remain binding and unchanged**, as do §§1–4 and **Amendment 12**, whose precondition-versus-repair
> boundary is unaffected. §3's torus theorem stands and was independently reconfirmed by R4.
>
> Cause: §5.4 step 1 directed the implementation to compute complement components over whole source faces
> separated by source edges — resurrecting the representation class CP4ab had already rejected in
> `PR8-R042 / M3-CP4b-R001` and recorded in `LESSONS.md` 22d/22e. That produced the stable regression
> `PR8-R043 / M3-CP4c2-R001` at accepted ordinal 305.

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN` is **COMPLETE / DEFINITION-ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, fixture, or selector change was made
or is authorized by this turn. This document freezes the contract that `M3-CP4c-2-CB1` will implement.

**The decision.** CP4c-2 introduces one new authority product, **`SurfaceCutGraph` (stage A2a′)**, produced
after A2a and consumed by A2b, whose sole obligation is to guarantee that the curve network's complement is a
disjoint union of open discs. `DESIGN.md` §7.2 is amended (**Amendment 12**) because its claim that region-disc
topology "holds by construction" is **provably false on closed surfaces**, and because its stop condition, read
literally, forbids the only viable fix.

**The scope decision.** CP4c-2 owns **C1 and C6** (the torus and the disc/mandatory-preservation contract).
**C3 is deferred** out of this checkpoint pending a measurement, for reasons given in §6. This is a
recommendation with a precise trigger, not a unilateral re-allocation: §6.3 states exactly what evidence would
move C3 back in.

#### 1. Predecessor verification — CP4c-1 closure independently checked

CP4c-1's closure claim was verified before this definition was written, from the repository rather than from
the report:

| Check | Expected | Independently computed | Result |
|---|---|---|---|
| 355 required selector | `e9d88f11…5afeaa` | identical | **PASS** |
| first-316 prefix | `601ce2b6…00193c` | identical | **PASS** |
| first-346 prefix | `20d3b0b1…3e46a` | identical | **PASS** |
| first-353 prefix | `51ff96d7…ac6a5` | identical | **PASS** |
| non-gating selector | 3 entries, `537a8010…ffcd6a` | identical | **PASS** |
| W0 — `src/` and `include/` frozen across CB4 | zero changes | zero changes; only `tests/FieldAlignedCurveNetworkTests.cpp` | **PASS** |
| W1 — witness productivity precondition removed | deleted, no weaker assert/skip/special case | deleted; per-trace loop intact | **PASS** |
| W2 — cardinality replaced | `ASSERT_FALSE(producedTerminalKinds.empty())` | present; both named checks survive | **PASS** |
| W5 — two inverted identities | retired, per-identity rationale | absent from source and selector; rationale in tracker | **PASS** |

The accepted prefixes are byte-identical to their accepted ancestors, so accepted authority is carried **in
order** and `first_red_ordinal` remains comparable across the whole CP4c arc. **The closure claim is upheld.**

One documentation defect was found and is recorded in §9: the tracker's `CAND-03` entry cites
`Architecture_M3_CP4c1_CB4_Code_Build_Report.md` for the "full rationale", but that document was retired in the
fifth consolidation. No information is lost — the per-identity rationale is reproduced in the tracker entry
itself — but the citation dangles.

#### 2. The measured state of A2b — DURABLE

All three production witnesses currently fail to produce a `GlobalTopologyPlan`, with **three different**
causes. This is the single most important fact for the implementation agent, because it means "A2b is broken"
is not one problem:

| Witness | A2a result | A2b result | Failure code | Stage |
|---|---|---|---|---|
| torus | network published: 48 `HardFeature` mandatory edges, **0** singularities, 48 structural nodes, **0** traces, **0** events | fails | `UncutFaceComponentOrbitSeedNotUnique` | A2b |
| prescribed sphere | network published: **24** traces, **56** events | fails | `RotationSystemInconsistent` | A2b |
| mechanical feature | **no atlas** | never reached | `IncompleteCycleBasis` | **A1** |

The mechanical witness never reaches A2b at all; it stops in A1. It belongs to CP4c-3 with C2 and is **out of
scope for CP4c-2** — do not attempt to fix it here.

#### 3. Theorem — the torus network provably cannot bound discs

This is not a conjecture and it does not require new measurement.

Let `S` be a closed orientable surface of genus `g`, and let `G` be a graph embedded in `S` with `V` vertices
and `E` edges. If every component of `S \ G` is an open disc, the embedding is **cellular**, and Euler's formula
gives

```
V − E + F = χ(S) = 2 − 2g,     so     F = E − V + 2 − 2g.
```

For the torus, `g = 1` and `χ = 0`, so `F = E − V`. The complement is non-empty — the torus publishes zero
traces, so almost every source face is untouched by the network — hence `F ≥ 1` is required, which forces

```
E ≥ V + 1.
```

**The measured torus network has `V = 48` and `E = 48`, so `F = 0`.** Contradiction. At least one component of
the complement is therefore **not** a disc.

The result is stronger and more useful than the arithmetic coincidence suggests. A graph with `E = V` in which
every vertex has even degree is a disjoint union of cycles, and **any** disjoint union of cycles has `E = V`
exactly. Therefore:

> **No disjoint union of closed curves can ever be a cut graph of the torus.**

Cutting a torus along disjoint loops yields cylinders or a torus-with-holes, never a disc — regardless of
*which* loops they are. So this is not a defect of the particular committed fixture, and it cannot be fixed by
choosing better feature curves. **A cut graph of a genus-`g` surface must contain vertices of degree ≥ 3 and
must realize a homology basis; a feature/singularity-derived network has no mechanism that guarantees either.**

This is exactly what the production code detects. `src/geometry/GlobalTopologyPlan.cpp:1694-1746` unions
untouched faces across edges that are neither mandatory nor trace-touched, then requires each resulting
component to receive **exactly one** orbit seed from its labeled neighbours. A cylindrical component touches
labeled faces on both of its boundary circles, collects two distinct seeds, and fails at line 1741 with
`UncutFaceComponentOrbitSeedNotUnique`. **The error code is correct and the producer is behaving correctly.
There is no bug at that line.** It is reporting a missing input.

#### 4. The `DESIGN.md` §7.2 defect

§7.2 states nine normative derivation steps and eight invariants. Two of them are wrong or ill-defined on closed
surfaces:

- **Invariant 7** — "every resulting region has disc topology unless explicitly typed otherwise" — and the
  closing claim that "**because tracing is combinatorial and terminates on contact, invariants 3 and 7 hold by
  construction.**" §3 proves invariant 7 does **not** hold by construction. Termination-on-contact makes traces
  well-defined; it says nothing about whether the resulting graph is a cut graph. The two properties are
  independent, and the design conflates them.
- **Step 8** — "extract the faces of the embedded graph." For a **non-cellular** embedding the "faces of the
  embedded graph" are not discs, and the phrase has no well-defined meaning as an instruction. The step
  presupposes cellularity that step 1–7 never establish.

And the closing sentence creates the trap:

> "The architecture contains no limit-cycle detection, tiny-region collapse, or **non-disc repair step, and
> adding one is a stop condition**: such a step would be a repair of an immutable upstream product."

**Read literally, the design forbids the only viable fix.** Amendment 12 resolves this, and the resolution turns
on a distinction the implementation agent must understand exactly, because getting it wrong produces an
architecture violation that will pass a naive gate:

> **Establishing a precondition before a product is derived is not the same as repairing that product after it
> is derived.** The stop condition exists to prevent A2b from *observing* a non-disc region and then patching,
> collapsing, or re-cutting it — a mutation of an immutable upstream product, which would destroy
> single-writer authority and make the disc certificate self-fulfilling. It does **not** forbid a separate,
> earlier authority from *supplying additional cuts as an input*, so that region derivation has a cellular
> embedding to work with in the first place.

The practical test the implementation agent must apply to its own design: **if the cut decision can be made
without ever looking at a produced `GlobalTopologyPlan` region, it is a precondition; if it needs to see one, it
is a repair and is a stop.**

##### Amendment 12 — normative, replaces the quoted text in §7.2

1. Invariant 7 is **not** claimed to hold by construction. It holds **conditionally**, on the curve network
   together with the cut graph forming a cellular embedding of the source surface. Invariant 3 continues to hold
   by construction from termination-on-contact and is unaffected.
2. Step 8 is amended to read: *extract the faces of the cellular embedding formed by the curve network together
   with the published `SurfaceCutGraph`.* Face extraction on a non-cellular embedding is undefined and must
   fail closed with a typed error, never produce a region.
3. A new normative step is inserted between steps 7 and 8: *complete the network to a cellular embedding by
   consuming the `SurfaceCutGraph` product, which is derived from the source topology and the immutable curve
   network and is produced before any region exists.*
4. The stop condition is narrowed to its intent and restated: **repairing, collapsing, re-cutting, or
   re-typing a region after `GlobalTopologyPlan` has derived it remains a stop condition.** Supplying cuts as a
   typed input, before derivation, from a separate single-writer authority, is explicitly permitted and is the
   only sanctioned route.
5. §4.6's motorcycle-graph region-decomposition guarantee is amended to name its condition: it supplies the
   decomposition guarantee **only when the field has at least one singularity or the surface has a boundary**.
   On a closed surface carrying an index-free field the motorcycle graph is empty, and the decomposition
   guarantee comes from the cut graph instead.

#### 5. The frozen contract for `SurfaceCutGraph` (stage A2a′)

##### 5.1 Position and authority

- **Produced after** A2a (`FieldAlignedCurveNetwork`) and **before** A2b (`GlobalTopologyPlan`).
- **Single writer.** Nothing else may create, extend, or amend cut edges. A2b consumes it `const` and may not
  add to it.
- **Inputs, all immutable:** `SourceAuthoritySnapshot`, `FieldTransportAtlas`, `FieldAlignedCurveNetwork`.
- **It may not read, construct, or depend on any `GlobalTopologyPlan` or any region.** This is the §4
  precondition-versus-repair boundary and it is a hard architectural constraint, not a style preference.

##### 5.2 Output

A typed product carrying, at minimum:

1. an ordered, deterministic set of **cut edges**, each identified by an existing `SourceEdgeTopologyKey` — cuts
   run along existing source mesh edges only; **no new geometry, no subdivision, no vertex insertion**;
2. a **cellularity certificate** recording `V`, `E`, `F`, the computed `χ`, the source surface's `χ`, and their
   equality;
3. per-component evidence sufficient to show each complementary component is a disc, in the shape the existing
   region certificate already uses — `boundaryWalkCount == 1`, `sourceFacesConnected == true`,
   `eulerCharacteristic == 1`;
4. provenance binding it to the exact `FieldAlignedCurveNetwork` semantic digest and source digest it was
   derived from, so a mismatched pairing fails closed.

##### 5.3 Required guarantees

- **Cellularity.** `network ∪ cutGraph` is a cellular embedding of the source surface. This is the product's
  reason to exist and must be certified, not assumed.
- **Mandatory preservation.** Every mandatory edge — hard feature and boundary — remains in the combined graph.
  Cuts may be added; nothing may be removed, merged, or reclassified.
- **Exactness and determinism.** No tolerance, no floating-point threshold, no iteration limit that can alter
  the result. The same input produces the same cut set byte-for-byte, independent of container iteration order
  and of source face/edge ordering.
- **Idempotence.** When the network is already cellular — which is the expected case for any witness with
  singularities — the product must publish an **empty** cut set and a passing certificate. It must not add
  gratuitous cuts.
- **Fail closed.** If cellularity cannot be achieved, publish a typed error. Never publish a partial cut graph
  and never let A2b proceed on an uncertified embedding.

##### 5.4 Construction guidance — explicit, because the implementation agent must not have to guess

The recommended construction is a **tree–cotree decomposition** (Eppstein; Erickson–Whittlesey), applied per
complementary component:

1. Compute the complementary components exactly as the existing producer already does at
   `GlobalTopologyPlan.cpp:1694-1704` — union faces across edges that are neither mandatory nor trace-touched.
   **Reuse that traversal rather than writing a second one**, so the two cannot diverge; if it must be moved to
   be shared, move it, do not copy it.
2. For each component, compute `χ` and its boundary-cycle count from the source mesh restricted to it. It is a
   disc **iff** `χ == 1` **and** boundary-cycle count `== 1`. Both conditions are required: an annulus has
   `χ == 0`, and a sphere-with-two-holes and a disc are distinguished only by the second.
3. For each non-disc component, build a spanning tree of its dual (face-adjacency) graph and a spanning tree of
   its primal graph; the edges in neither tree are the generators. Add the corresponding primal edges to the cut
   set. Each added generator strictly reduces the component's first Betti number, so the process terminates.
4. Re-verify from scratch. **Do not infer cellularity from the construction argument** — recompute `V`, `E`,
   `F` on the combined graph and check `V − E + F == χ(S)`, then check every component's disc certificate. The
   project's standing rule applies: an oracle built on the mechanism it tests is not yet a test.

Ties in generator selection must be broken by a **total order on typed IDs**, never by container order, never by
geometry, and never by a floating-point quantity.

##### 5.4.1 R5-REV corrective override — whole-source-face barrier components are not cellularity authority

**Status: binding correction recorded by `M3-CP4c-2-TB-X2-R5-REV`; exact redesign belongs to
`M3-CP4c-2-DEFN-R1`.**

R5 independently proved that §5.4 step 1's whole-source-face/source-edge-barrier construction is **not an exact
representation of the complement of `FieldAlignedCurveNetwork` when trace arcs cross source-face interiors**.
On the accepted two-ring witness, retained CP4ab fragment/orbit authority has three interior embedded-graph
faces while the source-edge-barrier proxy has two whole-face components. The proxy may be arithmetically
self-consistent and still describe a different complex.

Therefore, until DEFN-R1 freezes the replacement:

1. **§§5.1–5.3 remain binding.** `SurfaceCutGraph` must certify the actual immutable network plus its added cuts,
   preserve idempotence, determinism, and fail-closed behavior, and may not repair a produced A2b region.
2. **§5.4 step 1 is withdrawn as cellularity authority.** A whole-source-face `SourceFaceComponentPartition`
   separated by trace carrier edges may be used only as proposal/provenance/diagnostic data. It may not define
   the actual complement, its face count, or its per-component disc proof.
3. **§5.4 steps 2–4 are non-authoritative wherever they depend on that proxy representation.** Final `V/E/F`,
   boundary walks, and disc certificates must all be recomputed in one exact representation of the actual
   embedded `network ∪ cutEdges`.
4. **Do not repair this by changing only the Euler terms.** On the accepted two-ring, using proxy `10/11/2`
   would make the equation green while certifying the wrong object. The representation and every consumer of
   it must move together, per LESSONS 22d/22e.
5. **No product mutation is authorized by this note.** DEFN-R1 must first freeze a pre-region
   face-fragment/orbit (or equivalent exact arrangement) authority, candidate-cut update rule, termination proof,
   and independent same-semantic-complex oracle.

**A note on quality, and its limit for this checkpoint.** A cut graph is not unique, and the choice affects
downstream quad quality: cuts ideally follow the field and lie where a seam is least visible. **CP4c-2 does not
optimize that.** Its obligation is a correct, deterministic, certified cut graph. Choosing a *good* cut graph is
a quality concern, and the frozen requirement here is only that the interface make a future policy swap possible
— the selection rule must be one named, replaceable strategy, not scattered inline decisions. Do not build the
alternatives harness in this checkpoint.

#### 6. Scope — what CP4c-2 owns, and the C3 deferral

##### 6.1 In scope

- **C1** `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` — the torus derives regions
  through the production entry path. This is the checkpoint's anchor and its non-vacuity guarantee.
- **C6** `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` — produced regions
  carry the disc proof and preserve mandatory topology.
- `DESIGN.md` Amendment 12 and the `SurfaceCutGraph` product.

##### 6.2 A vacuity trap that must be closed

**C3 and C6 are both quantified over "produced witnesses."** Today no witness produces a plan, so **both would
pass vacuously** on a suite where nothing reaches A2b. That is the same defect class as CP4c-1's C5 — a
criterion whose truth value does not depend on the thing it is supposed to certify.

**Binding requirement:** CP4c-2 may not close on a vacuous C6. C1 is the non-vacuity anchor — the torus must
actually produce a plan with at least one region, and C6 must be shown to have examined at least that many
regions. Measure **X7** makes this reportable rather than assumed.

##### 6.3 Why C3 is deferred, and what would bring it back

**C3** `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` is currently failing on the
prescribed sphere with `RotationSystemInconsistent`. That failure is **not** the cut-graph gap:

- the sphere has `χ = 2`, 24 traces and 56 events — a network with real structure, unlike the torus;
- its failure code is different and is raised from a different part of A2b (many sites in
  `GlobalTopologyPlan.cpp`, including 412-564 and 790-839);
- nothing measured so far localizes it.

Designing a fix for an unmeasured failure is how CP4c-0 acquired a false premise once already. **The cause of
`RotationSystemInconsistent` on the sphere must be measured before it is designed for.** Bundling it into
CP4c-2 would repeat the CP4c-0 / CP4c-0b dependency inversion that cost this project a checkpoint split.

**Trigger to bring C3 back into CP4c-2:** if the CP4c-2 diagnostic required by measure **X2** shows that the
sphere's `RotationSystemInconsistent` is *caused by* non-cellularity — that is, it disappears once the sphere's
embedding is certified cellular — then C3 is in scope and CP4c-2's gate becomes **358 = 355 + C1 + C3 + C6**.
If X2 shows the sphere is already cellular and still fails, C3 belongs to its own checkpoint, and CP4c-2's gate
is **357 = 355 + C1 + C6**. **The selector count is not frozen by this document**; X2 decides it, and the CB
turn freezes it.

##### 6.4 Out of scope — do not touch

The mechanical witness and its A1 `IncompleteCycleBasis`; C2; CP4c-3; any change to accepted ordinals 1-355;
quad quality or seam aesthetics; the alternatives harness.

#### 7. Measures **X0–X9** for `M3-CP4c-2-CB1`

- **X0 — preconditions.** Start from accepted CP4c-1 authority: 355 selector `e9d88f11…5afeaa` with prefixes
  `601ce2b6…`, `20d3b0b1…`, `51ff96d7…`. Re-verify all four before and after; **all four must be byte-identical
  afterward.** Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX linked. `runtimeExecution=false`.
- **X1 — re-derive the theorem from the product, not from this document.** Publish the torus network's `V`, `E`
  and the source `χ`, and show `F = E − V + χ` is not a possible positive face count. **If the published
  numbers disagree with §3's `V = 48, E = 48`, stop and report** — that would mean this definition rests on a
  stale measurement, and it must be re-adjudicated rather than worked around.
- **X2 — the C3 scope decision, measured.** Publish, for the prescribed sphere, whether `network` alone is
  already a cellular embedding (`V − E + F == χ == 2`), and whether `RotationSystemInconsistent` still occurs
  once a certified cellular embedding is supplied. Report the exact failing site. This measurement, and only
  this measurement, decides whether the CP4c-2 gate is 357 or 358 per §6.3.
- **X3 — the product.** Implement `SurfaceCutGraph` to the §5 contract: single writer, source-edge cuts only,
  cellularity certificate, mandatory preservation, exact and deterministic, idempotent on already-cellular
  input, fail-closed. **It may not read a `GlobalTopologyPlan`.**
- **X4 — A2b consumes it.** Amend region derivation to consume the cut graph and to fail closed with a typed
  error on an uncertified embedding. **Do not** add any non-disc repair, region collapse, or re-cut inside A2b —
  that is the §4 stop condition and it is unchanged.
- **X5 — determinism proof.** Show the cut set is invariant to source face and edge ordering, and to container
  iteration order, by an identity that permutes input ordering and compares published cut sets exactly. A cut
  graph that depends on iteration order is not a product, it is a coincidence.
- **X6 — idempotence proof.** Show that a witness whose network is already cellular receives an **empty** cut
  set and a passing certificate.
- **X7 — non-vacuity, per §6.2.** Publish the torus's region count and the number of regions C6 actually
  examined. **A green C6 over zero regions is a red result**, and must be reported as such rather than counted.
- **X8 — documentation.** Apply Amendment 12 to `DESIGN.md` §7.2 and §4.6 exactly as §4 above states. Add the
  new stage to the pipeline stage list wherever A0-A9 are enumerated, so the stage map does not silently
  disagree with the code.
- **X9 — prohibited.** Editing any accepted identity or ordinal 1-355; changing the 355 selector or its
  prefixes; adding a non-disc repair, collapse, or re-cut in A2b; introducing any tolerance, threshold, or
  iteration cap that can change the cut set; inserting geometry, subdividing edges, or moving vertices;
  reading a `GlobalTopologyPlan` from A2a′; touching the mechanical witness, C2, or CP4c-3; optimizing seam
  quality; building the alternatives harness.

#### 8. Falsifiable predictions

Stated so the CB and its TB can prove this definition wrong rather than merely comply with it:

1. The torus network's published `V` and `E` are **48 and 48**, and the source `χ` is **0**. *(X1)*
2. The torus's non-disc complementary components are **annuli** — `χ == 0` with boundary-cycle count `== 2` —
   not higher-genus pieces. Anything else means the mandatory-edge set is not a disjoint union of cycles and §3's
   second argument needs revisiting.
3. **At least 2** cut edges are required for the torus, because a genus-1 surface needs two independent
   non-separating cuts to become a disc. Fewer means the certificate is wrong.
4. With cuts supplied, the torus produces a plan whose every region certificate has
   `eulerCharacteristic == 1` and `boundaryWalkCount == 1`, and C1 and C6 both go green **non-vacuously**.
5. The prescribed sphere's network is **already cellular** and its `RotationSystemInconsistent` persists —
   making C3 a separate defect and the gate **357**. *This is the prediction most likely to be wrong, and X2
   exists precisely to test it; if it is wrong, that is a good outcome and C3 rejoins CP4c-2 at 358.*

Any deviation from 1-4 is material and routes to review. A deviation from 5 changes the gate count and is
handled by §6.3 without a review, because X2 was designed to decide it.

#### 9. Defects recorded by this turn

1. **Dangling citation.** `Regression_Root_Cause_Tracker.md`'s `M3-CP4c1-TB-R4-CAND-03` entry cites
   `Architecture_M3_CP4c1_CB4_Code_Build_Report.md`, retired in the fifth consolidation. The substantive
   rationale is reproduced in the tracker entry itself, so nothing is lost; the pointer is corrected by this
   turn to name the consolidated record instead.
2. **`DESIGN.md` §7.2's "by construction" claim is false** on closed surfaces, and has been since the document
   was written. Amendment 12 corrects it. Recorded as a design defect, not a product regression: no code ever
   relied on the false claim — A2b fails closed instead, correctly.

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB1`**, Code + Build, runtime-free, under measures **X0-X9**.

Its successor is `M3-CP4c-2-TB`, the full gate at **357 or 358** as decided by X2. **CP4c-2 closes on that gate
green with §8's predictions 1-4 met and X7's non-vacuity report showing a non-zero region count.** Anything less
routes to independent review, not to a retry.

---

## Part II — M3-CP4c-2 DEFN-R1

*Source document: `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN-R1 — Frozen Definitions: the actual embedded-graph complex for A2a′

> **SUPERSEDED IN PART by `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` (2026-08-29). Never read this
> document alone.**
>
> - **§6 case 2 is withdrawn.** Amendment 14 makes a trace-crossed source edge an **admissible** cut. The stated
>   ground — that promoting one would subdivide an immutable trace — is false about this codebase: `build_arcs`
>   already emits one trace arc per network event and already splits a mandatory source edge at a trace terminal,
>   and the crossing point is already published exactly. §6 cases 1 and 3 stand.
> - **§8 is superseded.** Completeness is **proved** for all cases, not split: `network ∪ (source 1-skeleton)` is a
>   cellular embedding, so a sufficient cut set always exists. §8.2's typed stop
>   (`NoAdmissibleCutForNonDiscComponent`) is retired as an outcome, and §8.3's conditional trigger is void.
> - **§10 Option B is withdrawn**, its single trigger having been proved impossible; Option A stands and is now
>   unconditional.
> - **Everything else stands unchanged and binding** — Amendment 13, §§4, 5, 7, 9, and Amendment 12.
> - `DESIGN.md` §7.2.1 carries the normative record of Amendments 12, 13 and 14.

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN-R1` is **COMPLETE / DEFINITION-ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, fixture, or selector change was made
or is authorized by this turn. This document supersedes the withdrawn parts of
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` §5.4 and freezes the contract that `M3-CP4c-2-CB4` will
implement, under measures **AC0–AC9**.

**The decision.** The normative complex for A2a′ is the **actual embedded graph of
`FieldAlignedCurveNetwork ∪ cutEdges`**, represented by the **arc / dart / rotation / face-orbit machinery that
A2b already contains** — `GlobalTopologyArc`, `GlobalTopologyOrientedArc`, `GlobalTopologyNodeRotation`,
`walk_graph_faces` — lifted into a shared pre-region authority that A2a′ and A2b both consume. Nothing new is
invented; the correct representation already exists one stage downstream and is duplicated badly one stage up.

**Amendment 13** to `DESIGN.md` §7.2 records this. **Amendment 12 stands unchanged** — its precondition-versus-
repair boundary is unaffected and remains binding.

#### 1. A reviewer error, owned precisely

`M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` §5 declared the **source-mesh barrier complex** normative, on three stated
grounds. R5 has falsified it and the withdrawal is accepted in full. The failure is worth stating exactly,
because the same reasoning will be available to the next agent and must not be repeated.

I gave three reasons. Each was individually true and collectively wrong:

1. *"It is what A2b actually consumes"* — at `GlobalTopologyPlan.cpp:1694-1704`. **True, and irrelevant.** That
   code path is the *whole-source-face seeding fallback*, not A2b's region authority. A2b's actual region
   authority is `walk_graph_faces` over arcs and rotations, and it produces graph-face orbits. I read one
   traversal, matched it to the symptom, and never asked whether A2b had a second, primary representation.
2. *"The frozen DEFN §5.2 committed to source-edge-only cuts"* — **true, and a non-sequitur.** That cuts are
   drawn from source edges says nothing about which complex certifies them. A source edge added to the graph
   becomes an arc; it does not make whole source faces the unit of complement accounting.
3. *"In it, `V − E + F = χ` is a genuine identity"* — **true, and the trap.** The barrier complex is internally
   self-consistent. That is exactly why it was seductive and exactly why self-consistency is not evidence: a
   coherent computation over the wrong object is still the wrong object. R5 §6 states this correctly.

**The control that would have caught it existed and I did not apply it.** `LESSONS.md` **22d** — "check that
the product's representation can express the answer before debugging the algorithm that computes it" — and
**22e** — "converting a representation converts every consumer of it, or none" — were both written for
`PR8-R042 / M3-CP4b-R001`, the *same* `RP-01 / AUTHORITY_DOMAIN_CONFLATION` pattern, on the *same* two-ring
witness. 22d says in terms that a source face cannot be the atomic unit when trace arcs cross its interior.
Reading `LESSONS.md` in full is mandatory start-of-turn step 5. I did not consult it before freezing a
representation decision, and I froze the representation CP4ab had already rejected.

**Recorded for the next agent:** a review that names a normative representation must cite the accepted
architecture that settles it, not the code path that exhibits the symptom. Where an earlier checkpoint has
already adjudicated a representation, that adjudication is the authority.

#### 2. Independent verification of R5's arithmetic

Recomputed rather than accepted:

| Complex, accepted two-ring | `V` | `E` | `F` | `V − E + F` | source `χ` |
|---|---:|---:|---:|---:|---:|
| actual embedded graph (CP4ab authority) | 9 | 11 | 3 | **1** | 1 |
| source-edge-barrier proxy (R4 D1) | 10 | 11 | 2 | **1** | 1 |
| what `SurfaceCutGraph` actually computes | 9 | 11 | **2** | **0** | 1 |

Both complexes are self-consistent; the producer is a mixture of the two, and `0 ≠ 1` is precisely what
`proves_cellularity()` rejects at `SurfaceCutGraph.cpp:473-474`. R5's localization is confirmed.

The actual-graph `F = 3` is independently corroborated: retained CP4ab evidence records
`walk.orbits.size() = 4` with exactly one exterior orbit, and `drafts.size() = 3` — one draft per interior
orbit. **`F = 3` is a measured product quantity, not a reconstruction.**

#### 3. Amendment 13 — normative, supersedes DEFN §5.4 step 1

1. The complex in which A2a′ certifies cellularity is the **actual embedded graph** of the immutable
   `FieldAlignedCurveNetwork` together with the candidate `cutEdges`. Its vertices are network nodes plus any
   node created by a cut; its edges are network arcs plus cut arcs; its faces are the **dart orbits** of that
   graph under the node rotation system.
2. **Source-edge carrier provenance is not graph-edge authority.** A source edge that a trace merely crosses is
   support/provenance. It becomes a graph edge only when it is itself a mandatory edge or a selected cut edge.
3. The whole-source-face / source-edge-barrier partition is **withdrawn as cellularity authority**. It may be
   retained **only** as a cut-*proposal* heuristic and as diagnostic provenance, and every publication of it
   must carry an explicit label saying it is not a cellularity oracle.
4. `DEFN` §§5.1–5.3 — the product's position, single-writer authority, output shape and guarantees — remain
   **binding and unchanged**. §5.4's construction guidance is replaced by §§4–8 of this document.
5. **Amendment 12 is unaffected.** Establishing a precondition before a product is derived is still not
   repairing it afterward, and A2a′ still may not read a `GlobalTopologyPlan`.

#### 4. The representation, named concretely

The implementation agent must not invent a representation. **All four pieces exist today in
`src/geometry/GlobalTopologyPlan.cpp` and `include/directional/geometry/GlobalTopologyPlan.h`:**

| Concept | Existing type / function | Meaning |
|---|---|---|
| arc | `GlobalTopologyArc` — `id`, `kind`, `firstNode`, `secondNode`, optional `mandatoryEdge`, optional `trace` | one exact arc of the embedded graph |
| dart | `GlobalTopologyOrientedArc` — `arc` + `orientation` | one directed side of an arc |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` | the cyclic dart order at a node |
| face | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` | each orbit is one face boundary walk |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` | the CP4ab ownership unit: a source face split by the orbits crossing it |

**The corrective is a lift, not a rewrite.** A2a′ must consume this machinery rather than its own
`network_barriers` / `build_components` / `certify_component` triple. Move the arc-and-rotation construction and
`walk_graph_faces` into a shared pre-region authority — a new header under `src/geometry/` or an equivalent —
that both A2a′ and A2b include. **Do not copy it.** A second implementation is how this checkpoint arrived
here; `LESSONS.md` 22e requires one conversion covering every consumer.

#### 5. Conventions that must be made exact, not assumed

These are the places where a plausible guess produces a wrong certificate. Each must be **written down in the
CB report with the reasoning**, not inferred from a passing witness.

- **5.1 Boundary orbits on a surface with boundary.** The accepted two-ring is a disc, `χ = 1`, and its walk
  yields **4 orbits of which exactly one is exterior**; `F = 3` counts interior orbits only. Freeze the rule
  that identifies the exterior orbit(s) and excludes them, and state how it generalizes to a surface with
  several boundary loops. For a **closed** surface — torus, sphere — there is no exterior orbit and every
  orbit is a face.
- **5.2 Disconnected graphs.** The torus's network is 48 arcs over 48 nodes with every node of degree 2 —
  a disjoint union of closed curves, so the graph is **not connected**. The Euler identity for a cellular
  embedding assumes connectivity; with `c` components it acquires a correction term. **Derive that term
  explicitly, state it, and verify it on the torus.** Do not adopt `V − E + F = χ` unqualified: on the torus it
  is false even before any cut is considered, and mistaking that for non-cellularity would be right for the
  wrong reason.
- **5.3 Nodes of degree 0, 1 and 2.** The rotation system must be well defined at every node, including the
  degree-2 nodes that dominate the torus and any isolated node. State the convention.
- **5.4 What counts as `V` and `E` when a cut shares an endpoint with the network.** A cut edge whose endpoint
  is already a network node adds an arc but no vertex; one whose endpoint is a bare source vertex adds both.
  The existing producer already attempts this at `SurfaceCutGraph.cpp:449-456` and must be re-derived in the
  new complex rather than carried over.

#### 6. Cut semantics in the actual complex

This is the substantive new constraint, and it is where the previous design was silently unsound.

**A cut edge is a source edge promoted to a graph arc.** Adding it changes the arrangement. Three cases, and
all three must be handled explicitly:

1. **The source edge is untouched by any trace.** It becomes one arc between its two endpoints. Straightforward.
2. **The source edge is a carrier that a trace crosses at an interior point.** Promoting it creates an
   **intersection with an immutable trace arc**. That would subdivide the trace — mutating an immutable
   upstream product, which Amendment 12 forbids. **Such an edge is therefore not an admissible cut.**
3. **The source edge already is a mandatory edge.** It is already an arc; it cannot be "added" and must not be
   double-counted.

**Frozen rule: the admissible cut set is exactly those source edges that are neither mandatory edges nor
crossed by any trace at an interior point.** Admissibility must be decided exactly, from published trace
segment carriers, with no tolerance.

#### 7. Certification, in one complex

Both certificates are recomputed from the actual combined graph. **No proxy quantity may appear in either.**

- **Per-face:** every orbit that is not an excluded boundary orbit must bound a disc. Publish, per orbit, the
  evidence used.
- **Global:** the Euler identity in the form fixed by §5.2, over `V` = graph vertices, `E` = graph arcs,
  `F` = counted orbits, against source `χ`.
- **Provenance:** each certificate carries the digests already required by DEFN §5.2 plus a **complex label**
  naming the actual-embedded-graph complex, so a future reader can never again mistake which object was
  certified.

**Prohibited:** mixing any barrier-partition count into either certificate; relaxing `proves_cellularity()` to
accommodate a count; and — restating R5 §5, which is correct — changing the global certificate to the proxy's
`10/11/2`, which would make the two-ring green while certifying the wrong object.

#### 8. Cut-selection completeness — proved where it can be, typed stop where it cannot

Measure AB7 required a completeness proof or an explicit definition stop. **The honest answer is that
completeness is provable for one case and not yet for the other, and this definition freezes that split rather
than papering over it.**

- **8.1 Trace-free non-disc components — PROVABLE, and this is the torus.** Where no trace crosses the
  component, every source edge in it is admissible under §6, so a tree–cotree construction over the component's
  own primal and dual spanning trees yields generators whose promotion strictly reduces its first Betti number.
  The process terminates. **The torus is entirely in this case: it has 0 traces.** CP4c-2's own witness is
  therefore fully served.
- **8.2 Trace-crossed non-disc components — NOT PROVED.** With §6 removing every trace-crossed source edge from
  the admissible set, a component may have no admissible cut that reduces its genus. **No completeness claim is
  made.** The producer must, in that situation, **fail closed with a distinct typed error** — a new code such as
  `NoAdmissibleCutForNonDiscComponent`, carrying the component locus — and must never fall back to an
  inadmissible cut, a tolerance, or a partial cut set.
- **8.3 Why this is not a blocker in practice, and the condition on that claim.** The case in 8.2 arises only
  for a witness that is **both** non-cellular **and** trace-crossed. The torus is non-cellular and trace-free;
  the prescribed sphere is trace-dense and, on the standing prediction, already cellular and needing no cuts at
  all. **If the sphere turns out to be non-cellular, 8.2 becomes live and CP4c-2 must return to definition** —
  measure AC7 makes that an explicit stop rather than a surprise.

#### 9. The independent oracle

AB8's independence bar is raised and made concrete. The oracle must:

1. build arcs, rotations and orbits **by its own construction**, not by calling the shared authority of §4 and
   not by calling `SurfaceCutGraph`;
2. publish actual graph `V`, `E`, total orbits, excluded boundary orbits, counted `F`, component count `c`,
   the §5.2 identity and its result;
3. publish per-source-face fragment/orbit structure, so the CP4ab representation is directly visible;
4. publish cut provenance — for each cut, its admissibility class under §6;
5. compare **term by term** against the producer's published certificate and report each difference
   individually;
6. carry `complex=actualEmbeddedGraph` on every record.

**Explicitly insufficient, and named because it was accepted once already:** a different implementation over
the source-edge-barrier partition. Self-consistency inside the wrong complex is not independence.

The retained `sourceEdgeBarrier` oracle is **not deleted**. It is relabelled diagnostic-only, keeps
`complex=sourceEdgeBarrier`, and must carry a field stating it is not a cellularity oracle. It remains useful
for measuring the proposal heuristic.

#### 10. Sequencing, and the accepted regression

`PR8-R043 / M3-CP4c2-R001` — accepted ordinal 305 red — is the highest-priority item, and there are two ways to
clear it.

- **Option A — fix the certificate in the actual complex (RECOMMENDED).** Ordinal 305 fails because the
  certificate is wrong. Fixing it restores accepted behavior *and* delivers the checkpoint. The accepted
  identity is doing its job: it detected a real defect the moment CP4c-2 wired A2a′ into its path.
- **Option B — decouple A2a′ from the accepted path until the certificate is correct.** Cheaper and faster to
  green, but it restores the prefix by removing the check that caught the defect, and it re-opens the torus gap
  that CP4c-2 exists to close.

**Option A is frozen as the plan.** Option B is retained as a **contingency with one trigger**: if §8.2 goes
live — the sphere proves non-cellular and no admissible cut set exists — then CP4c-2 returns to definition, and
the accepted prefix must not be held hostage to that redesign. In that case, and only then, decoupling is
authorized so accepted authority is restored while the definition work proceeds.

#### 11. Measures **AC0–AC9** for `M3-CP4c-2-CB4`

- **AC0 — preconditions.** Accepted historical authority remains CP4c-1 **355/355**. Preserve all six frozen
  selector files and hashes: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355
  `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under `GMP_COMPILE_POLICY.md`
  with GMP/GMPXX; `runtimeExecution=false`. Keep `selected_r2_branch=NONE`, `selected_gate=NONE`,
  `gate_execution_authorized=false`.
- **AC1 — lift, do not duplicate.** Move the arc/rotation/face-walk construction of §4 into one shared
  pre-region authority consumed by **both** A2a′ and A2b. **A second implementation is prohibited** — that is
  `LESSONS.md` 22e. Report the exact file and symbol that now owns it and every call site converted.
- **AC2 — convert every consumer in one package.** A2a′'s per-face certificate, its global certificate,
  `GlobalTopologyPlan`'s consumption of the cut graph, and every diagnostic that reads either must move to the
  actual complex **together**. Enumerate them in the CB report and state, for each, that it was converted.
  **A partial conversion is the defect this checkpoint is correcting; it must not be the fix.**
- **AC3 — write the conventions down.** Publish §5.1–5.4's four conventions as prose plus code, with the
  derivation of §5.2's disconnected-graph correction term shown, not asserted.
- **AC4 — admissible cuts.** Implement §6 exactly: admissible = source edge that is neither a mandatory edge
  nor crossed by a trace at an interior point, decided exactly with no tolerance. Publish, per candidate cut,
  which class it fell into.
- **AC5 — the typed stop.** Add the §8.2 error code (`NoAdmissibleCutForNonDiscComponent` or an equally
  explicit name) with a component locus. **Never** fall back to an inadmissible cut, a tolerance, or a partial
  cut set. This code existing is not a failure of the design; it is the design refusing to certify what it
  cannot.
- **AC6 — derive the witnesses, never encode them.** The two-ring's `9 / 11 / 3 / χ=1` must fall out of the
  representation. **No witness-name branch, expected-value table, or constant.** If the representation cannot
  reproduce it without witness-specific logic, **stop and report** — §5's conventions are then wrong.
- **AC7 — the §8.2 trigger is a stop, not a judgement call.** If any witness reaches a non-disc component with
  no admissible cut, the CB **stops and returns to definition**. It does not widen admissibility, does not
  subdivide a trace, and does not proceed with a partial cut set.
- **AC8 — the oracle.** Implement §9's independent oracle as a **non-gating** identity, and relabel the
  retained `sourceEdgeBarrier` oracle diagnostic-only with the explicit not-a-cellularity-oracle field.
- **AC9 — prohibited.** Mixing any barrier-partition quantity into a cellularity certificate; relaxing
  `proves_cellularity()`; changing the global certificate to the proxy's `10/11/2`; subdividing or otherwise
  mutating an immutable trace; A2a′ reading a `GlobalTopologyPlan`; a second implementation of the arc/orbit
  machinery; encoding any witness's expected values; changing or inventing selectors; running a cumulative
  gate, R6, 357/358, `CB4`'s own acceptance, mechanical/C2, or CP4c-3; reverting AA1, whose innocence R5 §9
  establishes; and executing Option B of §10 outside its single stated trigger.

#### 12. Falsifiable predictions

1. Under the actual complex the accepted two-ring yields `V = 9`, `E = 11`, counted `F = 3`, identity result
   `1 = χ`, **derived from authority**. Accepted ordinal 305 returns green.
2. The torus yields `V = 48`, `E = 48`, `c = 4` connected components, and — under §5.2's corrected identity —
   **non-cellular**, matching the frozen theorem. Its four complement components are annuli.
3. Every torus cut candidate is **admissible** under §6, because the torus has zero traces; §8.1 applies and
   the cut selection terminates.
4. The prescribed sphere, once measurable, is **already cellular** in the actual complex, needs zero cuts, and
   `CellularityNotEstablished` disappears for it. *(This is the standing prediction from DEFN §8.5, the X2 plan,
   and R4 — still unadjudicated across six turns. It is the load-bearing uncertainty.)*
5. `NoAdmissibleCutForNonDiscComponent` is defined but **never fires** on any of the three witnesses.
6. No accepted identity other than 305 changes state.

Prediction 4 is the one that decides whether §8.2 goes live. Prediction 2's correction term is the one most
likely to be got wrong on the first attempt.

#### 13. Stop / successor

The exact next turn is **`M3-CP4c-2-CB4`**, Code + Build, runtime-free, under measures **AC0–AC9**.

Its successor is a fresh artifact-only **`M3-CP4c-2-TB-X2-R6`** — **not** a cumulative gate — which must re-prove
accepted prefixes 316/346/353/355 including ordinal 305, then publish the §9 oracle and the term-by-term
comparison, then attempt D2. `R5-ORCH-01` must be fixed in the runtime harness before R6: postflight must run
from an unconditional finalization or trap path so a red process cannot suppress it.

`selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, `gate_execution_authorized` remains
**false**.

---

## Part III — M3-CP4c-2 DEFN-R2

*Source document: `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN-R2 — Frozen Definitions: trace-crossed cut admissibility, and CP4c-2 gate membership

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN-R2` is **COMPLETE / DEFINITION AND PLANNING ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, or fixture change was made or is
authorized by this turn. One **selector authority file was created**, which is this turn type's proper output and
was explicitly deferred to it by measure **AF5**; no existing selector byte was modified.

This document supersedes `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` **§6 case 2** and **§8** only.
Everything else in DEFN-R1 — Amendment 13, §§4, 5, 7, 9 — **stands unchanged and remains binding**, as does
Amendment 12.

**Two decisions.**

1. **Amendment 14.** A source edge crossed by a trace at an interior point **is an admissible cut.** DEFN-R1 §6
   case 2 excluded it on the ground that promoting it would subdivide an immutable trace. That ground is
   **factually wrong about the product**: the producer already subdivides every trace into one arc per event, and
   already subdivides a mandatory source edge at a trace terminal. Arcs are a derived representation; the
   `FieldAlignedCurveNetwork` is untouched either way. With the exclusion removed, **cut-set completeness is
   proved outright** (§5) and DEFN-R1 §8.2's open case closes.
2. **AF5 gate membership is resolved per identity** (§7). Candidate **357 is superseded** and candidate **358 is
   withdrawn**; the CP4c-2 required-green gate is the newly frozen **selector 361**, whose 355- and 357-prefixes
   are byte-identical to the accepted and previously frozen authorities.

Measures issued here are **AG0–AG9**.

---

#### 1. Why DEFN-R1 §8.2 is live, stated exactly

DEFN-R1 §8.3 made the trace-crossed case conditional: *"The case in 8.2 arises only for a witness that is both
non-cellular and trace-crossed… the prescribed sphere is trace-dense and, on the standing prediction, already
cellular and needing no cuts at all. If the sphere turns out to be non-cellular, 8.2 becomes live."*

**The trigger has now fired on measured evidence.** `M3-CP4c-2-CB6` obeyed measure `AF1` — extract the sphere's
independent oracle row from retained result artifact `9721564203` before planning any new runtime — and read:

```
m3Cp4c2ActualGraphOracle  witness=prescribed-sphere  complex=actualEmbeddedGraph
V=18  E=30  F=18  c=1  chi=6  sourceChi=2  excludedBoundaryOrbits=0
surfaceCutGraphCallsInsideOracle=0     producerStatus=error / CellularityNotEstablished
```

`18 − 30 + 18 = 6 ≠ 2`. For any embedded graph `V − E + F ≥ χ`, with equality exactly when the embedding is
cellular, so **the prescribed sphere's pre-cut network graph is not a cellular embedding**, independently of the
producer. The standing prediction — carried unadjudicated since DEFN §8.5 — is **REFUTED**, and the sphere carries
24 traces. That is precisely DEFN-R1 §8.3's stated condition, so §8.2 is live on evidence rather than on an
argument about evidence, and CB6 correctly stopped before implementing anything.

**Two facts that must not be conflated, because they are both true.** R7-REV established that the *producer's*
`CellularityNotEstablished` is `topology_error`'s `default:` bucket for 36 distinct `GlobalTopologyPlanErrorCode`
values, raised at `SurfaceCutGraph.cpp:240/243` **with the cut set still empty** — upstream of any cut proposal and
upstream of any cellularity decision. CB6's oracle bypasses the producer entirely
(`surfaceCutGraphCallsInsideOracle=0`) and measures the graph directly. So the sphere has **two independent
problems**: a producer that fails early through a lossy error translation, *and* a network that genuinely needs
cuts. Neither finding weakens the other, and fixing one does not fix the other.

**A derived reading, offered as such and not as measurement.** The excess `6 − 2 = 4` is the standard defect term:
a sphere has no genus, so every non-disc complement component contributes one unit per boundary walk beyond its
first. Four excess units therefore indicate roughly four extra boundary circles — for example four annular
components, or one component with five boundary circles. **AG3 should verify this against the per-component
records rather than adopting it**; it is a prediction about what the cut search will face, not a result.

DEFN-R1 §8.3 also carried a second cost that only became visible once the trigger fired: it made the checkpoint's
**contingency** (§10 Option B, decoupling A2a′ from the accepted path) fire on the same condition. A contract and
its rollback plan hinging on one fact is a single point of failure. DEFN-R2 therefore resolves the contract
**unconditionally**, so that no further measurement of any witness can reopen the definition.

**What this turn does not claim.** It does not solve the sphere's *producer* failure. That failure occurs with zero
cuts, before cut selection runs at all, and nothing in Amendment 14 touches that path. `AF0`'s printed code remains
the prerequisite for any product fix there, and DEFN-R2 changes neither `M3-CP4c2-TB-X2-CAND-04` nor its ownership.
What DEFN-R2 does supply is the contract under which the sphere's *measured* non-cellularity can be resolved once
the producer reaches cut selection at all — and §5 proves a sufficient cut set exists for it.

---

#### 2. The finding that resolves the contract

DEFN-R1 §6 case 2 reads:

> *"The source edge is a carrier that a trace crosses at an interior point. Promoting it creates an intersection
> with an immutable trace arc. That would subdivide the trace — mutating an immutable upstream product, which
> Amendment 12 forbids. Such an edge is therefore not an admissible cut."*

Three verified facts falsify the premise. All are in `src/geometry/EmbeddedGraphTopology.cpp`, at source bytes
identical to the packaged semantic source `755485865a7cf9c485d754f22b82a41ee151824b`.

**2.1 There is no "immutable trace arc". A trace is already many arcs.** `build_arcs` (`:344-408`) collects, for
each trace, every network event incident on it, keyed by **segment position**, then emits one `Trace` arc per
consecutive pair. A trace with `k` interior events becomes `k + 1` arcs, each carrying `trace.id`, `firstSegment`,
`onePastLastSegment` and its own `sourceFaces` span. **Subdividing a trace in the derived arrangement is the
established, accepted representation**, and it is how the accepted 355 gate has been green for the whole arc.

**2.2 The producer already subdivides a source edge at a trace contact.** `build_arcs` (`:281-329`) splits a
`Mandatory` source edge into `ArcDraft(firstNode, terminal)` and `ArcDraft(terminal, secondNode)` when a trace
terminates on it. One `NetworkEdgeId`, two arcs, a shared node interior to the source edge. The immutable
mandatory edge is unchanged; only the arrangement has two arcs.

**2.3 The crossing point is already published exactly, and already indexed.** A
`FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:246-269`) is one source-face
traversal carrying `incomingCarrier`, `outgoingCarrier`, and an exact `entryPoint` of type
`authority::FieldBoundaryPoint`. Segment `i`'s exit through its outgoing carrier **is** segment `i+1`'s entry, at
`segments[i+1].entryPoint` — an exact point on that source edge, with no tolerance. `trace_crossed_source_edges`
(`SurfaceCutGraph.cpp:78-120`) already reads exactly these points and already tests strict interiority exactly
(`exact_interior_parameter`).

**Conclusion.** A trace crossing a source edge is a point that the network itself publishes exactly, at a segment
boundary the arc-subdivision machinery already keys on. Promoting that edge requires no new geometry, no
tolerance, no predicate, and no mutation of any upstream product. Amendment 12 forbids A2a′ **repairing** an
upstream product; it does not forbid A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**The reviewer error this repeats, named so it is not repeated a third time.** DEFN-R1 §6 reasoned from a property
of the *product* ("the trace is immutable") to a constraint on the *representation* ("therefore it cannot be
subdivided"), without checking what the representation already did. That is the same shape as the R2 error owned in
DEFN-R1 §1 — a true statement about one authority applied to a different one. The control is `LESSONS.md` 22e:
before ruling a representation out, read what the existing consumers of that representation actually do.

---

#### 3. Amendment 14 — normative, supersedes DEFN-R1 §6 case 2 and §8

Recorded against `DESIGN.md` §7.2 alongside Amendments 12 and 13.

1. **A source edge crossed by one or more traces at interior points is an admissible cut.** Promoting it adds one
   graph arc per sub-interval between consecutive crossing points, and one graph node per crossing point.
2. **Crossing nodes are cut-created nodes.** Amendment 13 §1 already defines the vertex set as "network nodes plus
   any node created by a cut". A crossing node is such a node. It is **not** a network node, carries no
   `NetworkEdgeId` or event, and must never be published back into the `FieldAlignedCurveNetwork`.
3. **The trace is subdivided in the arrangement, not in the product.** The trace arc spanning the crossing is split
   at the same segment position the crossing occupies. `trace.id`, its segments, its events and its digests are
   unchanged. This is exactly what §2.1 shows the producer already does at every event.
4. **The admissible cut set is exactly those source edges that are not already graph arcs** — that is, every source
   edge that is neither a mandatory edge nor an already-selected cut. `SurfaceCutCandidateClass::TraceInteriorCrossing`
   is **retained as published provenance** and **removed as an exclusion**: it now records *how* an edge was
   promoted, not *whether* it may be.
5. **All admissibility and ordering decisions remain exact.** Crossing positions come from published
   `FieldBoundaryPoint` parameters; interiority uses the existing exact predicate; ordering along an edge uses
   exact comparison. **No tolerance may be introduced anywhere in this path**, and no crossing may be inferred from
   geometry rather than read from the network.
6. **DEFN-R1 §6 cases 1 and 3 stand unchanged.** An untouched source edge becomes one arc; a source edge that is
   already a mandatory edge is already an arc and must not be double-counted.
7. **DEFN-R1 §§4, 5, 7 and 9 stand unchanged.** The complex, the four conventions, the certification rules and the
   independent-oracle bar are unaffected. The oracle must now additionally reconstruct crossing nodes by its own
   construction (§9 measure **AG6**).

---

#### 4. What must actually be built, itemized

This is the real cost of Amendment 14. It is bounded, and every piece has an existing template in the codebase.
**None of it may be invented where a template exists** — `LESSONS.md` 22e.

**4.1 An edge-interior synthetic node kind.** `CutNodeBindings`
(`src/geometry/EmbeddedGraphTopology.h:44-48`) today maps `SourceVertexId → NetworkNodeId` plus a reverse map and a
`combinedNodeExtent`. It must gain a second synthetic-node kind keyed by the crossing's exact identity. **The key
must be semantic, not positional:** the crossing of trace `t` at segment position `p` on source edge `e` is
identified by `(SourceEdgeTopologyKey e, TraceId t, std::size_t p)`. Two traces crossing the same edge at the same
exact parameter is a distinct case and must be rejected with a typed error, not merged — coincident crossings are
a network-level fact A2a′ has no authority to adjudicate.

**4.2 Exact ordering along a promoted edge.** Multiple traces may cross one source edge. The promoted edge becomes
`n + 1` arcs for `n` crossings, and they must be emitted in order along the edge. **Freeze the orientation
convention**: order by the `FieldBoundaryPoint` parameter measured along the canonical
`SourceEdgeTopologyKey::first() → second()` direction, compared exactly. State the convention in the CB report with
its derivation; do not infer it from a passing witness.

**4.3 Trace-arc subdivision at crossings.** `build_arcs` builds each trace's `TraceCut` set exclusively from
`network.events()` (`:357-378`). It must additionally admit crossing cuts, at the segment position of the crossing,
bound to the §4.1 synthetic node. The existing `cuts.emplace(position, node)` structure already expresses this;
what changes is the source of the entries, and the conflict check (`inserted.first->second != event.node`) must be
extended to cover an event and a crossing claiming the same position.

**4.4 The degree-four edge-locus rotation — the one genuine gap.** At an edge-locus node,
`build_rotation_system` (`:833-935`) handles exactly two arc kinds: `Mandatory`, gated by
`mandatoryRayCount == 2 && outgoing.size() == 3`, and everything else, which is **required** to be a `Trace`
(`if (!arc.trace.has_value()) → RotationSystemInconsistent`). **A `Cut` arc incident to an edge-locus node is an
unhandled shape today**, and a crossing node is exactly that: two collinear `Cut` rays plus two `Trace` rays,
degree four.

The template is already there and is the correct one. The mandatory branch uses a four-sector cyclic model around
the canonical edge direction: `key.primary = towardSecond ? 0 : 2` for the two collinear rays, with trace rays
placed in the complementary odd sectors by the `sideRank` of the source face they enter (`:846-855`). The extension
is to admit `Cut` rays into the collinear slots on the same rule, by the same
`mandatory_ray_points_to_second_endpoint` logic (`EmbeddedGraphTopology.cpp:651`, called at `:897`) generalized to a
cut arc's endpoints. **Generalize that function; do not write a second one.**

Note also `LESSONS.md` 53: the existing degree-three edge-locus rotation was written for a trace ending inside a
mandatory edge and *has never once executed*. Extending unexecuted code is not a reason to rewrite it, but it **is**
a reason to require an identity that executes both the degree-three and the degree-four shape (§7.4).

**4.5 The proposal layer must stop excluding trace-crossed edges.** Two places, both in
`src/geometry/SurfaceCutGraph.cpp:324-326`: `barriers` is built as `mandatory ∪ traceCrossed ∪ cuts`, and proposed
edges are filtered by `if (mandatory.count(edge) || traceCrossed.count(edge)) continue;`. Under Amendment 14 the
filter is simply wrong — it removes exactly the edges that are now admissible, and it is the mechanism by which a
false `NoAdmissibleCutForNonDiscComponent` would be produced.

The `barriers` set is a subtler matter and must be reasoned about, not patched. A trace crossing source edge `e`
does **not** separate `e`'s two incident triangles — the trace passes through both. Treating `e` as a barrier is a
**conservative over-approximation** that over-separates the proposal partition. Because the authoritative verdict
is always the actual-complex certificate (Amendment 13 §3: the barrier partition is a proposal heuristic and
diagnostic provenance only), over-separation costs extra cuts, never correctness. **CB may keep the conservative
`barriers` set, but must state that it is conservative and publish the resulting over-separation count**; it may not
keep the proposal *filter*.

---

#### 5. Cut-set completeness — PROVED

DEFN-R1 §8 split completeness into a provable trace-free case and an unproved trace-crossed case. With Amendment 14
the split disappears.

**5.1 Theorem (cellularity of the saturated graph).** Let `S` be the source surface with triangulation `M` and
1-skeleton `M¹`, and let `N` be the embedded arc set of the `FieldAlignedCurveNetwork`. Then `N ∪ M¹` is a
cellular embedding in `S`.

*Proof.* The complement of `M¹` in `S` is the disjoint union of the open source triangles, each an open disc.
Fix one triangle `T`. The arcs of `N` meeting `T`'s interior are trace sub-arcs. Each such arc has both endpoints
on the already-cut structure of `T`: a crossing point on `∂T` (a carrier edge, by the definition of
`incomingCarrier` / `outgoingCarrier`), a corner of `T` at a singularity port, or a node interior to `T` lying on
another trace sub-arc that itself reaches `∂T`. Cutting an open disc along a finite family of embedded arcs whose
endpoints lie on the boundary or on previously added arcs yields open discs. Hence every complement component of
`N ∪ M¹` is an open disc. ∎

**5.2 The two conditions, stated rather than assumed.** The proof needs (a) every trace sub-arc's endpoints attach
to the boundary or to already-attached structure, and (b) no node of the graph has degree 0. Both are properties
the producer already enforces or can check: crash-on-contact termination gives (a) — every trace ends at a
singularity, a mandatory barrier, or another trace — and `build_rotation_system` already rejects degree 0 outright
(`:737-741`). **AG3 requires both to be verified and published, not assumed.** A trace terminating at an
unattached interior point would leave a slit rather than a subdivision; a slit disc still satisfies
`boundaryWalkCount == 1` and `χ == 1`, so it is admitted, but it must be *observed* if it occurs.

**5.3 Corollary (existence and termination bound).** For any cut set `C ⊆ M¹`, `N ∪ C` can always be extended to a
cellular embedding by promoting further source edges, since promoting all of them yields `N ∪ M¹`, cellular by
§5.1. **A sufficient cut set therefore always exists, and at most `|E(M)|` promotions are ever required.**
DEFN-R1 §8.2's open case is closed.

**5.4 What the theorem does not give, and the error-code split it forces.** §5.3 proves a cut set *exists*. It does
not prove the greedy tree–cotree proposal *finds* one. These are different failures and the current single code
`NoAdmissibleCutForNonDiscComponent` conflates them — which is precisely the `LESSONS.md` 57 defect this
checkpoint just paid eight turns for. Frozen:

- **`NoAdmissibleCutForNonDiscComponent` is retired as a possible outcome.** Under Amendment 14 it can only fire
  when every source edge of a non-disc component is already a graph arc, and §5.1 shows that configuration is
  cellular. If it fires, the producer's own admissibility classification disagrees with the theorem — a **defect**,
  and it must be reported as one under a distinct code, not as a definition gap.
- **`CutSearchExhaustedBeforeCellularity` (new, name may be improved but must be equally explicit)** is the honest
  code for "the proposal heuristic made no progress". It carries the component locus and the counts.
- **Saturation is the defined last resort, and it is reported, never silent.** On search exhaustion the producer
  promotes the remaining admissible source edges of the offending component and re-certifies. §5.1 guarantees this
  succeeds. It **must** publish `saturationUsed=true` with the component locus and the number of edges promoted.
  A2a′ does not assign a disposition — A8 does — so this is a published fact, not a self-declared degradation.
- **Saturation firing on any of the three witnesses is a red flag, not an outcome.** AG4 predicts it never fires;
  if it does, the proposal heuristic is inadequate and that is a finding to report, not to absorb.

**5.5 DEFN-R1 §10's contingency loses its trigger.** Option B — decoupling A2a′ from the accepted path — was
retained with exactly one trigger: "if §8.2 goes live — the sphere proves non-cellular and no admissible cut set
exists". §5.3 proves the second clause can never hold. **Option B is therefore withdrawn**, and the accepted path
stays wired to A2a′. This is a strengthening: the accepted 355 keeps its detector, which is what caught `PR8-R043`
in the first place. Nothing else in DEFN-R1 §10 changes; Option A remains the plan and is now unconditional.

---

#### 6. Prohibited — things that will look like solutions

- **Introducing any tolerance** into crossing detection, interiority, or ordering along an edge. Every quantity in
  this path is published exactly by the network. An epsilon here is a design defect, not a tuning problem.
- **Inferring a crossing from geometry** rather than reading it from `segments[i].entryPoint` /
  `edgeTransitExit` / `terminalPoint`. A recomputed intersection is a second authority for a datum the network
  already owns — `RP-01`.
- **Publishing a crossing node back into `FieldAlignedCurveNetwork`**, or altering any trace's segments, events, or
  digests. Amendment 12 stands.
- **Writing a second rotation-ordering routine** for degree four instead of generalizing the existing edge-locus
  four-sector model. A second implementation is how this checkpoint arrived here.
- **Merging two coincident crossings** on one edge instead of rejecting them with a typed error.
- **Keeping `NoAdmissibleCutForNonDiscComponent` as a live outcome** with its current meaning, or letting
  saturation fire silently.
- **Relaxing `proves_cellularity()`**, mixing any barrier-partition quantity into a certificate, or changing the
  global certificate to the proxy's `10/11/2`. DEFN-R1 §7 and AC9 stand in full.
- **Treating Amendment 14 as an explanation of the prescribed sphere's failure.** The sphere fails with zero cuts,
  upstream of every line of this. Conflating them would be exactly the mistake §1 exists to prevent.

---

#### 7. AF5 — gate membership, decided per identity

The `AF5` hole was that **no `SurfaceCutGraph.*` identity appeared in the accepted 355, in candidate 357, or in
candidate 358** — CP4c-2 would have accepted a new pipeline stage while requiring none of that stage's own
witnesses. This section closes it. "It was never added" is not a rationale, and neither is "it passes today".

##### 7.1 The four existing A2a′ identities

| identity | contract it holds | decision | rationale |
|---|---|---|---|
| `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` | **idempotence** — an already-cellular network receives zero cuts, and the certificate carries `complex = ActualEmbeddedGraph` with one face and one boundary walk | **GATING** | It is CP4c-2's most basic contract and the only identity asserting the complex *label* Amendment 13 §3 requires. Its witness is `make_square_mesh` — planar, 4 vertices, 2 faces, no interior vertex — so its zero-transport atlas lift is trivially integral and it carries none of the risk in §7.2. |
| `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` | **representation-independent identity** under source face/edge reordering | **GATING** | It is the **only** falsifier of live measure `AD3`, which currently defends hashing the raw `face.orbit` index into a *semantic* digest with a comment rather than a test. `RP-05` is a stable regression pattern with two prior events; leaving its guard ungated is not acceptable. Enters the gate red until `AF3`/`AF4` give it a viable witness. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` | **semantic/provenance separation at the A2a′ boundary** | **GATING** | This is what measure `AD5` was for: check the split where it lives, not two stages downstream at ordinal 310. Green in R7-2. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` | the same contract on a **closed genus-1** witness | **GATING** | `PR8-R044` is runtime-proved on one witness only. A closed-surface witness is not redundant with a disc. Enters the gate red until `AF3` rebuilds it on the production `torus.rawfield` authority. |

**Two of the four enter the gate red. That is correct.** A required-green selector states what must be true for the
checkpoint to close; it is not a record of what happens to pass today. `gate_execution_authorized` remains `false`,
so nothing is executed on this basis yet.

##### 7.2 Candidate 357 — superseded

357 = accepted 355 + `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` +
`GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`. Both identities are correct, both
bind the torus through the production entry path, and both are **retained**. 357 is superseded only because it is
incomplete, not because anything in it is wrong. Its 357 bytes are a byte-exact prefix of the new gate.

##### 7.3 Candidate 358 — withdrawn

358's sole addition is `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, which binds the
torus **and** `cp4c_mechanical_fixture()`. `build_cp4c_production_fixture` throws when the pipeline did not retain
atlas/network/cut-graph/plan, and the mechanical witness has no atlas — it stops in A1 at `IncompleteCycleBasis`
and is explicitly owned by CP4c-3 / C2. **A gate may not bind a witness its own checkpoint declares out of scope.**

358 is withdrawn as a gate candidate. Its file is retained as historical authority and must not be deleted.

**Criterion C3 is not withdrawn with it.** Rotation-system / face-walk agreement is a real CP4c-2 criterion and has
now been deferred six times. §7.4 splits it so the in-scope half enters the gate and the out-of-scope half moves to
the checkpoint that owns it.

##### 7.4 New identities that must be created and appended

These do not exist yet, so they are not in the frozen selector below. **AG7 makes their append mandatory and
named**, rather than leaving them to be silently omitted the way the four in §7.1 were.

| identity to create | contract | owner |
|---|---|---|
| `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` | criterion **C3**, torus half only — the mechanical half moves to CP4c-3 / C2 | CB6 |
| `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` | Amendment 14 §§3.1–3.3: promotion yields `n+1` cut arcs and `n` crossing nodes, trace arcs split at the same segment positions, network digests unchanged | CB7 |
| `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour` | §4.4: the four-sector edge-locus rotation admits `Cut` rays; **must execute the degree-three shape too**, which `LESSONS.md` 53 records has never run | CB7 |
| `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted` | §5.4: saturation terminates in cellularity and publishes `saturationUsed` with locus and count | CB7 |

The resulting gate is **365**. Its bytes are frozen by the turn that creates the identities, under AG7.

##### 7.5 The frozen CP4c-2 gate — selector 361

Created this turn as `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_361.txt`. It is candidate
357 with the four §7.1 identities appended in the order listed.

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 355 <file> \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| candidate 357 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 357 <file> \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| **CP4c-2 gate 361** | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | whole file: `sha256sum <file>` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |

Verified at authoring, per `AE4` and `AE5`: every value is exactly 64 lowercase hex; each was **computed from the
committed bytes**, not transcribed; the 355-prefix hash equals the accepted authority in `ORIENTATION.md` §3 and the
357-prefix hash equals the previously frozen candidate 357, so **prefix comparability of `first_red_ordinal` across
the whole CP4c arc is preserved**. All 361 lines are unique, and each of the four appended identities resolves to
exactly one `TEST(...)` definition in `tests/FieldAlignedCurveNetworkTests.cpp`.

`selected_gate` remains **NONE** and `gate_execution_authorized` remains **false**. Freezing a gate's bytes is not
selecting it; selection happens at a TB with an explicit authorization.

---

#### 8. Falsifiable predictions

1. Every source edge in the torus is admissible under Amendment 14 — the torus has zero traces, so §4.1–§4.4 add
   **no** crossing nodes there, and the torus's `V/E/F = 72/76/4`, `χ = 0` is **unchanged** by this amendment.
2. The two-ring's actual embedded graph `9 / 11 / 3`, `χ = 1` is likewise unchanged; it has three traces but no
   promoted trace-crossed cut, because it is already cellular and receives zero cuts.
3. Amendment 14 changes no accepted identity's result. If any ordinal in the accepted 355 moves, the change was not
   confined to the arrangement and must stop.
4. `NoAdmissibleCutForNonDiscComponent` never fires again on any witness, because under §5.3 the configuration it
   reports cannot exist.
5. `CutSetSaturationProvesCellularityWhenSearchIsExhausted`'s `saturationUsed` is **false** on all three witnesses.
   If it is true anywhere, the tree–cotree proposal is inadequate and that is a finding.
6. **The prescribed sphere will require cuts, and at least one will be trace-crossed.** CB6 measured its pre-cut
   graph non-cellular with excess 4 and it carries 24 traces over a mesh with zero mandatory edges, so the cut
   search has no trace-free source edges to prefer. This is the production witness Amendment 14 exists for.
7. **It is nevertheless not yet reachable**, because the sphere's producer fails at `SurfaceCutGraph.cpp:240/243`
   before cut selection. So the degree-four edge-locus rotation is first exercised only by a **constructed**
   witness — the torus promotes cuts but has zero traces, and the two-ring needs none. **AG5 therefore requires a
   purpose-built witness even though the sphere is the eventual real one**; without it the amendment can ship
   unexecuted, which is the `AF5` failure repeating one level down.
8. The excess-4 reading of §1 resolves into per-component records showing roughly four extra boundary circles. If
   the components instead show something else, §1's derived reading was wrong and only the reading — not the
   non-cellularity, and not Amendment 14 — is affected.

Prediction 7 is the load-bearing one. Prediction 3 is the one that must be checked first and hardest.

---

#### 9. Measures **AG0–AG9**

**AG0 — selector and gate authority.** The CP4c-2 required-green gate is **361**, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, with 355- and 357-prefix hashes as in §7.5.
Candidate 357 is superseded and candidate 358 is withdrawn; **both files are retained** as historical authority and
must not be deleted. Recompute all three 361 values from committed bytes at every preflight; never transcribe.
`selected_gate=NONE`, `gate_execution_authorized=false`, `selected_r2_branch=NONE` remain unchanged.

**AG1 — implement Amendment 14 as one conversion.** §4.1 through §4.5 land **together**. A partial conversion —
crossing nodes without the rotation extension, or the proposal filter removed without the arc subdivision — is the
defect this checkpoint has already corrected twice. Enumerate every touched site in the CB report and state, for
each, that it was converted.

**AG2 — generalize, do not duplicate.** The degree-four edge-locus rotation extends the existing four-sector model
and generalizes `mandatory_ray_points_to_second_endpoint` to cut arcs. A second ordering routine is prohibited.
Report the exact symbol that now owns it and every call site.

**AG3 — publish the theorem's conditions, and the sphere's component structure.** Verify and publish, per witness: that every trace sub-arc's endpoints
attach to the boundary or to already-attached structure, and that no graph node has degree 0. State §5.1's proof
and §4.2's edge-orientation convention as prose plus code, with derivations shown, not asserted. Additionally
publish the prescribed sphere's per-component records behind its `chi=6` excess and check them against §1's derived
excess-4 reading, adopting or refuting it explicitly.

**AG4 — the error-code split.** Replace `NoAdmissibleCutForNonDiscComponent`'s meaning per §5.4: add
`CutSearchExhaustedBeforeCellularity` with component locus and counts, implement saturation as the defined last
resort, and publish `saturationUsed`, its locus, and the promoted-edge count on every run. Saturation may never be
silent. **Verified in this review: `NoAdmissibleCutForNonDiscComponent` is consumed by no test in the repository**
— its only occurrences are the raise site (`SurfaceCutGraph.cpp:326`), the name function (`:339`) and the enum
declaration (`SurfaceCutGraph.h:86`) — so no accepted identity depends on it and the enum value may be repurposed
or retired freely. Re-verify before editing rather than trusting this line.

**AG5 — a witness that actually exercises the crossing.** Predictions 6-7: the prescribed sphere is the eventual
real witness but is unreachable behind its producer failure, and no *reachable* committed witness promotes a
trace-crossed edge. Construct one — a small closed or bounded fixture with a trace crossing a source edge that a
tree–cotree cut must promote — and assert its precondition **at runtime inside the fixture**, in the CP3a style
`LESSONS.md` §2 requires. Without this, Amendment 14 ships unexecuted.

**AG6 — extend the independent oracle.** DEFN-R1 §9 stands, plus: the oracle reconstructs crossing nodes by its own
construction and publishes, per promoted edge, its crossing count and the resulting arc count, compared term by
term against the producer.

**AG7 — the four new identities enter the gate, by name.** §7.4's four identities are created and **appended** to
selector 361 in the listed order, producing gate **365**. The turn that creates them recomputes and records the
365 whole-file hash and re-verifies the 355 / 357 / 361 prefix hashes. Omitting any of them requires an explicit
written rationale in that turn's report — silence is not a decision.

**AG8 — sequencing, and the one condition under which it collapses.** `M3-CP4c-2-CB6` under **AF0–AF4** remains the
exact next turn and is **not** widened by this document. Reason: AF0 makes the sphere's collapsed error readable and
AF1 may change what is needed, and building Amendment 14 on an unreadable failure is how R2 went wrong. AG1–AG6
belong to **`M3-CP4c-2-CB7`**. **Single merge condition:** if AF0's printed code localizes the sphere's
`RotationSystemInconsistent` to `build_rotation_system`'s edge-locus branch (`EmbeddedGraphTopology.cpp:833-935`),
then it and §4.4 are the same code and CB6 may absorb AG2 — and only AG2. Any other locus keeps the split.

**AG9 — prohibited.** Everything in §6, plus: changing any byte of selectors 316/346/353/355/357/358; changing
selector 361 other than by the AG7 append; selecting a gate or setting `gate_execution_authorized=true`; executing
any gate, cumulative gate, or benchmark; reverting AA1; executing DEFN-R1 §10 Option B, whose trigger §5.5
withdraws; treating Amendment 14 as an account of the sphere's failure; and compiling without GMP/GMPXX per
`GMP_COMPILE_POLICY.md`.

---

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB6`**, Code + Build, runtime-free, under **AF0–AF4** with the **AF9**
prohibitions — unchanged by this document except for AG8's single merge condition. Its successor TB carries
**AF6**, **AF7** and **AF8**. `M3-CP4c-2-CB7` then implements Amendment 14 under **AG1–AG6**, and the turn that
creates §7.4's identities carries **AG7**.

CP4c-2's required-green gate is **selector 361**, frozen. `selected_r2_branch` remains **NONE**, `selected_gate`
remains **NONE**, `gate_execution_authorized` remains **false**. CP4c-2 is open and runtime-unaccepted; CP4c-3
remains blocked.

---

## Part IV — M3-CP4c-3 DEFN

*Source document: `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN — Frozen Definitions, Review and Plan

#### 0. Turn type and verdict

`M3-CP4c-3-DEFN` is **COMPLETE / DEFINITION + REVIEW/PLAN, COMBINED**.

No Directional runtime, build, compile, package, benchmark, product, test or fixture change was made or is
authorized. One **selector authority file was created** — this turn type's proper output — and no existing selector
byte was modified.

**Cadence change, by user authorization (2026-08-30):** *"combine DEFN step with REVIEW/PLAN step going forward when
DEFN is the next step in the chain."* From this turn on, a `DEFN` turn **is** the review-and-plan turn for its
checkpoint: it freezes definitions, adjudicates inherited candidates, decides gate membership, and issues the
successor's measures in one turn. A separate `REVIEW/PLAN` turn is no longer scheduled ahead of a `DEFN`. The
existing `CB → TB → green? → close / red → REVIEW+PLAN → CB` cadence is otherwise unchanged, and this collapses only
the `REVIEW+PLAN → DEFN` edge. Recorded additively in the durable turn-workflow sections of `TODO.md` and
`Future_Chat_Session_Handoff.md`.

**Four decisions.**

1. **`IncompleteCycleBasis` is a seven-way collapse** (§3), and no evidence has ever identified which of its seven
   conditions the mechanical witness hits. That is `LESSONS.md` 57 recurring in A1, and the checkpoint must
   instrument before it designs.
2. **The prescribed sphere is IN CP4c-3's gate** (§4), after two checkpoints outside one.
3. **CP4c-3 runs in two phases** (§5) with one frozen gate, **selector 367** (§6), extended by append.
4. Measures **AK0–AK9** are issued for `M3-CP4c-3-CB1`.

Amendments 12, 13 and 14 are **unchanged and remain binding**. Accepted selector 365 is unchanged.

---

#### 1. What CP4c-3 owns

**Parent responsibility** (`ROADMAP.md` §1): the closed-surface missing field-transport adjacency in A1, then the
mechanical witness — criterion **C2**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`.

**Inherited from CP4c-2** by R10-REV measure AJ9:

| record | substance |
|---|---|
| `M3-CP4c2-TB-X2-CAND-04` | the prescribed sphere: (a) producer `RotationSystemInconsistent` at source face `25-27-28`, `producerCutEdgeCount=0`, **before** cut selection; (b) independently, a non-cellular pre-cut graph `V/E/F = 18/30/18`, `χ=6` vs `sourceChi=2` |
| `M3-CP4c2-TB-X2-R10-CAND-01` | Amendment 14's **ordinary** trace-crossed proposal path is structurally unreachable; only saturation promotes such an edge |
| `M3-CP4c2-TB-X2-R8-CAND-02` | zero-node / zero-arc closed-surface cut-graph behaviour is undefined |

**Not CP4c-3's:** the torus post-A2b `tracing` failure (downstream of A2b, tracked separately), and anything from
A3 onward.

---

#### 2. Review of the inherited items

##### 2.1 `R10-CAND-01` — cause established, corrective is narrow and heuristic-only

R10-REV localized this fully and the mechanism is in the committed loop:

```cpp
barriers   = mandatory ∪ traceCrossed ∪ cuts;
components = proposal_components(topology, barriers);
proposed   = proposal_tree_cotree_cut_edges(topology, component, barriers);
for (edge : proposed) { if (mandatory.count(edge)) continue;  cuts.insert(edge); }
```

DEFN-R2 §4.5's **filter** was correctly removed — only `mandatory` is skipped. The **barrier set** still contains
`traceCrossed`, so a trace-crossed edge *bounds* a proposal component instead of lying inside one, and a
tree–cotree generator search draws from a component's interior edges. The ordinary path therefore has no
trace-crossed edge available to propose, and saturation is the only route.

**This is a proposal-heuristic defect, not a certification defect.** Amendment 13 §3 already denies the
source-edge-barrier partition any certification authority; the authoritative verdict is always the actual-embedded-graph
certificate, which R10 proved green. So the corrective touches the heuristic only and **does not reopen
Amendment 14**. Frozen corrective: model a trace crossing as a **per-face chord**, matching the fragment machinery
A2b already uses, so a trace-crossed edge is interior to its component. Owned by **AK4**.

##### 2.2 `R8-CAND-02` — decided here rather than deferred a third time

Question: what should A2a′ do when the network is empty (zero nodes, zero arcs) on a closed surface?

**Decision: reject with a typed error naming the empty network.** Rationale: A2a′'s contract is to *add cuts that
make an existing network's complement cellular*. An empty network has no complement structure to complete — cutting
"from scratch" would make A2a′ the producer of the entire embedded graph, which is A2a's single-writer authority
(`ORIENTATION.md` §1). Silently succeeding would also mean a witness with no field-aligned content could produce a
"certified" plan, which is the vacuous-green shape `LESSONS.md` 64r warns about. A typed rejection keeps
single-writer authority intact and fails closed with a locus, per the architecture's own commitment.

The new code must be **additive** — a new `SurfaceCutGraphErrorCode` value, appended, with no renumbering of
existing values, since accepted identities consume them. Owned by **AK5**.

##### 2.3 `CAND-04` — the sphere's two problems, and why (a) comes first

(a) and (b) are independent and (a) blocks observation of (b) through the producer. Until the producer reaches cut
selection, the sphere's cut set cannot be examined at all. So (a) is sequenced first, and it is the same shape as
the A1 problem in §3 — a typed error whose exact origin site has never been printed, at a finer grain than
"`RotationSystemInconsistent`, one of nine sites in `EmbeddedGraphTopology.cpp`".

---

#### 3. The finding — `IncompleteCycleBasis` is a seven-way collapse, and nobody has printed which one

The mechanical witness has been out of scope for the entire CP4c arc, and **no diagnostic has ever been run on it**.
`ORIENTATION.md` §4 records only "no atlas — stops in **A1** at `IncompleteCycleBasis`". Read at source, that code
is not one condition:

| site in `src/authority/FieldTransportAtlas.cpp` | condition | locus published |
|---|---|---|
| `:1597` | `PCFaceTangentBundle::init(local->mesh)` threw | region only |
| `:1613` | `cycles.rows()`, `cycleCurvatures.size()` or `cycles.cols()` disagrees with `interiorVertices + boundaryLoops + 2·genus` | region only |
| `:1673` | a cycle coefficient is neither ≈0 nor ≈±1, or a column index is out of range | region only |
| **`:1682`** | **no `FieldTransportAdjacency` exists for a cycle's edge** | region + **edge** |
| `:1688` | a local edge has a negative incident face | region + edge |
| `:1700` | `order_cycle_steps` could not order the directed cycle | region only |
| `:1751` | per-kind cycle partition counts disagree with expected local/boundary/handle counts | region only |
| `:1818` | boundary-cycle count ≠ `local->mesh.boundaryLoops.size()` | region only |

**Seven distinct mechanisms, one name, and five of them publish nothing but a region id.** Site `:1682` is
literally "missing field-transport adjacency" — the phrase `ROADMAP.md` uses for CP4c-3's parent responsibility — so
the roadmap's framing points at one specific site among seven that has never been confirmed.

This is `LESSONS.md` **57** recurring in A1: *a `default:`-shaped collapse assigns a name that will be believed*.
CP4c-2 paid **eight turns** for exactly this at `topology_error`, and the fix that ended it — AF0's additive
`originatingTopologyError` provenance field — is a directly reusable template. **CP4c-3 must not design a fix for
the mechanical witness before the discriminator is printed.** That is **AK1**, and it is the first measure for the
same reason AF1 was first at CB6.

**A second, related gap:** these checks all read `local->mesh`, built by `make_local_region_mesh`
(`:850-895`) from a region's faces plus **all** their vertices. Whether a region's local mesh is a manifold disc, or
pinches at a vertex where several feature curves meet — common in mechanical parts — determines
`isBoundaryVertex`, `boundaryLoops` and hence the expected counts at `:1613`, `:1751` and `:1818`. **AK2** requires
the local-region-mesh shape published alongside the failing site, because the site alone will not explain the count.

**No mechanism is promoted here.** The candidate readings above are hypotheses; AK1/AK2 exist so the next turn
reports a measurement rather than adopting one. This is the R2 discipline, and the last three checkpoints have all
been shortened by honouring it.

---

#### 4. Scope decision — the prescribed sphere IS in CP4c-3's gate

R10-REV measure AJ2 required this decided explicitly and in writing. **Decision: the sphere is gated.**

**Why.** It has now sat outside two consecutive frozen gates. `LESSONS.md` 64w and the `AF5` finding record that a
witness outside every gate is how a defect survives indefinitely — the sphere's own eight-turn misdiagnosis is the
project's proof of that. A third silent pass would make the pattern a habit. It is also the only remaining witness
that cannot reach A2b at all, and A2b's region authority is what M4 builds on: deferring it pushes an unknown of
unknown size into the next milestone. And its problem (b) is **directly coupled** to `R10-CAND-01`, which CP4c-3
already owns — a sphere that needs trace-crossed cuts is precisely the production witness the ordinary proposal path
must be able to serve.

**Scope boundary this does not cross.** Adding the sphere as a gated **witness** is not reallocating a **criterion**:
`ROADMAP.md` §1 allocates C1/C3/C6 to CP4c-2 and C2 to CP4c-3, and that allocation is untouched. Which witnesses a
checkpoint's identities bind is a DEFN decision, and `ROADMAP.md` §1 states the successor selector is not frozen
until the definition turn. The sphere enters through §5's phase 2, gated by a new identity named in §6.2 — not by
widening C2.

---

#### 5. Phase structure

CP4c-3 has two product problems in two different stages, plus two carried defects. One undifferentiated CB would
repeat the partial-conversion failure this project has now corrected three times, so the checkpoint runs in two
phases against **one** frozen gate. Phase 1 is diagnostic and non-mutating of product semantics; phase 2 fixes.

**Phase 1 — make both failures legible (`M3-CP4c-3-CB1`, measures AK1–AK3).** Instrument A1's
`IncompleteCycleBasis` collapse and the sphere's `RotationSystemInconsistent` at site granularity, publish the
local-region-mesh shape, and run the result through a TB. **No product fix.** Phase 1 exists because both problems
are currently named by a code that does not identify their mechanism, and because CP4c-2's own record shows what
designing across that gap costs.

**Phase 2 — fix, on measured causes (`M3-CP4c-3-CB2+`, measures AK4–AK6).** The mechanical witness's A1 defect, the
sphere's A2a′ defect, `R10-CAND-01`'s proposal-heuristic correction and `R8-CAND-02`'s typed rejection. Ordering
within phase 2 is a phase-1-review decision, not fixed here, because the measured causes may share a locus — as the
torus and sphere did.

---

#### 6. The gate

##### 6.1 Frozen now — selector 367

Created as `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_367.txt`: accepted **365** plus the
two identities that exist today and that CP4c-3 owns by prior commitment.

| ordinal | identity | why gated |
|---|---|---|
| 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | criterion **C2**, CP4c-3's parent responsibility |
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | criterion **C3**'s full form, binding torus **and** mechanical. DEFN-R2 §7.3 split C3 and committed the mechanical half to CP4c-3; this honours that commitment. The torus-only variant at ordinal 362 stays in the accepted prefix and is not removed. |

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `…_Selector_367.txt` | `head -n 355 \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `…_Selector_367.txt` | `head -n 357 \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `…_Selector_367.txt` | `head -n 361 \| sha256sum` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| **accepted 365 prefix** | `…_Selector_367.txt` | `head -n 365 \| sha256sum` | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **CP4c-3 gate 367** | `…_Selector_367.txt` | whole file: `sha256sum` | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |

Verified at authoring per `AE4`/`AE5`: every value computed from the created bytes, each exactly 64 lowercase hex;
all 367 lines unique; each appended identity resolves to exactly one `TEST(...)`; and **all four earlier prefixes
reproduce their frozen hashes**, so `first_red_ordinal` stays comparable across the entire CP4c arc. Both appended
identities are **red today** — the mechanical fixture throws — and that is correct: a required-green selector states
what must hold for the checkpoint to close, not what passes today.

`selected_gate=NONE`; `gate_execution_authorized=false`. Freezing bytes is not selecting.

##### 6.2 To be appended — named now so they cannot be silently omitted

These identities do not exist yet, so they are not in the frozen file. **AK7** makes their append mandatory and
named, producing gate **370**.

| identity to create | contract | phase |
|---|---|---|
| `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | §4's decision: the sphere reaches A2b through the production path and publishes disc-proved regions | 2 |
| `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | `R10-CAND-01`: the ordinary tree–cotree path selects a trace-crossed edge with `saturationUsed=false`; the AG5 witness is retained as the positive saturation case | 2 |
| `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | `R8-CAND-02`: §2.2's decision, with the new appended error code and a locus | 2 |

The turn that creates them recomputes and records the 370 whole-file hash and re-verifies the 355 / 357 / 361 /
365 / 367 prefixes. Omitting any requires an explicit written rationale in that turn's report — silence is not a
decision (`LESSONS.md` 64w).

---

#### 7. Prohibited

- **Designing a fix for the mechanical witness or the sphere before AK1/AK2 print the site.** Both are currently
  named by a collapsed code. CP4c-2 spent eight turns on exactly that mistake.
- **Renumbering or removing any existing `FieldAtlasBuildErrorCode` or `SurfaceCutGraphErrorCode` value**, or
  changing any existing error mapping. New provenance and new codes are **appended and additive** only — accepted
  identities consume the current values.
- **Reopening Amendments 12, 13 or 14**, or relaxing `proves_cellularity()`, the fragment-count invariant,
  `UncutFaceComponentOrbitSeedNotUnique`, or the actual-embedded-graph complex.
- **Changing accepted selector 365's bytes**, or any byte of 357 / 358 / 361, or 367 other than by AK7's append.
- **Treating `R10-CAND-01`'s corrective as a certification change.** It is a proposal-heuristic change; the
  certificate is untouched.
- **Introducing any tolerance** into a topological decision, or inferring a quantity the producers already publish
  exactly.
- Removing CP4c-2's diagnostic surface — `originatingTopologyError`, the AI2 fragment/orbit publication, the
  actual-embedded-graph oracle, the repaired D2 harness. They belong to the product now.
- A `DEFN` turn compiling, packaging, executing runtime, running a gate, or benchmarking.

---

#### 8. Falsifiable predictions

1. The mechanical witness's `IncompleteCycleBasis` resolves to **one** of §3's eight sites, and it is **not**
   `:1597` (a `PCFaceTangentBundle::init` throw), because a throw would more likely have surfaced as a crash in the
   many turns this fixture has been loaded.
2. If it is `:1613`, `:1751` or `:1818`, the local-region-mesh shape published by AK2 will show a region whose
   boundary is not a disjoint union of simple loops — the count checks all derive from `boundaryLoops` and
   `isBoundaryVertex`.
3. The sphere's `RotationSystemInconsistent` resolves to one of the nine `sourceFace`-carrying sites in
   `EmbeddedGraphTopology.cpp` and involves source face `25-27-28`.
4. Fixing the sphere's producer failure does **not** make it cellular: its pre-cut `χ=6` against `sourceChi=2` is an
   independent measurement, so it will still need cuts, and they will be trace-crossed.
5. `R10-CAND-01`'s corrective changes **no** accepted identity's result, because the proposal heuristic has no
   certification authority. If any of ordinals 1–365 moves, the change was not confined to the heuristic and must
   stop.
6. The torus's accepted numbers are unchanged by everything in this checkpoint: `cutEdgeCount=28`,
   `torusRegionCount=4`, actual graph `V/E/F = 72/76/4`.

Prediction 5 is the one to check first and hardest. Prediction 1 is the one most likely to be wrong.

---

#### 9. Measures **AK0–AK9**

The next turn is **`M3-CP4c-3-CB1`**, a phase-1 Code + Build that instruments and does not fix.

**AK0 — preconditions and frozen authority.** Accepted runtime predecessor is CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and all four prefixes from
committed bytes at authoring and preflight, validate each as exactly 64 lowercase hex, and never transcribe. No
existing selector byte may change. Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX, `runtimeExecution=false`.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AK1 — print the A1 discriminator. Additive only.** Add an optional provenance field to `FieldAtlasBuildError`
identifying **which** of §3's conditions fired — an enumerated reason, not a line number (`LESSONS.md` 62's stale
`419/437/474` labels are the counter-example). Populate it at all eight sites. Print it wherever
`field_atlas_build_error_code_name` is printed today. **Prohibited:** changing which condition maps to
`IncompleteCycleBasis`, renumbering the enum, or adding a new `FieldAtlasBuildErrorCode` value in this CB. This is
AF0's template applied to A1; follow it exactly.

**AK2 — publish the local-region-mesh shape with the failure.** For the failing region, publish `V`, `E`, `F`, the
computed `eulerCharacteristic`, `boundaryLoopCount`, `genus`, `interiorLocalVertices.size()`, the resulting
`expectedCycleCount`, and the actual `bundle.cycles.rows()` / `cycleCurvatures.size()` / `innerAdjacencies.size()`.
The site alone will not explain a count mismatch; the counts will. Publish for **every** region of the mechanical
witness, not only the first failing one — a per-region row set, in the AG3 idiom.

**AK3 — print the sphere's site at nine-way granularity.** AF0 gave the sphere
`originatingTopologyError=RotationSystemInconsistent`; that is one code across nine `sourceFace`-carrying sites in
`EmbeddedGraphTopology.cpp`. Add the same enumerated-reason provenance so the site is identified, and publish it
through the existing frozen non-gating sphere diagnostic. **No product fix for the sphere in phase 1.**

**AK4 — `R10-CAND-01`, phase 2.** Model a trace crossing as a **per-face chord** in the proposal heuristic, matching
the fragment machinery, so a trace-crossed edge is interior to its component and reachable by the ordinary
tree–cotree search. Heuristic only: the certificate, the complex and Amendment 14 are untouched. Publish, per
witness, whether the ordinary path or saturation selected each trace-crossed edge. Keep the AG5 witness as the
positive saturation case and add the §6.2 identity for the ordinary case.

**AK5 — `R8-CAND-02`, phase 2.** Implement §2.2's decision: an empty network on a closed surface is rejected with a
**new, appended** typed error naming the empty network, with a locus. Do not renumber existing values. Add the
§6.2 identity.

**AK6 — the two product fixes, phase 2, on measured causes only.** The mechanical witness's A1 defect and the
sphere's A2a′ defect. Each CB states, in its report, the measured site from AK1/AK3 that it is fixing. **A fix whose
report cannot name the measured cause is not authorized.**

**AK7 — the three new identities enter the gate, by name.** §6.2's identities are created and **appended** to
selector 367 in the listed order, producing gate **370**. That turn recomputes and records the 370 whole-file hash
and re-verifies the 355 / 357 / 361 / 365 / 367 prefixes. Omission requires a written rationale.

**AK8 — enumerations.** Every measure in CP4c-3 that says "every consumer", "every site" or "every region" must
either contain the enumeration, produced by search, or require the implementer to produce and publish it by
**search** rather than by copying this document's tables. §3's eight-site table is a cross-check to compare against
*after* the implementer has produced their own — `LESSONS.md` 59 and 61 exist because a copied enumeration inherits
the author's omissions.

**AK9 — bookkeeping and prohibitions.** §7's prohibitions bind every CP4c-3 turn. Carry
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01` and `M3-CP4c2-TB-X2-R8-CAND-02` as CP4c-3-owned with the
dispositions in §2 and §4. **Stable accounting remains 44 / 14 / 30**, produced-witness debt **5**, authoritative M3
packages **67**. Every TB continues to run the frozen non-gating selector in full or justify skips per identity
(`AF6`).

---

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-3-CB1`**, Code + Build, runtime-free, under **AK0–AK3** with §7's prohibitions.
Its successor is an artifact-only TB that executes gate **367** from ordinal 1 and publishes the AK1–AK3 evidence;
that TB's review then orders phase 2.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; its gate is frozen at **367** and unselected.

---

## Part V — M3-CP4c-3 DEFN-R1

*Source document: `Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN-R1 — Frozen Definitions, Review and Plan

#### Status

**DEFINITION + REVIEW COMPLETE / AL2 SETTLED / OPTION A ADOPTED IN ITS DERIVED-VIEW FORM (A′) /
AMENDMENT 15 DECLARED / MEASURES AM0–AM9 ISSUED**

This turn discharges **AL2** under the standing cadence in which `DEFN` *is* the review-and-plan turn. Definition,
review and planning only: nothing was executed, compiled, packaged, relinked or benchmarked, no gate was selected
or run, and **no product, test, fixture, selector or build-logic byte changed**. The only source read was read.

Measures issued here are **AM0–AM9**. Gate **367** remains frozen and unselected.

---

#### 0. What this turn verified independently

The working tree is byte-identical to the semantic source TB1 executed:

```
git diff --stat 48dd011c4aa689a245b74527ed9df0900ada9bf3 HEAD -- tests/ src/ include/   →  empty
```

so every source claim below describes exactly the code that produced ordinal 366's red. Every line reference was
read at HEAD, not carried forward from a prior record.

This document does not re-derive TB1's adjudication; that is
`Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` (AL0–AL9). It answers the one normative question that
record deliberately refused to answer by implementation.

---

#### 1. The question, stated exactly

`M3-CP4c-3-TB1` measured `IncompleteCycleBasis → CycleTransportAdjacencyMissing` at region `0`, source edge `0-3`,
and the review established the mechanism: a `HardFeature` **barrier** edge remained **interior** to its topology
region's local mesh, so the cycle basis spanned an edge for which the atlas deliberately created no transport
adjacency. Region decomposition and traversability classification disagree about the same edge.

AL2 requires this turn to settle, normatively:

1. what a topology region **is** when a barrier does not separate — option **A** (cut) versus **D** (fail closed),
   with **C** (give the barrier an adjacency) prohibited;
2. if A, the exact treatment of an **open arc's endpoints**, where the cut surface touches itself, **with its
   derivation**;
3. that `χ`, `boundaryLoops` and `expectedCycleCount` stay consistent for a slit region — **shown, not asserted**;
4. recorded as a `DESIGN.md` §7.2.1 amendment.

§§2–5 derive the answers. §6 decides. §7 states what the decision costs. §8 is the plan.

---

#### 2. Theorem 1 — the defect class is *exactly* `HardFeature` edges interior to a region

This bounds the whole problem, and it is provable from the two classification sites rather than observed on one
witness.

`FieldTransportAtlas::make` (`src/authority/FieldTransportAtlas.cpp:1456-1491`) routes every source edge through
four buckets **in this order**:

| order | bucket | condition |
|---|---|---|
| 1 | `SourceBoundary` | `secondRaw < 0` — one incident face |
| 2 | `HardFeature` | `hardFeatureEdges.count(edge) != 0` |
| 3 | `NonTraversable` | `rowRegions[first] != rowRegions[second]` **or** `rowComponents` differ |
| 4 | `adjacencies` | otherwise — a transport adjacency is created |

`make_local_region_mesh` (`:850-902`) builds a region's local mesh from **that region's faces only**. Therefore:

- a **bucket-1** edge has one incident face, so at most one of its faces is in any region → it is a **boundary**
  edge of the local mesh, never interior;
- a **bucket-3** edge has its two faces in **different regions** (or components), so exactly one lies in each
  region's face set → again a **local boundary edge**, never interior;
- a **bucket-4** edge has an adjacency, so it cannot raise `CycleTransportAdjacencyMissing` at all.

**Only bucket 2 can be interior to a local region mesh while carrying no adjacency.** Note the ordering matters:
`hardFeatureEdges` is tested *before* the region/component test, so a hard-feature edge whose two faces sit in one
region is classified `HardFeature`, not `adjacencies`.

**Corollary — isolation seams are not affected.** `scratch_internal_isolation_seam`
(`src/geometry/SurfaceCellTracing.cpp:6837-6851`) marks an edge whose faces are in the **same** region and **same**
component but different *sheets*, and which is **not** a hard feature. In A1 such an edge fails bucket 2 and fails
bucket 3, so it lands in bucket 4 and **does** get a transport adjacency. Isolation seams are interior to a region
by design and are traversable by design; they are not part of this defect class and must not be swept into the
fix.

**Definition (frozen).** For a topology region `R`,

```
B(R) = { e ∈ hardFeatureEdges : both faces incident to e belong to R }
```

`B(R)` is the region's **non-separating barrier set**. It is exactly the set of edges that are non-traversable in
A1 and interior in A1's local mesh. Everything below is stated about `B(R)`.

---

#### 3. Theorem 2 — cutting along `B(R)` can never disconnect `R`

This is what makes the operation safe, and it is forced by how regions are built, not by luck.

`build_source_topology_regions` (`src/geometry/SurfaceCellTracing.cpp:6715-6741`) builds the face-adjacency graph
by skipping (a) edges whose faces are in different raw components and (b) every edge in
`options.hardFeatureEdges`, then flood-fills. A region `R` is a connected component of *that* graph. Since all
faces of `R` share one raw component (`:6824-6827`), the only edges of `R` skipped during its own flood fill are
exactly `B(R)`.

**Therefore the face-adjacency graph of `R` using only non-barrier edges is connected by construction.** Cutting
along `B(R)` removes exactly those barrier adjacencies and leaves that graph untouched, so the cut mesh's face
graph is connected, and a triangulated surface with a connected face graph is connected.

**The cut mesh is always connected, for every region and every barrier set.** Consequently `χ = 2 − 2g − b` applies
to it with one component and `genus` stays well defined — the assumption `:1652-1660` already makes.

**Corollary.** No subset of `B(R)` separates `R`: if one did, `R`'s non-barrier face graph would be disconnected,
contradicting the construction. In particular, on a region with `χ = 2` and `b = 0` — a sphere, where **every**
closed curve separates — `B(R)` contains **no cycles at all**: every component of `B(R)` is a **tree**. The
mechanical witness's `B(R)` is a forest.

---

#### 4. The endpoint rule — AL2 item 2, derived

Cutting is a purely combinatorial rewrite of the local face array: duplicate the vertices of `B(R)` according to
how the barrier divides their stars, re-index the faces, and hand the result to `TriMesh::set_mesh`. No geometry
moves; both copies of a duplicated vertex keep the same position.

**Rule (frozen).** For a vertex `v` incident to `B(R)`, let `d(v)` be its degree **in `B(R)`**. The number of
copies of `v` in the cut mesh is the number of connected components of `star(v) ∖ B(R)`:

```
copies(v)  =  d(v)                    if v is interior to R's local mesh
           =  d(v) + 1                if v lies on R's local-mesh boundary
copies(v)  =  1                       if v ∉ B(R)
```

**Derivation.** The star of an interior vertex is a disc whose link is a cycle; `d(v)` radial barrier rays cut that
disc into exactly `d(v)` sectors — including `d(v) = 1`, where a single ray does **not** disconnect the disc and
leaves one sector. The star of a boundary vertex is a half-disc whose link is a path; `d(v)` interior rays cut a
path into `d(v) + 1` pieces. Each sector becomes one copy, and the faces of that sector are re-indexed to it.

**This settles the endpoint question, and the answer is that an open arc's tip is not duplicated.** A tip has
`d = 1`, hence exactly one copy: the cut surface genuinely touches itself there, and that is representable. The tip
is nevertheless *incident to* the slit, so it becomes a **boundary vertex** of the cut mesh, appearing exactly once
on the slit's boundary loop, with one incoming and one outgoing boundary edge (the two copies of the arc's terminal
edge). Its link is a single fan.

**The cut mesh is therefore a manifold with boundary**, which is what `PCFaceTangentBundle::init` requires and what
`make_local_region_mesh`'s `set_mesh` will accept. `TriMesh::set_mesh` derives `EV`, `EF`, `isBoundaryVertex`,
`isBoundaryEdge` and `boundaryLoops` from V/F (`include/directional/core/TriMesh.h:202-241`), so **every downstream
count follows automatically from the rewritten face array**. Nothing else in `make_local_region_mesh` needs new
bookkeeping except the `globalVertexByLocal` map, which becomes many-to-one.

**Degenerate shapes the rule already covers, and which AM1 must report rather than assume away:** a branch vertex
(`d ≥ 3`) yields `d` copies; a barrier component that is a closed loop yields `copies = d = 2` everywhere and no
tip; a barrier vertex on the region's own boundary yields `d + 1`. Theorem 2 forbids closed loops only when `R` is
a sphere, so the loop case is real on other regions and must not be special-cased away.

---

#### 5. Arithmetic consistency — AL2 item 3, shown

Let `R` have `V, E, F`, `χ = V − E + F`, boundary loops `b`, and let `B = B(R)` have `n = |V(B)|` vertices and
`m = |B|` edges, with `∂` = the number of `B`'s vertices lying on `R`'s local-mesh boundary.

The rewrite changes counts by `ΔF = 0`, `ΔE = m` (each cut edge becomes two), and

```
ΔV = Σ_{v ∈ V(B)} (copies(v) − 1) = (2m − n) + ∂
```

using `Σ d(v) = 2m` and §4's rule. Hence the **cut identity**:

```
χ(R_cut) = χ(R) + ΔV − m = χ(R) − (n − m) + ∂ = χ(R) − χ(B) + ∂
```

*Cutting along `B` lowers the Euler characteristic by the Euler characteristic of `B`, plus one for each of `B`'s
vertices already on the boundary.* Four checks, all correct:

| case | `χ(B)` | `∂` | predicted `χ'` | truth |
|---|---|---|---|---|
| sphere, one open arc | 1 | 0 | `2 − 1 = 1` | sphere with a slit **is** a disc ✓ |
| torus, one non-separating closed loop | 0 | 0 | `0 − 0 = 0` | torus cut along a generator **is** an annulus ✓ |
| disc, arc from an interior tip to the boundary | 1 | 1 | `1 − 1 + 1 = 1` | still a disc ✓ |
| disc, arc between two boundary points | 1 | 2 | `1 − 1 + 2 = 2` | **two** discs, `χ = 1 + 1` ✓ |

**Now the mechanical witness, fully determined without measuring it.** Region 0 has `V/E/F = 152/450/300`,
`χ = 2`, `b = 0`, `genus = 0`. By Theorem 2's corollary every component of `B` is a tree, so `χ(B) = c` where `c`
is the number of barrier components, and `∂ = 0`. Therefore

```
χ' = 2 − c        b' = c        genusNumerator = 2 − b' − χ' = 2 − c − (2 − c) = 0   →   genus' = 0
```

`genusNumerator` is `0`, hence non-negative and even, for **every** `c`. The region is a sphere with `c` holes.
Boundary vertices of the cut are exactly the copies of `B`'s vertices, `Σ copies(v) = 2m`, so

```
interiorVertices' = V + ΔV − 2m = 152 + (2m − n) − 2m = 152 − n
expectedCycleCount' = interiorVertices' + b' + 2·genus' = (152 − n) + c
```

**The independent cross-check that makes this "shown" rather than "asserted".** `dual_cycles`
(`include/directional/geometry/MeshTopology.h:55-74`) is documented to emit `#V − #b` inner-vertex cycles **in
vertex order**, then `#b` boundary cycles, then `2g` generator cycles, with columns **indexed into inner edges
alone**. Its row count must equal the dual cycle space dimension plus the one known dependency. Inner edges after
the cut are `E' − 2m = (450 + m) − 2m = 450 − m`, faces `300`, one component, so

```
dim(dual cycle space) = (450 − m) − 300 + 1 = 151 − m
rows − dim = [(152 − n) + c] − [151 − m] = 1 + (m − n) + c = 1 − χ(B) + c = 1 − c + c = 1
```

**The rank deficiency is exactly 1, the same value it has on the uncut mesh** (152 rows vs. 151 dimensions today).
The slit does not change the dependency structure, so nothing downstream that tolerates today's single dependency
becomes newly broken. The three count guards `CycleDimensionCountMismatch`, `CycleKindPartitionMismatch` and
`BoundaryCycleCountMismatch` remain satisfiable, and `innerAdjacencies` drops from `450` to `450 − m` — **exactly
the barrier edges leave**, which is the entire point of the change.

**And the failure becomes structurally impossible, not merely avoided.** `dual_cycles`' columns are inner edges
only; a barrier edge is a boundary edge of the cut mesh; therefore it can never appear as a column, so
`:1751-1761`'s `find_adjacency_in(adjacencies, edge)` is never called for it. `CycleTransportAdjacencyMissing`
cannot fire for a barrier after the change — it survives, correctly, only for a genuinely missing adjacency on a
traversable edge.

---

#### 6. Decision — Amendment 15, option **A′**

**Adopted: option A, in its derived-view form.** The cut belongs to **A1's derived local mesh**, and **not** to the
`SurfaceTopologyRegion` product.

> **A topology region's face set, its published `euler_characteristic()` and its published `boundary_loop_count()`
> are unchanged. What changes is that A1's *transport domain* for a region is the region **cut along its
> non-separating barrier set `B(R)`**, and every tangent-bundle, cycle-basis and index quantity A1 derives is
> derived from that cut mesh.**

Three reasons, in order of weight.

**6.1 The region product cannot express an open slit, and forcing it to would break an accepted product.**
`build_source_topology_regions` derives `boundaryLoopCount` by walking `boundaryAdjacency`, and `:6905` **requires
every boundary vertex to have exactly two boundary neighbours**, returning `std::nullopt` — failing the entire
`SourceTopologyRegions` product — otherwise. At the region level there is no vertex duplication: an open arc's tip
would have exactly **one** boundary neighbour, so simply adding `B(R)` to `region.boundaryEdges` does not produce a
slit, it produces a **hard failure of A0/A2's region authority for every witness with an open feature arc**. The
slit is only representable where vertices can be duplicated, and that is the local mesh.

**6.2 It is the Amendment 14 precedent, applied to the same class of question.** Amendment 14 established that an
immutability guarantee constrains the **writer**, not a **derived view**: A2a′ may place a node where the network
already says two curves meet without mutating the network. The identical shape holds here. The region product's
face set and its Euler data are facts about the *uncut source complex* and stay true. A1's cut mesh is a derived
view built for transport, and building it does not repair, contradict or rewrite the region.

**6.3 It makes the two classifications agree by derivation instead of by assumption.** The root cause is that A1's
cycle machinery assumed region boundaries and non-traversable edges coincide. Under A′ that assumption becomes a
**construction**: the transport domain's boundary is, by definition, the region boundary **together with** its
non-traversable interior edges. The corrective form `RP-01` prescribes — make one derive from the other rather
than maintaining two authorities that happen to agree — is satisfied exactly.

**Rejected: C**, prohibited as AL9 already froze — it would let transport cross a feature and destroys the barrier
semantics hard features exist to express.
**Rejected: B** — `PCFaceTangentBundle::init` takes a mesh, not a barrier set, so it converges on A′ anyway.
**D is retained as the frozen fallback**, with an explicit trigger; see §7.4.

---

#### 7. What the decision costs — three consequences, each with a required control

A′ is not free, and none of these is visible from the failing line. Each is a **required** part of the change; an
implementation that lands the fix without them converts a loud red into a quiet weakening, which is exactly the
pattern `LESSONS.md` 62 records.

##### 7.1 The `CanonicalBindingMismatch` cross-check must be **replaced**, not deleted

`:1654-1658` currently rejects a region unless the local mesh's `χ` and `boundaryLoopCount` equal the region's own
published `euler_characteristic()` and `boundary_loop_count()`. Under A′ the cut mesh's values **deliberately
differ**, so this check will fire on every witness with a non-separating barrier. Deleting it removes a real
guard — it is the only place the local mesh is tied to the region authority at all.

**Required replacement.** Keep the comparison against the region's published values for the **uncut** local mesh,
then assert the **cut identity of §5** relating the two:

```
χ(cut) == region.euler_characteristic() − χ(B) + ∂        and        b(cut) == b(uncut) + (new slit loops)
```

with `χ(B) = |V(B)| − |B|` computed from the barrier set the cut actually used. This is **strictly stronger** than
today's check: it constrains three independently derived quantities instead of two, and it fails closed if the cut
and the region ever disagree about which edges were barriers. A distinct appended error code must name that
condition; it may not reuse `CanonicalBindingMismatch`, which would re-collapse a typed error one turn after this
project resolved two such collapses.

##### 7.2 The region's certificate changes kind, from a closed identity to a boundary-corrected one

`:1857-1898` branches on `boundaryLoopCount`. Today the mechanical region has `b = 0` and takes the closed branch:
`FieldQuadrangulabilityWitnessKind::ClosedShenSufficient`, with the **equality** `interiorIndexSum ==
requiredIndexSum == 4χ` enforced at `:1872`. After the cut, `b' = c ≥ 1`, so it takes the `RelativeBoundary` branch
at `:1878`, where `correction = requiredIndexSum − interiorIndexSum − boundaryIndexSum` is **absorbed into the
first boundary cycle** (`:1892`) provided only that `correction % 4 == 0`.

That is correct mathematics — Gauss–Bonnet with boundary — but it replaces an equality test with a congruence test
plus an absorption. **The cut therefore weakens the index check for exactly the regions it is applied to.** This is
a genuine, accepted cost of A′ and must be stated in the CB report rather than discovered later; §8's AM6 requires
the published witness kind and the absorbed `correction` value to be reported per region, so the weakening is
visible in evidence instead of implicit.

##### 7.3 The quiet one: a prescribed singularity on a barrier arc silently loses its verification

This is the most dangerous consequence and it is invisible at every failing line.

Every vertex incident to `B(R)` becomes a **boundary** vertex of the cut mesh, so it is no longer in
`interiorLocalVertices` and **no `LocalVertex` cycle is emitted for it**. Two things follow:

- `:1843-1851`'s agreement check — that the atlas's computed `turningLift` equals the **prescribed** raw singularity
  index at that vertex — **no longer runs** for it;
- and the global reconciliation does not catch the gap. `rawSingularity` versus `rawBoundarySingularity` is
  partitioned at `:1557` by **`sourceMesh.isBoundaryVertex`** — the *global* mesh — so a slit vertex is still
  classified as an *interior* singularity. The boundary reconciliation at `:1960-1976` fails closed when an owner
  is missing, but the interior path at `:1980-1990` does **not**: `localCycleByGlobalVertex.find(rawVertex)` simply
  leaves `region` and `cycle` as `std::nullopt` and the loop continues. The result is a `FieldSingularityFact`
  with **no region and no cycle binding, and no error**.

So a prescribed singularity sitting on a feature arc goes from *verified against the field's own holonomy* to
*unverified and unbound*, with a green build. This is a **pre-existing latent gap** — the asymmetry between
`:1960` and `:1980` exists at HEAD — that A′ makes reachable for the first time.

**Required control.** The interior path must be made to fail closed in the same shape as the boundary path: every
`rawSingularity` entry must bind to exactly one cycle — a `LocalVertex` cycle, or, when its vertex was consumed by
a slit, the boundary cycle of the slit loop that carries it — and a prescribed singularity with no owner is a typed
failure, not a `nullopt` field. This is not scope creep: without it the fix trades a red gate for an unverifiable
certificate, which the project has twice recorded as the worse outcome.

##### 7.4 The frozen fallback, with its trigger

If **AM5**'s implementation cannot deliver §7.1–§7.3 within CP4c-3, the fallback is **option D**: retain today's
behaviour but name it precisely with a **new, appended** `IncompleteCycleBasisReason` — "a non-separating barrier
edge remains interior to its region" — replacing the misleading `CycleTransportAdjacencyMissing` for this
condition only. **The trigger is explicit and must be declared in the CB report, not decided silently:** D is taken
if and only if §7.3's binding control cannot be made to fail closed without changing an accepted A1 contract. If D
is taken, **CP4c-3 cannot close on criterion C2**, and the gate expectations must be revisited by a further DEFN
before any TB. D is a stop, not a fix, and must be reported as one.

---

#### 8. Measures **AM0–AM9**

The next turn is **`M3-CP4c-3-CB2`** — Code + Build, instrumentation and correction, runtime-free.

**AM0 — preconditions and frozen authority.** Accepted runtime predecessor remains CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and **all four** predecessor
prefixes from committed bytes at authoring and at preflight, and validate each as exactly 64 lowercase hex. Never
transcribe a digest. No existing selector byte may change. `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`. GMP/GMPXX linkage is mandatory for the compile.

**AM1 — publish the barrier set before cutting anything.** For the mechanical witness publish: `|hardFeatureEdges|`;
whether edge `0-3` is a member; and the connected-component decomposition of `B(R)` per region — for each
component, its vertex count, edge count, `χ`, whether it is a tree or contains a cycle, its degree-1 tip vertices,
its degree-≥3 branch vertices, and how many of its vertices lie on the region's local-mesh boundary. Publish the
totals `n = |V(B)|`, `m = |B|`, `c`, `χ(B)` and `∂` that §5's identity consumes. This confirms §2's elimination
directly, sizes the change, and **falsifies §5 if the numbers disagree**.

**AM2 — implement the cut as a face-array rewrite in `make_local_region_mesh`.** Duplicate vertices by §4's rule,
re-index faces per sector, hand the result to `set_mesh`, and let `EV/EF/isBoundaryVertex/boundaryLoops` derive
themselves. `globalVertexByLocal` becomes **many-to-one**; every consumer of it must be audited by search, not by
copying this document's list. Two are known and must be handled: `global_edge_key` (`:1694`, `:1753`) — safe,
because both copies of a duplicated vertex carry the same global vertex and cut edges never appear as inner edges —
and `:1795`'s positional `interiorLocalVertices[row] → globalVertexByLocal[...]` mapping, which stays injective
because **every copy of a cut vertex is a boundary vertex** and so is never in `interiorLocalVertices`. State in
the CB report which consumers the search found and how each was classified.

**AM3 — replace the `:1654` cross-check per §7.1** with the cut identity, under a **new appended** error code. Do
not delete the check and do not reuse `CanonicalBindingMismatch`.

**AM4 — make the interior singularity binding fail closed per §7.3.** Every `rawSingularity` must bind to exactly
one cycle; an unbound prescribed singularity is a typed failure. Publish, per witness, the count of prescribed
singularities, how many bound to a `LocalVertex` cycle, how many to a slit boundary cycle, and how many bound to
nothing — the last must be zero.

**AM5 — the correction itself.** Land AM2–AM4 together. They are one change: AM2 without AM3 fails closed on every
barrier witness, and AM2 without AM4 is a silent weakening. State explicitly in the CB report whether option A′ or
the §7.4 fallback D was taken, and if D, which of §7.1–§7.3 could not be delivered and why.

**AM6 — report the certificate-kind change per §7.2.** Per region publish the witness kind
(`ClosedShenSufficient` / `RelativeBoundary`), `requiredIndexSum`, `interiorIndexSum`, `boundaryIndexSum` and the
absorbed `correction`. A region that changed kind because of the cut must be named as such.

**AM7 — the sphere is untouched by this turn, and AL3/AL4 still govern it.** AL3's `NoCarrierMatch` versus
`AmbiguousCarrierMatch` sub-reason, with the trace/event/`sourceEdge`/`sourceFace` row, every candidate position in
the ambiguous case, and **which pass** produced the result, is carried into CB2 unchanged. **AL4 stands: do not
design the sphere's fix until AL3 reports.** The two causes share no locus, so shipping AL3's instrumentation in
the same CB as AM5's correction is permitted; *designing* the sphere's correction is not.

**AM8 — gate append.** AL7's three identities still append to **367**, producing **370**. Amendment 15 adds three
more, producing **373**:
`FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`,
`FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity`,
`FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`.
All **five** predecessor prefixes (355, 357, 361, 365, 367) must be re-verified byte-identical at the freeze, and
370's prefix must reproduce inside 373. Omitting any identity requires a written rationale in the CB report.

**AM9 — prohibited.** Giving a barrier edge a transport adjacency (option C). Adding `B(R)` to
`region.boundaryEdges` or otherwise changing `SurfaceTopologyRegion`'s published `euler_characteristic()` /
`boundary_loop_count()` — §6.1 shows it fails the product outright. Deleting the `:1654` check rather than
replacing it. Landing AM2 without AM4. Treating an isolation seam as a barrier (§2 corollary). Renumbering or
removing any existing error-enum value or changing any existing mapping — new reasons and codes are **appended**
only. Reopening Amendments 12, 13 or 14. Changing accepted selector 365's bytes, or 357 / 358 / 361, or 367 other
than by AM8's append. Weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`. Introducing any tolerance into a topological decision. Removing CP4c-2's,
CB1's or this turn's diagnostic surface. Executing Directional runtime, running a gate, or benchmarking in a CB
turn.

---

#### 9. Falsifiable predictions

Recorded so the next turn can be judged against them rather than around them.

1. **AM1 will report `c ≥ 1` open-arc (tree) components for the mechanical witness, and zero cycles in `B(R)`.**
   Theorem 2's corollary forces it on a `χ=2, b=0` region. A measured cycle in `B(R)` **falsifies Theorem 2** and
   this whole amendment must be reopened.
2. **Edge `0-3` will be reported a member of `hardFeatureEdges`.** §2's elimination predicts it; a negative result
   falsifies the review's mechanical cause and CB2 must stop rather than proceed.
3. **After the cut, region 0 will publish `χ' = 2 − c`, `b' = c`, `genus' = 0`, `interiorVertices' = 152 − n`,
   `expectedCycleCount' = 152 − n + c`, and `innerAdjacencies = 450 − m`.** Any deviation falsifies §5.
4. **`CycleTransportAdjacencyMissing` will not fire for a barrier edge again**, because barrier edges are no longer
   columns of `dual_cycles`. If it does, the cut did not take effect where it was needed.
5. **Region 0's witness kind will change from `ClosedShenSufficient` to `RelativeBoundary`.** Predicted by §7.2. It
   is expected, not a defect, but it must appear in evidence.
6. **AM4 will report a non-zero number of prescribed singularities bound to a slit boundary cycle** only if the
   witness actually places singularities on feature arcs; zero is an acceptable outcome. What is **not** acceptable
   is a non-zero "bound to nothing" count.

---

#### 10. Gate membership and accounting

Gate **367** stays frozen and unselected; freezing bytes is not selecting them. The append point is defined by
**AM8** (367 → 370 → 373) and is executed at CB2's freeze, not here. `selected_gate=NONE`,
`gate_execution_authorized=false`, `selected_r2_branch=NONE`.

Nothing in this turn touches runtime, so accounting is unchanged: **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, authoritative M3 packages **68**. **+0 events / +0 recurrences.**

Tracker dispositions this turn sets:

- `M3-CP4c3-DEFN-CAND-01` — **CAUSE ESTABLISHED / CORRECTIVE DEFINED**. Amendment 15 fixes the corrective as option
  A′ with the §7.1–§7.3 controls; AM5 owns implementation. Closure condition unchanged: ordinal 366 green in a run
  reaching at least 366.
- `M3-CP4c2-TB-X2-CAND-04` — unchanged, **ACTIVE / ONE LEVEL SHORT**; AL3/AL4 carried forward as AM7.
- `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02` — unchanged, phase-2, no shared locus.
- **New: `M3-CP4c3-DEFN-R1-CAND-01`** — the unreconciled interior-singularity binding at `:1980-1990`. A
  pre-existing latent gap, not introduced here, made reachable by A′. Owned by **AM4**.

#### 11. Exact next turn

**`M3-CP4c-3-CB2`** — Code + Build under **AM0–AM9**, runtime-free, GMP/GMPXX linked. It implements Amendment 15
(AM2–AM6), carries AL3's sphere instrumentation (AM7), and freezes the **373** gate append (AM8). A red TB after it
routes to `REVIEW + PLAN` as usual.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**.

---

## Part VI — M3-CP4c-3 DEFN-R2

*Source document: `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN-R2 — Frozen Vertex-Star Continuation Definitions

**Turn:** `M3-CP4c-3-DEFN-R2`
**Type:** Definition + Review/Plan only
**Governing plan:** `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md` §7, measures **AX0–AX9**
**Verdict:** **AX1–AX8 DISCHARGED / AMENDMENTS 22 AND 23 DECLARED / VERTEX 30 PROVED EXACTLY AND THE OLD ELECTION
FALSIFIED BY GEOMETRY, NOT ONLY BY CARDINALITY / ONE BOUNDED SUCCESSOR AUTHORIZED UNDER AY0–AY9**

No Directional runtime, compile, link, package, benchmark, product, test, fixture or selector byte was executed or
mutated. Selector **373** remains byte-frozen at
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; **selector 374 still does not exist** and is
authorized only conditionally (AY7). Accepted authority remains **365**. Stable accounting remains
**44 / 14 / 30**, produced-witness debt **5**, semantic M3 packages **73**.

---

#### 0. AX0 — frozen preconditions, restated

Accepted selector 365, frozen selector 373, TB6/package-75 runtime evidence, CB8's architectural stop, and the
deferred ordinal-370 / prescribed-sphere / saturation authority are all carried forward unchanged. Ordinal 370, the
sphere and saturation are **not touched by this turn**. Amendments 17, 18 and 21 are not weakened anywhere below;
Amendments 22 and 23 are additive and are written to *serve* 17 and 18 rather than to soften them.

**Analysis performed:** static reconstruction from the committed fixture
`benchmarks/fixtures/milestone-g/mechanical_feature.obj` using exact rational arithmetic. Every numeric claim marked
**EXACT** below is a rational identity over the committed coordinates — no floating point, no factorization, and no
tolerance is used to establish it. Floating values appear only as *labels* for quantities that are irrational, and
they are never load-bearing.

---

#### 1. AX1 — the datum, its writer, and its lifetime

> **The primitive datum is one exact incoming geometric ray, anchored once at the vertex-arrival event, expressed
> in the arrival face's own chart, and never re-expressed by any candidate.**

Contract (names descriptive, not an implementation mandate):

| field | meaning |
|---|---|
| `sourceVertex` | the vertex being transited |
| `arrivalFace` | the source face the trace was inside when it reached the vertex |
| `arrivalBranch` | the A1 branch label the trace was following **in `arrivalFace`** |
| `arrivalRay` | the exact direction, in `arrivalFace`'s chart, of the ray **from the vertex back along the incoming trace** |
| `arrivalMode` | `FaceInterior` / edge-locus, as today |

**Orientation and sign are fixed here** so no consumer may choose: `arrivalRay` points **away from the vertex,
back along the direction the trace came from**. It is the reversed direction of travel. This convention is chosen
because it makes the seed a ray of the star itself — an object the fan can contain — rather than a velocity that
must be negated by each reader.

**Writer.** A2a branch continuation writes exactly one seed per vertex-arrival event. There is no seed per
candidate, no seed per face, and no seed per branch label.

**Lifetime.** The seed is immutable for the duration of the transit decision and is consumed by exactly one
authority (AX5). It is not re-derived, re-normalized, re-projected, or replaced downstream.

**Diagnostic-only, and explicitly demoted:** every candidate face's own
`FieldBranchBoundaryPairing::direction`, every per-face `representativeDirection`, and the branch label obtained by
applying `signedLift` in a target face. These may be published as audit rows (AX8). **None of them may enter the
decision.** They are what the current code decides on, and that is the defect.

---

#### 2. AX2 — vertex-star geometry and what "straight continuation" means

##### 2.1 The reference semantics

> **Amendment 22 — a curve continues through a source vertex along the *straightest geodesic* of the intrinsic
> vertex star, decided in one arrival-anchored development, and the outcome is one typed certificate.**

Definition, in six steps, stated independently of any numeric kernel:

1. **Fan.** Take the admissible incident-face fan of `sourceVertex`, ordered by source topology, truncated by the
   barrier policy exactly as A1 already truncates it, and terminated by source boundary where present. Barrier and
   boundary truncation are inherited, not redefined.
2. **Anchor.** Place `arrivalFace` first, with `arrivalRay` at developed angle `α`, measured from the fan-first
   radial edge of `arrivalFace`, `α ∈ [0, θ(arrivalFace))`.
3. **Develop.** Unfold each subsequent face sector isometrically about its shared radial edge into one developed
   chart. The developed position of the `k`-th radial ray is the cumulative sum `A_k = Σ_{i<k} θ_i` of the intrinsic
   face angles at the vertex.
4. **Continue.** The **cone angle** is `Θ = Σ_i θ_i` over the fan. The straightest continuation leaves the vertex at
   developed angle `β = α + Θ/2`, taken modulo `Θ` on a closed star. This is the Polthier–Schmies straightest
   geodesic: the intrinsic angle on one side of the continuation equals the intrinsic angle on the other.
5. **Elect.** Apply the **existing, unchanged** exact half-open sector convention to the developed sectors
   `[A_k, A_{k+1})`. The convention is not widened, narrowed, or re-oriented.
6. **Certify.** Return exactly one `VertexTransitOwnerCertificate`, or exactly one typed non-owner state from §3.

##### 2.2 Why straightest geodesic and not "the developed straight line"

This is the load-bearing choice of the turn, and it is what dissolves AX3's problem rather than managing it.

"Developed straight line" means `β = α + π`. On a star with `Θ ≠ 2π` that angle can exceed `Θ` (a **gap**: the
continuation points into no face) or the development can wrap past itself (an **overlap**: two developed sectors
claim it). Those are the two pathologies CB8-REV correctly refused to let a CB guess at.

`β = α + Θ/2` has neither. For any `Θ > 0` and any `α ∈ [0, Θ)`, `β mod Θ ∈ [0, Θ)` — it always lands in exactly one
half-open developed sector, because the sectors partition `[0, Θ)`. **Gap and overlap cannot arise.** The two
definitions coincide exactly when `Θ = 2π`, i.e. at every intrinsically flat vertex, which is the case the pipeline
overwhelmingly meets and the only case in which "straight" is unambiguous anyway.

So the amendment does not *resolve* the non-flat ambiguity by policy; it **chooses a semantics in which the
ambiguity does not exist**, and pays for that with the single, stated commitment that continuation at a cone point
bisects the cone. That commitment is visible, testable and reversible; a seam, an ordering or a tolerance would be
none of those.

##### 2.3 What is *not* redefined

A1 remains the authority on branch identity and edge transport. **`signedLift` maps a branch label; it is not, and
may not be described as, a transport of an arbitrary geometric ray.** The development above uses A0 source geometry
plus A1 fan topology. It does not consult, and may not consult, any per-face cross representative.

---

#### 3. AX3 — the residual typed states

Under §2 the gap and overlap cases are gone. Four states remain, and each is named rather than resolved silently.

| state | condition | disposition |
|---|---|---|
| `VertexTransitOwnerCertificate` | `β mod Θ` lies strictly inside one developed sector | the normal result |
| **boundary ray** | `β mod Θ` equals a developed radial position `A_k` **exactly** | **not a degeneracy.** The existing exact half-open convention already owns this: the ray belongs to the sector where it is `next`. It is recorded in the certificate as `onRadialRay = true` with the ray's identity, because it is the case a later regression must be able to find. |
| `VertexStarTruncatedBeforeContinuation` | the fan is **open** (barrier or source boundary) and `β` falls outside the admissible arc | **typed fail-closed.** The continuation leaves the admissible domain; A2a must terminate the trace or report, exactly as it already does at a barrier. Amendment 16 forbids restoring uniqueness by crossing a barrier, and this state is how that prohibition is reported rather than hidden. |
| `VertexStarDegenerateSector` | some `θ_i` is exactly `0` or exactly `π`, i.e. a degenerate incident triangle at this vertex | **typed fail-closed here, `RegularizableDegeneracy` only at the conditioning stage.** Amendment 20 already rules that value-changing repair of input geometry happens once, at the boundary, and is recorded. A degenerate sector discovered at A2a is an *input* defect surfacing late; A2a reports it with its locus and does not repair it. |

**Prohibited for every one of these:** candidate ordering, nearest-angle selection, a seam placed to break a tie, a
tolerance, and inventing a port or a face that source geometry does not supply (Amendment 21).

---

#### 4. AX4 — the exact kernel, and the honest cost

##### 4.1 The predicate class, named precisely

Electing a sector is deciding, for the cumulative sums `A_k`, the sign of

```
    (α + Θ/2)  −  A_k        =  ½·( Σ_{i≥k} θ_i  −  Σ_{i<k} θ_i )  +  α
```

Each `θ_i` is a face angle at the vertex with

```
    cos θ_i = D_i / √P_i ,    sin θ_i = √Q_i / √P_i ,
    D_i = u·w ,   P_i = (u·u)(w·w) ,   Q_i = P_i − D_i²        — all three EXACT rationals
```

so the decision is the **sign of a signed sum of arccosines of algebraic numbers**. Composing the rotations exactly
places the result in a tower `ℚ(√Q_1, √P_1, …, √Q_k, √P_k)` of degree up to `4^k` in the fan length `k`.

> **Amendment 23 — where an exact decision has no bounded algebraic representation, the architecture must state the
> budget, not hide it.** A topological decision whose exact evaluation grows with an input parameter is admissible
> only if the producer (a) publishes a certified filter that returns the provably-correct answer or defers, (b)
> names an exact fallback that always terminates and is actually implemented, and (c) declares an explicit budget on
> the parameter together with a **typed fail-closed state** for inputs that exceed it. "The filter was
> inconclusive" is never an answer, and a budget that is not published is not a budget — it is an undiscovered
> failure mode. This is the exactness counterpart of Amendment 19: an unbounded computation with no declared limit
> is an unreportable exit wearing a performance costume.

##### 4.2 The chosen route

**Certified filter + specified exact fallback**, of AR2's three families. Concretely:

- **Filter.** Interval arithmetic over the same composition. It resolves every configuration in which `β` is not
  *exactly* on a radial ray, in time linear in the fan length, and it defers otherwise. It is certified in the
  Amendment 18 sense: it returns the provably-correct sector or it defers. It may never return an approximation.
- **Exact fallback.** Sign determination by successive elimination of radicals (repeated isolation-and-squaring),
  which is `O(2^k)` exact rational operations for a fan of length `k` and always terminates. This is the *only*
  path that decides the boundary-ray case of §3, so it is load-bearing, not decorative.
- **Budget.** The producer publishes a fan-length budget and raises a typed
  `VertexStarExactBudgetExceeded` above it. The budget must be **at least 16**, which covers every valence in every
  committed fixture with room to spare, and the constant must appear in the certificate — not in a comment.

The three inadmissible routes are restated so a later turn cannot rediscover them as ideas: plain
`FieldExactRational` hinge rotation (the field is not closed under the construction), floating transport followed by
`from_double_exact` (Amendment 18, and the CB6 defect verbatim), and "filter inconclusive ⇒ reject" (which silently
converts the boundary-ray case into a failure).

##### 4.3 A structural exemption worth stating

The general cost above is the *worst* case, and it is worth recording that the real fixture does not pay it. At the
measured locus every sign test reduced to **rational identities alone** (§5). A producer may therefore short-circuit
on exactly-recognizable rational relations — a right angle is `u·w = 0`; two angles are complementary iff
`D₁D₂ ≥ 0` and `(D₁D₂)² = Q₁Q₂`; supplementary iff `D₁D₂ ≤ 0` and `(D₁D₂)² = Q₁Q₂` — provided each short-circuit is
an exact identity and the general path remains reachable. This is an optimization, never a semantics.

---

#### 5. AX6 — the mechanical proof at vertex 30

All of the following are **EXACT** rational facts computed from the committed
`mechanical_feature.obj`. No factorization and no floating point is used in any of them.

##### 5.1 The star

Vertex 30 has one closed, consistently oriented six-face fan. Anchored at the arrival face and walked in fan order:

| fan step | source row | canonical face | radial ray reached | face angle `θ` |
|---:|---:|---|---:|---|
| 0 | **43** | `(24,30,32)` | 32 | **exactly `π/2`** (`u·w = 0`) |
| 1 | 218 | `(30,32,123)` | 123 | **exactly `π/2`** (`u·w = 0`) |
| 2 | 209 | `(30,119,123)` | 119 | `θ₂₀₉` ≈ 0.500840763396 |
| 3 | **208** | `(30,31,119)` | 31 | `θ₂₀₈` ≈ 1.069955563399 |
| 4 | **41** | `(25,30,31)` | 25 | `θ₄₁` ≈ 0.865430437682 |
| 5 | 40 | `(24,25,30)` | 24 (closes) | `θ₄₀` ≈ 0.705365889113 |

Every `θ_i` satisfies `Q_i > 0`, so every angle is strictly in `(0, π)`: no degenerate sector, `VertexStarDegenerateSector`
does not apply. The vertex is regular, not barrier-absorbed and not barrier-incident, so the fan is **closed** and
`VertexStarTruncatedBeforeContinuation` does not apply.

##### 5.2 The cone angle is exactly `2π` — proved, not observed

CB8-REV recorded a float angle-sum consistent with `2π` and explicitly declined to accept it as proof. It is now
proved, by four rational identities and nothing else:

```
  θ(43)  = π/2                          EXACT:  u·w = 0
  θ(218) = π/2                          EXACT:  u·w = 0
  θ(209) + θ(208) = π/2                 EXACT:  D₂₀₉·D₂₀₈ ≥ 0  and  (D₂₀₉·D₂₀₈)² = Q₂₀₉·Q₂₀₈
  θ(41)  + θ(40)  = π/2                 EXACT:  D₄₁ ·D₄₀  ≥ 0  and  (D₄₁ ·D₄₀ )² = Q₄₁ ·Q₄₀
  ────────────────────────────────────────────────────────────────────────────────────────
  Θ(v30) = 4 · π/2 = 2π                 EXACT
```

The complementarity test is the rational form of `cos(θ₁+θ₂) = 0`. The two relations are **not** an artifact of
looking for them: the same test over all six other pairings of the four non-right angles returns false in every
case, so the decomposition is the fixture's actual structure — a CAD surface whose quads are split into triangle
pairs — and not a coincidence fitted after the fact.

**Consequence:** vertex 30 is intrinsically flat, so Amendment 22's `β = α + Θ/2` coincides exactly with `α + π`
here. The proof does not depend on that coincidence; it is recorded because it means the mechanical witness cannot
distinguish the two semantics, which is a limitation of the witness and the reason AX7 exists.

The star is genuinely **non-coplanar**: the hinges `43|218` and `208|41` have non-parallel face normals, so this is
a folded fan, not a flat patch drawn in 3D.

##### 5.3 The developed chart, and the finding

With the chart anchored at face 43 and ray 24 at angle 0, the developed radial positions are

```
   ray  24 :  0
   ray  32 :  π/2                    EXACT
   ray 123 :  π                      EXACT
   ray 119 :  π + θ₂₀₉
   ray  31 :  3π/2                   EXACT   (because θ₂₀₉ + θ₂₀₈ = π/2)
   ray  25 :  3π/2 + θ₄₁
   ray  24 :  2π                     EXACT   (because θ₄₁ + θ₄₀ = π/2)
```

giving the developed sectors

```
   row  43 = [0,        π/2)      arrival face, excluded by FaceInterior
   row 218 = [π/2,      π)
   row 209 = [π,        π + θ₂₀₉)
   row 208 = [π + θ₂₀₉, 3π/2)
   row  41 = [3π/2,     3π/2 + θ₄₁)
   row  40 = [3π/2 + θ₄₁, 2π)
```

The seed is anchored in face 43, so `α ∈ [0, π/2)` — and `α ≠ 0` because `arrivalMode = FaceInterior` excludes the
radial ray. The continuation therefore lies at

```
   β = α + π  ∈  (π, 3π/2)  =  sector(209) ∪ sector(208)      EXACT
```

because `sector(209) ∪ sector(208) = [π, 3π/2)` is exactly the rational relation `θ₂₀₉ + θ₂₀₈ = π/2` proved above.

**One seed yields one certificate, and the split point is exact:**

- `α < θ₂₀₉` ⇒ owner is **row 209 `(30,119,123)`**;
- `α > θ₂₀₉` ⇒ owner is **row 208 `(30,31,119)`**;
- `α = θ₂₀₉` ⇒ `β` is exactly on radial ray **119**, and the unchanged half-open convention assigns it to the sector
  where that ray is `next` — the boundary-ray case of §3, decided by the exact fallback, never by a tolerance.

##### 5.4 What this falsifies

TB4 and TB6 both published **two** candidates: row 41 `(25,30,31)` and row 208 `(30,31,119)`.

> **Row 41 is not reachable by any continuation from arrival face 43.** Its developed sector is
> `[3π/2, 3π/2 + θ₄₁)`, and `β < 3π/2` for every admissible `α`. This is an EXACT consequence of
> `θ₂₀₉ + θ₂₀₈ = π/2`, which is a rational identity over the committed coordinates.

That is a **stronger** falsification than the cardinality argument the checkpoint has been running on since TB4.
TB4-REV proved that two elections imply two distinct data were tested. This proves *which* of the two elections is
geometrically impossible: not "the election is ill-posed", but "one of the two answers it produced is wrong about
the surface". The current mechanism elected a face that the intrinsic geometry cannot reach, because it asked face
41's own cross representative whether face 41's own wedge would accept it — a question every face can answer yes to.

It also means the corrected producer has a **known expected answer** at the measured locus for the first time in the
checkpoint: row 209 or row 208, split at `α = θ₂₀₉`, never row 41. AX6 is discharged, and the answer was not
overwritten to match the current expectation — it contradicts it.

---

#### 6. AX5 — the owning contract

- **A0** continues to own exact source support, coordinates and topology.
- **A1 `FieldTransportAtlas`** continues to own cross-branch identity and edge transport/lift, and is **not**
  redefined as a ray transport.
- **A2a branch continuation** writes exactly one `VertexStarRaySeed` per vertex-arrival event (AX1).
- **A2a vertex-star transit authority** — a derived, A2a-local single-writer object, not a new pipeline stage —
  consumes A0 geometry, immutable A1 fan topology and that one seed, and writes exactly one
  `VertexTransitOwnerCertificate` or one typed non-owner state from §3.

**Consumers.** `resolve_field_vertex_transit` is the only function that may consume the new authority, and its
result becomes the certificate. Candidate enumeration survives **only** as the set being tested; it writes nothing.
The following move to diagnostic-only and leave the decision path entirely:

```cpp
  incomingDirection = nextPairing->direction;     // the CB7/CB8 defect — removed from the decision
```

together with every per-candidate `representativeDirection` test and every use of `signedLift` as a ray transform.
The exact half-open predicate `direction_in_vertex_sector` is **kept unchanged** and is applied to developed
sectors instead of to per-face representatives — the predicate was never the defect, and TB4-REV's partition proof
remains valid and is now the reason the developed election is single-valued.

---

#### 7. AX7 — the regression identity and its witness

##### 7.1 Why vertex 30 cannot be the only witness

Vertex 30 is intrinsically flat (§5.2), so it cannot distinguish `β = α + Θ/2` from `β = α + π`. It is an excellent
falsifier of the **old** mechanism and a poor discriminator of the **new** semantics.

##### 7.2 The witness to derive

An exact **non-coplanar folded fan** with:

1. exact rational vertex coordinates;
2. a closed fan whose per-face angles are certified by the rational tests of §4.3, so the cone angle is known
   exactly and the expected owner is derivable by hand;
3. **at least one non-coplanar hinge**, so it is a genuine development and not a flat patch;
4. per-face cross representatives deliberately chosen so that **more than one** candidate face would accept its own
   representative — this is the property that makes it falsify `incomingDirection = nextPairing->direction`;
5. a seed placed strictly inside its arrival sector, plus a second instance placed exactly on a radial ray, so the
   boundary-ray case and the exact fallback are both exercised.

The extracted vertex-30 star is the recommended starting geometry for (1)–(3): seven vertices, six faces, exact
coordinates already committed, flatness already proved, non-coplanarity already checked. Property (4) is a
*field* choice, not a mesh choice, and must be constructed and published with the fixture. A second witness with
`Θ ≠ 2π` is required to discriminate the semantics of §2.2, and its expected owner must be derived from
Amendment 22 before the code is written, never read off the implementation.

##### 7.3 Selector governance

Selector **373** stays byte-identical. Ordinal **374** may be appended — exactly one line, nothing above it moving,
respelled or removed — **only after** the witness of §7.2 is shown to **fail** under
`incomingDirection = nextPairing->direction` and to **pass** under the frozen authority. Compiling it is not
sufficient; CB8-REV was right about that and this record does not relax it. The current minimal identity
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` is a channel test: it proves exact
state is published and proves nothing about which datum was tested, so it may be strengthened in place or replaced,
but it may not be admitted as-is.

---

#### 8. AX8 — the audit contract

Frozen fields, in decision order. This is the contract the later projection repair must publish; it deliberately
describes the **new** datum, because publishing richer evidence for the invalid per-cell datum would only make the
wrong decision better documented.

| group | fields |
|---|---|
| **seed** | `sourceVertex`, `arrivalFace`, `arrivalBranch`, exact `arrivalRay`, `arrivalMode`, and the seed's provenance (the trace/event that anchored it) |
| **kernel** | which route decided it — `Filter`, `ExactFallback`, or `RationalShortCircuit` — and, when the exact fallback ran, the fan length and the budget in force |
| **development** | the ordered fan, each face's exact `(D_i, P_i, Q_i)`, the truncation reason where the fan is open, and the exact cone angle or the certified relations that determine it |
| **election** | per developed sector: its identity and the exact sector-membership outcome; then `ownerCardinality`, the elected owner, and `onRadialRay` with the ray's identity when the continuation is exactly on one |
| **failure** | the typed non-owner state from §3 with its locus, and `VertexStarExactBudgetExceeded` with the fan length that exceeded the budget |

`M3-CP4c3-TB6-CAND-01` is closed by publishing **this** contract at the projection boundary
(`RemeshPipeline.cpp::network_failure_locus` plus the `RemeshDiagnostics` DTO), not by publishing today's rows.

**The authoring rule that this turn also owes the record**, because the same loss will otherwise recur at the next
new diagnostic shape: a measure that orders a measurement must name the identity or the projection that will carry
it, and a diagnostic added to a typed error for operational reporting must have its projection extended **in the
same change**. `vertexTransitStates` was built correctly three times and read zero times because three consecutive
measures each ordered rows that nothing was obliged to carry. `LESSONS.md` 75.

---

#### 9. AX9 — successor gate

AX1–AX8 are internally complete and one exact implementation route is feasible (§4.2), with the measured locus
decidable by rational identities alone (§5.2). **One bounded Code + Build successor is authorized**, under a new
measure prefix as AX9 requires.

##### `M3-CP4c-3-CB9` — measures **AY0–AY9**, Code + Build, runtime-free, GMP/GMPXX linked

**AY0 — preconditions.** Selector 373 byte-frozen and recomputed at authoring and preflight; accepted 365
untouched; `selected_gate=NONE`; `gate_execution_authorized=false`; no runtime, no gate, no benchmark.

**AY1 — the seed.** Implement `VertexStarRaySeed` per §1, written once by A2a branch continuation, with the sign and
chart conventions exactly as frozen. One seed per arrival event.

**AY2 — the development and the election.** Implement §2 with the **unchanged** `direction_in_vertex_sector`
predicate applied to developed sectors. Remove `incomingDirection = nextPairing->direction` and every per-candidate
representative from the decision path; retain them as audit rows only.

**AY3 — the kernel.** Implement the certified filter, the exact fallback, and the published budget of §4.2, in that
dependency order. The fallback must be implemented and reachable, not stubbed: it is the only path that decides the
boundary-ray case. Publish the budget constant in the certificate.

**AY4 — typed states.** Implement the four outcomes of §3, each with its locus, and record the diagnostic **before**
any conditional that can skip a state (Amendment 19).

**AY5 — the witness.** Derive and commit the folded-fan fixture of §7.2 with its exact coordinates, its exact
expected owner derived from Amendment 22, its boundary-ray instance, and its field construction. **Prove in the
report that it fails under the old mechanism**, quoting the old and new results side by side.

**AY6 — selector 374.** Append exactly one ordinal only if AY5's falsification is demonstrated. Selector 373 keeps
every byte. If AY5 does not falsify, **do not create selector 374** — report and stop.

**AY7 — the audit contract.** Implement §8's fields on the typed error, **and extend the `RemeshDiagnostics`
projection in the same change** so the rows have a reader. This is the closure of `M3-CP4c3-TB6-CAND-01`.

**AY8 — audit by assumption.** Two predicates, findings listed, each with a site named **outside** the ones this
record names: *"a value reaching a topological decision was re-expressed by its consumer"* and *"an exact
computation has no declared bound on its input size."*

**AY9 — prohibited.** Restoring any floating-point step in the decision chain, including
`from_double_exact` of a transported value (Amendment 18). Treating `signedLift` as a ray transform. Deciding from a
candidate's own representative. Candidate ordering, nearest-angle, seams, or **any** tolerance. Changing the
half-open sector convention, the `FaceInterior` rule, or barrier/boundary truncation. Inventing a port or a face
(Amendment 21). Repairing degenerate input geometry at A2a rather than reporting it (Amendment 20). Publishing an
owner without its certificate. Stubbing the exact fallback, or shipping an unpublished budget. Touching ordinal 370,
the prescribed sphere or saturation. Reopening Amendments 12–23. Changing any selector byte other than the single
authorized ordinal-374 append. Executing Directional runtime, running a gate, or benchmarking in a CB turn.

**Stop rule.** If the exact fallback cannot be implemented within the frozen semantics, CB9 stops and reports, as
CB8 correctly did. A second architectural stop is a valid outcome; a tolerance is not.

---

#### 10. Falsifiable predictions

1. **The corrected producer elects row 209 or row 208 at vertex 30 — never row 41.** Anything else contradicts
   §5.3, which is a rational identity over committed coordinates.
2. **Owner cardinality becomes exactly 1** at that locus, without any tie-break, because the developed sectors
   partition `[0, Θ)`.
3. **The filter decides vertex 30 without invoking the exact fallback**, since `α = θ₂₀₉` exactly is a measure-zero
   coincidence; the fallback will first be exercised by AY5's deliberate boundary-ray instance.
4. **Ordinals 1–365 stay green.** Every change is confined to the A2a vertex-transit decision and to additive
   diagnostics.
5. **A non-flat witness will separate `β = α + Θ/2` from `β = α + π`.** If it does not, the fixture is
   intrinsically flat and is not the discriminator §7.2 requires.

#### 11. Accounting and dispositions

Accepted 365 green in the last authoritative run; every finding on an unaccepted or definition-level surface.
**44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic packages **73**,
**+0 events / +0 recurrences**.

- **`M3-CP4c3-TB3-R1-CAND-01`** — **ACTIVE / SEMANTICS FROZEN**. The definition gap CB8-REV named is closed by
  Amendments 22 and 23, and the expected answer at the measured locus is now known exactly. Owned by AY1–AY3.
- **`M3-CP4c3-TB6-CAND-01`** — **ACTIVE / CONTRACT FROZEN**. §8 fixes what the projection must publish; AY7 closes
  it at the projection boundary.
- **`M3-CP4c2-TB-X2-R8-CAND-02`**, **`M3-CP4c2-TB-X2-CAND-04`**, **`M3-CP4c2-TB-X2-R10-CAND-01`**,
  **`M3-CP4c3-DEFN-R1-CAND-01`** — all unchanged and deferred; untouched by this turn by AX0.
- **New: `M3-CP4c3-DEFN-R2-CAND-01`** — *an exact computation with no declared bound on its input size.* Amendment
  24 requires a published budget and a typed state; AY8's second predicate sweeps for other instances.

#### 12. Exact next turn

**`M3-CP4c-3-CB9`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AY0–AY9**. Selector 373 stays frozen;
selector 374 is conditional on AY5. CP4c-2 remains **CLOSED / ACCEPTED at 365/365**; CP4c-3 remains **OPEN**.

---

## Part VII — M3-CP4c-3 DEFN-R3

*Authored in place on 2026-09-04 at `M3-CP4c-3-DEFN-R3`. This part is a **DEFN turn**, and under the project's turn
workflow **`DEFN` absorbs `REVIEW + PLAN`**: it freezes definitions, adjudicates the inherited candidates, and
issues its successor's measures in one turn. It supersedes Parts IV–VI where they conflict, and only there.*

**Boundary.** No Directional runtime, configure, compile, link, package, or product/test/fixture/selector mutation
occurred in this turn. Accepted selector **365** is untouched; selector **397** is byte-frozen. Measures
**CF0–CF9**, frozen by `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` §8 (folded into
`M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB24-REV`).

---

### 1. CF0 — the state this part inherits

Current runtime authority is `M3-CP4c-3-TB23-R1` on selector 397: **389 PASS / 8 RED**, accepted **1–365 =
365/365**, reds `{366, 367, 368, 369, 370, 374, 393, 397}`. The mechanical actual embedded complex is **certified
cellular** — `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`, every face proving disc topology.

Ordinal 366 has stopped at `UncutFaceComponentOrbitSeedNotUnique` since TB19: source-face component **0**, **191**
faces, `seedState=Multiple`, seed orbits `[0,1,3]`, boundary attribution **81 / 1 / 1** over 97 edges. Four
successive turns tried to determine whether that is a missing barrier or a mis-read seed. **None succeeded**, and
`M3-CP4c3-TB21-CAND-01`'s two branches have never been discriminated.

---

### 2. CF1 — what a certified face must publish

#### 2.1 The finding that decides it

`SurfaceCutGraphFaceCertificate` publishes exactly four fields per certified face:

```cpp
std::size_t orbit; std::size_t boundaryWalkCount;
std::size_t boundaryArcCount; bool discTopologyEstablished;
```

There is **no source-face membership and no boundary arc list**. The question every recent diagnostic has tried to
answer — *which certified face contains this source triangle* — is therefore not answerable by reading the
certificate. Each attempt had to **reconstruct** it from `walk.orbitByDart`, which is the seed quantity, and each
collapsed identically:

| Turn | Intended measurement | Why it reported nothing |
|---|---|---|
| CB24 | projection faithfulness residual | predicate **unsatisfiable by construction** |
| CB24 | per-side certificate faces | **aliased to the seed** |
| CB25 | certified-face ownership | edge-side path **re-derives the seed's dart orbit**; whole-face path collapses on "exactly one element" over a **coarser** partition |

#### 2.2 The certifier already computes the answer and discards it

`certify_actual_embedded_graph` (`src/geometry/SurfaceCutGraph.cpp:356–380`) begins by calling
**`build_embedded_graph_topology(sourceFaces, sourceVertexCount, sourceAuthority, network, cutEdges)`** — the
identical function `GlobalTopologyPlan` calls at `:2364` — and derives `embedded.faceWalk` from it. The certifier
holds the complete embedded topology, its arcs, its source topology and its face walk. It then publishes **counts
only**, and the plan rebuilds the identical structure to re-derive what the certifier already had.

**This is therefore a publication decision, not a new computation.**

> **AMENDMENT — WITHDRAWN AT `M3-CP4c-3-TB24-REV`.** The sentence immediately above is **false for the faces that
> matter** and is withdrawn. It is retained, struck, so a reader can see what was believed and why the successor
> failed. The face walk's darts are darts of *network and cut arcs*: a source face has a directly readable
> certified orbit **only if it is incident to an arc or crossed by a trace**. Every other source face — including
> most of component 0's 191 — has no dart of its own, and its owner must still be **propagated** across
> non-barrier edges from a face that does. That propagation is exactly the seeding algorithm DEFN-R3.2 set out to
> delete. CB27 implemented DEFN-R3.1 faithfully, re-implemented the propagation inside the certifier because it
> had to, and reproduced the identical failure — component 0, owner orbits `[0,1,3]`, locus `(0,1,2)`.
>
> **The normative decision of DEFN-R3.1 below is UNCHANGED and remains in force.** The certifier is the right
> authority. What is withdrawn is only the claim that it already knows the answer. See
> `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` §4 (folded into `M3_CP4c_Consolidated_Record.md` at
> `M3-CP4c-3-TB25-REV`), `M3-CP4c3-TB24-REV-CAND-02` and `LESSONS.md` 121.

#### 2.3 Normative decision — DEFN-R3.1

> **The owner map of a certified complex is a property of certification, and must be produced by the certifier.**
> `SurfaceCutGraphCellularityCertificate` **must publish a total source-face owner map**:
>
> - for a source face the network does **not** cross: the **single** certified-face id whose interior contains it;
> - for a source face the network **does** cross: the **set** of certified-face ids owning its local fragments,
>   keyed so that a consumer can attribute each fragment side without re-deriving it;
> - every published id must be one of that same certificate's `faces[].orbit` values;
> - the map must be **total** over the source faces of the certified complex.
>
> **Proof obligation.** `proves_cellularity()` is extended to require the map to be total and its ids to be drawn
> from the certificate's own faces. A certificate that cannot produce a total map does **not** prove cellularity —
> it reports a typed failure naming the first unowned source face.

**Rationale.** A consumer must never re-derive a partition its producer already computed. Re-derivation from
partial evidence is precisely what produced the aliasing, the unsatisfiable predicate and the coarse projection.

**What this does not decide.** Whether the two `build_embedded_graph_topology` invocations are unified into one is
an implementation question, not a definition. It is recorded as `M3-CP4c3-DEFN-R3-CAND-01` and left to the
successor's judgement; **two sources of truth for one object is a standing hazard**, and any unification must keep
the certifier's result authoritative.

---

### 3. CF2 — is the seed guard's premise checkable, and what replaces it

**Today: no.** The guard requires each connected component of uncut source faces to receive exactly one orbit seed
from its labeled neighbours. Whether that holds is a statement about **certified faces**, and certified faces do
not say which source faces they contain. The premise is unverifiable as the system publishes today, which is why
`seedState=Multiple` has been neither confirmed nor refuted for four turns.

**Under DEFN-R3.1: yes, and the guard's present form becomes unnecessary.**

> **DEFN-R3.2 — ownership is read, not seeded.** With a total owner map published, a source face's certified owner
> is a **lookup**. The seeding construction — `componentBarriers`, the unlabeled-face component partition,
> `seedOrbits`, and the per-edge seed rule with its `SingleFaceOwner` / `edgeOrbitEvidence` disjunction — is
> **replaced** by that lookup. `UncutFaceComponentOrbitSeedNotUnique` is **not weakened and not deleted**: it is
> **relocated** into a consistency check on the published map, failing closed when a component's faces do not all
> carry the same certified owner, and naming the component and the conflicting owners.

**This satisfies Parts IV and V.** Those parts prohibit *weakening* `UncutFaceComponentOrbitSeedNotUnique`. The
replacement is **strictly stronger**: it decides the same property from an authoritative total map instead of
reconstructing it from partial neighbour evidence, and it can name its own failure. A prohibition on weakening is
not a prohibition on replacing with something that decides more.

---

### 4. CF3 — the barrier set for any retained projection

`resolve_certificate_face_projection` unites source faces across every edge **not** in `embeddedGraphSourceEdges`,
which holds **mandatory and cut source edges only**. It therefore merges across trace-crossed edges, making its
components strictly coarser than the seed construction's — and a coarser component necessarily collects owners
from several certified faces, which is why all 191 faces reported `unavailable`.

> **DEFN-R3.3 — a derived partition must be at least as fine as the partition whose property it adjudicates.** Any
> source-face projection used to reason about certified ownership **must** use the full barrier set
> `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`. A projection over a strict subset of that set is **not**
> admissible evidence about ownership and may not be published as such.

Under DEFN-R3.2 no such projection is required at all. This clause binds any projection that is nevertheless
retained for cross-checking, so the omission cannot recur.

---

### 5. CF4 — adjudication of `M3-CP4c3-TB20-REV-CAND-02`

Parts IV and V each prohibit *"relaxing / weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`."* `M3-CP4c-3-CB21` made the fragment-count invariant's **low side**
non-fatal, and `M3-CP4c-3-TB18-REV` authorized that without consulting those lists.

**Both facts are accepted, and the substantive question has since been settled against the prohibition.**

- `|owners| = k + 1` equates a **local** fragment count with the cardinality of a set of **global** face-walk orbit
  owners. Equality requires the local-fragment → global-owner map to be injective.
- TB18 **measured** a counterexample on a witness whose complex is **certified cellular**: arc 15 with
  `forwardOrbit = reverseOrbit = 0`. On a cellular complex containing a bridge, the two sides of an arc genuinely
  share a face. The invariant is therefore **false**, not merely unproven.
- Part I §3's reasoning — which is what made the sibling guard "correct" — turns on a premise (**non-cellularity**)
  that TB21 measured false for the mechanical witness. The prohibition was authored when the only observed
  instance was the torus, where non-cellularity was independently proved.

> **DEFN-R3.4 — the prohibition on the fragment-count invariant is LIFTED, for stated reasons, and only for it.**
> `|owners| = k + 1` is not an invariant of a valid cellular complex, so a check asserting it cannot be preserved
> as written. `M3-CP4c-3-CB21`'s one-sided relaxation **stands and is not reverted**: its accepted-boundary safety
> was proved by construction — the validation loop is pure, and `>` holds on a strict subset of `!=`, so the
> failing set only shrinks and no previously-passing input changes.
>
> **The prohibitions on `proves_cellularity()` and `UncutFaceComponentOrbitSeedNotUnique` remain in force**, and
> DEFN-R3.1 *strengthens* the former while DEFN-R3.2 *relocates* rather than weakens the latter.

`M3-CP4c3-TB20-REV-CAND-02` is therefore **CLOSED — prohibition lifted with reasons**. Recorded so no successor
re-opens it by citing Parts IV/V alone: **Part VII governs where it conflicts with Parts IV–VI.**

---

### 6. CF5 — carried forward unweakened

`proves_cellularity()` (strengthened by DEFN-R3.1, never relaxed); the accepted **1–365** boundary; the certified
cellularity evidence `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`; **CB21's correction**; the closure of
ordinals 371/372/391/392; and the separate ownership of **367/368/369/370/374**, vertex-30 and the
finalize/contact fall-through. **There is still no vertex-30 discriminator.**

Also carried: Part I §3 is an **implication with a premise** and licenses "the network is not a cut graph" only
where non-cellularity is independently established; the face walk is a validated total permutation; shared orbit
ownership by the two sides of one arc is legitimate topology.

---

### 7. CF6 — the undiscriminated branches, and what would discriminate them

**Recorded plainly: neither branch of `M3-CP4c3-TB21-CAND-01` has ever been discriminated.** The two readings of
component 0's `[0,1,3]` remain:

- **(a) missing barrier** — two boundary edges genuinely separate certified faces and are absent from
  `componentBarriers`;
- **(b) mis-read seed** — the edges are ordinary and the seed rule reported an orbit that does not face the
  component.

> **DEFN-R3.5 — the discriminator.** Under DEFN-R3.1 the question is decided by **one lookup, not a measurement**:
> take the certified owners of the 191 member faces of component 0 from the published map.
> **If they are not all equal, reading (a) holds** — the component spans certified faces, and the barrier set is
> missing the separations between them, which the differing pairs name directly.
> **If they are all equal, reading (b) holds** — the component lies in one certified face and the two minority
> seeds were mis-reads.
>
> No further diagnostic instrumentation is authorized to answer this. If the published map cannot be produced,
> that is a DEFN-R3.1 failure and is reported as one.

---

### 8. CF7 — disposition of ordinals 393 and 397

**Ordinal 397 — `UnrelatedTopologyErrorLocusRemainsByteIdenticalAfterCertificateDiagnostics` — must be FIXED.**
CB25 appended `;cutCandidateCount=0` to the rendered locus of an **unrelated** topology error; the witness expected
`;sourceFace=2,4,6` and received `;sourceFace=2,4,6;cutCandidateCount=0`. The defect is in the product's locus
rendering, not in the expectation.

> **DEFN-R3.6.** Restore byte-identical rendering for errors the diagnostic work does not own. **Relaxing or
> re-scoping ordinal 397's expectation is prohibited.** A byte-identical regression witness that is edited to
> match a regression has been converted into its opposite.

**Ordinal 393 — `MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` — is SUPERSEDED, and its
assertions are REPLACED in place.** Its expectations (`differing > 0`, `certifiedFaceDiffersFromSeed`) were written
to falsify a *reconstruction*. Under DEFN-R3.2 the reconstruction and its seed both cease to exist, so those
expectations are not merely unsatisfiable but **meaningless** — there is no seed for a certified face to differ
from.

> **DEFN-R3.7.** The successor Code + Build **replaces ordinal 393's assertions** with the DEFN-R3.1 contract: the
> published owner map is total, its ids are drawn from the certificate's own faces, and the certified owners of a
> named component are reported. **The ordinal is retained and stays gating**; the identity name may be updated to
> match its new contract. It is **not** deleted, **not** reordered, and **not** made non-gating.
>
> This is the correct route rather than a permanent non-gating carve-out: the identity's *purpose* — falsifiable
> evidence about certified ownership — is preserved, while only the obsolete mechanism it referenced is replaced.
> The change must be recorded in the successor's report with the before and after assertions.

**Selector governance.** Selector 397 stays byte-frozen through the successor; identities are appended only, never
removed or reordered. Replacing an identity's assertions is a test-source change, not a selector change.

---

### 9. CF8 — successor gate

#### `M3-CP4c-3-CB27` — Code + Build, measures **CG0–CG9**, runtime-free, GMP/GMPXX linked

- **CG0** — accepted 365 untouched; selector **397** byte-frozen and republished unchanged; the eight standard
  compile targets with **mandatory GMP/GMPXX linkage**; **no runtime**; no acceptance claimed.
- **CG1** — implement **DEFN-R3.1**: publish the total source-face owner map on
  `SurfaceCutGraphCellularityCertificate`, produced by the certifier from the topology it already builds, with ids
  drawn from its own `faces[].orbit`.
- **CG2** — extend `proves_cellularity()` with DEFN-R3.1's proof obligation: the map is total over source faces and
  its ids are certificate face ids. A certificate that cannot produce it reports a typed failure naming the first
  unowned source face.
- **CG3** — implement **DEFN-R3.2**: replace the seeding construction with a lookup, and relocate
  `UncutFaceComponentOrbitSeedNotUnique` into a consistency check over the published map that names the component
  and the conflicting owners on failure.
- **CG4** — implement **DEFN-R3.6**: restore byte-identical locus rendering for unrelated errors.
- **CG5** — implement **DEFN-R3.7**: replace ordinal 393's assertions with the new contract, recording before and
  after; keep the ordinal gating.
- **CG6** — discharge the two carried debts, both of which require source changes and so belong here:
  `M3-CP4c3-TB23-REV-CAND-01` — make `tests/TestFixturePaths.h`'s `test_data_root()` **fail closed** rather than
  return a non-existent path; and `M3-CP4c3-TB23-R1-REV-CAND-01`, which CG4 covers.
- **CG7** — witnesses: one per new published field through the **production** path; a witness that the owner map is
  total on all three fixtures; a witness that the relocated guard **names its component and conflicting owners**;
  and — per the standing rule that a diagnostic must be falsifiable — a **unit** witness proving the consistency
  check *can* fail and a **production** witness proving whether it *does*. Append the next selector **named by its
  resulting identity count**; 397 stays an exact prefix; regenerate
  `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **CG8** — audit by assumption; prove accepted ordinals **1–365** unaffected by construction, and that
  `proves_cellularity()` is only strengthened.
- **CG9** — publish the `M3-CP4c-3-TB24` discriminators: **(1)** 1–365 stay 365/365; **(2)** the owner map is
  published and total on the mechanical witness; **(3)** **the certified owners of component 0's 191 faces are
  reported — all-equal or not, which decides `M3-CP4c3-TB21-CAND-01` per DEFN-R3.5**; **(4)** ordinal 366 either
  clears or fails with the relocated guard naming its component and conflicting owners; **(5)** ordinals **393 and
  397 are green**; **(6)** carried surfaces 367/368/369/370/374 unchanged and 371/372/391/392 still PASS.

---

### 10. CF9 — prohibited

Inventing a certificate field without naming its producer and its proof obligation. Weakening
`proves_cellularity()` or `UncutFaceComponentOrbitSeedNotUnique` — DEFN-R3.1 strengthens the first and DEFN-R3.2
relocates the second; neither may be softened. Relaxing or re-scoping **ordinal 397's** expectation. Deleting,
reordering or de-gating **ordinal 393**. Publishing a source-face projection built on a strict subset of
`mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` as ownership evidence. Any further **diagnostic-only** turn on the
ownership surface — DEFN-R3.5 makes it a lookup. Any fixture-specific branch, tolerance, float-derived topological
decision, or accepted-boundary relaxation. Reverting `M3-CP4c-3-CB21`. Any sphere / saturation / ordinal-370 /
folded-cone / vertex-30 / finalize-contact work.

---

### 11. Falsifiable predictions

1. The owner map is producible from what the certifier already computes, without a new traversal — CG1 lands
   without adding a face walk.
2. `proves_cellularity()` continues to hold on all three fixtures after CG2 strengthens it; if it does not, the
   certificate was over-claiming and the failure names the first unowned source face.
3. Component 0's 191 certified owners are **not all equal**, making reading (a) — missing barrier — the live
   branch. *This is a prediction, not an authorization*: CG9-3 reports the fact either way, and a correction is
   frozen only by the review that reads it.
4. Ordinals 393 and 397 both go green under CG4/CG5; 397 going green requires no expectation change.

---

### 12. Accounting and exact next turn

`M3-CP4c3-TB20-REV-CAND-02` **CLOSES** (prohibition lifted with reasons, §5). New `M3-CP4c3-DEFN-R3-CAND-01` —
`build_embedded_graph_topology` is invoked independently by both the certifier and the plan, giving two sources of
truth for one object; **ACTIVE / ARCHITECTURAL / NON-GATING**, owner CG1's judgement.
`M3-CP4c3-TB21-CAND-01` remains **ACTIVE / GATING**, now with a stated discriminator (§7).
`M3-CP4c3-TB23-REV-CAND-01` and `M3-CP4c3-TB23-R1-REV-CAND-01` are assigned to **CG6/CG4**.
`M3-CP4c3-TB23-R1-REV-CAND-02` is assigned to **CG5**.

This is a definition turn: no runtime, no gate, **+0 stable events / +0 recurrences**. Totals remain **44 events /
14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **88**. Accepted authority
remains **365/365**; CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB27` — Code + Build, runtime-free, GMP/GMPXX linked, under CG0–CG9.**

---

## Part VIII — M3-CP4c-3 DEFN-R4

**Turn:** `M3-CP4c-3-DEFN-R4` — definition turn (absorbs REVIEW + PLAN).
**Frozen owner:** CR6–CR8 of `Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` (folded into `M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB32-REV`).
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.

Runtime authority entering this turn: `M3-CP4c-3-TB31`, selector 408, **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, certified source-face ownership **300 established / 0 unavailable / 0 conflicting**, plan
component 0 at **189 faces / seedCount 1 / `Unique` / `[0]`**. Stable accounting **44 / 14 / 30**, debt **5**,
packages **96**.

### 1. CR8 — why the guard became reachable, established from source

TB31-REV recorded that it could not determine this statically and required transcription from the retained log.
**It is determinable from source, and the transcription is unnecessary.**

- `build_regions` is defined at `GlobalTopologyPlan.cpp:629` and called at `:2212`. It contains
  `UncutFaceComponentOrbitSeedNotUnique`.
- `build_fragment_corner_incidence` is defined at `:405` and called at `:2014`, **from
  `build_region_certificates`** (`:1988`), which takes the already-built `regions` as a parameter.
- `build_region_certificates` therefore runs **after** `build_regions`.

**`TraceArcDoesNotSeparateItsSides` is strictly downstream of `UncutFaceComponentOrbitSeedNotUnique`.** It was
unreachable for as long as the seed guard fired. CB36 cleared the seed guard, the mechanical fixture reached region
certificate construction for the first time, and the next guard on that path fired.

**This corrects TB31-REV §2.2**, which inferred from line numbers that the guard sat *upstream* of the seed guard
and treated its reachability as unexplained. It is downstream, and its reachability is fully explained by the
pipeline advancing. **CB36 did not change the walk this function observes**, which removes the risk TB31-REV
flagged as the reason the transcription mattered.

`M3-CP4c3-TB31-REV-CAND-03`'s evidence-attachment concern is unaffected and is decided at §5 below.

### 2. What `FragmentCornerIncidence` actually is — DEFN-R4.1

TB31-REV called `(face, orbit)` a **fragment identity** and concluded the key was not injective. That description
is withdrawn. The structure is not a fragment index.

> **DEFN-R4.1 — normative.** `FragmentCornerIncidence`, `map<SourceFaceTopologyKey, map<orbit, set<SourceVertexId>>>`
> (`GlobalTopologyPlan.cpp:399–401`), is an **ownership map**: `fragmentCorners[face][orbit]` is the set of `face`'s
> corner vertices owned by **certified face `orbit`**. It is keyed by owning region, not by fragment, and it is not
> required to distinguish two fragments that share an owner.

Both consumers use it exactly that way:

- `:1893–1906` — `cutFace->second.find(owningOrbit)`: *"which of this face's corners belong to **my** region?"*,
  failing with `RegionSourceFaceOwningFragmentMissing` when the region owns none.
- `:1927–1945` — iterating `(orbit, corners)` to classify a vertex as `ownedByRegion` when `orbit == owningOrbit`
  and `ownedByOtherRegion` otherwise: *"mine, or another region's?"*

Neither asks how many fragments a face has, nor which geometric fragment a corner lies in. The `FragmentKey` used
for region interior connectivity (`:1693–1699`) carries `owningOrbit` as a **constant tag** for every face of the
region, so it too is region-scoped rather than fragment-scoped.

### 3. A bridge chord — DEFN-R4.2

> **DEFN-R4.2 — normative.** When a trace arc's two darts lie in the **same** face-walk orbit, both sides of its
> chord are owned by that one certified face. The correct value of `fragmentCorners[face]` is then a **single entry
> containing every corner of the face**. This is the correct answer under DEFN-R4.1, not a key collision.

The full-chord branch already produces it: `result[face][cornerOrbit].insert(sharedCorner)` (`:541–543`) and
`result[face][sideOrbit].insert(other corners)` (`:544–548`) merge into one entry when
`cornerOrbit == sideOrbit`, yielding all three corners under the single owning orbit. Both consumers then answer
correctly — the region owns all three, and no vertex is misattributed to another region.

### 4. `TraceArcDoesNotSeparateItsSides` is RETIRED — DEFN-R4.3

> **DEFN-R4.3 — normative.** `GlobalTopologyPlanErrorCode::TraceArcDoesNotSeparateItsSides` is **retired from the
> emission path**. `build_fragment_corner_incidence` must not reject a trace segment because its arc's two darts
> share a face-walk orbit. The enum entry remains declared so the typed-error surface and ledger history stay
> stable; it becomes unreachable.

Three reasons, each independently sufficient and all checkable:

1. **Its premise is refuted by a settled fact.** *"Shared orbit ownership by the two sides of one arc is legitimate
   topology; BS9-5 remains retired"* has stood since TB18, and DEFN-R3.4 measured exactly that on **arc 15**,
   `forwardOrbit = reverseOrbit = 0`, on a certified cellular complex.
2. **It contradicts the correction this checkpoint just proved.** The separating-arc barrier rule keys on
   `forwardOrbit != reverseOrbit` precisely because equal orbits mean *does not separate*, and deliberately leaves
   arcs 20 and 24 (`0/0`) alone. A guard that then rejects those arcs asserts the opposite of the rule that
   depends on them.
3. **The same function already accepts equal orbits on its other path.** The ray branch writes
   `result[face][ray.forwardOrbit]` and `result[face][ray.reverseOrbit]` (`:608–615`) with no guard, merging
   silently and correctly when they coincide. **The rejection is an internal inconsistency within one function, not
   a protection of the representation.**

This retirement is **a consequence of DEFN-R4.1 and R4.2, not a relaxation**. TB31-REV's caution — that deleting
the guard would merge two distinct fragments — was correct about the mechanism and wrong about the consequence:
the merge is what DEFN-R4.1 requires. The successor must record the merge as intended behaviour at the site, so a
later reader does not reintroduce the guard.

**Prohibited:** removing the guard without recording DEFN-R4.1's contract in the code, and re-deriving fragment
identity from the orbit anywhere downstream.

### 5. Frontier evidence must not hang off one failure code — DEFN-R4.4

> **DEFN-R4.4 — normative.** The plan-side failing-component **face-set digest**, the certifier census identity and
> the `censusCorrespondence` / subset relation are properties of the plan's state, not of any particular typed
> failure. They must be published on the failure locus **whenever the plan terminates during region construction or
> region certification**, independently of which typed code terminates it.

They vanished at TB31 solely because the terminal code changed, which is the defect
`M3-CP4c3-TB31-REV-CAND-03` names.

### 6. Witnesses must not name the failure — DEFN-R4.5

> **DEFN-R4.5 — normative.** A witness whose contract is *"this evidence is published when the production path
> fails"* must assert the **evidence**, not **which** typed failure produced it. Ordinals **390, 393, 406 and 407**
> have their assertions **replaced in place**: each keeps every contract it legitimately owns, and each stops
> asserting `terminalFailureDetailCode == "UncutFaceComponentOrbitSeedNotUnique"`. Ordinals, names and selector
> bytes are unchanged; all four remain **gating**.

Where an identity genuinely needs a typed failure to exist, it asserts that the failure **carries the required
evidence fields**, not its name. This is the disposition CB35 applied to ordinals 390 and 404 and TB30 proved
correct, generalized.

**This is a restoration, not a weakening.** Six identities across two forward steps have redded because they pinned
the failure the product used to make; the two that survived both steps — **404 and 408** — assert publication and
completeness instead. That is the standard.

### 7. What DEFN-R4 does not decide

1. **Source-face ownership is CLOSED** — 300/300 certified, component 0 unique at `[0]`. The separating-arc barrier
   rule stands **at both sites** and is not re-opened.
2. **Ordinal 398 is untouched.** It fails on the prescribed sphere
   (`NotProductionReady/CellularityNotEstablished`), owned by `M3-CP4c2-TB-X2-CAND-04`. It is **not** an ownership
   gate and must not be re-scoped to exclude the sphere.
3. **Ordinals 368, 369, 370 and 374** keep their separate owners and are untouched.
4. **The two partitions are not unified.** `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` stay open; the
   plan's partition now yields a unique owner, so the divergence does not hold the frontier and its resolution is
   not required here.
5. **No new diagnostic contract** on ownership or on fragments. Everything above is decided from source.

### 8. Successor — CS0–CS6, `M3-CP4c-3-CB37`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`.

- **CS1** — retire the `TraceArcDoesNotSeparateItsSides` emission in `build_fragment_corner_incidence`
  (`:474–479`), per DEFN-R4.3. Record DEFN-R4.1's ownership contract at the site so the merge reads as intended.
  The enum entry stays declared.
- **CS2** — publish the plan-side failing-component digest, the certifier census identity and the
  `censusCorrespondence` / subset relation on every region-construction and region-certification failure locus, per
  DEFN-R4.4.
- **CS3** — replace in place the assertions of ordinals **390, 393, 406, 407** per DEFN-R4.5. Ordinals, names and
  selector bytes unchanged; all remain gating. **Nothing any of them legitimately owns may be relaxed.**
- **CS4** — **accepted-prefix safety by construction.** CS1's only reachable behaviour change is on a trace segment
  whose arc has equal dart orbits; enumerate what differs there and show every other path is identical.
- **CS5** — selector **408 unchanged**. If the ownership contract needs a witness, it appends as **409** with 408 as
  an exact 408-line prefix, asserting **publication and completeness** — that a face crossed by a bridge chord
  publishes exactly one owning-orbit entry containing all of its corners — and **never** a predicted owner value.
- **CS6** — `M3-CP4c-3-TB32` re-executes. **Credibility gate: 368, 369, 370, 374 and 398 must remain RED**, since
  none is touched. **Required outcome: 390, 393, 406 and 407 return to PASS.** For 366/367, either the plan
  proceeds past region certification or it stops at a **further** guard; a stop at
  `TraceArcDoesNotSeparateItsSides` falsifies DEFN-R4.3, and a stop reproducing
  `UncutFaceComponentOrbitSeedNotUnique` with component 0 at 189/1/`[0]` would falsify DEFN-R4.1.

### 9. Accounting

Definition turn: no runtime, no compile, no gate. **+0 events / +0 recurrences.** Totals remain **44 events / 14
categories / 30 recurrences**, produced-witness debt **5**, semantic M3 package count **96**. Accepted authority
remains **365/365**; CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB37` — Code + Build, runtime-free, GMP/GMPXX linked, under CS1–CS6.**

---
## Part IX — M3-CP4c-3 DEFN-R5

**Turn:** `M3-CP4c-3-DEFN-R5` — definition turn (absorbs REVIEW + PLAN).
**Frozen owner:** CW5 of `Architecture_M3_CP4c3_TB35_Independent_Review_Record.md`.
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.

Runtime authority entering this turn: `M3-CP4c-3-TB35`, selector **409**, **402 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, immutable CB40 package `10003613409` / source
`23a753a83f0eda0447172ce96bcd3180bf95ae8a`, run `34084955954`. Certified source-face ownership is
**300 established / 0 unavailable / 0 conflicting**. Stable accounting is **45 events / 14 categories / 31
recurrences**, produced-witness debt **5**, semantic M3 packages **100**.

### 1. DEFN-R5.1 — a face-walk orbit is an ordered single closed walk

> **Normative guarantee.** `FaceWalkResult::orbits[orbit]` is one **ordered single closed walk**. It is constructed by
> choosing one unvisited directed halfedge, repeatedly following the unique `successor[current]`, and ending the
> orbit only when the traversal returns to its starting directed halfedge. `canonicalize_cycle` then changes only
> the cyclic starting position; it does not split, splice or otherwise alter the walk.

Source authority: `EmbeddedGraphTopology.cpp:1746–1774`.

A single closed walk is **not** required to be a simple cycle. It may revisit a network node before its final arc;
bridges, slits and cut vertices can make that necessary. Therefore the fact that an in-progress boundary traversal
reaches its start node while entries remain does **not** prove that the boundary contains multiple walks.

### 2. DEFN-R5.2 — a plan region inherits that guarantee, but does not self-certify it

`build_regions` creates a region draft as `RegionDraft{orbit, walk.orbits[orbit]}`
(`GlobalTopologyPlan.cpp:986`) and publishes the same boundary unmodified (`:1450`). Existing source already
resolves the relation in the other direction by comparing `walk.orbits[orbit] == region.boundary`
(`region_orbit`, `GlobalTopologyPlan.cpp:379`).

> **Normative provenance rule.** Boundary provenance is a **derived relation to the current authoritative
> `FaceWalkResult`**, not a mutable claim stored on `GlobalTopologyRegion`.
>
> A current region boundary carries provenance **`FaceWalkOrbit(orbit)`** iff **exactly one** authoritative
> `walk.orbits[orbit]` equals the current ordered `region.boundary` exactly. If there is zero match or more than one
> match, provenance is **`Unguaranteed`**.

The existing `region_orbit(region, walk)` equality is the single authority for this relation and may be refactored
into a typed resolver, but no second mutable boolean/enum may be copied into `GlobalTopologyRegion` as independent
truth. This is required for the validation-candidate surface: tests deliberately copy a valid region and mutate its
boundary. A copied "came from face walk" flag would become stale while the exact relation correctly disappears.

**Prohibited provenance shortcuts:** region id, fixture name, source-face set, caller identity, a production-only
boolean, positional similarity, or any inference weaker than the exact ordered-boundary equality above.

### 3. DEFN-R5.3 — boundary-walk reasons are scoped by provenance

`validate_single_boundary_walk` has three typed structural reasons. Their authority is frozen as follows.

1. **`ArcChainBroken` applies to every boundary.** Consecutive oriented arcs must join exactly.
2. **`WalkNotClosed` applies to every boundary.** After all entries are consumed, the final node must equal the
   initial node.
3. **`ClosedBeforeEnd` is rejecting only for `Unguaranteed` boundaries.** Without an authoritative single-walk
   producer guarantee, returning to the initial node while entries remain is not accepted as one walk; validation
   fails closed at `ClosedBeforeEnd`. This remains the required negative for the synthetic multi-walk witnesses.
4. **`ClosedBeforeEnd` is non-rejecting observation for `FaceWalkOrbit(orbit)`.** The validator continues through
   the remaining entries and still applies `ArcChainBroken` and `WalkNotClosed`. The observation may remain on a
   later failure for continuity, but it must be accompanied by the derived provenance so it cannot be mistaken for
   a rejection authority.

The implementation order is part of the contract because it preserves the synthetic negatives:

1. resolve the **optional** exact `FaceWalkOrbit` relation without rejecting a missing match;
2. validate the boundary under DEFN-R5.3 using that provenance;
3. only after structural boundary validation, require the owning orbit for region certification and use the
   existing typed missing-orbit failure if no unique authoritative orbit exists.

Resolving a missing orbit **before** the boundary validator and immediately failing it is prohibited: that would
turn ordinals 312/409 into a different failure and erase the negative that owns `ClosedBeforeEnd`.

### 4. DEFN-R5.4 — ordinals 312 and 409 are immutable falsifiers of provenance overreach

Ordinal **312**, `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks`, and ordinal **409**,
`GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` (legacy name; current body is the reachable
shared-start multi-walk), remain **gating and unchanged**. Their synthetic boundary mutations no longer equal an
authoritative face-walk orbit, so both are `Unguaranteed` and must still reject with
`RegionBoundaryNotSingleWalk / ClosedBeforeEnd` at their existing loci.

No fixture branch, test-name special case, or "synthetic" flag is authorized. The exact relation of DEFN-R5.2 is
what distinguishes these cases from plan regions.

### 5. DEFN-R5.5 — Euler is a separate, unresolved question; measure the cancellation premise

Current source computes the region certificate as

`eulerCharacteristic = vertexCount - edgeCount + faceCount`

where `vertexCount = V_int`, `edgeCount = E_int`, and `faceCount = F` (`GlobalTopologyPlan.cpp:2097–2104`). The
source comment at `:2099–2100` justifies removing all boundary terms with
`V_boundary == E_boundary`, citing the validated single boundary walk and no-pinch condition. DEFN-R5.1 establishes
that the authoritative boundary is a **walk that may revisit nodes**; it does **not** establish that the distinct
boundary vertices/edges of the counted cell complex cancel under that reduction.

> **Normative disposition.** `RegionEulerCharacteristicNotOne` is **not corrected in the provenance turn**. The
> successor measures the exact multiplicity facts needed to decide whether the reduced Euler formula is valid for
> the current face-walk boundary. No value is forced to 1 and no region is accepted because its provenance is a
> face-walk orbit.

If 366/367 advance to `RegionEulerCharacteristicNotOne`, the failure detail must retain the existing exact
`vertexCount`, `edgeCount`, `faceCount`, `eulerCharacteristic` and additionally publish, without truncation for the
failing region:

- `regionBoundaryProvenance` = `FaceWalkOrbit` or `Unguaranteed`;
- `regionBoundaryOrbit` when provenance is `FaceWalkOrbit`;
- `regionBoundaryArcOccurrenceCount` — ordered oriented-arc entries;
- `regionBoundaryDistinctArcCount` — distinct underlying network arc ids represented by those entries;
- `regionBoundaryNodeOccurrenceCount` — cyclic boundary node occurrences, one start node per oriented entry;
- `regionBoundaryDistinctNodeCount`;
- `regionBoundaryRepeatedNodeOccurrenceCount = occurrenceCount - distinctCount`;
- `regionBoundaryStartRevisitBeforeEndCount`.

All counts are exact combinatorial counts from the authoritative boundary and arc endpoints; no float, tolerance,
approximation or reconstructed geometry is admissible. These fields are **measurement only**. A later review/DEFN
must decide whether the Euler reduction, the counted complex, or neither is wrong.

### 6. DEFN-R5.6 — candidate adjudication

- `M3-CP4c3-TB35-REV-CAND-01` becomes **DEFINED / GATING / ARCHITECTURAL / CORRECTION FROZEN**. The missing
  contract is DEFN-R5.1–R5.3; implementation owner is `M3-CP4c-3-CB41`, runtime verdict owner is TB36.
- `M3-CP4c3-TB34-REV-CAND-03` remains **ACTIVE / GATING / SPLIT**. Its `ClosedBeforeEnd` branch is now
  **definition-resolved** by DEFN-R5.1–R5.3; its `RegionEulerCharacteristicNotOne` branch remains open and is owned
  only by the measurement in DEFN-R5.5.
- The TB34 stable event remains counted. This definition changes **no** historical event/category/recurrence.

### 7. Successor — CX0–CX8, `M3-CP4c-3-CB41`

Code + Build, runtime-free, mandatory GMP/GMPXX linkage, `runtimeExecution=false`.

- **CX0 — boundary and compile discipline.** Change only the provenance/region-boundary validation and the bounded
  Euler measurement required below, plus directly necessary test/diagnostic plumbing. Compile the same eight
  standard targets required by the current CP4c Code + Build contract through `agent-compile-reusable.yml`; execute
  no Directional binary. Accepted runtime authority remains TB35.
- **CX1 — one provenance authority.** Reuse/refactor `region_orbit(region, walk)` as the exact resolver in
  DEFN-R5.2. Do **not** add a trusted mutable provenance flag to `GlobalTopologyRegion`.
- **CX2 — provenance-aware validation order.** Resolve optional provenance before boundary validation but do not
  fail a missing orbit yet; validate under CX3; only then require the owning orbit for certification. Preserve the
  existing typed missing-orbit path after structural validation.
- **CX3 — scope the reasons exactly.** `ArcChainBroken` and `WalkNotClosed` reject all boundaries.
  `ClosedBeforeEnd` rejects only `Unguaranteed`; on `FaceWalkOrbit` it is observation-only and traversal continues.
  Preserve exact typed reason/locus projection.
- **CX4 — hard negative preservation.** **Do not edit ordinals 312 or 409, their fixtures, names, assertions, order,
  or selector membership.** Selector 409 remains byte-identical. Audit the implementation against both before
  compile closeout.
- **CX5 — Euler measurement only.** Add the exact DEFN-R5.5 provenance/multiplicity fields to the
  `RegionEulerCharacteristicNotOne` evidence path and its production failure projection. Do not change the Euler
  formula, disc acceptance, `proves_disc_topology()`, region topology, or any correction outside that measurement.
- **CX6 — accepted and carried-surface safety.** No accepted identity 1–365 may change except that none is expected
  to change at all; no work on ordinal 398 or 368/369/370/374; no source-face ownership, partition-unification,
  retired-guard, sphere, saturation, ordinal-370, folded-cone, vertex-30 or finalize/contact change.
- **CX7 — Code + Build report must carry the TB plan.** Freeze immutable package/source/selector identities and a
  comprehensive artifact-only `M3-CP4c-3-TB36-EXEC` plan. TB36 executes selector 409 one identity per fresh
  process, accepted prefix first, no rebuild/repair/mutation, then stops for independent `TB36-REV` on semantic red.
- **CX8 — TB36 falsifiers.** Required credibility: accepted **1–365 = 365/365**; 312 and 409 PASS unchanged;
  390/393/404/406/407/408 PASS; 368/369/370/374/398 remain RED; ownership remains 300/0/0 and retired-code silence
  holds. For 366/367: a stop at `ClosedBeforeEnd` **falsifies** DEFN-R5.2/R5.3; advance to
  `RegionEulerCharacteristicNotOne` **confirms the provenance correction but does not authorize an Euler fix** and
  must publish all CX5 fields; advancement beyond Euler is raw frontier evidence for TB36-REV, not automatic
  checkpoint acceptance. Any accepted RED halts semantic advancement.

### 8. Prohibited

A mutable self-certifying provenance flag on `GlobalTopologyRegion`; fixture/test-name special casing; removing
`ClosedBeforeEnd` globally; weakening `ArcChainBroken` or `WalkNotClosed`; moving the missing-orbit failure ahead of
the synthetic boundary negative; editing ordinals 312 or 409; changing selector 409; changing the Euler formula or
forcing χ=1; weakening `proves_disc_topology()`; touching ordinal 398, 368/369/370/374, ownership, partition
unification, any retired guard, sphere/saturation/ordinal-370/folded-cone/vertex-30/finalize-contact work; any
float/tolerance-derived topological decision; any runtime in CB41.

### 9. Accounting and exact next turn

This definition turn runs no Directional runtime, compile, package, test or benchmark and creates no semantic
package. **+0 stable events / +0 recurrences.** Totals remain **45 events / 14 categories / 31 recurrences**;
produced-witness debt **5**; semantic M3 packages **100**; accepted runtime authority remains **TB35 365/365**;
CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB41` — Code + Build, runtime-free, GMP/GMPXX linked, under CX0–CX8.**

---

## Part IX-A — M3-CP4c-3 DEFN-R5 reconciliation amendment

**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE. **Amends Part IX; overrides nothing in it.**

Part IX was frozen from one execution of `M3-CP4c-3-DEFN-R5`. A second, independent execution of the same turn ran
concurrently and reached three findings that Part IX does not carry. Two of them **confirm Part IX against a
competing draft that was wrong**, and recording *why* the competing rule fails is the load-bearing content here —
it is the same failure mode that already cost this checkpoint an accepted-green regression once.

### A.1 — DEFN-R5.2's derived relation is not a stylistic preference; the alternative loses accepted green

The competing draft made provenance **established at construction**: set the guaranteed value in `build_regions`
where the boundary is taken from `walk.orbits[orbit]`, default unguaranteed, and store it on the region.

**That rule breaks accepted ordinal 312**, and the test says so directly
(`tests/FieldAlignedCurveNetworkTests.cpp:3247–3253`):

```cpp
auto candidate = plan.validation_candidate();
const auto duplicateWalk = candidate.regions[0].boundary;
candidate.regions[0].boundary.insert(candidate.regions[0].boundary.end(),
                                     duplicateWalk.begin(), duplicateWalk.end());
```

The synthetic region is a **copy of a real plan region**, whose boundary is then doubled. A stored construction-time
flag is copied with the struct and **survives the mutation**, so the region would present as `FaceWalkOrbit`,
`ClosedBeforeEnd` would be suppressed, and ordinal 312 would go RED — reproducing the `CB39` / `CU4` accepted-green
loss by a different route. Ordinal 409 mutates the same way (`:3276–3279`) and would fail identically.

DEFN-R5.2's derived exact relation has no such failure: the doubled boundary equals no authoritative
`walk.orbits[orbit]`, so it resolves to `Unguaranteed` and stays rejected. **DEFN-R5.2 and its prohibition on a
mutable region flag are confirmed, and the prohibition is the reason the rule is correct, not a note attached to
it.** `LESSONS.md` 148.

### A.2 — the Euler *causation* is settled even though the *correction* is not

Part IX §5 calls `RegionEulerCharacteristicNotOne` "a separate, unresolved question". The **correction** is
unresolved; the **causation** is not, and TB35-REV's framing of it as a *"second, independent finding"* is
**withdrawn**.

`GlobalTopologyPlan.cpp:2097–2104` computes `χ = V_int − E_int + F`, `certificate.edgeCount` counts interior edges
only (`:1861`, published as `E_int` at `:1804`), and `boundaryVertices` (`:1893–1969`) is consulted only to
**exclude** vertices from `interiorVertices` (`:2052`) — never counted. The comment at `:2099–2100` names the
no-pinch condition as the premise for dropping the boundary terms. **TB34 removed that premise's guard, so the
Euler failure it then observed was produced by the removal, not exposed by it.**

This does not change Part IX's disposition — it strengthens it. Under CX3 the guard stops rejecting face-walk
boundaries, so **366/367 advancing to `RegionEulerCharacteristicNotOne` is a predicted outcome of CB41, not a
discovery**, and CX8 already treats that advance as confirmation-without-authorization. CB41 must not read it as
new evidence, and TB36-REV must not count it as a new finding.

### A.3 — the naive Euler correction is refuted, which is why CX5 measures instead of correcting

The competing draft asserted that a boundary walk with k extra node revisits gives `V_bnd − E_bnd = −k`, hence
χ = 1 − k, and proposed generalizing χ to `(V_int + V_bnd) − (E_int + E_bnd) + F = 1` **coupled** to the scoping
change so that neither could land alone.

**The arithmetic is wrong.** It holds only when every boundary edge is traversed once. A **bridge is traversed
once per dart**, so a boundary walk of length L over a face containing a bridge has *both* `V_bnd < L` and
`E_bnd < L`, and the deficit is not determined by the node-revisit count alone. With ten terminal slits in this
fixture, repeated **edges** are expected, not exceptional. So no closed-form correction is derivable from the
revisit count, and the coupling argument built on it does not hold.

**This independently vindicates DEFN-R5.5.** The measurement it freezes is exactly the set that decides the
question — `regionBoundaryArcOccurrenceCount` **and** `regionBoundaryDistinctArcCount`, `…NodeOccurrenceCount`
**and** `…DistinctNodeCount` — because occurrence-versus-distinct must be resolved separately for arcs and for
nodes. A correction frozen on the revisit count alone would have been wrong. `LESSONS.md` 149.

### A.4 — fixture evidence for DEFN-R5.1

Part IX proves the single-closed-walk guarantee from construction. The fixture independently shows the guarantee is
**load-bearing rather than theoretical**: it publishes `terminalSlits=10` across twelve traces on a complex
certified cellular with `V=22, E=26, F=6, componentCount=1, χ=2, residual=0` and **every face established as a
disc**. A face containing a bridge necessarily revisits that bridge's base node, so rejecting repeated-node
boundaries would reject a decomposition the certifier has already established as cellular, and no change to region
construction avoids producing them for this input.

### A.5 — what this amendment does not change

Part IX governs. **DEFN-R5.1 through R5.6, CX0–CX8, the prohibited list, and the ordinals 312/409 contracts are
unchanged.** No stable event, category or recurrence changes: totals remain **45 / 14 / 31**, debt **5**, packages
**100**. Runtime authority remains **TB35** at 402 PASS / 7 RED, accepted **365/365**. **Exact next turn remains
`M3-CP4c-3-CB41` — Code + Build, runtime-free, GMP/GMPXX linked, under CX0–CX8.**

---

## Part X — M3-CP4c-3 DEFN-R6

**Turn:** `M3-CP4c-3-DEFN-R6` — definition turn (absorbs REVIEW + PLAN).
**Frozen owner:** CZ6 of the historical TB37 review, resolved through the folded-document index in
`M3_CP4c_Consolidated_Record.md`.
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.

Runtime authority entering this turn: `M3-CP4c-3-TB37`, selector **409**, **402 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, immutable CB42 package `10032277517` / source
`89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`, run `34161464783`. Ownership **300 / 0 / 0**. Stable accounting
**45 events / 14 categories / 31 recurrences**, debt **5**, packages **102**.

This part supersedes Part IX §5 (DEFN-R5.5), which froze `RegionEulerCharacteristicNotOne` as **measurement only**
and deferred the decision to "a later review/DEFN". TB37 supplied the measurement and TB37-REV made the finding;
Part X is that decision. **Every other clause of Part IX, and all of Part IX-A, stands unchanged.**

### 1. The measurement, and what it proved

```text
X     (sub-mesh vertices excluded from interiorVertices) = 36  = 0 + 20 + 16
B_int (barrier edges with both incident faces in region) = 12
E_one (sub-mesh boundary edges)                          = 20
      (sub-mesh boundary vertices)                       = 20
V_total / E_total / F / chi_full                         = 136 / 385 / 250 / 1
reduced certificate V_int / E_int / F / chi              = 100 / 353 / 250 / -3
```

> **The region's source sub-mesh is a genuine triangulated disc, and the certificate rejects it.**

The gap decomposes exactly:

> **(V_total − V_int) − (E_total − E_int) = 36 − 32 = (20 − 20) + (16 − 12) = 0 + 4**

### 2. DEFN-R6.1 — the cancellation premise is NOT the defect

> **DEFN-R6.1 — normative, and the correction of record.** The premise *"the validated single boundary walk and
> no-pinch condition give `V_boundary == E_boundary`"* is **true of the sub-mesh boundary**: 20 edges against 20
> vertices, measured. **Part IX-A §A.2's implication that the premise itself fails is withdrawn**, and so is the
> DEFN-R5 draft claim that a pinch makes the boundary terms stop cancelling.

The reduction failed for an unrelated reason, and recording that reason is the point of this clause: **a
correction aimed at the premise would have been aimed at the wrong thing.**

### 3. DEFN-R6.2 — interior barrier edges are interior cells

> **DEFN-R6.2 — normative.** A **barrier edge** — mandatory or cut — **with both incident faces in the region is an
> interior cell of the certified complex**, not a boundary cell. The certificate currently drops **12** such edges
> from `E_int` (`GlobalTopologyPlan.cpp:1848–1850`) and drops **16** further vertices from `V_int` through the
> `allOwned` test (`:2048–2094`), and those two exclusions do not balance. **The certificate's notion of "boundary"
> is the network's barrier set rather than the sub-mesh's actual boundary, and that misclassification is the whole
> of the 4-point error.**

A **terminal slit** is exactly such an edge — a barrier that dangles into a region rather than separating two — and
this fixture publishes ten of them.

### 4. DEFN-R6.3 — the certified complex, named

> **DEFN-R6.3 — normative.** The object a region certificate certifies is the **whole-face source sub-mesh** of
> `region.sourceFaces`: all distinct source vertices and all distinct source edges of those faces, with
> `F = |region.sourceFaces|`. Each source face belongs to exactly one region, because `fragmentOrbits[face]` is
> rejected unless `certifiedFaceOrbits.size() == 1` (`:1405`, applied at `:1432`), so the faces are partitioned.

> **This is the region rounded to whole faces, not the traced region.** The region the plan builds is bounded by
> the network walk, which includes **trace arcs — chords through face interiors** that are not source edges. A
> trace-cut face is assigned wholly to one side. **`χ = 1` is therefore a claim about the rounding**, and no turn
> may cite it as a statement about the traced region.

This is stated so it cannot be silently assumed later; it is **not** a defect finding, and it does not block the
correction. `M3-CP4c3-TB37-REV-CAND-01` remains **ACTIVE / ARCHITECTURAL / NON-BLOCKING**.

### 5. DEFN-R6.4 — the Euler criterion

> **DEFN-R6.4 — normative.** A region's Euler characteristic is
>
> **χ = V_total − E_total + F**, and disc topology requires **χ = 1**.
>
> **The reduced form `V_int − E_int + F` is withdrawn.** For a connected compact surface with boundary,
> `χ = 2 − 2g − b`, so `χ = 1` forces `g = 0, b = 1`; together with the already-checked `sourceFacesConnected` and
> `boundaryWalkCount == 1`, that is a disc. `proves_disc_topology()` keeps its present shape and only the value of
> `eulerCharacteristic` changes.

### 6. DEFN-R6.5 — the withdrawn premise has TWO sites, and both must go

> **DEFN-R6.5 — normative.** The withdrawn cancellation premise is stated in **two** places, and the implementing
> turn must remove **both**:
>
> 1. `src/geometry/GlobalTopologyPlan.cpp:2097–2098` — the comment above the χ assignment;
> 2. `include/directional/geometry/GlobalTopologyPlan.h:91–93` — the comment on
>    `GlobalTopologyRegionDiscCertificate::vertexCount`, whose second and third lines repeat it verbatim.

TB37-REV named only the first. The header site was found by this turn. **Leaving either in place re-seeds the
withdrawn assumption for the next reader** — which is exactly how the assumption survived from TB34 to TB37 in the
first place. `LESSONS.md` 53 and 147.

### 7. DEFN-R6.6 — do not repurpose `vertexCount` and `edgeCount`

> **DEFN-R6.6 — normative.** `certificate.vertexCount` and `certificate.edgeCount` **keep their present meanings**:
> `V_int`, and the count of **interior fragment adjacencies in the region dual graph**. `edgeCount` is incremented
> in the same loop that builds `neighbors` for the connectivity BFS behind `RegionInteriorDisconnected`
> (`:1847–1860`, consumed by the BFS at `:1862–1873` and the check at `:1874`); redefining it would silently change which regions are reported disconnected, which is **outside
> this correction**.
>
> The sub-mesh totals must be **added as new certificate fields**, so the published triple explains the published
> χ rather than contradicting it. Their comments must state their domain.

### 8. DEFN-R6.7 — the equivalence condition carries a proof obligation

> **DEFN-R6.7 — normative.** Reduced and full agree exactly when
>
> **X = E_one + B_int**
>
> and they differ by `X − (E_one + B_int)` otherwise. **The implementing turn may not assume this holds anywhere.**
> It must establish, per region on every accepted fixture, either that the identity holds or that the region's
> verdict is unchanged.

The measured region violates it by 4 (`36` against `20 + 12`). A region with **no interior barrier edges**, whose
excluded-vertex set is exactly its sub-mesh boundary vertex set, and whose sub-mesh boundary is a disjoint union of
cycles, satisfies it — which is why the accepted corpus has not previously exposed the defect. **That is an
explanation, not a proof, and DEFN-R6.7 requires the proof.**

### 9. Successor — CZ7 measures, `M3-CP4c-3-CB43`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`.

- **CZ7.1 — hoist the sub-mesh accumulation.** CB42 computes `submeshVertices` / `submeshEdges` **inside the
  `if (certificate.eulerCharacteristic != 1)` failure branch**, so they are unavailable to the criterion. Move
  them above the χ computation. This is a code-motion step with no behaviour of its own.
- **CZ7.2 — add the certificate fields** for `V_total` and `E_total` per DEFN-R6.6, documented with their domain,
  and compute `certificate.eulerCharacteristic` from them per DEFN-R6.4.
- **CZ7.3 — delete both premise comments** per DEFN-R6.5. Replace them with a statement of what is actually
  counted; do not leave a bare deletion.
- **CZ7.4 — discharge DEFN-R6.7.** Publish, for every region on every accepted fixture, `X`, `E_one`, `B_int` and
  the reduced-versus-full difference, and show either the identity or an unchanged verdict. **A blanket assertion
  that "accepted fixtures have no slits" is not a discharge.**
- **CZ7.5 — state the hash and ordering decision explicitly.** New certificate fields change
  `GlobalTopologyRegionDiscCertificate::operator<=>`, and `global_topology_plan_hash` consumes the certificate
  (`:2386–2400`). Say whether the new fields enter the hash. No identity pins a plan-hash literal today — **confirm
  that by grep, do not assume it** — and note that the hash changes regardless, because corrected regions publish a
  different `eulerCharacteristic`.
- **CZ7.6 — protected surface unchanged.** Ordinals **312** and **409** byte-identical; selector **409**
  byte-frozen; accepted **1–365** untouched; no work on 368/369/370/374/398; no ownership, partition-unification,
  retired-guard, sphere, saturation, folded-cone or finalize/contact change. **Region construction must not
  change** — TB37 established the region is correct and the certificate is not.
- **CZ7.7 — `M3-CP4c-3-TB38` re-executes** selector 409, one identity per fresh process, accepted prefix first.

**Falsification, stated before the build.**

- **Accepted prefix 365/365, and ordinals 312 and 409 PASS, are stop conditions.** Any accepted RED halts the turn.
- **The risk is not a direct assertion.** CB42's grep found no test-source assertion of
  `RegionEulerCharacteristicNotOne`. The risk is that a region which currently fails Euler now passes and reaches
  stages never executed on it.
- If 366/367 clear region certification, DEFN-R6.1–R6.4 are confirmed. **A new failure at a later stage is a new
  frontier, not a regression of this one**, and TB38-REV must classify it as such.
- If 366/367 still fail Euler under the full count, the measurement and the implementation disagree and the turn
  halts without a correction.
- If any accepted-fixture region changes verdict, **DEFN-R6.7's identity is refuted there** and the correction is
  not safe as written.
- If 366/367 clear Euler but a region elsewhere newly fails it, DEFN-R6.4 is too strong for some region the reduced
  form happened to pass, and the counted complex — DEFN-R6.3 — becomes the live question.

### 10. Prohibited

Correcting region construction; changing source-face ownership or the whole-face rounding while fixing the
arithmetic; repurposing `vertexCount` or `edgeCount`; weakening `proves_disc_topology()`, `sourceFacesConnected` or
`boundaryWalkCount`; forcing χ to 1, special-casing a fixture, or accepting a region on any ground other than the
criterion; deleting only one of the two premise comments; weakening or re-scoping ordinal 398; touching
368/369/370/374; re-opening any retired guard; any accepted-identity or selector byte change; any Directional
runtime in the definition turn.

### 11. Accounting

Definition turn: no runtime, no compile, no package, no gate. **+0 events / +0 recurrences.** Totals remain
**45 events / 14 categories / 31 recurrences**, produced-witness debt **5**, semantic M3 package count **102**.
Accepted authority remains **365/365**; runtime authority remains **TB37**; CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB43` — Code + Build, runtime-free, GMP/GMPXX linked, under CZ7.1–CZ7.7.**

---

## Part XI — M3-CP4c-3 DEFN-R7

### Actual-embedded face certificate binding replaces region support proxies

**Turn:** `M3-CP4c-3-DEFN-R7` — Definition turn (absorbs REVIEW + PLAN).
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.
**Runtime authority entering and leaving this turn:** promoted `M3-CP4c-3-TB39`, package104, selector **409**,
**402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`. Ownership remains
**300 / 0 / 0**. Stable accounting remains **46 events / 14 categories / 32 recurrences**, produced-witness debt
**5**, semantic package count **104**.

This part is the replacement contract ordered by TB39-REV. It **supersedes Part X DEFN-R6.3 and DEFN-R6.4 as
region-disc-topology authority**. Part X's measurements, domain findings, withdrawn-assumption record and historical
falsifiers remain evidence; they are not deleted. The correction is not a third Euler formula. The correction is to
consume the certificate already owned by the stage that constructs and certifies the actual embedded graph.

### 1. DEFN-R7.1 — one topology object, one owner

> **Normative.** The topology object of an A2b `GlobalTopologyRegion` is the **non-exterior face-walk orbit of the
> A2a′ `ActualEmbeddedGraph` whose ordered oriented-arc cycle is exactly `region.boundary`**. Its disc-topology
> authority is the matching `SurfaceCutGraphFaceCertificate` published by A2a′. A2b does not independently infer
> disc topology from `region.sourceFaces`, a source-edge barrier partition, fragment counts, corner ownership, or
> any Euler proxy over those projections.

The relation is not aspirational; current source already constructs both stages from the same deterministic graph
builder. `SurfaceCutGraph::certify_actual_embedded_graph()` and `GlobalTopologyPlan::canonical_candidate()` both call
`build_embedded_graph_topology(sourceFaces, sourceVertexCount, sourceAuthority, network, cutEdges)`. That shared
builder owns arcs, rotations and `FaceWalkResult`. `SurfaceCutGraph` publishes one face certificate for every
non-exterior orbit. `GlobalTopologyPlan::build_regions()` drafts one region for every non-exterior orbit and copies
that orbit's ordered boundary. The orbit ordinal is content-derived because canonical arc IDs and face-walk order are
content-derived; `SurfaceCutGraph` already includes the ordinal in its semantic digest.

Therefore the A2a′ face certificate is not evidence about a merely related object. It is evidence about the **same
actual-embedded face** that A2b publishes as the region.

### 2. DEFN-R7.2 — the binding key and exact relation

> **Normative.** The binding key is the current actual-embedded **face-walk orbit ordinal** `o`, derived on demand
> from exact equality `walk.orbits[o] == region.boundary`. It is never a stored "trusted at construction" region
> flag.

For a current candidate, one region is bound iff all of the following hold:

1. candidate source/network/cut-graph semantic bindings are current (`sourceDigest`, `networkDigest`,
   `cutGraphDigest` agree with their producers);
2. the candidate arcs/rotations yield a valid current `FaceWalkResult`;
3. exact `region_orbit(region, walk)` resolves **exactly one** orbit `o`; the ordered, oriented boundary is equal to
   `walk.orbits[o]`, not merely cyclically similar after a stale construction-time claim;
4. exactly one `cutGraph.certificate().faces` entry has `face.orbit == o`;
5. that entry is therefore non-exterior, because A2a′ publishes `faces` only for non-exterior orbits;
6. the entry has `boundaryWalkCount == 1`, `boundaryArcCount == region.boundary.size()`, and
   `face.proves_disc_topology() == true`;
7. the downstream region certificate contains the **exact consumed A2a′ face-certificate value** for that orbit;
8. candidate validation re-derives items 1–7 from the *current* candidate and current producers and compares the
   resulting certificate exactly before publication.

Items 3 and 8 are the copy/mutation control. Ordinals 312 and 409 start from `plan.validation_candidate()`, copy a
real region, and then mutate its boundary. A stored provenance/proof boolean would survive that copy. The derived
relation does not: once the boundary is no longer an exact current face-walk orbit, there is no binding.

### 3. DEFN-R7.3 — downstream certificate representation

> **Normative.** `GlobalTopologyRegionDiscCertificate` is a **binding/consumption certificate**, not a second
> topological certifier. Its semantic topology payload is one exact consumed `SurfaceCutGraphFaceCertificate`,
> associated with the region ID. The preferred concrete representation is an embedded value such as
> `SurfaceCutGraphFaceCertificate actualEmbeddedFace`; an equivalent representation is admissible only if it
> preserves the same four upstream fields exactly and cannot become a second writer of them.

The certificate retains the separate field-regularity payload (`interiorSingularityFree` and
`boundarySingularities`). Its methods have disjoint meanings:

- `proves_disc_topology()` delegates to the **consumed upstream actual-embedded face certificate**;
- `proves_field_regularity()` remains the A2b field/singularity predicate.

`proves_disc_topology()` must not consult source-support connectivity or any reduced/full/split/barrier Euler
measurement. Conversely, the upstream face certificate does not prove field regularity; A2b still owns that
separate check.

A copied mutable candidate may contain a copied face-certificate value. That copy is not publication authority by
itself. `make_from_candidate()` remains the checked seam and must rebuild the binding from the current region,
current face walk and current `SurfaceCutGraph`, then require exact equality with the candidate certificate.

### 4. DEFN-R7.4 — source-support proxies are diagnostics, not topology gates

> **Normative.** The following current `GlobalTopologyRegionDiscCertificate` members do **not** describe one
> actual-embedded cell complex and therefore leave the semantic disc certificate:
>
> `sourceFacesConnected`, `eulerCharacteristic`, `vertexCount`, `edgeCount`, `totalVertexCount`,
> `totalEdgeCount`, and `faceCount`.

Their present domains are intentionally recorded before removal:

- `sourceFacesConnected` — connectivity of the owned source-face/fragment support through non-barrier adjacency;
- `vertexCount` — source vertices surviving the reduced/projection exclusion (`V_int`);
- `edgeCount` — interior fragment/source-support adjacencies (`E_int`), not actual-embedded graph edges;
- `faceCount` — owned `(SourceFaceTopologyKey, orbit)` support fragments;
- `totalVertexCount` / `totalEdgeCount` — distinct vertices/edges of the whole-source-face rounding;
- reduced/full Euler values — arithmetic over those two different source-support projections.

These values may continue to be computed as **diagnostic observations** where useful, but they must not be part of
`GlobalTopologyRegionDiscCertificate::proves_disc_topology()`, must not be a second semantic certificate in
`candidate_semantic_digest`, and must not reject an otherwise bound A2a′ face as non-disc.

Consequences:

- `RegionEulerCharacteristicNotOne` is **retired as a producer of A2b disc-topology rejection**. Its enum/string may
  remain for source/API/history compatibility, but canonical region certification no longer raises it.
- `RegionInteriorDisconnected` is likewise **retired as a producer of disc-topology rejection**. The old support
  connectivity measurement may remain diagnostic; ownership/canonical fragment binding is already enforced by
  `build_regions()` and candidate reconstruction.
- `validate_no_region_fragment_pinch()` may not remain an independent disc-topology authority. If retained, it is a
  non-gating consistency diagnostic. A contradiction with a current certified actual-embedded face is an
  implementation/authority-binding defect, not permission to override A2a′ with a second region theorem.
- `validate_single_boundary_walk()` remains useful as **candidate/binding structure validation** and for the typed
  312/409 tamper falsifiers. It is not the source of the canonical region's disc proof.

This is the explicit withdrawal of the proxy authority that Part X accidentally installed.

### 5. DEFN-R7.5 — exact diagnostic domains and the `regionChiFull` contract

> **Normative.** A diagnostic name that says *full* must contain the whole-source-face value and no other value.
> If a field cannot be made unambiguous, rename it to include its domain.

For the existing support-projection measurements:

- **reduced support Euler** = `sourceSupportInteriorVertexCount - sourceSupportInteriorAdjacencyCount +
  sourceSupportFragmentCount`;
- **whole-source-face Euler** = `wholeSourceFaceVertexCount - wholeSourceFaceEdgeCount +
  wholeSourceFaceFaceCount`;
- `fullMinusReduced` is only the difference of those two named projection domains;
- `traceCutFaceCount`, `splitFragmentCount`, `fragmentCornerAttributionCount`,
  `interiorBarrierOneSideCount`, and `interiorBarrierBothSidesCount` remain diagnostics about their explicitly
  named support/projection domains; they are not cells of the canonical actual-embedded region unless a future
  definition constructs and proves such a complex.

`GlobalTopologyPlanError::regionFullEulerCharacteristic` / projected `regionChiFull` currently receive the reduced
`certificate.eulerCharacteristic` on 366/367. **That assignment is forbidden.** If the field survives, it must be
computed from whole-source-face `V_total - E_total + F`. The generic `eulerCharacteristic/vertexCount/edgeCount/
faceCount` failure fields must not silently carry the region-support proxy after the topology rejection that owned
them is retired; any retained publication gets a domain-explicit region-support name.

The stderr record currently named `record=euler_certificate` is not a certificate after this turn. A successor may
keep its data only under a diagnostic/projection name and with domain-explicit columns. Historical TB39 artifacts
remain valid evidence under the names they emitted at that time.

### 6. DEFN-R7.6 — complete consumer inventory frozen before implementation

The implementation successor may not discover a new consumer after changing the representation and then improvise
its semantics. This is the frozen census from exact source `7f8b36413aeb5af808979a106b7b2557c81e8865`:

| Consumer/surface | Current role | Required R7 treatment |
|---|---|---|
| `include/directional/geometry/GlobalTopologyPlan.h` `GlobalTopologyRegionDiscCertificate` | product fields + `proves_disc_topology()` | replace proxy proof payload with exact consumed A2a′ face certificate; retain field regularity separately |
| `build_region_certificates()` / `region_orbit()` | current exact boundary→face-walk derivation | keep derived relation; add unique upstream face-certificate lookup/binding |
| `build_region_certificate()` | computes support connectivity/Euler and raises region topology errors | consume bound face cert; stop using support proxies/pinch as disc authority; keep only explicitly diagnostic measurements |
| `canonical_candidate()` | creates region certificates and binds `cutGraphDigest` | produce the new binding certificate from current cut graph |
| `validate_candidate_structure()` | rebuilds expected certificates and compares exact equality | preserve this checked seam; re-derive current boundary/orbit/upstream cert so stale copied candidates fail |
| `candidate_semantic_digest()` | hashes every current proxy field | hash region ID + exact consumed face-certificate semantics + field-regularity semantics; do not hash retired support diagnostics as topology semantics |
| `GlobalTopologyPlan::region_certificates()` / `find_region_certificate()` | public accessors | expose the new binding certificate without a second proof interpretation |
| `GlobalTopologyPlanError` region Euler/support fields | typed failure payload | retire topology producer; domain-name any retained support diagnostics; fix full/reduced misbinding |
| `RemeshDiagnostics.h` + `project_global_topology_plan_failure_locus()` | serialization/projection | mirror the domain-explicit contract; never project reduced as full |
| `emit_fragment_euler_diagnostics()` / `emit_region_euler_certificate_diagnostics()` | stderr measurements | retain only as diagnostics with explicit domains; no `certificate` claim for proxy arithmetic |
| `tests/FieldAlignedCurveNetworkTests.cpp` ordinal 311 | published per-region disc proof | assert 1:1 region↔upstream face-cert binding and field regularity, not proxy χ |
| ordinal 312 | accepted copy/mutation boundary falsifier | byte/semantic intent preserved; mutated boundary must lose derived orbit binding and remain rejected |
| ordinal 313 | historical name, active interior-singularity negative | keep the interior-singularity oracle; do not resurrect a region-Euler rejection to satisfy the test name |
| ordinal 314 | independent disc proof oracle | keep actual-embedded face/orbit checks; published-certificate clause must agree with upstream face authority |
| ordinal 315 | tampered region certificate negative | tamper the new binding certificate and require `InvalidRegionCertificateBinding`; do not keep an Euler-only tamper merely to preserve old fields |
| ordinals 356/357/366 and shared `expect_cp4c_plan_disc_proofs()` | produced torus/mechanical proof assertions | assert exact upstream face binding; 366 may advance beyond the retired proxy rejection |
| ordinal 367 | produced face-walk agreement | preserve; no proxy-Euler dependency may be added |
| ordinal 368 | prescribed-sphere carried owner | no semantic correction; if it reaches A2b later, the same binding contract applies |
| ordinal 409 | gating copy/mutation boundary falsifier | preserve current typed rejection semantics and exact derived-provenance behavior |
| test failure formatter `append_plan_error()` | human/machine diagnostic serialization | use domain-explicit names consistent with product/pipeline projection |

No other production use of `GlobalTopologyRegionDiscCertificate`, its current proxy fields, or
`regionFullEulerCharacteristic` exists in the exact snapshot. Later stages' unrelated Euler fields are different
objects and are outside this correction.

### 7. DEFN-R7.7 — gate and tamper contract

The selector file remains **byte-frozen**. R7 changes assertions inside existing identities where required; it does
not change the identity set.

- **Ordinal 311** becomes the primary static/runtime proof that every published region has exactly one matching
  upstream certified actual-embedded face, the exact consumed certificate agrees, and field regularity remains true.
- **Ordinal 315** tampers the new consumed binding certificate (orbit or one of its exact face-certificate fields)
  and must still fail the checked publication seam with `InvalidRegionCertificateBinding`.
- **Ordinals 312 and 409** remain the hard falsifiers against sticky construction-time provenance. Their region
  boundary mutations must not inherit a valid face binding from the copied candidate.
- **Ordinals 356, 357, 366, 367, 390, 393, 404, 406, 407, 408** remain protected. The region-authority correction
  may change 366/367 only by removing the proxy topology rejection they currently encounter; no assertion owned by
  another mechanism is weakened.
- Accepted prefix **1–365 must remain 365/365** on the later artifact-only TB. Any accepted RED is a stop condition.
- Certified source-face ownership must remain **300 established / 0 unavailable / 0 conflicting**; the retired
  `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` codes remain absent.
- Separately owned 368/369/370/374/398 are not reclassified or corrected by R7.

The later TB must publish a **non-vacuous 1:1 binding census**: at least one row and exactly one row per emitted
region on each creditable produced witness that reaches A2b, naming region, derived orbit, upstream face-cert orbit,
boundary-arc count, and upstream `proves_disc_topology` result. Zero rows cannot pass this obligation.

### 8. DEFN-R7.8 — successor implementation boundary

The correction is bounded to the authority seam. It does **not** authorize changes to:

- `build_regions()` region construction, region IDs, face-walk generation, rotations or arc semantics;
- `SurfaceCutGraph` cut selection/cellularity semantics or source-face ownership;
- fragment ownership, `fragmentCorners`, source-face partitioning, trace geometry or cut-edge selection;
- selector bytes or identity membership;
- prescribed sphere 368, saturation 369, empty-network typed error 370, folded-cone 374, or ownership witness 398;
- any A3+ stage.

A source-support diagnostic may be renamed or moved only to make its observational domain explicit; that does not
make the diagnostic a new authority.

### 9. DEFN-R7.9 — frozen Code + Build successor

**Exact next turn: `M3-CP4c-3-CB45` — Code + Build, runtime-free, GMP/GMPXX linked.** It is governed by
`Architecture_M3_CP4c3_CB45_Code_Build_Plan.md` and measures **EA0–EA9**.

The successor must implement the binding contract, compile/package without executing Directional runtime, preserve
selector409 and all unrelated owners, and freeze the following artifact-only `M3-CP4c-3-TB40-EXEC` gate. DEFN-R7
itself does not compile or execute anything.

### 10. Falsifiable predictions frozen before implementation

1. A canonical region's derived orbit has exactly one A2a′ face certificate, and its boundary-arc count equals the
   current region boundary length. Any miss, duplicate or mismatch is an authority-binding defect and fails closed.
2. 312/409 remain rejected after copy/mutation because the current boundary no longer equals a current face-walk
   orbit; no copied proof value can rescue them.
3. 315 remains a valid tamper negative after its target moves from proxy Euler to the consumed face binding.
4. 366/367 no longer stop at `RegionEulerCharacteristicNotOne` solely because the reduced source-support proxy is
   `-3`. If they remain at the same code after R7 implementation, the old proxy still owns the gate and CB45 is
   incomplete.
5. The torus remains valid even though whole-source-face χ is 0, because that projection is not the actual-embedded
   face certificate. If R7 makes ordinal 356 RED on that measurement, the proxy was not actually retired.
6. The later binding census is non-empty and 1:1 for every region that reaches A2b. A zero-row verifier result is
   failure, not proof.
7. No change to source ownership, cut selection or region construction is necessary. A CB45 diff in those domains
   falsifies the bounded-correction claim and requires review before runtime.

### 11. Accounting

Definition / Review + Plan only: no runtime, no compile, no package, no selector mutation and no stable repricing.
**+0 events / +0 recurrences.** Totals remain **46 / 14 / 32**, debt **5**, packages **104**. TB39 remains current
semantic runtime authority at **402/7**, accepted **365/365**.

**Exact next turn: `M3-CP4c-3-CB45` — Code + Build, runtime-free, GMP/GMPXX linked.**

---

## Part XI-A — DEFN-R7 evidentiary amendment

**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE. **Amends Part XI; overrides none of its decisions.**
**Origin:** verification pass over the delegated `M3-CP4c-3-TB39-REV` / `M3-CP4c-3-DEFN-R7` work.

Part XI's decision is **upheld**. Binding A2b's region disc proof to the A2a′ actual-embedded face authority is
correct, and the structural claims it rests on verify from source:

- both stages call `build_embedded_graph_topology(sourceFaces, sourceVertexCount, sourceAuthority, network,
  cutEdges)` with the same arguments — `GlobalTopologyPlan.cpp:2500–2502` passes `cutGraph.cut_edges()`, and
  `SurfaceCutGraph.cpp:863` passes the same `cutEdges`;
- both derive exterior orbits from the same `exterior_boundary_orbits(...)`
  (`GlobalTopologyPlan.cpp:869`, `SurfaceCutGraph.cpp:866`);
- `SurfaceCutGraph.cpp:883` pushes one face certificate per **non-exterior** orbit and
  `GlobalTopologyPlan.cpp:986` drafts one region per **non-exterior** orbit.

**The 1:1 region ↔ face correspondence is real.** What follows corrects what that certificate *proves*, because
Part XI describes it as per-face evidence and it is not.

### A.1 — `discTopologyEstablished` is a complex-level bit, not a per-face measurement

> **Normative.** `SurfaceCutGraphFaceCertificate::discTopologyEstablished` is **the same value on every
> non-exterior face**. It is `discEmbeddingEstablished`, computed once at `SurfaceCutGraph.cpp:879` as
>
> `graphComponents == sourceComponentCount && exterior.size() == *boundaryLoops && graphEuler == sourceEuler`
>
> and stamped identically onto every face at `:883`. **No per-face topology is measured anywhere.**

This does **not** weaken Part XI's decision, and the reason matters: that conjunction is the **standard cellularity
criterion** for a graph embedded in a surface, and cellularity is exactly the theorem *"every non-exterior face is
a disc"*. The authority is sound. **It is a complex-level theorem, and it must be named as one.**

> **Therefore: A2b consumes a certified-cellular-complex authority, and a face certificate is that authority
> restricted to one orbit — not independent evidence about that orbit.** No turn may cite a face certificate as
> per-face evidence, and no turn may treat two face certificates as two observations.

### A.2 — `boundaryWalkCount == 1` is vacuous and is withdrawn as a check

> **Normative.** `boundaryWalkCount` is the **literal `1U`** at `SurfaceCutGraph.cpp:883`; it is never measured.
> Part XI §2 item 6's conjunct `boundaryWalkCount == 1` therefore **cannot fail**, and it is **withdrawn as
> evidence**. It may be retained as a structural assertion, but it must not be counted toward the binding proof.

The literal is *correct* — a face-walk orbit is a single closed walk by construction (Part IX, DEFN-R5.1) — and
that is precisely why it carries no information. **This is the `LESSONS.md` 155 failure mode appearing inside the
contract written to prevent it**: a check that passes because it asserts a constant, exactly as DEFN-R6.7's
verifier passed because it read an empty table. `LESSONS.md` 157.

Of Part XI §2 item 6's three conjuncts, only **`boundaryArcCount == region.boundary.size()`** is a real comparison,
and it is a consistency check between two derivations of one orbit — not a topology proof.

### A.3 — consequences for the frozen successor

These amend `CB45`'s measures without enlarging its scope.

1. **The R7.7 binding census must publish the complex-level inputs**, not only the per-region bit. A census of N
   regions each carrying the same `proves_disc_topology` value publishes **one** bit N times and reads as N pieces
   of evidence. Alongside region, derived orbit, upstream orbit and boundary-arc count, each creditable witness
   must publish `graphComponents`, `sourceComponentCount`, `exterior.size()`, `boundaryLoops`, `graphEuler` and
   `sourceEuler` **once per complex**, so the real evidence is visible and falsifiable.
2. **Ordinal 315's tamper target must be a field that varies.** Tampering `boundaryWalkCount` tampers a constant,
   and tampering `discTopologyEstablished` tampers a value uniform across every face. The tamper must use
   **`orbit`** or **`boundaryArcCount`**, or the consumed complex-level authority itself, and the plan's
   *"one of its exact face-certificate fields"* is narrowed accordingly.
3. **`Architecture_M3_CP4c3_CB45_Code_Build_Plan.md:37`** carries Part XI §2 item 6 verbatim and inherits this
   correction; its `boundaryWalkCount == 1` clause is a structural assertion, not part of the proof.
4. **The non-vacuity rule generalizes.** R7.7 already forbids a zero-row census. It must equally forbid a census
   whose every row carries the same value for the field under test: **a census must be able to disagree with
   itself, or it is not a measurement.**

### A.4 — what this amendment does not change

Part XI governs. **R7.1–R7.9, the consumer inventory, the tamper contract, the accepted-prefix stop condition and
the CB45 boundary are unchanged.** Runtime authority remains **TB39** at 402 PASS / 7 RED, accepted **365/365**,
package **104**. Accounting is unchanged at **46 events / 14 categories / 32 recurrences**, debt **5** — this is a
static amendment and creates no event. **Exact next turn remains `M3-CP4c-3-CB45`, Code + Build, runtime-free,
under EA0–EA9 as amended by A.3.**

---

## Part XII — M3-CP4c-3 DEFN-R8

### A census may speak only about its own domain

**Turn:** `M3-CP4c-3-DEFN-R8` — Definition turn (absorbs REVIEW + PLAN).
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.
**Runtime authority entering and leaving this turn:** promoted `M3-CP4c-3-TB42`, package107, selector **409**,
**398 PASS / 11 RED / 0 SKIP**, accepted **365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`.
Ownership remains **300 / 0 / 0**. Stable accounting remains **47 events / 14 categories / 33 recurrences**,
produced-witness debt **5**, semantic package count **107**.

This part discharges ED7.1–ED7.7 from the promoted TB42 review. It does **not** change Part XI or Part XI-A.
It decides which object the uncut-component census describes, what evidence a later `RegionCertification` failure
must carry instead, and how the four protected identities remain falsifiable without demanding evidence about a
disjoint object.

### 1. DEFN-R8.1 — the uncut-component census domain is the unlabelled-face partition

> **Normative.** The `GlobalTopologyPlan` uncut-component frontier census describes exactly the partition
> `P_U` constructed from the current **unlabelled-face set**
>
> `U = { f | fragmentOrbits[f] is absent or empty }`
>
> using the existing barrier set
>
> `B = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`.
>
> `P_U` is the connected-component partition of `U` across source edges not in `B`. The owner-consistency census
> contains one row per component of that same partition. No region, labelled trace-cut face, certified face, or
> `RegionCertification` failure is implicitly a member of `P_U` merely because it occurs later in the same plan.

This is the construction already present at `GlobalTopologyPlan.cpp:1341–1353`; this turn changes no byte of that
construction. TB42 measured the mechanical witness at **226** unlabelled faces, **9** partition components and
**9** owner-consistency rows. The failing region contains **10** source faces, **0** of which are in `P_U`.
Therefore the census exists and is healthy while being wholly unrelated to the failing region.

For any assertion that wants to use `P_U` as failure-local evidence, the **subject** is the object named by the
failure contract, not whichever locator happens to resolve first:

- an uncut-component failure owns that component's face set;
- a source-face failure owns that source face;
- a region failure owns the current region's complete `region.sourceFaces` set.

The relation of that subject `S` to `P_U` is typed as:

- **Inside** — `S` is non-empty and every face in `S` belongs to `U`;
- **Outside** — `S` is non-empty and no face in `S` belongs to `U`;
- **Partial** — some but not all faces in `S` belong to `U`;
- **Unresolved** — the subject itself cannot be identified from current authoritative data.

Only **Inside** licenses a claim that the uncut-component census describes the complete failure object. `Partial`
may be reported as cross-domain evidence but may not be collapsed to one component. `Outside` expressly forbids a
failure-local uncut-component assertion. `Unresolved` fails closed if a test or diagnostic requires a domain
classification.

### 2. DEFN-R8.2 — domain applicability is a predicate, never a stage name

> **Normative.** No census-owned invariant may be enabled or disabled by comparing
> `regionFrontierFailureStage` to a literal such as `"UncutComponent"`. Applicability is determined from the
> subject-to-domain relation in R8.1.

A stage name may remain diagnostic chronology. It is **not** proof of set membership and is not a test oracle.
The current `if (regionFrontierFailureStage != "UncutComponent") ...` shape is therefore retired as a domain
decision. This is the general rule: **a diagnostic or test that quantifies over a set must establish that its
subject belongs to that set before drawing a failure-local conclusion from the census**.

The existing CB47 measurements — source-face membership, region face count and region faces-in-partition count —
are valid domain-adjudication diagnostics and may be retained. They are not positive frontier evidence when the
relation is `Outside`.

### 3. DEFN-R8.3 — `RegionCertification` owns region/fragment evidence, not the uncut census

> **Normative.** When a failure is raised while certifying a current `GlobalTopologyRegion`, its failure-local
> evidence is the **current region's derived actual-embedded face-walk orbit and the fragment-owner relation for
> the failing source face**. It is not the uncut-component partition.

Part XI remains the prerequisite authority: `region_orbit(region, walk)` derives the current region's owning
face-walk orbit from exact boundary equality. R8 does not create a second topology certificate and does not alter
the Part XI binding.

For `RegionSourceFaceOwningFragmentMissing`, the diagnostic contract is:

1. `region` — the current region ID;
2. `sourceFace` — the source face whose fragment-owner lookup failed;
3. `regionOwningFragmentOrbit` — the **expected** owner orbit already published at the failing site;
4. the complete, deterministic set of fragment-owner orbit IDs actually published for that `sourceFace`;
5. the count of that set and an explicit `regionOwningFragmentOrbitPresent` membership result;
6. the existing face-local fragment-count controls (`localFragmentCount`, `ownerCount`, `expectedFragmentCount`,
   `ownerDeficit`) may accompany the relation but do not substitute for item 4.

The orbit set is the missing datum. TB41 already proved why cardinality is insufficient: the failing face reports
three local fragments, three owners, expected three and deficit zero, yet the expected region orbit is missing.
Therefore a count-only diagnostic cannot adjudicate this failure.

The owner-orbit set is **diagnostic only** in CB48. Publishing it must not add an owner, choose a winner, mutate
`fragmentCorners`, change `fragmentOrbits`, alter region construction, or move 366/367 past their current
`RegionSourceFaceOwningFragmentMissing` gate.

### 4. DEFN-R8.4 — the four protected identities are census-owned, not terminal-failure-owned

The four selector identities remain byte-frozen and gating. Their production fixture may end outside `P_U`; that
must not make the census oracle disappear. Each identity is restated around the producer that owns the datum.

#### Ordinal 390 — boundary-orbit attribution

`UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` must:

- validate a real published `P_U` component's boundary/seed attribution against the matching uncut-component
  census, including completeness/truncation and owner-count relations it already owns;
- classify the terminal failure subject with the R8.1 predicate;
- when that subject is `Outside`, assert the `Outside` receipt and the R8.3 region/fragment evidence instead of
  demanding a non-empty failure-local frontier component.

The identity may not pass merely because the terminal stage is later.

#### Ordinal 393 — projection/owner-map coverage

`MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` must validate the uncut-component
owner/projection publication **from a component in `P_U`**, not from a component inferred from the terminal failure.
Its coverage invariant remains distinct-source-face coverage rather than raw row arity. If the terminal region is
`Outside`, that is a separate domain receipt and does not waive the producer-owned census check.

#### Ordinal 406 — partition identity and correspondence

`UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent` must publish and validate
both partition identities and the explicit R8.1 relation. Equality is never required across different domains.
For an `Outside` region the correct result is **not-applicable as a failing-component correspondence**, accompanied
by the explicit `Outside` relation; it is not permission to invent a matching component. For an `Inside` subject,
the existing exact/superset correspondence rules remain live and must be checked.

#### Ordinal 407 — interior-arc census across both partitions

`InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` remains a cross-partition publication
identity. It must select an actual uncut-component census subject from `P_U`, publish each crossed source face and
its component in each named partition where defined, and preserve typed reasons for absent membership. It must not
use an `Outside` terminal region as though it were a plan uncut component.

**Non-vacuity requirement for all four.** CB48 must factor each identity's owned invariant into a deterministic
predicate/check that is applied to real production census data **and** to a deliberately corrupted copy of that
same-domain data. The real data must satisfy it; the corrupted copy must not. This negative is test-local and does
not create a selector identity. If any owned check cannot be falsified this way, CB48 stops before compile.

### 5. DEFN-R8.5 — the two-partitions question is adjudicated without unification

`M3-CP4c3-TB26-REV-CAND-04` is **ADJUDICATED BY DEFINITION**: the plan's `EmptyFragmentOrbits`/unlabelled-face
partition and the certifier's `NotTraceCut` partition are lawfully distinct domains. Their different face sets,
component counts and digests are not by themselves a product defect. The defect was **cross-domain substitution**:
a census over one partition was cited as failure-local evidence about an object in the other domain.

Therefore:

- no partition is widened or unified by CB48;
- ordinal 407 may compare the two only after naming both domains and preserving absent membership as data;
- a failure-local assertion may consume only a census whose domain predicate admits the failure object.

`M3-CP4c3-DEFN-R3-CAND-01` is **SEPARABLE and remains architectural / non-gating**. It concerns two independent
constructions of the same actual embedded topology and the danger of foreign orbit ordinals. Part XI plus CB46's
content anchor already prevents that foreign-ordinal comparison from owning this gate. It is not the reason `P_U`
and the certifier partition have different membership rules. **CB48 must not unify the two embedded-graph builders.**
That candidate remains open for a later architectural turn unless it becomes independently gating again.

### 6. DEFN-R8.6 — unchanged surface

The following are frozen:

- accepted **1–365 = 365/365**;
- ordinals **311/312/314/315/356/357/404/408/409** remain PASS contracts;
- selector **409** bytes and all selector membership are unchanged;
- Part XI and XI-A, `region_orbit`, orbit-keyed lookup, content anchor and actual-embedded face binding;
- source-face ownership, region construction, `fragmentCorners`, `fragmentOrbits`, cut selection, the `P_U` domain
  and its barrier set, and A2a′ cellularity semantics;
- 366/367 remain owned by `M3-CP4c3-TB40-REV-CAND-02`; R8.3 adds evidence only and does not correct them;
- 368/369/370/374/398 remain under their existing owners.

No accepted identity may be edited. No selector byte may change.

### 7. DEFN-R8.7 — frozen Code + Build successor: `M3-CP4c-3-CB48`

CB48 is **Code + Build only**, runtime-free, GMP/GMPXX linked. It implements only R8.1–R8.6 under the following
measures:

- **EE0 — domain predicate:** add one typed subject/domain relation (`Inside`, `Outside`, `Partial`, `Unresolved`)
  derived from authoritative face membership; do not branch on `regionFrontierFailureStage`.
- **EE1 — region fragment relation:** at `RegionSourceFaceOwningFragmentMissing`, publish the complete actual owner
  orbit set for `sourceFace`, its count, and whether `regionOwningFragmentOrbit` is present. Diagnostic only.
- **EE2 — projection/rendering:** carry EE0/EE1 through `RemeshPipeline` and the existing failure-locus renderer
  without changing unrelated error bytes.
- **EE3 — producer-owned census helpers:** replace `expect_later_region_frontier_evidence` as the four identities'
  gate with helpers that validate the census producer directly and separately validate the terminal subject's
  domain receipt.
- **EE4 — four protected identities:** restate only 390/393/406/407 as R8.4 specifies. For each, execute a
  deliberately corrupted same-domain copy and prove its owned predicate rejects it.
- **EE5 — branch receipts:** each of 390/393/406/407 prints one deterministic receipt naming the branch it
  actually exercised (`UncutCensus` plus terminal-domain relation) and why; "PASS" must remain distinguishable
  from "oracle did not run".
- **EE6 — frozen surface audit:** selector409, accepted test blocks, Part XI binding/content anchor, partition
  construction, region construction, ownership, `fragmentCorners`, cut selection and 366/367 control flow are
  byte/semantic unchanged as applicable.
- **EE7 — compile gate:** compile the changed owner target first, then the standard immutable package through the
  durable reusable workflow. Execute no Directional binary.
- **EE8 — successor plan:** author one artifact-only `M3-CP4c-3-TB43-EXEC` plan bound to the exact compile-green
  CB48 package; no rebuild, no test/benchmark definition edits in TB43.

Expected implementation surface is limited to the existing frontier/failure diagnostic contracts and the four
test bodies/helpers. A need to widen `unlabeledFaces`, change barriers, mutate owners, or correct the missing
fragment relation violates this definition and returns to review rather than expanding CB48.

### 8. Falsifiers and TB43 acceptance gate

The following falsify CB48 immediately:

1. accepted prefix is not **365/365**;
2. any of **311/312/314/315/356/357/404/408/409** loses its current contract;
3. selector409 bytes change;
4. any protected identity passes solely because a stage/branch skips its census-owned predicate;
5. any deliberately corrupted same-domain census still satisfies the corresponding owned predicate;
6. EE1 reports only counts and omits the exact owner-orbit membership needed to distinguish the observed
   three-of-three-but-wrong-owner case;
7. 366/367 advance because CB48 mutates ownership/fragment behavior rather than only publishing evidence;
8. any partition or embedded-graph construction is unified or widened to make the tests pass.

`M3-CP4c-3-TB43-EXEC` executes selector409 artifact-only from the exact CB48 package. If CB48 is correct and no
carried owner changes, the expected color vector is **402 PASS / 7 RED / 0 SKIP**, accepted **365/365**, with
390/393/406/407 recovered and the carried RED set `[366,367,368,369,370,374,398]`. The expectation is a falsifier,
not permission to synthesize success; TB43 records the actual ledger and stops for review on any discrepancy.

### 9. Accounting and exact next turn

Definition / Review + Plan only: no runtime, no compile, no package, no selector mutation and no stable repricing.
**+0 events / +0 recurrences.** Totals remain **47 / 14 / 33**, debt **5**, packages **107**. TB42 remains current
semantic runtime authority at **398 PASS / 11 RED**, accepted **365/365**.

**Exact next turn: `M3-CP4c-3-CB48` — Code + Build, runtime-free, under EE0–EE8.**

</details>

<a id="m3-preserved-3"></a>
<details>
<summary><strong>Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md</strong> — HISTORICAL IMPLEMENTATION PLAN</summary>

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

</details>

<a id="m3-preserved-4"></a>
<details>
<summary><strong>Architecture_M3_CP4c3_TB48_EXEC_Report.md</strong> — PRIMARY EXECUTION EVIDENCE</summary>

# M3-CP4c-3-TB48-EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / CB54 PREDICTION MET / SEMANTIC RED / RAW EVIDENCE PRESERVED / REVIEW REQUIRED

**Turn:** `M3-CP4c-3-TB48-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Authority and immutable input

TB48-EXEC consumed immutable CB54 package113 exactly as frozen. It did not configure, compile, relink, regenerate
discovery, repair package bytes or executable modes, mutate source/tests/fixtures/selectors, or run benchmarks.

- semantic source: `6dae3f6959551f6dcdd81f153aedb5f38411a96b`;
- immutable package113 artifact: `10125000895`, `m3-cp4c3-cb54-package113-result-34404928469`;
- package provider/download SHA-256: `e5fb50f92bbf4c4ffae5afeb203d6738490f6410b3a7e49245607e1b2e7835e9`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix selector count: 365;
- generic artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- package root manifest: **28/28 verified**;
- per-identity control: `timeout -k 5s 180s`;
- outer elapsed cutoff: none.

## 2. Execution evidence and caller boundary

Authoritative workflow run **`34409262512`**, event SHA `5bee00b7f4b4fb59c1716a8d99c3de026beaa602`, completed successfully. The artifact-only execute job is **`102659650326`** and completed successfully.

- result artifact: `10126711178`, `m3-cp4c3-tb48-result-34409262512`, provider/download SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`;
- persistent log artifact: `10126711588`, `m3-cp4c3-tb48-log-34409262512`, provider/download SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`;
- all **409** selector identities executed exactly once in ordinal order, one fresh process per identity;
- selection mismatches: **0**;
- timeout count: **0**;
- benchmark execution: false;
- configure / compile / relink / generated discovery: false;
- package repair / mode repair / source-test-fixture-selector mutation: false.

The caller records `harness_exit=0`; its independent boundary check records `boundary_ok=true`, `boundary_reason=ok`; the harness boundary records `script_exit=0`, `mode=--execute`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, and `timeout_count=0`. Package/source/execution-view pre/post censuses are byte-identical.

## 3. Raw measured result

TB48-EXEC measured:

- **409 total**;
- **405 PASS / 4 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED ordinals **`[368,369,374,398]`**;
- selection mismatch ordinals: `[]`;
- ledger SHA-256: `e450efbcc359ef544ab97c6fb9f0cb23b097e59b9680569390fe7a45a9350566`;
- failure-detail table SHA-256: `511f3c0bc6a4f971849b3c339e848a598905dd4af892cefe1506905ad82f5b4d`;
- resource-summary SHA-256: `1f85af61168f36ca9171b6e43b6f99e9165d26616c0f3f2e290e4c0e9a3cc79c`;
- identity-map SHA-256: `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`.

This exactly matches CB54's falsifiable aggregate prediction. It is mechanically valid raw EXEC evidence, not review or promotion authority. **TB47/package112 remains the reviewed semantic runtime authority** until independent `M3-CP4c-3-TB48-REV` adjudicates package113.

## 4. Ordinal370 — CB54 product correction recovers the frozen identity at runtime

Ordinal370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` is **PASS**, selected exactly once with exit 0. The frozen identity constructs an atlas-accepted closed torus with empty rails/network, requires `SurfaceCutGraph::make` to fail with existing `EmptyNetworkOnClosedSurface`, and requires a non-empty `sourceFace` locus. Its passing runtime therefore exercises both typed code 6 and the locus assertion from immutable package113. Current failure-detail/evidence SHA-256 is `c26de83abdc9496cd1301470918ec39ecca1cf389ef0ae1c6504da1800d1c431`.

Tracker intake: **`M3-CP4c3-TB48-EXEC-CAND-01` — RAW PRODUCT-CORRECTION RECOVERY / REVIEW REQUIRED / NON-STABLE / UNPRICED**. EXEC records the recovery only. Independent review owns final closure of `M3-CP4c2-TB-X2-R8-CAND-02`, package113 promotion, and checkpoint-closure judgment.

Accepted/protected ordinals307 and 367 remain **PASS**. Their prior dispositions are unchanged by EXEC.

## 5. Protected controls and ownership remain non-vacuously green

Protected 390/393/406/407 all remain **PASS** through the successful `PlanFrontier` evidence branch. Their retained receipts continue to record `branch=UncutCensus`, `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`, `terminalSubjectBranch=PlanFrontier`, and `planFrontierEvidenceBranchExecuted=yes`, with non-empty BW3/owner-map/partition/interior-arc evidence.

Ordinal385 again publishes **300 established / 0 unavailable / 0 conflicting** ownership. Frozen controls 404/408/409 also PASS.

## 6. Every observed RED categorized before closeout

The four RED ordinals reproduce their established separate failure surfaces and remain under their prior owners:

- **368** — prescribed sphere still fails before a cut graph with `NotProductionReady / CellularityNotEstablished / origin=RotationSystemInconsistent`, originating reason `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`; carried owner `M3-CP4c2-TB-X2-CAND-04`; current failure-detail SHA-256 `7772f846dd26ce469de28a285182a6d98f90c35fdfbd84757dce229a2312fa21`.
- **369** — `certificate.saturationUsed` remains `true` where the identity requires the ordinary tree-cotree proposal; carried owner `M3-CP4c2-TB-X2-R10-CAND-01`; current failure-detail SHA-256 `cc2ceeff468dea5dda3121548a68ab081518809783b06151eaa726ec183fdcbf`.
- **374** — the pre-classified folded-cone witness still stops at `atlasBuild=false`; carried owner `M3-CP4c3-TB7-CAND-02`; current failure-detail SHA-256 `f43da8d8de7d61b9132be3005bb652c732d1f6dc2f27eb87d8a181d2f2feaffa`.
- **398** — prescribed-sphere cut graph remains absent at `NotProductionReady/CellularityNotEstablished`; this remains downstream of 368; current failure-detail SHA-256 `c06eaa58a852f24fe6df465b2f8a783795294a9c1418a2dac0e391eb799bd2b5`.

No new RED identity or new failure surface appears. EXEC does not merge/reprice owners or prescribe corrections. Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, ownership **300/0/0**, accepted package count **113** pending review.

## 7. Retired-predicate silence and immutability

Across current result/log evidence there are zero occurrences of `TraceArcDoesNotSeparateItsSides`, `UncutFaceComponentOrbitSeedNotUnique`, `RegionEulerCharacteristicNotOne`, `FragmentCountRule`, and `FragmentPartition`.

Package/source/execution-view pre/post censuses are equal. No artifact mutation, source mutation, build, repair, discovery, benchmark, or executable-mode repair path executed.

## 8. Regression-tracker intake and authority boundary

Every observed RED is categorized in `Regression_Root_Cause_Tracker.md` as a carried recurrence under its existing owner. Ordinal370's RED-to-PASS transition is recorded as non-stable product-correction recovery evidence. Accepted remains 365/365 and EXEC establishes no new stable event/category. Stable totals remain **47 / 14 / 33**, debt **5**, ownership **300/0/0**, packages **113**.

**Reviewed semantic runtime authority remains TB47/package112** at 404 PASS / 5 RED until independent review. Raw TB48/package113 is not semantic promotion or checkpoint-closure authority by itself.

## 9. Exact successor

**Exact next: `M3-CP4c-3-TB48-REV` — independent REVIEW + PLAN, runtime-free.**

The review must adjudicate ordinal370's runtime recovery, the four carried RED owners, protected non-vacuity, stable accounting, package113 promotion and whether formal CP4c-3 closure follows from the already-met AU0–AU9 mechanical-witness criterion. It must perform mandatory REVIEW-turn document consolidation and update `ORIENTATION.md`. No retry, product/test patch, compile or new runtime is authorized before that review.

</details>

