## Resume-critical update — exact next `M6-CP1-CB5`, as amended by the TB4-REV review-agent addendum (RA-12) (2026-09-25)

**Start `M6-CP1-CB5` as a new runtime-free Code + Build turn.** Enter with `Turn: M6-CP1-CB5 / IN_PROGRESS / Successor: UNKNOWN`, a new `Started at`, and empty `Resumed at` / `Ended at`. Do not rerun TB4 and do not resume CB4.

The review agent upheld TB4-REV:
- the 21 new losses come from A6 treating any source-edge-collinear span as a seam (`RemeshPipeline.cpp:4908-4914`);
- one `RP-01` recurrence; accounting **55 / 16 / 39**, debt 1.

It also proved the attribution. On a single-sheet fixture only that branch can emit `MissingIsolationSeamEquivalenceAuthority`, and all 21 losses use single-sheet fixtures.

Amendments:
- **RA-12 (required in CB5):** keep the legacy isolation-failure names as prefixes and add site suffixes (`:a5-wedge`, `:a5-side`, `:a6-side-evidence`, `:a6-collinear-span`, `:a6-seam-span-transition`, `:a6-seam-faces`). Diagnostic only; no test or production code compares these strings.
- **Torus falsifier:** recovery of focused row6 and selectors 444/446/448 is a prediction, not a proof. The torus is multi-sheet, so the A5 and seam-span sites remain possible. If any stays RED in TB5, TB5-REV classifies it by its suffix.
- **Debts (not CB5):** legacy single-valued `SurfaceOccurrence` fields (`isolationSheet`, `chart`, `point`, `chartComponent`, `lattice`) are dead but published. Removing them or marking them representation-only is a CP1-acceptance precondition. Aggregated `equivalences` are not re-sorted.

Full record: `Architecture_M6_CP1_TB4_Review_Record.md` (TB4-REV plus the addendum). Plan: `Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md`.

## Superseded resume notes (historical — do not act on)

### `M6-CP1-TB4-REV` COMPLETE; exact next `M6-CP1-CB5` (2026-09-25)

**Do not rerun TB4 and do not resume CB4. Start bounded runtime-free `M6-CP1-CB5`, then immutable `M6-CP1-TB5-EXEC`, then mandatory `M6-CP1-TB5-REV`.**

Independent Review upholds TB4 mechanics at focused **6/7** + selector449 **425/449** = **431/456 PASS**, but adjudicates `M6-CP1-TB4-EXEC-CAND-01` as **one new stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**. A5 `collinearEdge` is generic exact source-edge support and permits same-sheet/no-certificate spans; A6 OrdinaryFront P2 incorrectly treats every such span as an isolation seam and requires `isolationCertificateBySeam[(region,edge)]`. R2 P2 separates these domains.

Stable accounting is now **55 events / 16 categories / 39 recurrences**, debt **1**, M6-owned. Candidate `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5` remains unpromoted. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**.

`M6-CP1-CB5` changes only A6 reciprocal `OrdinaryFront` near-endpoint classification: matching source-edge-collinear spans with **no exact isolation certificate** use the non-seam same-sheet + both-wedges rule; certificate-backed spans retain the existing exact seam face/sheet/reciprocal-transition rule. No A5/schema/support/test/fixture/selector/HardRail/Periodic change is authorized. Stop if existing certificate authority cannot make this distinction without a definition/product change.

Compile-green TB5 reruns the same **7 focused + selector449 = 456** processes. Recovery-green is 7/7 + 449/449 with all 21 new TB4 losses and carried pair-swap/444/446/448 recovered, row140/rows5/7 still PASS, no `OccurrenceInvalidCornerAuthority`, exact-one/zero-skip and immutable postflight. Any RED is Review-owned.

Full current adjudication: `Architecture_M6_CP1_TB4_Review_Record.md`. Exact plan: `Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md`.

### `M6-CP1-TB4-EXEC` COMPLETE; exact next `M6-CP1-TB4-REV` (2026-09-25)

**Do not rerun TB4 or start corrective implementation. Start mandatory runtime-free `M6-CP1-TB4-REV`.**

TB4 consumed CB4 candidate artifact/source `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5` immutably and executed the entire frozen gate in run/job `36157505252 / 108145613689`: **7 focused + selector449 = 456 fresh exact-filter processes**, exact-one selection, zero skips/selection mismatches, no watchdog, benchmark 0, and exact immutable postflight. Result/log artifacts are `10874311495 / 10873574681`.

- focused: **6/7 PASS**; only retained pair-swap row6 is RED at `MissingIsolationSeamEquivalenceAuthority`; multi-isolation row5 and the new seventh seam-endpoint/wedge-lineage identity PASS;
- selector449: **425/449 PASS / 24 RED**; RED ordinals `115,116,122,130,132,134,137,141,143,150,176,201,217,218,231,232,238,246,436,437,438,444,446,448`;
- relative to TB3, focused row5 and selector 186/214/239 recover, while row6 + 444/446/448 remain RED and **21 accepted selector identities newly turn RED**;
- result SHA-256 `32dca965d68d060c32e1e8f79ac146cf6381eb6cf5762c0854c5d792ae693e24`, evidence manifest **932/932**; log SHA-256 `9d50f4e6adb6e17a20bc13071107b41ea8113b55854a7b8dd1f2cafe8d9b4757`;
- EXEC records non-stable `M6-CP1-TB4-EXEC-CAND-01` and makes **no stable repricing**. Stable accounting remains **54 / 16 / 38**, debt **1**. Candidate remains unpromoted; accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 449/449.

Review must independently reopen the candidate and TB4 result/log artifacts, compare all 24 selector REDs to accepted M5 authority, adjudicate candidate grouping/root cause/recovery, and only then authorize any successor beyond Review. Full execution record: `Architecture_M6_CP1_TB4_Artifact_Only_Test_Benchmark_Report.md`.

### `M6-CP1-CB4` COMPLETE; exact next `M6-CP1-TB4-EXEC` (2026-09-25)

**Do not resume CB4. Start immutable artifact-only `M6-CP1-TB4-EXEC`, then mandatory `M6-CP1-TB4-REV`.**

CB4 implemented the accepted R2 + RA-1 – RA-11 seam-incident occurrence/lineage authority at exact semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`. The candidate is compile/package green and **unpromoted**. No generated Directional runtime executed.

- patch apply run/job `36150018237 / 108120755401`; exact patch SHA-256 `1be2b2b3785d46bdde23cd3d24af4346a649591a430595960e44a557b279235b`; applied source `20f60bb1...`;
- compile run/job `36150253128 / 108121497728`; result artifact `10871935178`, SHA-256 `dc6e979ac62b4599c2c8b15528524513f3bc5b45eb9068ed508fd3d08ccf7998`; log artifact `10871960013`, SHA-256 `bbdfe584c0aefa433f614f699c28686ab83c9bc8194b3f868c1db96589c2eabf`;
- all eight standard targets compiled/linked with GMP/GMPXX; root manifest 28/28; source clean; `runtimeExecution=false`;
- selector449 remains 449 LF rows at `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- strengthened focused identity `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` compiles; no runtime result is claimed.

TB4 is frozen at **7 focused + selector449 = 456 fresh exact-filter processes**. Use artifact `10871935178` immutably; do not rebuild or repair it. The Test + Benchmark turn must obey the artifact-only extraction/mode rules and update `Regression_Root_Cause_Tracker.md` for every observed regression before closeout.

Stable accounting remains **54 / 16 / 38**, debt **1**. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449**. CB4 grants no runtime credit or promotion.

Full evidence: `M6_Consolidated_Record.md §17 (folded CB4 compile authority)`.

### `M6-CP1-CB4` UNBLOCKED by RA-11: resume the same turn (2026-09-25T09:41:20Z)

**Resume `M6-CP1-CB4`.** This is the same turn: keep `Started at 2026-09-25T06:19:30Z` and set a new `Resumed at`. It is not a new turn, and no Definition turn is pending.

The per-face branch blocker is **resolved by review-agent amendment RA-11**. The blocker's facts are upheld. Its two proposed directions (an A4 product change, or deriving the branch) are unnecessary, because **nothing consumes a per-face branch**. The only A5-A7 reader of an occurrence branch is the transitional class key. Relation transport checks use A4 edge/endpoint lattice states.

RA-11 in brief:
- `CornerWedgeFaceBinding` = `(face, sheet, chart)`, with no branch.
- Each occurrence publishes `CornerPlacementProvenance`: the A4 corner `LocalLatticeState` verbatim, labelled with its A4 selected corner face. This is placement provenance only; the periodic builder leaves its branch at `0`.
- Class key = binding signatures + coordinate + scale + labelled placement provenance.
- Representative key has no branch.
- Stop rule: if CB4 finds another consumer that needs a wedge-face branch, stop and return to Review.

Normative text is at the end of `Architecture_M6_Frozen_Definitions.md`. Evidence is in `M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`, "Review-agent adjudication". No A4 or test change, and TB4 stays 7 + 449 = 456. Accounting 54/16/38, debt 1.

### `M6-CP1-CB4` BLOCKED on per-face branch authority (2026-09-25) — RESOLVED by RA-11

**Do not continue CB4 implementation or start TB4. No production/test patch or compile candidate was created.**

Static derivation against exact source snapshot run/artifact `36104814370 / 10850013454` proved that accepted D6/R2 requires every `CornerWedgeFaceBinding` to carry the exact `branchRotation` for that source face, but immutable A4 `SurfacePhaseFrontProduct` does not publish a per-face branch table or field-transport authority from which A5 can derive that value for an intermediate corner-wedge face. `SourceChartTransitionGraph` carries chart/simplex connectivity rather than field branch transport, and isolation-seam certificates cover only seam edges, not ordinary same-sheet fan edges. Any CB4 implementation would therefore have to invent a representative value, consume raw field authority outside the frozen A5 input boundary, or change the A4 product. All are outside the authorized plan.

- Blocker record: `.agents/Directional/M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`.
- Exact snapshot: source/event SHA `a304bd0b36011f2c100b8a6c127d8ba3c11810cf`; provider digest `ff39ad5104fbfadbb245c4e406428588b5c8142d4b84d723c876c2b7704ebb12`; embedded archive SHA-256 `bb5d91e6aca68fd491ad9c643d406e8273a520a96b1f5a814ac8b896baac8d2e`; 5314/5314 manifest rows verified; `runtimeExecution=false`.
- Stable accounting, debt, accepted M5 package/source, selector449 and routing449 are unchanged. This is a static definition/authority gap, not a runtime event.
- Required resolution: a bounded Definition amendment must either preserve A4-computed per-face branch authority in an authorized A4 product field, or redefine the binding branch value so it is derivable from existing A4 products with proofs for uniform, periodic-chart and bounded-disk producers.
- **No authorized successor turn ID is frozen yet.** Repository `STATUS` is BLOCKED with successor `UNKNOWN`; do not invent a Definition turn identifier.

### Recovery reconciliation — CB4 not started (2026-09-25T06:15:13Z)

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

`M6-CP1-TB4-REV` is **COMPLETE** (review-agent addendum included). CB4 candidate `10871935178 / 20f60bb1...` ran cleanly but is unpromoted, at focused **6/7** + selector449 **425/449** = **431/456**:
- recovered: focused rows 5 and 7, selectors 186/214/239;
- 21 new accepted losses, one `RP-01` recurrence: generic source-edge-collinear support consumed as isolation-seam authority in A6 (`RemeshPipeline.cpp:4908-4914`);
- still RED from TB3: focused row6 and selectors 444/446/448 (multi-sheet torus; cause not proved).

Definition authority: DEFN-R1 core, R2, and RA-1 – RA-12 at the end of `Architecture_M6_Frozen_Definitions.md`. Accepted runtime authority is unchanged: M5 `10814505512 / e284fea7...`, selector449 **449/449**. Stable accounting **55 / 16 / 39**, debt **1** (M6). Formal recovery of TB1 and TB3 is still open. The TB2 candidate is closed.

## Exact next turn

**`M6-CP1-CB5`** — bounded runtime-free Code + Build under `Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md`, including its review-agent amendment block.

1. **The single semantic change,** in the A6 reciprocal `OrdinaryFront` endpoint-span check:
   - keep presence parity and the same-edge requirement;
   - neither span collinear → the existing non-seam P2 rule;
   - both collinear on the same edge → look up `isolationCertificateBySeam[{region, edge}]`:
     - **no certificate** → the same non-seam P2 rule (same interior sheet, in both wedge sets; failure emits `QuotientReciprocalSideAuthorityMismatch`);
     - **certificate present** → the current seam branch, unchanged.
2. **RA-12 site suffixes** on every isolation-failure emission (A5 adapter and the four A6 sites). Diagnostic only.
3. **Frozen:** A5 span construction; support resolver; RA-1 – RA-11 semantics; schemas; occurrence/relation identity; quotient equality; HardRail/Periodic; remap; every test and fixture; selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...c5707`. No new focused identity.
4. **Compile** the eight GMP/GMPXX targets via `agent-compile-reusable.yml` with `runtimeExecution=false`. No Directional runtime.

**Successor if compile-green:** immutable `M6-CP1-TB5-EXEC`, running the same 7 focused + selector449 = **456** processes (benchmark 0), then mandatory `M6-CP1-TB5-REV`.
- **Recovery-green:** 7/7 and 449/449, row140 PASS, no `OccurrenceInvalidCornerAuthority`.
- **Residual REDs** are classified by RA-12 suffix. Downstream-casualty and torus falsifiers apply, and nothing is repaired or rerun inside TB5.

## Completed predecessor turns (reference only)

- `M6-CP1-TB4-REV` (+ review-agent addendum) — `Architecture_M6_CP1_TB4_Review_Record.md`.
- `M6-CP1-TB4-EXEC` — `Architecture_M6_CP1_TB4_Artifact_Only_Test_Benchmark_Report.md`.
- `M6-CP1-CB4` — source `20f60bb1`, candidate `10871935178` (folded into `M6_Consolidated_Record.md`).
- `M6-DEFN-R2-REV`, `M6-DEFN-R2`, `M6-DEFN-R1-REV`, `M6-DEFN-R1` — the definition chain.

## Current files

- `.agents/Directional/Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md` (exact next; amended)
- `.agents/Directional/Architecture_M6_CP1_TB4_Review_Record.md` (TB4-REV + review-agent addendum)
- `.agents/Directional/Architecture_M6_CP1_TB4_Artifact_Only_Test_Benchmark_Report.md` (latest runtime report)
- `.agents/Directional/Architecture_M6_Frozen_Definitions.md` (normative; RA-1 – RA-12 at the end)
- `.agents/Directional/Architecture_M6_DEFN_R2_Review_Record.md`
- `.agents/Directional/Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`
- `.agents/Directional/Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`
- `.agents/Directional/M6_Consolidated_Record.md`
- `.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`
- `.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CODE_BUILD.md
  - .agents/Directional/Architecture_M6_CP1_CB5_Ordinary_Front_Seam_Classification_Recovery_Code_Build_Plan.md
  - .agents/Directional/Architecture_M6_CP1_TB4_Review_Record.md  # includes review-agent addendum
  - .agents/Directional/Architecture_M6_Frozen_Definitions.md  # RA-1..RA-12 at end are normative
conditional_modules:
  - trigger: github_connector / GitHub Actions / patch transport
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M6_CP1_TB4_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md
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
