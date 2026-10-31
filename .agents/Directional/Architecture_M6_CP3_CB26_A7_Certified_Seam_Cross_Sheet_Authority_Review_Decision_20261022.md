# RA-131 — CB26 A7 certified cross-sheet independent Review (2026-10-22)

**Turn:** `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV`. **Decision:** accept the four-hunk CB26 source change as a faithful **compile-only** implementation of RA-130.8, and authorize **only** `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION` under RA-130.9. This is not a runtime acceptance, CP3 promotion, or source/test rewrite.

## Independently inspected immutable authority

- CB26 semantic commit `e3d60337ed34538547d3a6d519bafae5b184330e`; exact GitHub commit diff: **two paths only**, `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp`. No changes to A5/A6, A7 per-member, A8, header, selectors, fixture bodies/assertions, build source, or workflow. A GitHub compare to review snapshot `1f6577eaa1aaa6eec8332109205caaafa56333c9` found **no code paths changed** since this source.
- Exact source snapshot run `39754278572`, artifact `12414812318`: ZIP SHA-256 `8ff35f50e7ca3ddf0608bfd3b3c540fff6a57767b2d0578e27125c568cb24447`, `5777/5777` file hashes correct, source tar SHA-256 `06038abad238d45a4b79571565ef8334bfc5222397d9141ece1f46e88c252f77`.
- Compiled package run `39744189868`, artifact `12409939859`: independently verified outer ZIP SHA-256 `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa` and **28/28 internal checksums**. Packaged source is exact `e3d60337ed34538547d3a6d519bafae5b184330e`; linker evidence includes both `libgmpxx.so` and `libgmp.so`, exact-arithmetic backend GMP, `runtimeExecution=false`. Eight prescribed compile targets claimed by immutable package; **no binary was executed during this Review**.

## Independent B1–B6 adjudication

1. **B1 — D7 positive/tamper oracle preserved.** The unchanged `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` test (`tests/SurfaceCellTransitionQuotientTests.cpp`, around 3983–4060) explicitly requires a produced A5 relation, disjoint endpoint sheet sets, selected A6 forest edge, successful untampered A7 geometry, then rejection after clearing all three relation-evidence lists with typed code `UncertifiedCrossSheetBinding` and site exactly `cross-sheet`. The new A7 branch checks those lists and uses that site; its positive outcome is **still unmeasured** on the new source.
2. **B2 — canonical endpoint identity.** New A7 calls `certified_seam_direction` using `relation.id.first`/`second`, not the arbitrary `QuotientForestEdge` order, and binds the matching endpoint spans.
3. **B3 — no redundant predicate.** `certified_seam_wedge_side` already requires the face, sheet and occurrence wedge binding; `certified_seam_direction` enforces opposite seam sides. No second pair/binding check was introduced. The selected direction is computed once.
4. **B4 — certificate-owned transition.** The new predicate checks `region==certificate.region()`, `seam==certificate.seam()` and the certificate's two sheet identities in either orientation, in the relation's first-side, second-side or equivalence transition evidence. A merely same-sheet-set transition from another region/seam cannot satisfy it. The three-list OR is intentional and its complete clearing is independently falsifiable by D7.
5. **B5 — diagnostic distinction.** Missing certified direction yields `cross-sheet:seam-direction`; missing matching certificate transition yields `cross-sheet`; uncertified OrdinaryFront keeps its predicate but reports `cross-sheet:no-certificate`; Periodic keeps its predicate but reports `cross-sheet:periodic`. The shared error mapping adds the nonempty site suffix; the D3 fixture helper now records code and site without modifying an assertion.
6. **B6 — Periodic remains latent.** Its preexisting cross-sheet predicate is unchanged. No periodic positive or failure is inferred from the new labels. An observed `cross-sheet:periodic` must stop TB27 and return to Review.

**Changed-surface check:** commit shows the A7 forest case, the A7 error-to-message mapping, and one TQ helper diagnostic, with no unrelated hunks. All touched lines are at most 100 columns. The guard did not weaken HardRail, same-region, shared-sheet, per-member wedge connectivity, source support or A8. Cross-sheet semantics are not certified at runtime merely because the static branch is reachable.

## Frozen successor — M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION

- **Type:** immutable artifact-only Test + Benchmark. Execute exactly the **18 TB26 selections** (same test identities and controls, including `cp3entry:3/5`) **plus** these three exact A7 guards: `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`, `M6CP2.A7WedgeTransitionWrongRegionRejects`, `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`. No selector-497 edit, no source/test/fixture/compile/relink change; consume artifact `12409939859` and semantic SHA `e3d60337ed34538547d3a6d519bafae5b184330e`.
- **Positive gate:** independently capture each selected test name, one RUN and one terminal verdict, A7 site/code where applicable, and immutable package pre/post hashes. Do not claim end-to-end PASS from only passing the former A7 gate.
- **Falsifiers/stop rules:** any of the eight target rows still at `cross-sheet:seam-direction`; D7 evidence tamper passes or its rejection site differs from `cross-sheet`; D3 quarter-turn gauge tamper passes; any of the six TB26 controls or the three new site guards turns RED; a `cross-sheet:periodic` event occurs; a test is skipped/missing; a source/package digest or no-rebuild/no-runtime-boundary condition fails. An emerging different first failure is evidence to preserve, not automatically a falsifier.
- **Gate:** TB27 reports the actual outcomes, then independent TB27-REV decides any acceptance or corrective work. CB27 negative-test work remains unassigned until that Review. CP2 491/491 remains the last accepted runtime; CP3 selector 497, stable 66/17/49, debt 1, TB21 candidate 449/497, RP-01 open, RP-02 unreached and Gate C suspended are unchanged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — review changes no selector or runtime acceptance; byte-frozen selector files remain unchanged in exact source snapshot, and commit/compare have no selector path changes. |
| Decisive claims independently re-derived | CB26 2-path commit diff; B1–B6 against actual RP helper, A7 branches, TQ D7 oracle, exact source archive and compile package. |
| Non-vacuity checked | D7 positive requires actual produced disjoint-sheet A5/A6/A7 witness; tamper clears all three collections. D3 rotates gauge; both results require TB27 measurement. |
| Prior obligations discharged/carried | RA-130 B1–B5 statically implemented; B6 periodic latent. D3/D7 runtime falsifiers and three guards carried to TB27. RA-127.4b/unrelated-seam/no-direction negatives remain conditional CB27. |
| Stable accounting | CP2 491/491 accepted; candidate TB21 449/497; 66/17/49, debt 1; no promotion. |
| New candidates/obligations recorded | No new runtime regression; TB27 named with B6 stop and D3/D7 oracles; tracker unchanged except review transition. |
| ORIENTATION currency line | Updated to RA-131 / next TB27. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for compile-only review; §4 no witness state change; §8 no new defect pattern. |
| CHANGELOG | One RA-131 entry prepended. |
| ROADMAP | Inspected; M6-CP3 still active, M7/M8 planned; no milestone transition. Updated checked date. |
| Selector manifest | n/a — frozen selector unchanged. |
| LESSONS | Existing **Compile, runtime, and acceptance are independent evidence** and **A negative must reach the intended guard** remain applicable; no new generalizable lesson. |
| Consolidation under CLEAN_UP_POLICY | No completed current-authority or otherwise safely foldable family record identified; retained RA-130 and CB26 records. No silent deletions. |
| Successor frozen | `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION`; falsifiers above. |
| Turn boundary held | Static review only; no binaries, compiles, tests, benchmarks, source/test/selector edits. |
| review_check.py boundary | Exact helper requires historical `.git` objects absent from Action snapshot. Run attempted; its historical baseline and commit ancestry checks cannot be proven with a git-less archive. GitHub commit/compare and complete hashed snapshot independently confirm unchanged code and selectors. |
| `STATUS` lifecycle maintained | New-turn bootstrap on 2026-10-22; final direct beacon after documentation commit. |
| Pushed to origin, branch in sync | Verified PR #8 remote HEAD `f199852100bd2ceae10d9c0831189de464cf79a2` after verified patch pushes and cleanup; GitHub compare from `e3d60337` lists only documents/control state. A local `git status -sb` cannot be asserted because the downloaded snapshot has no Git history; remote HEAD and workflow push results were independently checked. |
