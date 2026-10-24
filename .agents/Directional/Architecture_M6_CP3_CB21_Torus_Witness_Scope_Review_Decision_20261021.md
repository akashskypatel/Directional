# RA-116 — CB21 torus witness scope, independent Review (2026-10-21)

**Turn:** `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV`. **Verdict:** CB21 accepted for **static scope and compilation only**; TB22 runtime evidence is not yet available. Working PR #8 remains draft/open. No product, test, selector, fixture, benchmark, build or workflow logic changed in this Review.

## RA-116.1 Independent source and package checks

- Reviewed GitHub's exact semantic commit [`8453e19e6ac7d976a9cac45978ad31104a52f034`](https://github.com/akashskypatel/Directional/commit/8453e19e6ac7d976a9cac45978ad31104a52f034), not just CB21's report. Its entire file set is **one** file, `tests/SurfaceCellTransitionQuotientTests.cpp`; `+73/-47`. The diff has precisely three edited regions: `ProducedTorusWitnessFixture`'s last member, the shared torus fixture's candidate loop/selection/receipt/return, and `cp3entry:1`'s assertion stream. No other test/helper and no `src`, `include`, selector, harness or workflow files changed in the implementation commit.
- The original reciprocal pairing still requires two tracer-produced `PeriodicCut` front edges, the same relation, the same source occurrence/span orientations, and inverse routes; holonomy still requires the published ID, successful semantic-action resolution and exact cut-route/inverse comparison. The earlier odd-delta `continue` is gone: all candidates reach both independent measurements. The selected candidate is the earliest holonomy match among odd gauges if one exists, otherwise the earliest holonomy match. The complete seven counters and each per-candidate `delta/recip/holo` plus `selected` are assembled, including in the no-witness exception. D2 remains the same `ASSERT_TRUE(delta==1 || delta==3)` with only a receipt appended. The fixture's input source, source/A3 generator enumerator and semantic-relation helper are unchanged.
- The candidate generator takes face IDs from actual source-region occurrence owners; the phase-front constructor requires a nonempty, face-count-matched branch-rotation vector when periodic holonomies are published (`SurfaceCellTracing.cpp:8495-8504`). Thus a reciprocal candidate selected with `delta=-1` is not a supported produced fixture state; this was checked, not assumed. In particular no gauge-parity constraint is bypassed in `cp3entry:1`.
- Independently downloaded compile package `12318897957`: ZIP SHA-256 **`f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`**, root `SHA256SUMS` SHA-256 **`4726b88230cb81560ae5464327680a4199bcc7ce42a0e1de011728ba6c171bc0`**, and packaged source archive **`63b260ac5045c141b8918b6d2678a673450e49d82429826bc6614f6d44c98520`**. All **28/28** listed files verify, packaged TQ SHA-256 `a1179ad15cf03f3f7f9802bc35a3fc1986ebd95cedb8a86c479509497a2dc8e8` equals exact verified branch snapshot TQ. Preflight/build are `0/0`, five source statuses empty, eight target names are present, actual linker command contains `libgmpxx.so` and `libgmp.so`, and command boundary explicitly says `runtimeExecution=false`, `exactArithmeticBackend=GMP`.
- Source snapshot run `39544316215`, artifact `12320538954`, exact head `4d0b0a1f9139691dfea8ae1ab7fd6c0199e5e877`, verified **5,720/5,720** file hashes. The source-snapshot trigger and STATUS commits are nonsemantic and do not alter packaged TQ.

## RA-116.2 Non-vacuity and remaining obligations

The new census now distinguishes `sourceFaceGaugePairs=5; oddFaceGaugePairs=0` from unmeasured reciprocal or holonomy predicates, but **no runtime observation yet proves that `reciprocalTracerPairs` or `holonomyMatchedPairs` is positive**. The CB21 change has not been credited as a runtime fix. A passing selector beyond the shared fixture must reach its own assertion; a fixture throw does not count. The D2 organic odd-gauge witness remains open under RA-33.2/RA-111.3; absent odd candidates trigger `cp3entry:1`'s real D2 assertion, not a fabricated success. `RP-01` remains open; `RP-02` unreached. RA-115.3 M1 failures (`cp3entry:2`, `focused30:12`, ten M1 identities) and deferred fixture-debt obligations are carried to their existing owners unchanged. No stable event or new candidate is created by this static Review.

## RA-116.3 Exactly one successor

**Authorize only** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, artifact-only Test + Benchmark on package `12318897957`, source `8453e19e6ac7d976a9cac45978ad31104a52f034`, using `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`. Exactly 11 independent test processes: seven torus fixture consumers, `cp3entry:6`, and three unchanged controls. No compile/rebuild, code edit or selector revision. A RED TB routes to mandatory independent TB22 Review; do not launch DEFN-T1 or M1 automatically. Its precommitted falsifiers are in the plan.

## Review closeout

The verified 32,048-byte Review patch (SHA-256 `8ace3ed09bcafbf620f51dbb9e5067691744eabedfb0a58d41ad60e968499f04`) was applied by the durable Drive dispatcher (`39546749497`, result artifact `12321875478`) and the user-owned Drive staging object was permanently retired (`delete_file success=true`). The independent full-history review gate passed before the temporary workflow and markers were retired. No tests or benchmarks were executed.


| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a to CB21: no selector mutation; selector497 remains frozen; accepted CP2 is unchanged (491/491), no new accepted prefix |
| Decisive claims independently re-derived | GitHub semantic diff, exact TQ bytes, 28/28 packaged hashes, clean build/GMP evidence, independent predicate and selection walk |
| Non-vacuity checked | No runtime claim: reciprocal and holonomy existence unmeasured; exact TB22 receipt/falsifiers explicitly frozen |
| Prior obligations discharged/carried | RA-115.5 static CB21 scope discharged; D2/RA-33.2/RA-111.3, RA-105.3 M1, RP-01, RP-02 and fixture debts carried unchanged |
| Stable accounting | 66 / 17 / 49; debt 1; CP2 491/491 package 11391685901; R3 rejected 403/497; latest TB21 449/497 unaccepted |
| New candidates/obligations recorded | No new stable event; existing obligations remain in tracker and TODO |
| ORIENTATION currency line | Updated to CB21 Review and TB22 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged (no witness runtime); §8 unchanged (existing witness-scope lesson) |
| CHANGELOG | New CB21 Review entry |
| ROADMAP | n/a: no checkpoint status moved |
| Selector manifest | n/a: no selector additions/acceptance |
| LESSONS | Existing §2 **A fixture change reaches every fixture built from it** and **A failure hidden behind an earlier one is unmeasured** |
| Consolidation under CLEAN_UP_POLICY | CB21's 21-line compile evidence remains current immutable package authority; no superseded per-turn report eligible to fold before TB22 |
| Successor frozen | `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, 11 rows and falsifiers in TB22 plan |
| Turn boundary held | Runtime-free Review; documentation only |
| review_check.py boundary | **PASS** on complete-history GitHub Actions checkout, run `39547232827`, log artifact `12322225719`, exact event source `4cfe0d1a5e1c042e57d40c8a96236c9a213047cd`: all frozen selector hashes match, protected durable rewrite sections preserved, zero source/test/build mutation. `review_check.py ledgers --base 8b7299b43` also **PASS**; no historical CHANGELOG/LESSONS shrinkage. |
| `STATUS` lifecycle maintained | Entry and resume beacons published, `Started at` preserved (`2026-10-21T04:28:35Z`); final COMPLETE beacon to be published as the final repository action after cleanup and verification. |
| Pushed to origin, branch in sync | The complete verified patch was pushed as `56a1754794e0b90012dce99884afc302288eaaca`, with all six intended paths independently confirmed. PR #8 GitHub head verified after workflow and trigger retirement (`46ea50f8aff8b0254fd02939f0a7cadd3e47a0bb`); the full-history CI checkout is clean, though it is a detached HEAD (`git status -sb` does not supply a local branch tracking comparison). |

> *Closed by RA-117 (2026-10-21): TB22 confirmed the fixture-selection scope (reciprocal 5/5, holonomy 5/5); the five CP2 rows split into a fixture atlas defect and the unowned torus A5 isolation family; CB22 is next.*
