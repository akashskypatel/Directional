# M5-CP3-TB1-R12 Review Record

**Turn:** `M5-CP3-TB1-R12-REV`
**Type:** **REVIEW + PLAN / runtime-free / no implementation**
**Disposition:** **R12 MECHANICALLY UPHELD / ORDINARY-TORUS REGRESSION CAUSE PROVED / NONZERO-Z4 FAILURE NOT SUFFICIENTLY OBSERVABLE / EXISTING RP-01 CONTINUATION / CANDIDATE UNPROMOTED**
**Exact successor:** `M5-CP3-CB15`

## 1. Independent evidence re-derivation

Review independently re-opened the immutable R12 result and the exact CB14 package/source authority rather than inheriting EXEC conclusions.

- candidate/source: `10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a`;
- compile run/job: `35798853372 / 106984376759`;
- R12 run/job: `35802519951 / 106995887964`;
- result/log: `10726868409 / 10726518857`;
- result/log ZIP SHA-256: `3f5978b7e0753dccd68fa53ddc50e50b3a5d4d3ea61d2bbd6e9da688531877bc / 146fa160681f012c10979eb8018f6b91e1ad41b2ce5ef5c02c70dc0f36a9d265`;
- result self-manifest: **912/912**, SHA-256 `fd3ad48624f311feb1bfb5a19e00a9515dc00f231f90b2409bb9676677891524`;
- candidate ZIP/root-manifest/source-archive SHA-256: `1995b8cf3de6190bff60f0e8d4ad74de90cc82327b80fd5c29f2fc0eb089d902 / 92fb6c0747db81514b2060ab195d3b7e68ede14c035c1b7f116a4e8a36679279 / 1bfd66e0a2c9a4b78dffe0280859130eed8bcd6e34032c07255bd0aaa83829bd`;
- routing/identity-map SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce / 7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 / first427 SHA-256 independently re-hashed from packaged source: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

All **446/446** planned exact filters selected exactly once with zero skips: mechanism **9/9**, focused atlas **1/1**, produced **0/6**, selector430 **429/430**, hence **439 PASS / 7 RED**. Protected selector ordinals **191/192/247** remain PASS and **408** is RED. Benchmark count is zero. Candidate package/source/execution-view postflight is exact and all prohibited-operation counters are zero.

Review source snapshot run/artifact is `35806863844 / 10728142268`, event SHA `428edbf04ed360411e033587b34f25597cb18992`; provider ZIP SHA-256 `987e275ec42534961c88f4a66b8e870720cc63731d5c0b6aa256f4586140e35d`; embedded source manifest verifies **5296/5296**. Review executed no Directional runtime.

## 2. Ordinary torus regression: cause proved

The R12 ordinary torus front is not merely a possible canonicalization hazard. Source and prior runtime make it a proof by elimination.

R11-R1 on CB12 passes produced rows1/2/3/6 and selector430 **430/430**. CB14 changes only four semantic/test files relative to CB12: `SurfaceCellTracing.h`, `SurfaceCellTracing.cpp`, `RemeshPipeline.cpp`, and `SurfaceCellTransitionQuotientTests.cpp`. On the ordinary torus, CB14 progresses beyond `PeriodicActionCorrespondenceMismatch` and reaches final checked-product construction; otherwise the observed public failure could not be `InvalidFinalCellState`.

CB14 constructs each same-region relation in exact semantic A3 **Forward -> Reverse** direction, then calls `insert_periodic_holonomy(...)`. That insertion unconditionally invokes `canonicalize_periodic_holonomy(...)`, which is allowed to replace the relation with its inverse action and reversed generator/cut routes while preserving the orientation-neutral `PeriodicRelationId`. The edge's exact A3 Forward/Reverse interval roles and `periodicFromLattice` / `periodicToLattice` states are not rebound when that storage normalization occurs.

The new exact-A3 branch of `SurfacePhaseFrontProduct::make(...)` then treats the stored canonical representative as though it were still the semantic Forward -> Reverse representative. It requires, in this order:

1. semantic `forwardEdge->route == stored cutRoute` and `reverseEdge->route == stored cutRoute.reversed()`;
2. endpoint-gauge states re-derived using the stored action rotation;
3. the stored action mapping semantic Forward endpoint states to semantic Reverse endpoint states.

If insertion leaves the semantic representative unchanged, all three are satisfied by the immediately preceding builder construction: the same routes, endpoint-state constructor, rotation and action are reused. Therefore the observed checked-product rejection proves that at least one ordinary-torus relation took the inverse storage-canonical representative. In that case item 1 is the first false new predicate: stored `cutRoute` is the semantic reverse carrier while `forwardEdge->route` remains the semantic Forward carrier. The later generic `InvalidFinalCellState` merely hides `SurfacePhaseFrontProduct`'s more precise rejection.

This is the same authority-domain family as `RP-01`: **storage-canonical relation orientation is representation authority, not semantic A3 direction authority**. Canonical storage is valid; consuming it without first orienting it deterministically to the exact semantic Forward -> Reverse carrier is not.

`M5-CP3-TB1-R12-CAND-01` is therefore reclassified:

**CAUSE PROVED / PRODUCT / EXISTING `RP-01 AUTHORITY_DOMAIN_CONFLATION` CONTINUATION / STORAGE-CANONICAL RELATION ORIENTATION CONSUMED AS SEMANTIC A3 DIRECTION / NON-STABLE / OWNER `M5-CP3-CB15` / +0.**

The correction must not remove canonical storage or try action/inverse until one passes. It must determine the semantic representative solely from exact route/A3 orientation identity, then validate one action in that direction.

## 3. Nonzero-Z4 failed recovery: exact first false predicate is not currently observable

Rows4/5 remain byte-equivalent in semantic failure to R11-R1 at public `PeriodicActionCorrespondenceMismatch`, but CB14 changed the helper being diagnosed. The old R11-R1 proof that raw cut-domain coordinates make the second endpoint map false cannot simply be copied onto the new endpoint gauge.

CB14's helper now rejects on a fixed conjunction covering:

- exact Forward/Reverse occurrence roles;
- generator-rotation identity on all four endpoint states;
- same-edge source-chart relationships;
- same-edge occurrence identity and cross-edge occurrence distinctness;
- reciprocal scale levels;
- both branch-rotation correspondences;
- transported relation-gauge delta correspondence;
- both exact endpoint mappings.

Several predicates are construction-owned, but the current R12 evidence emits neither the four relation-endpoint states nor a typed failing subpredicate. In particular, source-chart equality and the transported delta in the new per-endpoint branch gauge depend on exact produced endpoint states not recoverable from the public failure string alone. Review therefore **does not guess** which predicate is first false and does not authorize another endpoint-gauge formula change.

The R11-R1 root remains historically proved for CB12. R12 proves only that CB14 did not recover it. `M5-CP3-TB1-R11-R1-CAND-01` remains **OPEN / FAILED RECOVERY / EXISTING RP-01 CHAIN / FIRST CB14 SUBPREDICATE UNRESOLVED / NON-STABLE / +0**.

## 4. Direction observation remains open

The R11-R1 reviewing-agent amendment remains controlling. `M5-CP3-TB1-R6-REV-OBS-01` is **OPEN**. R12 row4 still stops before relation publication and therefore cannot independently compare a produced action against the exact Forward -> Reverse source/A3 expectation, nor can it exercise the required inverted-pair rejection. Source path reachability is not independent direction proof.

CB15 may add observability needed to reach this proof, but neither Review nor Code + Build may discharge the observation without runtime evidence.

## 5. Regression accounting and debt

No stable counter changes are justified. The newly proved ordinary-torus defect was introduced by the unpromoted CB14 recovery candidate and is another representation-vs-semantic-direction manifestation inside the already-open `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recovery chain. The four produced RED controls and selector408 share that one cause; counting them separately would double-count one defect. The nonzero-Z4 failure is the still-unrecovered antecedent in the same chain.

Stable accounting therefore remains **50 events / 14 categories / 36 recurrences**. Produced-witness debt remains **3**: the two M5 nonzero-Z4 debts plus the M6-owned closed-complex debt.

The historical produced relation-owner/container-order and missing-owner debts discharged at R7 remain discharged. R12 shows a regression in the current unpromoted candidate before those assertions execute; it does not erase the previously accepted produced evidence. It does, however, prohibit promoting CB14 or treating rows1/2/3/6 as current-candidate credit.

Accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. CB14 remains unpromoted. `M5-CP2-TB1-REV-OBS-01` remains OPEN and selector publication remains prohibited.

## 6. Frozen corrective successor

Exactly one successor is authorized: runtime-free Code + Build **`M5-CP3-CB15`** under `Architecture_M5_CP3_CB15_Semantic_Periodic_Direction_And_Correspondence_Diagnostics_Plan.md`.

CB15 has two inseparable bounded obligations:

1. correct the proved storage-representation/semantic-direction boundary by deterministically orienting a canonical stored relation to exact A3 Forward -> Reverse authority from carrier identity, never by trying both actions or choosing whichever validates;
2. make the unchanged nonzero correspondence helper publish a typed first-false-predicate diagnostic/receipt sufficient for the next artifact-only gate and Review to identify the CB14 failure without changing the relation-endpoint gauge formula.

CB15 is compile/package only with mandatory GMP/GMPXX. It may not execute Directional runtime, alter the field/fixture/A3 plan, weaken checked validation, change selector430, fit endpoints/translations, search transforms, or change the CB14 endpoint-gauge derivation before the missing predicate is observed.

A compile-green CB15 routes to fresh artifact-only **`M5-CP3-TB1-R13-EXEC`**. R13 must execute one new focused semantic-orientation identity plus the unchanged 446 R12 identities (**447 fresh processes total**) and then mandatory Review. The existing 446 identities and selector430 bytes remain unchanged. R13 must recover rows1/2/3/6 and protected ordinal408 or the semantic-direction correction is rejected; rows4/5 may remain RED only if the new typed receipt identifies one exact first false predicate and all immutable-gate requirements hold.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. |
| Decisive claims independently re-derived | R12 912/912 and 439/7 vector re-opened; CB12->CB14 semantic delta restricted to four files; ordinary torus storage-canonical inversion proved by contradiction against the new validator; nonzero helper predicate deliberately left unresolved because its operands are absent. |
| Non-vacuity checked | Ordinary controls were green in R11-R1 and accepted ordinal408 was green; R12 reaches checked product and reds. Rows4/5 retain genuine nonzero source/A3 preconditions but stop before relation publication/tamper, so no debt credit is invented. |
| Prior obligations discharged/carried | R10 storage-order source defect stays CLOSED; R6 direction observation remains OPEN per reviewing-agent amendment; `M5-CP2-TB1-REV-OBS-01` OPEN; two M5 nonzero-Z4 debts OPEN; historical rows1/2/3 debt discharges retained. |
| Stable accounting | **50 events / 14 categories / 36 recurrences**, debt **3**; accepted runtime `10601978228 / 0798547d...`; CB14 unpromoted. |
| New candidates/obligations recorded | `R12-CAND-01` cause-proved as existing RP-01 storage-canonical-vs-semantic-direction conflation; CB14 nonzero recovery remains unresolved and gains a typed-observability obligation. |
| ORIENTATION currency line | `M5-CP3-TB1-R12-REV`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for R12 evidence, torus regression, open direction observation, CB15 next, and storage-representation-vs-semantic-direction RP-01 instance. |
| CHANGELOG | Root and Directional changelogs updated with Review adjudication and CB15 successor. |
| ROADMAP | M5 CP3 status updated to R12 Review complete / CB15 next. |
| Selector manifest | n/a — no selector added, changed, or accepted. |
| LESSONS | No new entry; the finding is a direct instance of existing lesson 30 (canonicalized representative vs raw/semantic representative) and RP-01 authority-domain discipline. |
| Consolidation under CLEAN_UP_POLICY | Superseded R11-R1 Review and consumed R12 Review plan folded into `M5_Consolidated_Record.md`; retained current R12 runtime report, this Review record, one CB15 plan, consolidated/frozen authority and selectors. |
| Successor frozen | Exactly one successor: `M5-CP3-CB15`, with explicit semantic-direction falsifiers, diagnostic-only nonzero-Z4 scope, compile-only boundary and stop rules. |
| Turn boundary held | Yes — Review executed no Directional runtime and made no product/test/fixture/selector/build-source mutation. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** with exact selector427/selector430 declared hashes; no product/test/fixture/build or selector mutation. |
| `STATUS` lifecycle maintained | Entry beacon published; terminal COMPLETE/CB15 beacon reserved for the final repository write. |
| Publication / branch sync | Review closeout requires the exact documentation patch to be pushed before cleanup and the terminal `STATUS` beacon to be the final repository write; branch sync is established operationally by those successful closeout steps rather than by a local-repository claim. |
