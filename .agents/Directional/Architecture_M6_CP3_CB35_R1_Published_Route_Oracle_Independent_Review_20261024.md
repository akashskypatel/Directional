# CB35-R1 published-route oracle — independent static Review (2026-10-24)

**Canonical turn:** `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION-REV`. **Verdict: NOT ACCEPTED — material test-authority gap R-2.** No TB36 authorization. Static review only: zero executable/test/benchmark/compile execution, zero product/test/selector source edits.

## Exact evidence independently rederived

- Exact compiled semantic commit `c67c6e72a21c89b0fa202cdd593982f8cb0646b0`: `git show` file list includes only `tests/SurfaceCellsPhase10Tests.cpp`, +5/−1. Snapshot at `4d3bc5efbcb270b3e6f3805bf5f51bc768cce2fa` (run 40141143103, artifact 12578358176): outer ZIP SHA-256 `7611f1ac882cc726a4dc3b5c12decaf3f6d81c44f1825bb2702167c06c49f093`; inner tar digest and 5,859/5,859 file checksums validated against `SHA256SUMS`.
- Independently downloaded exact eight-target immutable compile artifact `12577649024` (run 40138512704), ZIP SHA-256 `2911d931a5faf172097d0291ae47ea17d839cf089bfb114d11b791e057304a9a`: all 28/28 `SHA256SUMS` entries verified. Package source file hash matches verified snapshot test file (`603734dd47d6bf20143d08c9f8bd47de01f84d77498e49a5f976bcc02e782898`). Metadata: source `c67c6e72a21c89b0fa202cdd593982f8cb0646b0`, preflight/build exit 0/0, clean statuses, eight targets, both `gmpxx` and `gmp` link evidence, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- Rehashed accepted selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; selector497/frozen original 189–192 have no edits in semantic diff. Unchanged acceptance: CP2 491/491; TB32 candidate 481/500 with 19 inherited RED, TB35 11 PASS/2 RED; stable 66 events/17 categories/49 recurrences, one produced-witness debt; RP-01 open, RP-02 unreached.

## Supported R-1 correction

The R1 addition checks all 32 steps exist, the canonical stored edge-key list matches the fixture's independently supplied list, each observed step's `LatticeTranslation` is zero, and the composed **full** `GridAutomorphism` is identity, while preserving ±1/inverse and remaining identity rotations. Wrong unmarked canonical topology or nonzero shift will now fail. This discharges the specific prior missing canonical-edge and translation assertions but **does not establish directed traversal identity**.

## Material finding R-2 — canonical identity is not oriented route identity

`tests/SurfaceCellsPhase10Tests.cpp:141–146` defines `route_topology(route)` by iterating `route.steps()`. `CanonicalRoute::steps()` (`include/directional/authority/CanonicalRoute.h:64–66`) exposes `canonicalSteps_`, independent of the current traversal direction. The test at `tests/SurfaceCellsPhase10Tests.cpp:4662–4694` takes `route.oriented_steps()` into `steps` but compares `periodic_route_topology(fixture)` only to `route_topology(route)`, never to the actual **ordered oriented** `steps` topology/direction sequence.

`src/authority/AuthorityKernel.cpp:85–100` proves the concrete counterexample: `CanonicalRoute::reversed()` returns the *same* `canonicalSteps_` and toggles `canonicalOrientation_`. `oriented_steps()` reverses the order and applies each step's `.reversed()` (inverting transport and orientation). Consequently substituting `route.reversed()` for the published route leaves canonical topology equality and count unchanged, keeps each zero shift zero, swaps/inverts the distinguished ±1 pair while preserving the inverse relationship, and maintains identity for all other rotations and the total automorphism. The updated witness therefore still accepts a **reversed traversal** with a different directed sequence. This is a static falsification of the **oracle**, not evidence of a runtime production failure. Do not promote to a stable regression event.

**Required remedy:** Compare every actual `oriented_steps()[i]` with the fixture-authored expected directed step and add an independent reversal-negative discriminator; keep the R1 full automorphism/zero-shift/rotation and negative witness assertions. [Narrow successor plan](Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Plan_20261024.md) freezes that single test-only correction. Do not run TB36 before successful R2 Code+Build and independent Review. If published route orientation is unspecified by the authoritative contract, stop for Definition rather than inventing expected orientation.

## Disposition, obligations, boundary and maintenance

- R-1 corrected canonical topology + translations: discharged as narrower facts. R-2 oriented route identity: new non-stable test-authority candidate, owned by `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE`. Falsifier: flipped route must fail an independently derived full directed witness. Tracker updated; accepted-green loss not measured.
- RA-152 F1 production A4 dead atlas transport, D1–D4, RA-152.5, 191/192 ingress authority, G4-B002, DIAG-RETAIN and the 19 inherited RED remain carried with original owners. No new product fix, source changes, acceptance, or milestone transition. Frozen TB36 five-case pre-fix baseline remains conditional/unreached.
- Read mode exception: mandatory start documents were initially read directly before `READ_MODE=snapshot` was locked, contrary to conservation-policy pre-read gate; corrected immediately to one hash-verified snapshot. This is a process deviation; do not represent it as source/test impact. No policy or normative document changed.
- `CLEAN_UP_POLICY` consolidation: inspected active prior R-1 plan, CB35-R1 compile record, RA-152/TB35 prior evidence and consolidated owner pointers; no deletion/folding because these are active reviewed proof/dependency records. Review record and R2 plan prepared, current ORIENTATION/Handoff/TODO/CHANGELOG/tracker revised locally pending remote patch application. Source-snapshot trigger queued for cleanup via the manifest. No accepted selector, ROADMAP, or frozen definition change.
- The local snapshot has no actual Git history; a synthetic local baseline used solely to verify diff correctness does **not** satisfy a real-history `review_check.py boundary` run. We ran the boundary command on that snapshot and it **failed** exactly the history-dependent baseline and durable-rewrite ancestry checks; the authoritative full-history check remains unresolved, with no pass claim. An independent `document_drift_audit.py` on the snapshot also reports three missing fixture links in `ORIENTATION.md` (pre-existing at the snapshot base, not introduced by this patch). No `git status -sb` proving origin sync can be claimed from the synthetic repository. If the tool boundary cannot be run on a full-history checkout, record as outstanding procedure rather than fabricating success.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; 497 frozen/unmodified |
| Decisive claims independently re-derived | R1 exact test-only diff; canonical vs oriented source semantics; 28/28 package hashes; 5,859/5,859 snapshot hashes; exact package source SHA and GMP/GMPXX/no-runtime evidence |
| Non-vacuity checked | R1 rejects unmarked canonical topology and shifts; reversed route **still passes** directed oracle, R-2; no runtime was run |
| Prior obligations discharged/carried | R-1 canonical-edge and translation narrow fix discharged; oriented-route identity R-2 carried; RA-152 F1/D1–D4, RA-152.5, 191/192 and G4-B002 still carried |
| Stable accounting | 66/17/49, debt1; CP2 491/491; TB32 481/500 candidate, TB35 11/13; selector497 frozen |
| New candidates/obligations recorded | R-2 test-authority non-stable, tracker updated; accepted-green loss not proved |
| ORIENTATION currency line | CB35-R1-REV 2026-10-24 and R2 corrective successor |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current candidate unchanged, §4 unchanged (no witness executed), §7 R1 superseded by R2, §8 canonical/oriented non-vacuity pattern |
| CHANGELOG | CB35-R1 independent non-acceptance entry |
| ROADMAP | n/a: M6-CP3 stays active, no checkpoint closure |
| Selector manifest | n/a: no new or accepted selector or changed row |
| LESSONS | Existing non-vacuity and semantic identity separation; no distinct general lesson needed |
| Consolidation under CLEAN_UP_POLICY | No active evidentiary docs deleted; R1+RA-152 records remain live proof and referenced predecessors |
| Successor frozen | `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE`; exact falsifiers in R2 plan |
| Turn boundary held | Static read/review + docs only; no test/production/selector/build source or runtime mutation |
| review_check.py boundary | Ran on synthetic snapshot: FAIL (missing genuine baseline/ancestry); real-history verification outstanding, not a pass |
| `STATUS` lifecycle maintained | Entry beacon set at `2026-10-24T23:02:49Z`; final state must follow successful durable patch/cleanup and last-action beacon |
| Pushed to origin, branch in sync | Pending remote patch-application and authoritative branch-sync confirmation; do not treat local synthetic Git baseline as origin sync |
