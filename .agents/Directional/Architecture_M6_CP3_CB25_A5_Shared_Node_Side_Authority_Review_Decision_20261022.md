# RA-128 — CB25 independent Review: scoped acceptance (2026-10-22)

**Turn:** `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV`. **Verdict:** ACCEPT **CB25's scoped code and compile-only evidence**; do not promote runtime or CP3 acceptance. **Exact successor:** `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST` (artifact-only TB26).

## 1. Independent source and compile evidence

- Immutable review snapshot: `2d542b47e9064bf74b8b7f1442b1417a5955f158`, workflow [39718824561](https://github.com/akashskypatel/Directional/actions/runs/39718824561), source artifact `12400116414`, outer ZIP SHA-256 `793a98ce430fa7ae1ac0252f5d2bc3bb85ed73224df50b488314207843949feb`, inner tar hash and **5770/5770** source-manifest checks verified. The source-snapshot marker and `STATUS` are nonsemantic control state.
- Independently fetched the one-commit diff at `c5e0b242f3c3015f1f4f5f886058f0086fe1f679`: **only** `src/pipeline/RemeshPipeline.cpp` (+21/-6); no test, fixture, selector, workflow, A2, or A6 changes. Its `RemeshPipeline.cpp` SHA-256 `07bb8878361fa8886f52ae306e6d03201bd915222c5a5a69a0a1cfb6f5fceedf` matches the independently unpacked CB25 compile-source archive.
- Original CB25 exact compile artifact `12399179446`, ZIP SHA-256 `a82c75e0f648fa8f1c8e34e07934d7a01321692e12e993638f02465766f236e9`; all **28/28** entries in `SHA256SUMS` independently validated. Source ID is the same `c5e0b242...`; eight requested targets listed, `preflight=0`, `build=0`, final source status empty, exact backend `GMP`, generated link line resolves **both `libgmpxx.so` and `libgmp.so`**, boundary `runtimeExecution=false`. Binaries were **not executed** in this Review.

## 2. Semantic adjudication — RA-127.5

1. `certified_seam_shared_node` uses one exact predicate: canonical `support` equality, `placement.selectedFace` equality, and `placement.lattice.latticeCoordinate` equality. No world-coordinate tolerance or sheet-label inference is introduced. A1 discharged for CB25 scope.
2. `certified_seam_direction` guards both span-to-selectedFace comparisons by `!sharedNode`. Every other original predicate remains, including common collinear seam, certificate/region equality, distinct certificate sheets, certified wedge binding membership and typed sheet equality; only certified opposite side orientations return a direction.
3. The rejection-site classifier calls the **same** helper and applies the same exemption to precisely `first-face`/`second-face`, preserving label order and format. A2 discharged.
4. `seam_transport_certificate` still rejects zero or multiple admissible certificates. The A6 gauge-face authority and D3 gauge-stripped-versus-expected-turn rejection are source-unchanged. The shared function now permits formerly blocked relations to reach A6, but the downstream guard has **not been runtime-proven** for those relations.
5. Static non-vacuity: the shared-node branch materially changes the two A5 face predicates, while inequality in any of the three identity fields retains both predicates. Wedge nonmembership, same-side, equal-sheet and ambiguous-certificate checks still reject by inspection. This is a static contract check, **not** a replacement for the A4 negative tests or D3 runtime tamper.

No source-contract discrepancy requiring a new corrective CB was found. This verdict is limited to RA-127.5's approved semantic diff and compile package; no new stable regression or accepted-green promotion is established.

## 3. Exact successor and stop/falsifiers

`M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST` is **artifact-only Test + Benchmark** on immutable package `12399179446` / source `c5e0b242...` without rebuild or any source/fixture/test mutation.

- Harvest all 12 A5-ISO identities: `focused30:6,20,24,25,26,27,28`; `selector:444,446,448`; `cp3entry:3,5`. Preserve `selector:447` as guard and all six TB25 PASS controls; use the existing artifact-only TB harness/reusable workflow and report exact selected identities, zero skips, manifests and package postflight. No selector edit or acceptance inference.
- Report for `cp3entry:3` and `cp3entry:5`: (i) the producer finds a certified reciprocal cross-sheet relation, (ii) A6's untampered decision and stripped/expected turns, and (iii) `cp3entry:3`'s existing D3 quarter-turn face-gauge tamper rejects as `RelationCertificateConflict`. A runtime PASS without reaching these paths does not discharge the obligation.
- **Falsifiers/stop:** any of the 12 repeats the exempted A5 `first-face`/`second-face` rejection despite exact shared-node identity; any invalid wedge/same-side/sheet/ambiguous certificate is admitted; a guard/control previously PASS becomes RED; the A6 untampered relation is reported as accepted without measured certified reciprocity; the D3 tamper is admitted; package identity or manifest checks fail. Publish the first actual failure and return for Review; do not weaken A6, D3, validation or selectors.
- **Carry A4** to a later separately authorized **CB26** (test-only): outside-wedge shared node, same certified side, and same edge+face but different lattice coordinate. `DEFN-SEAM-NZ`, M1, D2 and DIAG-RETAIN remain deferred until their own gates.

Accounting unchanged: stable **66/17/49**, debt **1**, CP2 accepted **491/491**, R3 rejected **403/497**, TB21 candidate **449/497**, frozen selector **497**, RP-01 open, RP-02 unreached, Gate C suspended.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector mutation or accepted-prefix promotion in this compile-only Review. |
| Decisive claims independently re-derived | One-commit patch, source SHA match across snapshot/package, helper/consumer guards, 28/28 package hashes, both GMP links, eight targets and no runtime. |
| Non-vacuity checked | Changed A5 branch reaches a nontrivial predicate; exact D3/negative cases explicitly carried to TB26/CB26 rather than assumed passed. |
| Prior obligations discharged/carried | RA-127 A1/A2 discharged (static CB25); A3 to TB26; A4 to CB26; nonzero-turn witness deferred. |
| Stable accounting | 66/17/49, debt 1; CP2 491/491 accepted, selector497 frozen, candidate TB21 449/497. |
| New candidates/obligations recorded | No new stable/candidate event; tracker references this review and carried A3/A4. |
| ORIENTATION currency line | Updated to RA-128 / TB26 next, 2026-10-22. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 corrected; §4 n/a (no witness runtime); §8 n/a (no new recurring pattern). |
| CHANGELOG | CB25 review entry added. |
| ROADMAP | n/a — M6-CP3 state and exit gate unchanged. |
| Selector manifest | n/a — neither selector bytes nor accepted authority changed. |
| LESSONS | Existing non-vacuity / accepted-runtime-before-credit lessons applied; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | No eligible obsolete per-turn records: CB25 compile package/record remains current for TB26, RA-127 contract is load-bearing, and the RA-128 decision is current. No protected or current evidence folded. |
| Successor frozen | `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST`, falsifiers and stop rules in §3 above. |
| Turn boundary held | Static review only; no product/test/fixture/selector/build source edit, no benchmark or binary execution. |
| review_check.py boundary | Local snapshot-derived baseline: product/test and selectors PASS, historic-Git-ancestry checks FAIL because source snapshot does not include original `.git` history. Independent GitHub one-commit diff checked; no remote boundary-pass claim. |
| `STATUS` lifecycle maintained | Entry beacon written for current turn; final COMPLETE beacon required only after evidence/doc transport, cleanup and closeout. |
| Pushed to origin, branch in sync | Reusable Drive patch transport verifies exact-base path authority and pushes the committed review documentation; remote completion to be verified before final beacon. |
