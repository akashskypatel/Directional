## Resume-critical update — exact next turn is `M6-CP1-CB4` (recovery reconciliation, 2026-09-25T06:15:13Z)

**Start `M6-CP1-CB4` as a new runtime-free Code + Build turn. Nothing is held; no definition or review turn is pending.**

- **Why this note exists.** An implementation session started at 05:40:26Z. At that moment the review turn was still `IN_PROGRESS`; its COMPLETE beacon landed at 05:42:01Z. The session produced no work, and the loop recorded it as `CHAT_UNKNOWN`.
- **Verified by the review agent at recovery:**
  - no `M6-CP1-CB4` commit exists on any origin ref (head at recovery: `65acce1f`);
  - no GitHub Actions run exists after `36097522915` (05:11:33Z, DEFN-R2 cleanup);
  - no `M6-CP1-CB4` Drive staging or work-preservation patch exists.
- **So CB4 is a fresh turn, not a resume.** The entry beacon is `Turn: M6-CP1-CB4 / IN_PROGRESS / Successor: UNKNOWN`, with a new `Started at`, empty `Resumed at` and empty `Ended at`.
- **Authority chain, all accepted:**
  - DEFN-R1 core;
  - DEFN-R2 amendments;
  - `M6-DEFN-R2-REV` review amendments RA-1 – RA-10, normative at the end of `Architecture_M6_Frozen_Definitions.md`, rationale in `Architecture_M6_DEFN_R2_Review_Record.md` §3.

  The CB4 plan's status is **AUTHORIZED**. Its RA block overrides any older "HELD" wording in that file.
- **Unchanged:** stable accounting **54 / 16 / 38**, debt 1; accepted runtime authority `10814505512 / e284fea7...` under selector449 449/449; candidate `10840014758 / 660015f2...` unpromoted.

## Superseded resume notes (historical — do not act on)

### `M6-DEFN-R2` COMPLETE (2026-09-25)

*(Historical; `M6-DEFN-R2-REV` is complete and has authorized CB4.)*

`M6-DEFN-R2` resolved all four DEFN-R1 Review blockers and P1-P4 without touching source/test/selector bytes:

- B1: evidence-only `CornerWedgeIsolation` lineage equivalence with ordered exact `(region,seam,fromSheet,toSheet)` transitions; split-square v0/center/v2 can be `{0,1}` with non-empty lineage evidence without inventing quotient relations.
- B2: complete per-occurrence binding signatures; relation-local HardRail/Periodic selected-path charts/components; A7 lineage charts are union-of-all bindings; component remap preserves exact binding/transition tuples before legacy projections.
- B3: source-edge collinearity is exact `SourceSupport`; cell-interior incident face is selected topologically from accepted canonical cell orientation plus source winding. The orientation premise was re-proved for uniform, periodic-chart and bounded-disk builders.
- B4: A5 relation failures are one-to-one and mapped by the adapter to frozen M5 names; only duplicate structural owner/kind predicates may move earlier, while semantic route/transport/value/support checks stay live.
- P1-P4: ordered maximal support spans, reciprocal near-endpoint agreement, fail-closed singular/SingularityPort exclusions, and hard-rail/region wedge limits are frozen.

Frozen-test audit: focused rows 5/6, selector rows 186/214/239/444/446/448, and HardRail single-sheet assertions remain statically satisfiable. Seventh focused identity is strengthened to materialize/assert v0/center/v2 lineage. TB4 remains 7+449=456 if Review accepts and CB4 later compiles.

Exact source snapshot: run/artifact `36095854118 / 10847467936`, SHA `342a306ebd3ba68cb6e1135cf9e25726bd8ad461`, provider SHA-256 `a19261e06e11293b9240b8a44c24f95042190df1d7154ba330c5e677fb9875c2`, embedded archive SHA-256 `c0ca5581851b76b1a169cdffb4c3b7243070d54225f176e6510ce909b152ab1c`, `runtimeExecution=false`.

Stable accounting remains **54 / 16 / 38**, debt 1, +0. Accepted M5 authority remains package/source `10814505512 / e284fea7...` under selector449 449/449. `M6-DEFN-OBS-01` recurred as the already-known pre-READ_MODE process miss; decisive conclusions were re-derived from the verified snapshot and no new lesson/event is created.

### `M6-DEFN-R1-REV` COMPLETE (2026-09-25)

**Exact next turn: `M6-DEFN-R2` (runtime-free Definition amendment). CB4 stays HELD.**

The review agent upheld the DEFN-R1 core model: corner-wedge sheet sets, wedge/side certificate carriers keyed by `(region, seam edge)`, owner-less `OrdinaryFront`, A6 membership validation, the A7 union, and no mixed-face records. The split-square table re-derives exactly. The definition is **not accepted as frozen** because of four blocking findings (`Architecture_M6_DEFN_R1_Review_Record.md`):

- **B1 (decisive).** Frozen focused row5 (`SurfaceCellTransitionQuotientTests.cpp:2639`) requires non-empty `lineage.equivalences` for every multi-sheet lineage, but equivalences come only from relation unions (`RemeshPipeline.cpp:4384-4393`). Under D5, v0 and v2 are relation-free singleton classes with `{0,1}` and no equivalences, so TB4 is RED by construction. Represent wedge evidence in `equivalences`, and have the seventh identity assert lineage.
- **B2.** D6 does not specify which binding each face-dependent consumer uses: the transitional class key and `QuotientClassId` ordinal, `representative_key`, selected relation path charts and components (torus rows 444/448), and lineage `sourceCharts`.
- **B3.** Wedge endpoints still come from tie-broken segment faces. There are three side builders, and the split square uses `segment_on_source`, which breaks ties by source-face row. One exact collinearity/interior-face rule is needed, with the orientation premise proved per builder.
- **B4.** D7 contradicts frozen §4.6. A5's many-to-one `UnownedRelation` lets specific M5 codes become generic; split the A5 codes 1:1 and map them at the adapter.

Accounting stays **54 / 16 / 38**, debt 1. Accepted runtime authority is unchanged.

### `M6-DEFN-R1` COMPLETE (2026-09-25)

*(Historical; its successor `M6-DEFN-R1-REV` is now complete.)*

`M6-DEFN-R1` froze complete corner-wedge sheet authority, wedge/side seam-certificate carriers, exact seam-collinear side semantics, per-wedge face/chart/branch provenance, A6 owner-less OrdinaryFront checks, A7 lineage union semantics, row140 adapter ownership, and the CB4/TB4 re-scope. The new focused identity is `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; TB4, if later authorized, is 7 focused + selector449 = 456.

Accepted runtime authority remains `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` with selector449 449/449 PASS. Stable accounting remains **54 / 16 / 38**, debt 1. Candidate `10840014758 / 660015f2...` remains unpromoted. Selector449/routing449 are unchanged.

Review must independently re-open source/evidence and re-derive: split-square v0/center/v2 wedge/certificate orientations; all eight endpoint pair memberships; interior seam vertex crossing one/two seam edges; exact seam-collinear incident-cell side authority; per-wedge provenance; row140 adapter-only compatibility; selector/routing hashes and seven-test pre-registration. If any of those semantics is ambiguous, amend Definition rather than implementing.

# Directional Future Chat Session Handoff

## DURABLE — live resume authority

## Current authority

`M6-DEFN-R2-REV` is **COMPLETE: `M6-DEFN-R2` ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-10**. The seam-incident definition chain is closed:

- **DEFN-R1 core:** corner-wedge sheet sets; wedge/side certificates keyed by `(region, seam edge)`; owner-less `OrdinaryFront`; A6 membership validation; A7 union; no mixed-face records.
- **DEFN-R2:**
  - evidence-only `CornerWedgeIsolation` lineage transitions;
  - complete binding signatures;
  - relation-local path charts;
  - winding-selected interior faces (orientation premise proved in all three builders);
  - one-to-one A5 relation failures;
  - P1-P4.
- **RA-1 – RA-10:**
  - boundary and region-boundary collinear edges;
  - P3/P4 keyed only on arc failure, never on vertex category;
  - row-invariant permutation checks rather than `hash_completion`;
  - `OccurrenceUnownedRelation` name and row3's enum `UnownedRelation` kept;
  - lineage sheets = wedge union only;
  - `crossesSheets` retired, with adapter mapping to the legacy isolation-seam names;
  - wedge-arc endpoints and direction;
  - resolver-defined span support (1e-8);
  - transitional `quotientClass` unchanged.

Accepted runtime authority is unchanged: M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**. TB3 candidate `10840014758 / 660015f2...` remains unpromoted. Stable accounting is **54 events / 16 categories / 38 recurrences**, debt **1**.

## Exact next turn

**`M6-CP1-CB4`** — runtime-free Code + Build under `Architecture_M6_CP1_CB4_Relation_Owned_Isolation_Equivalence_Code_Build_Plan.md` (AUTHORIZED), as amended by RA-1 – RA-10. Compile-green → immutable `M6-CP1-TB4-EXEC` (7 focused + selector449 = **456** fresh exact-filter processes, benchmark 0) → mandatory `M6-CP1-TB4-REV`.

**Entry.** Follow lesson 178, and treat this as a fresh turn:
1. List origin commits, Actions runs and Drive staging for `M6-CP1-CB4`. None existed at recovery.
2. Write the `M6-CP1-CB4 / IN_PROGRESS` beacon (new `Started at`) as the first repository write.
3. Freeze `READ_MODE=snapshot` before reading documents.

**Recommended work order.** This is a single coherent patch, ordered by dependency; the plan's stop rules still apply.
1. **Static derivations first,** recorded in the CB4 report:
   - split-square v0/centre/v2 wedges and transitions (v0 `1→0`, v2 `0→1`);
   - one seam-vertex two-edge fan;
   - one collinear side each for boundary, internal and hard-rail edges (RA-1);
   - the row140 and row3 failure flows (RA-5);
   - the audit list in plan §9 (focused 1-6, selector 140/186/214/239/444/446/448, Phase10 HardRail single-sheet rows).
2. **Types.** Wedge face bindings, the isolation-transition tuple, the new A5 occurrence fields, and `PureQuadEquivalenceKind::CornerWedgeIsolation` with its transitions field. Include it in comparison and in `hash_completion`.
3. **A5.**
   - span support per RA-9, interior face per RA-1, wedge arc per RA-8, wedge/side evidence;
   - P3/P4 per RA-2/RA-3;
   - one-to-one relation failures per RA-5, with the adapter's legacy-name table per R2 §6 and RA-5/RA-7.
4. **A6 / transitional materializer.**
   - remove `crossesSheets` (`RemeshPipeline.cpp:4180-4191`) and add span membership plus reciprocal-side checks (RA-7);
   - class key from complete binding signatures, with the `quotientClass` ordinal unchanged (RA-10);
   - representative key per R2 §4.3; relation-local step and path charts;
   - delete only the duplicate owner/kind branches.
5. **A7 lineage.**
   - sheets = wedge union (RA-6); `sourceCharts` = union of binding charts;
   - `CornerWedgeIsolation` entries (front edges −1, identity action);
   - remap complete tuples before projecting.
6. **Seventh identity** `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`, plus one test-local reversed-row split-square helper. Permutation checks compare only row-invariant semantic data (RA-4).
7. **Checks and compile.**
   - by-value accessor split-range scan clean;
   - selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` byte-identical;
   - no existing test or fixture edited;
   - compile/package the standard eight GMP/GMPXX targets via `agent-compile-reusable.yml`, with `runtimeExecution=false`.

**Durability.** This turn is large. Emit the `RETENTION_POLICY.md` / `Durable_Handoff_Policy.md` item 13 work-preservation patch to Drive before any long compile loop, and before yielding. If the turn must yield, publish `IN_PROGRESS` or `BLOCKED` after the last repository write.

## Completed predecessor turns (reference only)

- `M6-DEFN-R2-REV` — accepted R2 with RA-1 – RA-10 (`Architecture_M6_DEFN_R2_Review_Record.md`).
- `M6-DEFN-R2` — B1-B4 and P1-P4 amendments (`Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`).
- `M6-DEFN-R1-REV` — core upheld, four blockers (`Architecture_M6_DEFN_R1_Review_Record.md`).
- `M6-DEFN-R1` — corner-wedge model (`Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`).

## Current files

- `.agents/Directional/Architecture_M6_CP1_CB4_Relation_Owned_Isolation_Equivalence_Code_Build_Plan.md` (AUTHORIZED implementation plan; filename historical)
- `.agents/Directional/Architecture_M6_Frozen_Definitions.md` (normative; RA-1 – RA-10 at the end)
- `.agents/Directional/Architecture_M6_DEFN_R2_Review_Record.md` (acceptance + RA rationale)
- `.agents/Directional/Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`
- `.agents/Directional/Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`
- `.agents/Directional/Architecture_M6_DEFN_R1_Review_Record.md`
- `.agents/Directional/Architecture_M6_CP1_TB3_Artifact_Only_Test_Benchmark_Report.md` (latest runtime report)
- `.agents/Directional/Architecture_M6_CP1_TB3_Review_Record.md` (TB3 Review + addendum)
- `.agents/Directional/M6_Consolidated_Record.md`
- `.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`
- `.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CODE_BUILD.md
  - .agents/Directional/Architecture_M6_CP1_CB4_Relation_Owned_Isolation_Equivalence_Code_Build_Plan.md
  - .agents/Directional/Architecture_M6_DEFN_R2_Review_Record.md
  - .agents/Directional/Architecture_M6_Frozen_Definitions.md  # RA section at end is normative
  - .agents/Directional/Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md
conditional_modules:
  - trigger: github_connector / GitHub Actions / patch transport
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md
  - .agents/Directional/Architecture_M6_DEFN_R1_Review_Record.md
  - .agents/Directional/Architecture_M6_CP1_TB3_Review_Record.md
  - .agents/Directional/M6_Consolidated_Record.md
  - turn-based-coding-agent/references/core/turn-boundaries.md
  - turn-based-coding-agent/references/core/evidence.md
  - .agents/Directional/GitHub_Workflow_Policy.md
  - .agents/Directional/GMP_COMPILE_POLICY.md
do_not_preload:
  - folded superseded M6 per-turn records
  - uncited historical reports
  - research/provenance/examples
```
