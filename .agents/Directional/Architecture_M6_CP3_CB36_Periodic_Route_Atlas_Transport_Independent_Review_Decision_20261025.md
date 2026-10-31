# CB36 periodic route atlas transport — independent static Review (2026-10-25)

**Turn:** `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT-REV`. **Decision: ACCEPTED FOR FOCUSED TB37 ONLY.** No runtime acceptance, production success or selector promotion is claimed. Semantic source `038ae7fd7c290731c28225d2693a3e13866e325a`; exact reviewed source from verified snapshot `9f691d975f53af467a45cdbeaa3abdb4d89e5d6f` matched packaged `SurfaceCellTracing.cpp` byte-for-byte (SHA-256 `1635a47149341fd672febb4c7cfdbf1fd5208cbfd8e437e43ed6406b511bc83c`). The source-snapshot ZIP SHA-256 is `46b3a5dde27be31444165627e2a27fae133d3b503794c72e6df7a9b04e259d72`, 5,873/5,873 source entries re-hashed. Source read is static only.

## Source-change audit and falsifiers

1. GitHub's exact semantic-commit patch and base comparison show only `src/geometry/SurfaceCellTracing.cpp` (+20/−5) in the semantic commit; the base-to-semantic comparison additionally contains a dispatcher request control-plane update, not a second product change. No product/test/selector/workflow/build-file change. `STATUS` and snapshot-trigger mutations are later control-plane commits.
2. At `SurfaceCellTracing.cpp:14937–14999`, the **first** branch is `if (transitionLookup.atlas != nullptr)`, retrieving `atlas->transport(*sharedKey, faceCycle[index], faceCycle[(index+1U)%faceCycle.size()])` and using `directed->transport` in `GridAutomorphism` for `TransitionStep::interior`. The established ordered cycle and zero translation remain unchanged.
3. If `transport()` returns no directed value, the branch rejects with `PeriodicHolonomyMismatch` and the six-locus convention `(-1, -1, sourceFace, targetFace, -1, sourceEdge)`. This is a **static-only** falsifier: RA-153.3 says the preceding strip BFS already requires those transports; no unreachable public negative test is invented.
4. Legacy `hasTransitions` and `edgeMatching` branches preserve their previous matching selection, direction inversion and `QuarterTurn::from_integer` conversion, now assigned at the end of each branch. The null-atlas/no-matching path still defaults to identity. The route guard, action, cut, BFS, overload and factory are outside the patch.
5. `FieldTransportAtlas::transport` (`src/authority/FieldTransportAtlas.cpp:3081–3087`) reads **traversable adjacency** and returns the directed transport. Atlas build (`:2033–2063`) keeps the same raw forward/reverse quarter-turn values in transition records but rejects hard-feature/cross-region traversal in adjacency; this agrees with the existing strip BFS. Branch propagation (`SurfaceCellTracing.cpp:6718–6730`) already reads the same accessor. No new numerical tolerance or fallback was introduced.

**Remaining uncertainty:** a static review cannot prove the intended k=1/k=2 rejection, directed odd-step runtime, or preservation of historical PASS or RED results. The hidden factory sub-site from TB36 remains unmeasured. These are TB37 discriminators, not claims of this review. RA-153.3's homology/sufficiency assumption was not re-proved by an independent topological theorem here; its scope is unchanged and TB37 may falsify behavior.

## Independently verified immutable compile evidence

[GitHub Actions run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), result artifact `12590917524`: provider ZIP SHA-256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; re-hashed all **28/28** packaged entries; `metadata/source-commit.txt` is `038ae7fd7c290731c28225d2693a3e13866e325a`. Preflight and compile exits are 0; five source-status receipts empty; `compiled-targets.txt` contains exactly the eight approved targets. `CMakeCache.txt` has `DIRECTIONAL_ENABLE_GMP:BOOL=ON`; generated executable link evidence contains both `libgmpxx.so` and `libgmp.so`; command boundary declares `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No binary, test, benchmark or generated runtime was executed in this Review.

The current 449-row accepted-selector source file re-hashes to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` (unchanged accepted prefix). The 497-case CP3 selection remains frozen/unpromoted. Candidate totals and stable accounting do not change: **66 events / 17 categories / 49 recurrences**, debt **1**; CP2 **491/491** accepted; TB32 **481/500** candidate; TB35 **11/13**; TB36-R1 **0/5** pre-fix. RP-01 open, RP-02 unreached.

## Exactly one authorized successor and stops

`M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` is artifact-only, 16 **unique** fresh-process cases using the exact compiled CB36 package. Pre-registered source is [Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv](Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv), SHA-256 `d14b24d96c66c6a2c346b60003a5697dfab1764109b45854a3f145bba70b667d`: 3 TB36 witnesses and the original 13 TB35 tests. Predicted k1/k2 GREEN (reason 29, locations −1), published route GREEN with odd/inverse steps, 189/190/193–195, gauge oracle, two A3 guards and three TB33 factory controls PASS, frozen 191/192 remain RED/Produced/None. STOP and route to independent Review if either monodromy remains reason 68 (first request test-side `publishedProductError`/site diagnostic), if 191/192 changes, or if any previous TB35 PASS regresses. Missing, duplicate, skipped, crashed or zero-selected process is orchestration failure, never RED/PASS credit. TB38 497-row census belongs to a later separate turn after TB37 Review; do not combine it. No recovery, retune or selector mutation.

**Carried:** RA-152.5 axis binding; D4 legacy oracle 189–192 homes (RA-153 E1: 191 A3 `NonReciprocalAdjacency`); RA-146.2/.4, RA-45.4, G4-B002, `DIAG-RETAIN`, 19 inherited TB32 REDs, RP-01, RP-02 and M6 production verification. No new stable event or candidate ID is added solely for compile/inspection evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 source SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; 497 unchanged/unpromoted. |
| Decisive claims independently re-derived | Semantic commit patch + comparator, snapshot 5,873 hashes, packaged source byte equality, 28 package hashes, eight targets/GMP, atlas directed-transport source. |
| Non-vacuity checked | Difference from deleted atlas branch changes odd transport and guard; TB37 k1/k2, route and stable controls discriminate. Static missing-transport path unreachable by public input as RA-153 specifies. |
| Prior obligations discharged/carried | RA-153.3 static requirements discharged; RA-152.5/D4, RA-146.2/.4, RA-45.4, G4-B002, DIAG-RETAIN, 19 residual REDs and RP-01/02 carried. |
| Stable accounting | 66/17/49, debt1; accepted CP2 491/491, TB32 481/500 candidate, TB35 11/13, TB36 0/5, frozen497. |
| New candidates/obligations recorded | None; existing F1 moves from uncompiled correction to compiled/static-accepted pending TB37 behavioral verification. |
| ORIENTATION currency line | Updated to CB36-REV and exact TB37 successor. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a no representative witness state changed; §8 corrected F1's present state, no new pattern. |
| CHANGELOG | CB36-REV entry added. |
| ROADMAP | CP3 authority/next-gate wording updated; M6-CP3 remains open. |
| Selector manifest | n/a no selector addition or promotion. |
| LESSONS | Existing independent-evidence/negative-reachability/typed-failure lessons cited; no new category. |
| Consolidation under CLEAN_UP_POLICY | CB36 code/build and RA-153 remain current/live causal references; index adds their role, no destructive fold of load-bearing current files. |
| Successor frozen | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY`; 16-row manifest and RA-153.4 STOP rules above. |
| Turn boundary held | Review static only; no product/test/fixture/selector/benchmark/build mutations or runtime. |
| review_check.py boundary | Snapshot-local `review_check.py boundary` **executed, exit 1**: the four rewrite-ancestry/source checks cannot succeed in a no-history synthetic snapshot. The actual rewrite baseline's five protected headings were independently retrieved from GitHub and are preserved; exact semantic commit review shows no product/test/selector changes. GitHub-recorded historical boundary and ledger verification is now independently established (2026-10-25 continuation), as detailed below. The original `review_check.py boundary` exit 1 was on a synthetic no-history checkout; it is NOT relabeled as a passing execution. |
| `STATUS` lifecycle maintained | Entry beacon created; final direct-write required after remote documentation publication. |
| Pushed to origin, branch in sync | Verified push at `1fcd84643c2e1f8cdbf60f473e02253e0643c10c`, exactly the nine intended paths, and matching open/draft PR #8 head. Local synthetic snapshot cannot attest `git status -sb` against the actual origin; no false local-sync claim. |

## Actual-history independent equivalence audit (2026-10-25)

The GitHub repository rewrite baseline `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is an ancestor of the reviewed PR branch. Direct GitHub commit-path enumeration since that baseline and independent per-commit addition/deletion retrieval verified **165/165** `CHANGELOG.md` modifications and **16/16** `.agents/Directional/LESSONS.md` modifications. Every commit had nonnegative line-count delta; no missing file detail or negative delta was found. Cumulative deltas, +2,186 and +58, match exact baseline-to-current newline counts (2,134 → 4,320 and 325 → 383). The API history audit is an independent equivalent of the history-sensitive ledger predicate; the `review_check.py ledgers` command was NOT executed against an authentic Git checkout.

The three rewrite-protected documents retain **4/4**, **1/1**, and **0/0** protected headings respectively. GitHub commit comparison from semantic CB36 commit `038ae7fd7c290731c28225d2693a3e13866e325a` to reviewed head showed **no changes** to product, tests, fixtures, benchmark, CMake, or numbered required-green selectors. Protected selector contents were independently rehashed in the verified 5,873-file source snapshot; the source is unchanged to the reviewed head. The remote repository has no live uncommitted worktree represented by this inspection; no `git status -sb` result is claimed.

**Final decision:** static CB36 review accepted only for the pre-registered 16-case TB37 artifact-only verification. No runtime, selector, or M6-CP3 acceptance is claimed.
