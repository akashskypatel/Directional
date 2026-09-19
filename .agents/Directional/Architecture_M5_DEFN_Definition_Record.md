# M5-DEFN Definition / Independent Review Record

**Turn:** `M5-DEFN`
**Decision:** **APPROVED WITH AMENDMENTS / DEFINITIONS FROZEN / RUNTIME-FREE**
**Normative output:** `Architecture_M5_Frozen_Definitions.md`
**Exact successor:** `M5-CP1-CB1` under `Architecture_M5_CP1_Code_Build_Plan.md`

## 1. Independent derivation

The definition was checked against the current source snapshot rather than accepted from the incoming plan. The decisive source facts are:

- `PeriodicRelationId` is presently an index-backed `SemanticId` and production still calls `from_index(...)`;
- `insert_periodic_holonomy(...)` allocates the first unused integer and rejects a second distinct same-region relation as `AmbiguousBasis`;
- multi-component aggregation remaps relation IDs through `periodicRelationOffset`;
- `PureQuadEquivalenceProvenance` carries front-edge representation handles;
- `close_completion_lineage_source_authority(...)` turns retained equivalences into an adjacency graph and performs consumer-side reachability traversal;
- accepted M4 production proves the row408-class torus reaches `Produced`, while the prior R3 evidence shows that produced subject contains zero periodic holonomies.

Those facts support the M5 diagnosis: storage/representation still participates in relation naming and a downstream consumer still reconstructs missing relation-path semantics.

## 2. Amendment to the incoming interpretation

The incoming plan required canonical relation IDs but did not settle whether action/transport belongs to identity. Review freezes the narrower rule:

> **relation locus is identity; relation action/transport is value.**

A periodic relation is identified by topology-region scope plus canonical orientation-neutral generator/cut **carrier** paths. Exact action and step transport remain in the immutable relation value. This is necessary for the required tamper semantics: changing only the transform on the same carrier must become `ConflictingPeriodicRelation`, not manufacture a new identity.

The selected-path rule is likewise narrowed: the producer records the exact chain it actually used. A validator verifies that exact chain; it does not choose the lexicographically smallest path from the entire relation table. That makes an unused valid relation provably decision-neutral.

## 3. Failure/debt adjudication

The five M5 relation failures are all expressible without M6 A5 occurrence ownership: existing `MissingPeriodicRelationOwner` and `DuplicatePeriodicRelationId` remain the missing/duplicate owners; CP2 adds conflicting, nonreciprocal, and representation-renumbered relation failures. Their independent negatives derive expected path identity from semantic carrier content rather than producer ordinals/factory output.

All four M5 produced-witness debts remain open. Direct helpers/drafts prove mechanisms only. The original `>=2` relation/edge, missing-owner, and nonzero-Z4 discriminators are unchanged. Stable accounting remains **49 / 14 / 35**, produced-witness debt **5**.

## 4. Consolidation/process disposition

The consumed `Architecture_M5_DEFN_Definition_Plan.md` is folded into `M5_Consolidated_Record.md`; live authority is the frozen definition plus one CP1 plan. No new lesson is added: the session's early read-mode sequencing miss is an instance of the existing read-mode/control-plane discipline already recorded in `LESSONS.md` (lesson 152), and no semantic editing occurred before correction to immutable snapshot mode.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — M5-DEFN accepts no new runtime package/selector and does not alter selector430; M4-TB3 Review remains the selector430 promotion authority. |
| Decisive claims independently re-derived | yes — current source snapshot independently located index-backed relation construction, insertion-order allocation, component-offset remapping, same-region `AmbiguousBasis`, front-edge representation handles, and consumer-side BFS reachability reconstruction. |
| Non-vacuity checked | yes — the four carried M5 debts remain explicitly uncredited because existing mechanism fixtures are direct/draft and the proven production torus currently has zero periodic holonomies. |
| Prior obligations discharged/carried | M5-DEFN definition obligation discharged; four M5 produced-witness debts carried unchanged to CP1/CP2 mechanism and CP3 direct-production owners; one M6 debt unchanged. |
| Stable accounting | **49 events / 14 categories / 35 recurrences; debt 5; accepted package `10591801825`; selector430 430/430.** |
| New candidates/obligations recorded | none — definition clarifies existing M5 architecture debt; tracker updated with definition-only/no-runtime disposition. |
| ORIENTATION currency line | `M5-DEFN`, 2026-09-19 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | updated — M5 definitions/current next; torus zero-periodic production state; CP1 priority; identity/value instance of existing representation-identity pattern. |
| CHANGELOG | M5-DEFN entry added to project and root changelogs. |
| ROADMAP | updated — M5-DEFN complete/frozen; exact next `M5-CP1-CB1`; stale remaining-path summary corrected. |
| Selector manifest | n/a — no selector added, accepted, renamed, or mutated. |
| LESSONS | existing lesson 152 cited; no genuinely new recurring pattern. |
| Consolidation under CLEAN_UP_POLICY | `Architecture_M5_DEFN_Definition_Plan.md` consumed/folded into `M5_Consolidated_Record.md`; one current normative definition + one next plan retained. |
| Successor frozen | exactly one: `M5-CP1-CB1`; falsifiers/stop rules are in `Architecture_M5_CP1_Code_Build_Plan.md` §§4,7. |
| Turn boundary held | yes — documentation/planning only; no production/test/fixture/selector/build-logic mutation, compile, test, benchmark, or generated Directional runtime. |
| review_check.py boundary | **PASS** — all review-turn boundary checks passed; no product/test/fixture/build/selector mutation and selector430 matched HEAD. |
| `STATUS` lifecycle maintained | entry beacon is `M5-DEFN / IN_PROGRESS`, Started at `2026-09-19T22:13:32Z`, Resumed blank; final COMPLETE/SUCCESSOR/end timestamp is reserved for the mandatory last repository mutation. |
| Pushed to origin, branch in sync | pending work-preservation patch application and final control-plane verification; this row will be finalized before closeout. |
