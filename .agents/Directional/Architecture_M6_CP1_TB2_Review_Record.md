# M6-CP1-TB2 Independent Review Record

**Turn:** `M6-CP1-TB2-REV`
**Type:** mandatory runtime-free independent Review
**Disposition:** **COMPLETE / TB2 MECHANICS UPHELD / CB2 ITERATOR SYMPTOM CLEARED BUT FROZEN RECOVERY NOT CLOSED / ONE NEW STABLE ACCEPTED-PREFIX EVENT / ONE NON-STABLE FOCUSED MECHANISM FAILURE / CANDIDATE UNPROMOTED**
**Candidate:** artifact/source `10834642074 / 724316a5b3f49e33dc8e649989bb413b3dc6b7c9`
**TB2 runtime:** run/job `36063687138 / 107848407035`, result/log `10835579933 / 10836175636`
**Accepted predecessor:** artifact/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Exact successor:** `M6-CP1-CB3`

## 1. Independent evidence re-opened

Review re-opened the immutable candidate, TB2 result/log evidence, accepted M5 predecessor, packaged source, frozen M6 definitions, accepted selector449/routing449, and the TB1 recovery pre-registration rather than accepting the EXEC report as self-proving.

Candidate `10834642074` re-verifies at ZIP SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`; root `SHA256SUMS` is **28/28** at SHA-256 `a0fffc173149d1917ed6ab6a7dbb3c70335dee0b0e4ecb6ce652438d02037c9e`; packaged source is exact semantic source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` with archive SHA-256 `eaf577ccdc534c2e9e48b8b8fed31079849b268c4a6c1b47b0f253ff3ad6034b`. GMP/GMPXX evidence is present and the originating package records `runtimeExecution=false`.

TB2 result `10835579933` re-verifies its recursive self-manifest **933/933**. The ledger contains exactly **455** ordered exact-filter processes: six frozen focused identities then all 449 accepted selector identities. Mechanical totals are focused **5/6 PASS**, selector449 **448/449 PASS**, aggregate **453/455 PASS**, exact-one selection, zero skips, zero crashes, zero selection mismatches, benchmark 0, and no build/configure/relink activity. Postflight package/source/execution-view censuses and selector/routing/source bytes are unchanged.

Accepted selector authority is byte-identical: selector449 remains SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Accepted predecessor `10814505512 / e284fea7...` is the same M5 authority that passed all 449 rows.

## 2. TB2 mechanics are upheld

The two REDs are organic semantic outcomes from a mechanically valid immutable gate:

1. focused row5 `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — `SurfaceCellTransitionQuotientTests.cpp:2641`, `foundMultiIsolationLineage=false`;
2. selector449 ordinal140 `SurfaceCellAuthorityContractCutover.HardRailPairExplicitRailIdMismatchRejectsStrictTransport` — `SurfaceCellsPhase10Tests.cpp:6865`, expected `InvalidHardRailTransport`, actual `OccurrenceUnownedRelation`.

All other planned rows PASS. No evidence supports timeout, selection, packaging, fixture mutation, or orchestration as the cause. No rerun is authorized or required.

## 3. TB1 iterator-range event: mechanism cleared, formal recovery still open

The CB2 correction does what its diagnosis predicted: `OccurrenceInvalidCornerAuthority` is absent from **all 455** TB2 processes, the by-value split-range scan remains clean, and the retained pair-swap identity now PASSes. This is strong runtime evidence that the `CROSS_TEMPORARY_ITERATOR_RANGE` mechanism was removed.

The frozen TB2 recovery rule is conjunctive, however: CAND-01 closes only if (a) no process reports `OccurrenceInvalidCornerAuthority` **and** (b) selector449 is **449/449 PASS**. TB2 is 448/449. Review therefore does **not** rewrite the pre-registration after seeing a different RED: `M6-CP1-TB1-EXEC-CAND-01` remains formally open until a fresh selector449 gate is fully green. Its original symptom is cleared; its frozen recovery condition is not yet satisfied.

## 4. Selector row140: new stable `VALIDATION_ORDER_SHADOWING` event

Row140 is a valid accepted-prefix regression, not a malformed fixture or stale expectation.

The unchanged negative creates a reciprocal HardRail pair whose two explicit `HardRailId` values differ and has historically required the materializer to fail with `InvalidHardRailTransport`. The candidate still contains that established downstream strict-transport check. New A5 publication now runs first: when both HardRail endpoints carry different rail IDs, `SurfaceOccurrenceComplexProducer::produce` returns `SurfaceOccurrenceComplexErrorCode::UnownedRelation`; the adapter maps this to `OccurrenceUnownedRelation`, so the pre-existing `InvalidHardRailTransport` guard is never reached.

Both validations reject the tampered relation, so this is not an acceptance-versus-rejection correctness inversion. It is nevertheless a real compatibility regression in the accepted fail-closed contract: the newly earlier generic ownership guard shadows the established, more specific HardRail transport rejection. `LESSONS.md` §4 lesson 22f already names this defect pattern: when an earlier guard silently shadows the guard a negative test targets, restore the shadowed validation precedence rather than weakening the test.

**Classification:** `M6-CP1-TB2-REV-CAND-01` becomes one stable accepted-prefix event in new singleton category **`VALIDATION_ORDER_SHADOWING`**. Stable totals become **53 events / 16 categories / 37 recurrences**. The test remains authoritative and must not be broadened to accept either failure string.

**Recovery falsifier:** a bounded correction must preserve A5's fail-closed relation ownership while restoring the established specific `InvalidHardRailTransport` result for the explicit mismatched-HardRail case. It must not make the relation valid, bypass A5 ownership, duplicate independent semantic authorities, or weaken selector row140.

## 5. Focused multi-isolation RED: valid CP1 mechanism failure, non-stable

The focused row5 failure is also real, but it does **not** satisfy the stable-event criterion because this focused identity had never been accepted green and is not part of selector449. Historical M5 records explicitly left it ungated for M6 mechanism work.

The same `split_isolation_fixture()` does prove that the producer publishes one checked cross-sheet isolation-seam certificate: accepted selector449 row186 `ReciprocalIsolationSeamCertificateMaterializes` remains PASS and verifies distinct certificate sheets. That older test is not sufficient proof of quotient-lineage consumption, because `build_authoritative_phase_front_mesh` sets `consumedInternalIsolationSeams = isolationCertificateBySeam.size()`; it counts available checked certificates, not actual quotient relation consumption. The M6 focused identity is deliberately stronger: it requires at least one output lineage whose `sourceIsolationSheets` contains more than one sheet and whose equivalence evidence is non-empty. TB2 produces no such lineage.

Static source confirms that final lineage sheets are the set of `occurrence.isolationSheet` values in each quotient class, while A5 assigns each occurrence one sheet from its corner projection/source face. The existing A5 relation endpoint pairs are then the sole union authority. Review can therefore bound the failure to the **A5 occurrence-sheet -> relation endpoint -> quotient class -> lineage propagation path**, but the current evidence does not prove which step first loses the intended two-sheet distinction, nor does it prove CB1 introduced the behavior. No common cause with row140 is assumed.

**Classification:** `M6-CP1-TB2-REV-CAND-02` is a **non-stable focused CP1 mechanism failure**, +0 event / +0 category / +0 recurrence. It blocks CP1 acceptance and remains owned by `M6-CP1-CB3`.

**Recovery falsifier:** trace the exact split-isolation occurrence sheets and relation endpoint unions statically, identify the first authority-preserving step that fails to carry both sheets into one legitimate quotient class, and correct only that production locus. The correction must preserve exact source support, relation-only equality, and the rule that geometric/lattice coincidence cannot weld occurrences. The certificate-count diagnostic may not be used as a substitute for lineage proof. If satisfying the focused identity would require redefining frozen A5 occurrence-sheet semantics or inventing a new authority rather than repairing an implementation gap, CB3 must stop and return to Review/Definition.

## 6. Accounting, authority, and successor

Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**. Candidate `10834642074` remains unpromoted. Produced-witness debt remains **1**, M6-owned. Stable accounting after this Review is **53 events / 16 categories / 37 recurrences**.

The exact successor is bounded runtime-free Code + Build **`M6-CP1-CB3`**. It owns two and only two semantic recovery surfaces: (1) restore accepted HardRail failure precedence without weakening A5 fail-closed authority; and (2) recover the retained multi-isolation quotient-lineage mechanism at the first proved authority-loss locus. No A6/A7 extraction, selector publication, test weakening, fixture substitution, benchmark semantic work, or unrelated cleanup is authorized. If compile/package is green, exact successor is fresh `M6-CP1-TB3-EXEC`, then mandatory `M6-CP1-TB3-REV`.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; accepted predecessor remains 449/449 |
| Decisive claims independently re-derived | candidate 28/28; TB2 result 933/933 and 455-row ledger; row140 A5-vs-materializer call order; split-isolation certificate-versus-lineage distinction; stable/non-stable pricing |
| Non-vacuity checked | row140 changed an accepted 449/449 identity and reaches a different earlier typed rejection; focused row5 reaches successful materialization then fails the retained multi-sheet-lineage assertion |
| Prior obligations discharged/carried | TB1 CAND-01 mechanism symptom cleared but frozen 449/449 recovery clause carried; pair-swap risk discharged by PASS; row140 and focused multi-isolation carried to CB3 |
| Stable accounting | **53 / 16 / 37**, debt **1**; accepted package/source `10814505512 / e284fea7...`, selector449 449/449 |
| New candidates/obligations recorded | `M6-CP1-TB2-REV-CAND-01` stable `VALIDATION_ORDER_SHADOWING`; `M6-CP1-TB2-REV-CAND-02` focused non-stable; tracker updated |
| ORIENTATION currency line | `M6-CP1-TB2-REV`, 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 witness table unchanged because no milestone witness acceptance state changed |
| CHANGELOG | root and Directional changelogs updated newest-first |
| ROADMAP | M6-CP1 state updated to TB2 Review / CB3 next |
| Selector manifest | n/a — no selector was added, published, or accepted |
| LESSONS | existing §4 lesson 22f cited; no genuinely new lesson added |
| Consolidation under CLEAN_UP_POLICY | superseded CB2 plan/report, TB1 report/Review, and consumed TB2 plan folded into `M6_Consolidated_Record.md` and removed; retained current TB2 report, this Review, frozen definitions, consolidated record, and one CB3 plan |
| Successor frozen | exactly `M6-CP1-CB3`; falsifiers are stated in this record §4-§6 and the CB3 plan |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation, compile, or Directional runtime |
| review_check.py boundary | **PASS** — all review-boundary, selector-hash, and durable-marker checks passed |
| `STATUS` lifecycle maintained | entry beacon published as `M6-CP1-TB2-REV / IN_PROGRESS`; final COMPLETE beacon is the final repository write |
| Pushed to origin, branch in sync | **CONFIRMED** — documentation landed in `2affe1b11f92d12861aea582ddf7b15e4eeb3819`; cleanup run/job `36069409010 / 107866594452` removed both Review markers plus the cleanup manifest in `598f97652260c2e4460682478a485b3af82c72ab`; exact seven durable workflows remain; no alternate ref is used |

## Post-closeout continuation correction

A later `@cont.txt` continuation failed to re-list the completed turn's Actions history before arming orchestration, contrary to the existing resumed-turn reconciliation lesson. It therefore reinstalled the already-consumed Review documentation caller and triggered duplicate run `36071205165`. The durable Drive reusable failed closed before patch application because the Review documentation paths had changed since base `6a1c3a53e1cc9ece9c0dd08e2630da60fceca645`; no source, test, fixture, selector, benchmark, or durable Review-document patch was applied, and the run records `runtimeExecution=false`.

The duplicate Drive staging file was owner-deleted, the duplicate caller was retired in `069493e25a0a2ee7b39f41cb239ed88e4e2a59a0`, and cleanup run `36071574167` removed the duplicate marker and cleanup manifest in `c4b34011222bb578d29127d40b7c26c310eb5695`. This is a process-only correction with **+0 event / +0 category / +0 recurrence**. The Review verdict, accepted authority, stable accounting **53 / 16 / 37**, debt **1**, and exact successor `M6-CP1-CB3` are unchanged.
