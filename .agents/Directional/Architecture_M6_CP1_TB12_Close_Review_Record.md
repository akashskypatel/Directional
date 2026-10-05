# `M6-CP1-TB12-CLOSE-REV` — Independent Review Record

**Type:** Review only; runtime-free.
**Date:** 2026-10-05.
**Reviewed candidate:** `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
**TB12 runtime:** `37266239234 / 111623615471`; result/log `11326949864 / 11328055226`.
**Disposition:** **REJECT FOR TEST-AUTHORITY RECOVERY**. The production C1 implementation is statically consistent with RA-25/CB12, but identity29 is a false rejection because its chosen fixture does not establish the selected-cross-sheet witness that the test assumes. Candidate remains unpromoted.

## 1. Independent evidence re-derivation

The Review used exact source snapshot `37271313511 / 11328074296` at source/event SHA `08f53f78fd1039f16c026322622516c626ccfe70`; snapshot manifest verifies **5386/5386** files. No Directional runtime was executed in Review.

TB12 evidence independently re-checks as:
- exact immutable candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`;
- focused30 **29/30**, selector449 **449/449**, aggregate **478/479**;
- exactly **479** fresh exact-filter processes, exact-one selection, zero skips, benchmark 0;
- result self-manifest **979/979** and immutable postflight;
- sole RED focused ordinal29 `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`; ordinal30 and all prior focused identities are green.

Ordinal29 fails at the pre-tamper assertion `crossSheetEdge != nullptr`; raw evidence says: `split-isolation witness must exercise a selected cross-sheet join`. No transition is rewritten before failure.

## 2. CAND-01 adjudication

### Finding F1 — identity29 assumes a selected-forest witness that the fixture contract does not provide

CB12 C1 is explicitly scoped to a **selected-forest edge** whose endpoint `cornerWedgeSheets` are disjoint. The production code now checks that such an edge has at least one `CornerWedgeIsolationTransition` connecting one endpoint sheet set to the other through `fromSheet/toSheet`; otherwise it returns `UncertifiedCrossSheetBinding` at site `cross-sheet`. Static Review confirms that exact predicate.

Identity29 uses `split_isolation_fixture()`, builds ordinary A5/A6 products, then scans `a6->selected_forest()` for a disjoint-sheet edge and asserts one exists. TB12 proves that assertion false for this fixture. The failure occurs before the C1 tamper and therefore says nothing about the exact production predicate.

A6's selected forest is a deterministic spanning forest constructed by union-find over the sorted owned relations. The frozen contract requires a valid deterministic spanning forest; it does **not** require every valid split-isolation fixture to select a cross-sheet relation rather than leave that relation cycle-closing. Therefore absence of a selected cross-sheet edge in this fixture is not a production-selection defect.

### Finding F2 — production C1 is not disproved, but its new falsifier remains runtime-unproved

The baseline split-isolation A7 product succeeds. Static source matches the required C1 endpoint-sheet connectivity predicate. However, because identity29 never reaches its tamper, the candidate does not yet have runtime evidence that unrelated `fromSheet/toSheet` values are rejected. Review therefore does **not** promote the candidate and does **not** claim C1 runtime closure.

### Candidate disposition

`M6-CP1-TB12-CLOSE-EXEC-CAND-01` is adjudicated **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**. This is not a stable event because no accepted-green selector/focused row regressed and no production defect is established. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

## 3. RA-27 recovery rule

Recovery is test-authority only. Identity29 must use a deterministic **valid production-derived A6 product** that contains at least one selected-forest edge with disjoint endpoint sheet sets. The witness may be constructed test-side from a valid A5 publication seam, but A6 must be created by `SurfaceQuotientProducer::produce`; do not forge an impossible quotient product or bypass A6 validation.

The recovered identity must prove all of the following in one test:
1. non-vacuity: locate and assert a selected-forest edge with disjoint endpoint sheet sets;
2. positive control: baseline A7 accepts that exact witness;
3. negative discriminator: rewrite all relevant relation/endpoint isolation transitions for that edge to sheet IDs that connect neither endpoint set;
4. exact failure: A7 returns `UncertifiedCrossSheetBinding` at site `cross-sheet`;
5. no weakening: do not replace the selected-forest predicate with “any relation”, do not weaken endpoint-sheet membership, and do not change C1 production semantics.

If constructing such a valid A6 witness requires a production semantic change, **STOP for Review**.

## 4. Recovery routing

Exact next is runtime-free Code + Build **`M6-CP1-CB12-CLOSE-R2`**. It is test-only except for documentation and may change only `tests/SurfaceCellTransitionQuotientTests.cpp` plus focused-authority documentation if strictly needed. The focused identity name/order remains unchanged; selector449/routing449 and production source remain byte-identical.

Compile-green R2 routes to immutable **`M6-CP1-TB12-CLOSE-R1-EXEC`**, unchanged focused30 + selector449 = **479** fresh exact-filter processes, followed by mandatory **`M6-CP1-TB12-CLOSE-R1-REV`**. Only that Review may promote a recovered candidate and release `M6-CP1-CLOSE-REV`.

## 5. Review closeout

| Duty | Result |
|---|---|
| TB12 evidence | PASS mechanically; 478/479 semantic |
| Identity29 root cause | FALSE REJECTION / fixture witness assumption |
| Production C1 | statically consistent; runtime falsifier not yet proved |
| Candidate promotion | NO |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime in Review | none |
| Exact successor | `M6-CP1-CB12-CLOSE-R2` |
