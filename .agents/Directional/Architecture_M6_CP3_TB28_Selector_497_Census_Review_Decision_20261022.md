# TB28 independent Review — RA-133 (2026-10-22)

**Turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV`. **Verdict:** accept TB28 as independently verified **candidate-only census** of the unchanged CB26 package; **do not promote CP3 acceptance**. The full 497-entry gate is still RED (462 PASS / 35 RED). No new runtime, compile, source, test, fixture, selector, workflow, or benchmark change is authorized or performed in this Review.

## Primary evidence and independent arithmetic

- Source snapshot: `9f23dd290694c74edb21e7f80cec60824c594550`, ZIP SHA-256 `d46a2d0b07dca8a9011c854a18fa3dd4b75cf9ff6ed52571d11e5070754f91f6`; 5,784/5,784 source files and nested source archive verified. This is a review snapshot, **not** a replacement semantic source; CB26 semantic authority remains `e3d60337ed34538547d3a6d519bafae5b184330e`.
- TB28 immutable [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact `12424484672`; independently re-hashed ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; SHA256SUMS verifies **1019/1019** files. Recorded immutable compiled package `12409939859` / `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`.
- Independently parsed `combined-ledger.tsv` and all 497 archived per-case logs: distinct `(phase,ordinal)` 497/497; one `[ RUN ]` per exact test identity; PASS logs each contain one `[ OK ]` with no failed test, and RED logs a failing test; SHA-256 matches every log's ledger row. The separately published 497-row full ledger agrees on phase, ordinal, identity, owning executable, exit, verdict, and log hash. The 35-row RED inventory is exactly the RED subset.
- **30 focused30** 26 PASS/4 RED; **12 focused12** 12/0; **449 selector** 421/28; **6 cp3entry** 3/3. Total **462 PASS / 35 RED**. The TB21 inventory contains 48 RED identities; set subtraction yields exactly 13 RED→PASS: `focused30:6,20,24,25,26,27,28`, `selector:444,446,447,448`, `cp3entry:3,5`. TB28 RED ⊂ TB21 RED; **0 PASS→RED**. All 12 known seam family cases and selector:447 pass.
- Artifact `execution-boundary.txt` and `immutability.txt` record no compile, configure, relink, benchmark, package/mode repair, selector or fixture mutation; before/after source/package/execution-view censuses agree. No surviving RED log contains an A7 `UncertifiedCrossSheetBinding` rejection; this is **not** proof of unexecuted A7 negative paths.
- Selector-449 authority hash from RA-132 is `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; frozen focused30, focused12 and routing receipts are rechecked in the archive's before/after censuses, not rewritten. The accepted CP2 491-case prefix is a **different earlier authority**, not a proven contiguous prefix of the CP3 selector; do not claim a nonexistent prefix hash relationship.

## All 35 inherited REDs — observable classification, not invented root causes

This is a complete partition of the exact residual RED identity set, checked against each original log. Categories mark the **first observed failed stage/precondition**, not a claim that the underlying product cause is known. Every identity remains RED and non-promoted.

| First-failure family | Exact identities | Count | Disposition |
|---|---|---:|---|
| M1 validation precedence/transport | `focused30:3,22,23`; `selector:139,140,142,211,219,227,230` | 10 | RA-105 M1 candidate, defer causal specification to DEFN-M1; do not change expected typed rejection based on earlier fixture throw |
| Neighboring hard-rail / A5 prerequisites | `focused30:12`; `cp3entry:2` | 2 | Preserve failed certificate/producer preconditions; defer with M1 evidence without attributing either to M1 as proven root cause |
| Odd-gauge torus D2 | `cp3entry:1` | 1 | `oddFaceGaugePairs=0` from 5 candidates, while D2 requires delta 1 or 3. No relaxation; DEFN-T1 must determine attainable producer witness |
| Periodic product/fixture setup | `selector:189–195,220,221,296,302,304,439` | 13 | Most tests throw before their asserted negative oracle (`source A3 unavailable` or `direct periodic-owner product`); no false PASS or proof of those guards; restore fixture authority in separately reviewed work |
| Typed hard-feature front setup | `cp3entry:4` | 1 | Missing expected front; causal owner remains unresolved |
| Other inherited producer/test oracles | `selector:174,201,204,242,247,250,405,442` | 8 | Retain individual first-failure records and per-identity fixture-debt/correctness review; do not merge unlike failures into one cause |
| **Total** | **All 35, disjoint** | **35** | **Remain RED** |

The exact names, exits, SHA-256s and first failure for all 35 are retained in `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`. M1's prior candidate is **not** proof that the 10 failing products all share one fixed cause; e.g. three hard-rail pair tests fail in precondition reconstruction. The observed torus D2 receipt establishes **absence of a witness on this fixture**, not mathematical impossibility of nonzero face gauge. Selector:242/247 failures include expected Rejected versus actual Produced; these cannot be dismissed as cosmetic text drift. Selector:442 fails an atlas/singularity construction prerequisite. All 35 inherit TB21's red identity set, but first-failure text can change across packages; no shared causal assumption is made solely from membership.

## Non-vacuity, obligations, and stable gate decision

RA-132 D3 and D7 tamper positives remain PASS in the 497 archive (`cp3entry:3/5`), and the 12 seam-family results cross the intended positive path. They establish their **specific tested constraints**, not universal certified-seam rejection coverage. CB27 is still required for RA-127.4b endpoint-coordinate/outside-wedge/same-side and RA-130 B4 unrelated-seam evidence, missing-certificate, and seam-direction sites; `cross-sheet:periodic` (RA-130.7) and nonzero-turn carrier obligations remain conditional on constructible witnesses. No new stable accepted-green loss is observed: **66 events / 17 categories / 49 recurrences**, witness debt **1** unchanged; CP2 **491/491 accepted**, R3 **403/497 rejected**, TB28 **462/497 candidate only**, RP-01 OPEN, RP-02 UNREACHED, Gate C suspended.

## Exactly one authorized successor — Code + Build, test-only

`M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES`. Scope **only** `tests/SurfaceCellTransitionQuotientTests.cpp`, preserving all source/fixture/selector/harness/workflow code. Implement the five RA-132.6 A7 negative cases using the D7 fixture and immutable A6 product: unrelated certificate transition on another same-sheet-pair seam rejects at `cross-sheet`; missing certificate rejects at `cross-sheet:no-certificate`; altered lattice endpoint and outside-wedge span each reject at `cross-sheet:seam-direction`; same-side only when it reaches the intended check, otherwise record the earlier per-member guard. Assert the exact A7 site and separately derived A6 disposition; keep intact the positive D3/D7 controls. **Falsifiers/STOP:** altered test preconditions cannot be constructed; tamper fails at an earlier unrelated stage; positive controls no longer produce the certified relation; rejection site differs; test has an early return/skip; any source/header/selector mutation is necessary. Stop and return to independent Review rather than weaken assertions or touch production. CB27 uses the authorized GMP/GMPXX eight-target compile-only dispatcher; no runtime in CB27; separate CB27-REV and TB29 required.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: CP3's frozen 497 composite is not a contiguous extension of accepted CP2 491; archive hashes and immutable before/after selector input checked, no new selector admitted |
| Decisive claims independently re-derived | 1019 result files, 5784 source files, 497 exact test logs/identities, per-case SHA, owner/verdict, 13/0 set differences, 35 disjoint REDs |
| Non-vacuity checked | D3/D7 are PASS and tamper-bearing; absent A7 negatives expressly carried |
| Prior obligations discharged/carried | RA-132 census/zero-regression and RA-130 B1 targeted verification discharged; RA-127.4b, RA-130 B4/B5 and RA-130.7 carried to CB27 or witness-dependent review; M1/D2/fixture debt retained |
| Stable accounting | 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497; candidate TB28 462/497; frozen selector 497 |
| New candidates/obligations recorded | TB28 classified inherited-RED candidate in tracker; five CB27 negatives scoped; no stable events added |
| ORIENTATION currency line | Updated to RA-133/TB28 on 2026-10-22 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current; §4 witness matrix unchanged; §8 existing premature-credit/non-vacuity patterns apply, no new pattern |
| CHANGELOG | RA-133 review entry added |
| ROADMAP | CP3 candidate evidence updated; checkpoint still active |
| Selector manifest | n/a: no new selector or accepted promotion |
| LESSONS | Existing §1/§2 on evidence/non-vacuity and fixture authority cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | No newly superseded expendable record safe to fold; TB28 full ledger and RA-132 authority remain load-bearing; no removal |
| Successor frozen | `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES`, exact negatives/falsifiers above |
| Turn boundary held | Review-only, 0 runtime, 0 build, 0 code/test/selector changes |
| review_check.py boundary | Executed on verified source-snapshot-derived synthetic checkout: no product/test/fixture/selector mutations detected, but historical baseline/durable-source checks **FAIL (not verifiable)** because snapshot excludes actual Git ancestry. Independent live GitHub compare establishes rewrite baseline `8b7299b43` and semantic CB26 SHA `e3d60337` are ancestors, with no code/test/fixture/selector drift from CB26 to branch; independently compared all rewrite-baseline `DURABLE` headings to live branch, none missing. Full per-commit append-only history scan remains unverified; no synthetic-git PASS claimed. |
| STATUS lifecycle maintained | Started timestamp retained at `2026-10-22T12:47:53Z`; resume beacon written at `2026-10-22T14:22:26Z`. Final direct COMPLETE beacon is the last remote mutation of this Review. |
| Pushed to origin, branch in sync | Durable Drive application [run 39793881309](https://github.com/akashskypatel/Directional/actions/runs/39793881309) committed seven exact documentation paths at `38bd1c2aab146290024ddc3285ca66289eb8f032`; GitHub remote commit comparisons verified no additional review product/code changes. Cleanup removed the snapshot trigger and temporary manifest. Final branch HEAD checked via GitHub connector. `git status -sb` on a real checkout was unavailable because the verified Web snapshot excludes `.git`; a synthetic checkout cannot certify remote synchronization. |
