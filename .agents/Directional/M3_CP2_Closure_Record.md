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
