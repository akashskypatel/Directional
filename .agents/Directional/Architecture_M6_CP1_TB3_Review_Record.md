# M6-CP1-TB3 Independent Review Record

**Turn:** `M6-CP1-TB3-REV`
**Type:** mandatory runtime-free independent Review
**Disposition:** **COMPLETE / TB3 MECHANICS UPHELD / ONE NEW STABLE ACCEPTED-PREFIX RP-01 EVENT / HARDRAIL RECOVERY PROVED / MULTI-ISOLATION RELATION-OWNER GAP LOCALIZED / CANDIDATE UNPROMOTED**
**Candidate:** artifact/source `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**TB3 runtime:** run/job `36084948588 / 107914657100`, result/log `10844285398 / 10844020833`
**Accepted predecessor:** artifact/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Exact successor:** `M6-CP1-CB4`

## 1. Independent evidence re-opened

Review re-opened the immutable CB3 candidate, TB3 result evidence, the accepted M5 TB2 result, selector449/routing449 bytes, current frozen M6 definitions, and exact current source instead of accepting the EXEC report as proof.

Candidate artifact `10840014758` re-verifies at provider/download SHA-256 `b1117c6efe2cdc8a04e46647fd1bb5af79094234a03348df8ffd6e6ae5ed5c66`; its root manifest is **28/28**, semantic source is `660015f2f15359fd426e2c855aea9f4201c70216`, packaged source archive SHA-256 is `90c6305132ceca1bcd5f12dfd03a7a3b818fe3e9462128dedb5c3f5788f67ecc`, GMP/GMPXX authority is present, build/preflight receipts are zero, source receipts are clean, and the package records `runtimeExecution=false`.

TB3 result `10844285398` independently verifies **929/929** files. Its ledger contains exactly **455** planned processes: six focused identities followed by selector449 in exact order. Totals are focused **4/6 PASS**, selector449 **443/449 PASS**, aggregate **447/455 PASS**; every process selected exactly one test, none skipped, benchmark count is zero, no build/configure/relink/discovery/repair occurred, and package/source/execution-view postflight is byte-exact.

Selector449 remains exactly 449 LF rows at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Freshly reopened accepted M5 result `10815911956` verifies **911/911** evidence files and **449/449 PASS** with exact-one selection and zero skips. Its ordinals 186, 214, 239, 444, 446 and 448 are all PASS, so the six TB3 selector losses are accepted-prefix PASS -> RED transitions.

GitHub compare proves semantic source `660015f2...` is an ancestor of the Review snapshot and that source..Review changes touch only documents/control-plane files: no `src/`, `include/`, `tests/`, `benchmarks/`, CMake or `cmake/` byte drift exists. Static review of the snapshot is therefore evidence about the tested semantic source.

## 2. TB3 mechanics are upheld and the common RED family is non-vacuous

The eight RED processes are organic semantic outcomes from a mechanically valid immutable gate. Focused rows5/6 and selector ordinals **186, 214, 239, 444, 446, 448** all fail first at `MissingIsolationSeamEquivalenceAuthority`. No process reports `OccurrenceInvalidCornerAuthority`. Selector ordinal140 `HardRailPairExplicitRailIdMismatchRejectsStrictTransport` PASSes the unchanged accepted negative, proving CB3 restored its specific `InvalidHardRailTransport` contract.

The common family is not a vacuous assertion change. Accepted row186 independently constructs one checked isolation-seam certificate with distinct sheets and reciprocal transport before materialization; accepted row239 establishes the same cross-sheet source-adjacent condition; the three produced-torus rows were accepted green on the M5 producer authority; focused pair-swap was also PASS at TB2. TB3 reaches the new relation-equivalence guard before those tests' former downstream assertions. Deleting that guard would change the observed outcome, so the mechanism is active rather than report-only.

## 3. Root cause: A5 omits relation-owned isolation-equivalence authority and A6 reconstructs it from representation paths

The frozen A5 contract already requires every `ownedRelations[]` entry to carry a **typed relation owner / certificate reference**; A6 may consume only that published authority and may not search for or synthesize a missing relation. A7 permits a multi-sheet quotient only when A5/A6 relation certificates explicitly establish the equivalence.

Current implementation does not realize that contract for an ordinary cross-sheet relation:

1. CB3 correctly assigns each A5 occurrence's sheet from the start of its authoritative outgoing directed side, while requiring the side-attached representation and canonical corner to resolve the same exact `SourceSupport`.
2. `SurfaceOccurrenceRelation` stores semantic endpoints plus `firstFrontEdge/secondFrontEdge`, explicitly labeled representation projection only. `OrdinaryFront` publishes no isolation-seam certificate reference.
3. The transitional materializer separately scans each owning cell side's boundary-path `entryRoute` into `isolationSeamsByFrontEdge`.
4. For an ordinary reciprocal front pair it unions those front-edge-derived seam lists, then compares the **A5 occurrence endpoint sheets**. If an endpoint pair spans sheets while the reconstructed list is empty, it returns `MissingIsolationSeamEquivalenceAuthority` before quotient union.
5. Final lineage itself is sound with respect to this boundary: `sourceIsolationSheets` is the sorted set of actual quotient-member `occurrence.isolationSheet` values. The failure occurs before the relation can legitimately form that quotient.

This is an authority-domain defect, not a reason to restore CB3's rejected global-certificate augmentation. The semantic datum is **which exact checked isolation certificate owns this cross-sheet occurrence relation**. Current code tries to rediscover that ownership later from front-edge/boundary-path representation traversal. A representation path can be valid while not traversing the seam that explains the relation endpoint sheet change; certificate inventory can also contain valid but unrelated seams. Neither is the A5 relation-owned reference required by the frozen contract.

**Classification:** `M6-CP1-TB3-EXEC-CAND-01` becomes **one stable event / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence**. Six accepted selector identities transition PASS -> RED at one common first-failure mechanism; the two focused losses localize the same mechanism and do not add stable events. Stable accounting advances **53 -> 54 events / 16 categories / 37 -> 38 recurrences**. Produced-witness debt remains **1**, M6-owned.

## 4. Prior-candidate dispositions

- **`M6-CP1-TB2-REV-CAND-01` (`VALIDATION_ORDER_SHADOWING`) — CLOSED / RECOVERY PROVED.** Row140 is fresh PASS with the established `InvalidHardRailTransport` outcome. Its historical stable event remains counted; recovery never subtracts an event.
- **`M6-CP1-TB2-REV-CAND-02` (focused multi-isolation) — MERGED INTO TB3 CAND-01 / STILL OPEN.** CB3 made the intended distinct-sheet occurrence authority visible, but the witness now stops earlier at the missing A5 relation-owned isolation certificate. The original downstream `foundMultiIsolationLineage=false` is superseded as first failure, not disproved as a closure obligation.
- **`M6-CP1-TB1-EXEC-CAND-01` (`CROSS_TEMPORARY_ITERATOR_RANGE`) — MECHANISM CLEARED / FORMAL RECOVERY STILL OPEN.** `OccurrenceInvalidCornerAuthority` remains absent, but the frozen recovery rule also requires a fresh selector449 **449/449**. TB3 is 443/449, so Review does not rewrite that pre-registration.

Accepted runtime authority therefore remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**. Candidate `10840014758` remains unpromoted and grants no CP1/G4 closure.

## 5. Bounded successor

Exact successor is runtime-free Code + Build **`M6-CP1-CB4`**. It owns one semantic correction only: implement the already-frozen A5 relation-owned isolation-equivalence reference for ordinary relations whose occurrence endpoints span isolation sheets, and make the transitional A6/materializer consume that published reference instead of deriving semantic owner authority from front-edge boundary-path traversal.

CB4 must not change occurrence identity, outgoing-side sheet authority, source support, quotient equality, tests, fixtures, selector449/routing449, periodic/HardRail owner semantics, or revive certificate-inventory substitution. If the exact isolation certificate cannot be derived uniquely from already-accepted A4/M5 typed authority for the relation without inventing a new semantic rule or changing the frozen A5 contract, CB4 stops and returns to Review/Definition.

If compile/package is green, the exact runtime successor is `M6-CP1-TB4-EXEC`: unchanged six focused + selector449 = **455** fresh exact-filter processes, followed by mandatory `M6-CP1-TB4-REV`. Recovery-green requires 6/6 focused, 449/449 selector, row140 still PASS, no `OccurrenceInvalidCornerAuthority`, all six TB3 selector losses recovered, multi-isolation lineage spanning >1 sheet with relation evidence, pair-swap PASS, exact-one/zero-skip, benchmark 0 and immutable postflight.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; accepted result `10815911956` independently re-opened at 449/449 |
| Decisive claims independently re-derived | candidate 28/28; TB3 result 929/929 and 455-process ledger; accepted 449/449 differential; no code drift from semantic source; A5 relation shape, materializer seam reconstruction/guard, and quotient-lineage sheet derivation |
| Non-vacuity checked | row186 proves a real checked distinct-sheet certificate before the failing call; accepted torus rows and TB2 pair-swap provide prior green controls; all eight TB3 REDs reach the active `MissingIsolationSeamEquivalenceAuthority` guard |
| Prior obligations discharged/carried | TB2 row140 stable event recovery-proved closed; TB2 focused multi-isolation merged into active TB3 RP-01 event; TB1 iterator mechanism cleared but formal 449/449 recovery clause carried |
| Stable accounting | **54 / 16 / 38**, debt **1**; accepted package/source `10814505512 / e284fea7...`, selector449 449/449 |
| New candidates/obligations recorded | `M6-CP1-TB3-EXEC-CAND-01` adjudicated stable existing-RP-01 recurrence; tracker updated; CB4/TB4 recovery obligation frozen |
| ORIENTATION currency line | `M6-CP1-TB3-REV`, 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 updated; §4 n/a because accepted witness state did not change |
| CHANGELOG | root and Directional changelogs updated newest-first |
| ROADMAP | M6-CP1 updated to TB3 Review / CB4 next |
| Selector manifest | n/a — no selector was added, changed, published or accepted |
| LESSONS | existing single-authority/representation lessons 22 and 30 cited; no genuinely new lesson added |
| Consolidation under CLEAN_UP_POLICY | CB3 plan/report, TB2 report/Review and consumed TB3 plan folded into `M6_Consolidated_Record.md` and removed; retained TB3 runtime report, this Review, frozen definitions, consolidated record and one CB4 plan |
| Successor frozen | exactly `M6-CP1-CB4`; falsifier and stop rule are in §5 and the CB4 plan |
| Turn boundary held | runtime-free Review; no Directional compile/runtime and no product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | **PASS** — all boundary, selector-hash and durable-marker checks passed on the complete Review diff |
| `STATUS` lifecycle maintained | entry beacon `M6-CP1-TB3-REV / IN_PROGRESS` published; final COMPLETE beacon is reserved as the final repository write with exact successor `M6-CP1-CB4` |
| Pushed to origin, branch in sync | **CONFIRMED by configured-branch patch application/cleanup authority checks; no alternate ref used.** Final `STATUS` write follows only after cleanup verification. |
