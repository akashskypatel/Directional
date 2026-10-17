# `M6-DEFN-R5` — CP3-Entry Definition Plan

**Turn:** `M6-DEFN-R5`
**Type:** bounded, runtime-free Definition. No source, test, fixture, selector or build edits, and no generated Directional executable.
**Entry authority:**
- M6-CP1 CLOSED / ACCEPTED, mechanism-only (`M6_CP1_Closure_Record.md`);
- M6-CP2 CLOSED / ACCEPTED (`M6_CP2_Closure_Record.md`).

**Reviewed runtime authority:** `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, focused-30 + focused-12 + selector449 = **491/491**.
**Accounting:** 60 / 16 / 44, debt 1 (`G4-B002`).
**Mandatory successor:** `M6-DEFN-R5-REV`. This Definition authorizes no implementation.

## 1. Why this turn exists

Frozen §10 makes M6-CP3 the M6 exit on **direct production**. Several obligations were deferred to this gate across CP1/CP2 and must be decided before any CP3 direct-production TB (RA-17 §4). The index below is the complete carried list; this turn decides **exactly these**.

## 2. Obligation index (decide each; cite `file:line` for every decision)

| # | Obligation | Origin | Current-source anchor |
|---|---|---|---|
| D1 | Periodic unequal-face-gauge **exact-A3 witness**, and replacement of the face-gauged final check with a coordinate + relation-gauge rule | RA-16 §4; RA-17 §4; TB7 addendum §G5 | frozen §RA-16 (`Architecture_M6_Frozen_Definitions.md:651`) |
| D2 | HardRail **cross-region branch certification**, which needs published per-endpoint face-gauge authority | RA-16 §4; RA-17 §4 | A5 HardRail relation construction |
| D3 | OrdinaryFront **coordinate identity**, or isolation-seam transition, across isolation seams | RA-16 §4; RA-17 §4 | A5 OrdinaryFront relations; A6 collinear span check |
| D4 | **A5 chart-barrier census.** A5 builds its chart-transition barrier set from HardRail front routes only, while completion protects `hardFeatureRailEdges`; PeriodicCut-carried hard features are absent from A5's set. Decide whether the asymmetry is semantic; if so, define the correction and its witness. | DEFN-R4-REV F2; RA-20 §4 | `RemeshPipeline.cpp:3785-3795` |
| D5 | **Class-wide continuous references** (RA-26 §5(i)/(ii)): (i) optimizer energy and gradient normal/field reference, which today comes from quad corner 0's representative face; (ii) the final-validation field-metric empty-common-chart fallback, which today uses the first endpoint's anchor scope. **Must not assume `selectedFace` ∈ class chart faces** (RA-28b §4). State a cost bound under finite differences and line search. | RA-26 §5; RA-28b §4 | `SurfaceMeshOptimizer.cpp:1482`, `:1958`, `:2675` |
| D6 | **Permutation falsifier** (RA-26 §5(iv)): one produced fixture under a source-face row permutation **and** an output quad corner rotation that changes at least one multi-sheet class's representative face and at least one quad's corner 0. Freeze the equality under which optimized positions, validation metrics and acceptance must be invariant. | RA-26 §5(iv) | — |
| D7 | **A7 selected-edge cross-sheet rule.** (a) Its executed falsifier needs a *produced* seam-collinear fixture (a front edge along an isolation seam); define that fixture via the real tracer, never hand-built records (RA-27a §6). (b) The rule ignores relation kind while sheet IDs are global labels, so under non-default `traverseUnmarkedSharpBends = false` a HardRail across a crease would be falsely rejected (`M6-CP1-TB12-REV-OBS-02`); decide relation-kind-aware semantics. | RA-27a §6, §7 | A7 cross-sheet block (`RemeshPipeline.cpp`, `cross-sheet` / `cross-sheet:wedge` sites) |
| D8 | **CP3 exit evidence plan** (frozen §10 M6-CP3). For each conjunct, freeze the direct-production witness, the identity or selector row, and the gate: coordinate distinctness without a relation; exact-once relation consumption; exact shared support; source-row / output-row / scheduler permutation invariance (may share D6); unchanged `G4-B002` candidate extraction + hard-feature tamper on **direct production**; `G4-B001` strict torus 3/3 re-proof; `G4-B004` representative occurrence → quotient → embedding → **A8 verifier** chain. | frozen §10; `G4-B001/B002/B004` | — |
| D9 | **CB sequencing and gate arithmetic.** Order the Code + Build turns so that D1–D4 and D7 (entry gates) precede any direct-production TB. D5/D6 change optimizer behavior, so pre-register a stop rule for any accepted selector449 row that changes outcome. Name every appended identity and compute the gate from the enumerated list. Decide whether focused-30 + focused-12 fold into a cumulative published selector before CP3. | lesson 188; D5 precedent | — |

**Not owned here (later owners; do not decide):**
- adapter cross-sheet site loss (`M6-CP1-TB12-R1-REV-OBS-02`, M8-CP2);
- the verifier product-copy cost (RA-29d §7, M8-CP2);
- the overlay row-order diagnostic (`M6-CP1-CB12-REV-OBS-01`, M8-CP2);
- S1/S2 hardening (M8-CP2);
- any M7 disposition semantics.

## 3. Method requirements (from lessons 199–205)

1. **Reachability first** (lesson 199). For each D-item, state which producer branch real data reaches and cite its construction. No witness may be hand-built where a producer path exists.
2. **Edge cases in the accepted gate** (lesson 204). Before freezing any new predicate, grep the accepted gate for rows that deliberately exercise the property, and trace the producer's own encoding (for example canonical-orientation inversion, `RemeshPipeline.cpp:4917-4921`).
3. **Per-conjunct falsifiers** (lessons 200, 205). For every new rule, list its conjuncts and name the tamper that defeats each mutant. Name the negative witness that proves detection, not just the green gate.
4. **Bound** (lesson 188). If D1–D9 cannot all be decided in one session, close **IN_PROGRESS** with the completed D-items listed in the record. Do not compress the remainder into unreviewed assertions.

## 4. Deliverables

- `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`, written incrementally in D-item order, with `file:line` citations.
- A normative amendment (RA-30) in `Architecture_M6_Frozen_Definitions.md`.
- The first CP3 Code + Build plan(s), **HELD** until `M6-DEFN-R5-REV`.
- Handoff, ORIENTATION, TODO and ROADMAP updated. Accounting unchanged unless a regression is found.

## 5. Must not change

- A5/A6/A7/A8 semantics as frozen (RA-1 – RA-29d);
- selector449 `d4a0d1b7…`, routing449 `9c88a5ed…`, focused-30 `1e815443…`, focused-12 `2aa57aac…`;
- every source, test and fixture.

## 6. Exit criteria (checked by `M6-DEFN-R5-REV`)

- D1–D9 each decided with reasons and `file:line` evidence, or explicitly carried with an owner if outside CP3.
- Every new predicate has a per-conjunct falsifier design and a reachability argument.
- CB sequencing places all entry gates (D1–D4, D7) before any direct-production TB.
- The gate count is computed from the named identities.
- `G4-B002` stays open (debt 1) until CP3 direct-production evidence is accepted.
