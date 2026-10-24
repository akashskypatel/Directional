# CB28A independent review — three M1/A5 rejection diagnostics (2026-10-22)

**Canonical turn:** `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV`. **Decision: ACCEPT the exact CB28A diagnostic-only change and immutable compile evidence, not runtime or M6-CP3 acceptance.** This Review executes no compiled binary and mutates no product, test, fixture, selector, build or workflow source. RA-136.2–4 is controlling authority.

## Independent source and artifact verification

- Independently inspected GitHub semantic commit [`4473e41e94a35f1bf189fa046e86bac92c7391fb`](https://github.com/akashskypatel/Directional/commit/4473e41e94a35f1bf189fa046e86bac92c7391fb) and its actual patch: **one file**, `tests/SurfaceCellTransitionQuotientTests.cpp`, +16/−3, with exactly three target assertions, identified by their test identities rather than displaced line numbers. No production code, fixture, expected result, predicate, test selection or workflow change.
- `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` (`focused30:12`): existing `ASSERT_NE(relabelledA5, nullptr)` now streams `a5_rejection_message(relabelledA5Construction)`. This helper uses `std::get_if` and returns an explicit message when the alternative is absent; no unchecked variant access.
- `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` (`focused30:22`) and `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` (`focused30:23`): existing `ASSERT_NE(front, nullptr)` expressions append a `get_if<SurfacePhaseFrontProductError>` conditional. `std::get<SurfacePhaseFrontProductError>` is evaluated only in the true branch; on success the additional text is not needed and GTest's fatal assertion still gates subsequent dereferences. This is failure-formatting, not a route around the assertions.
- Downloaded immutable compile package `12465330920` from [run 39867988763](https://github.com/akashskypatel/Directional/actions/runs/39867988763). Independently computed outer ZIP SHA-256 **`da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`** and verified **28/28** internal manifest entries, including the exact `source/source-4473e41e94a35f1bf189fa046e86bac92c7391fb.tar.gz` archive. Eight targets recorded; preflight and build exit 0/0; generated link command includes `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`, `runtimeExecution=false`. All compilation jobs completed successfully; test-benchmark job skipped. No runtime outcome inferred.
- Separate exact-source snapshot [run 39873583775](https://github.com/akashskypatel/Directional/actions/runs/39873583775), snapshot artifact `12466363994`, outer SHA-256 `435a400f37ae50adc8a3a5a20215e18e01148209c1c684f1d485823b2bd20f31`, was verified and inspected locally. Its source includes later entry-beacon/trigger commits and does not supersede compiled semantic SHA.
- Reused the original 35-row immutable TB28 RED inventory (`66c0ba377c834a969d481cf1ee2253688fa12b7686a0ced6d9da9695e01eb3da`) and source-defined named tests. No CP3 selector bytes or accepted CP2 prefix were altered. **Important:** CP3 497 is a composite selector, not a contiguous extension of accepted CP2 491; no fictitious common-prefix hash claimed.

## Scope, non-vacuity, obligations

The expressions can expose an authentic rejection reason where a previously silent `ASSERT_NE` fails. They cannot force a test PASS or bypass the assertions. Actual messages on the three failing runtime cases are **unmeasured** until TB29. RA-136.2's three missing messages are discharged **statically only**; four A7 negative oracles, the D3/D7 positive witnesses and all 35 inherited TB28 REDs are preserved for TB29. No new stable production regression and no promotion: stable **66/17/49**, produced-witness debt **1**, accepted CP2 **491/491**, rejected R3 **403/497**, candidate TB28 **462/497**, frozen CP3 selector **497**; RP-01 OPEN, RP-02 UNREACHED, Gate C suspended. `DEFN-SEAM-NZ`, periodic and `DIAG-RETAIN` remain conditional/deferred.

**Exactly one successor:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST`. Separate artifact-only targeted 44-identity harness and typed first-failure harvest. Exact scope, package SHA, 4 new A7 negatives, D3/D7, three A7 guards, 35 TB28 RED identities, fail-closed execution boundaries, independent checks and falsifiers: `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`. **No TB29 execution occurred in this Review.** Next independent gate after TB29 is `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV`; do not enter it until TB29 completes and its evidence is independently inspectable.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector appended or accepted; CP2 491 and frozen composite 497 are distinct authorities; CB28A touched only TQ messages. |
| Decisive claims independently re-derived | Exact GitHub one-file diff, three target test names, guarded expression semantics, 28/28 package manifest, SHA, GMP/GMPXX link, preflight/build 0/0, compile-only boundary. |
| Non-vacuity checked | Failure-only streaming preserves fatal assertion; three missing reasons become observable, but their actual runtime content remains unproven. |
| Prior obligations discharged/carried | RA-136.2 three diagnostics discharged statically; RA-136.4 four A7 negatives, D3/D7, A7 guards and 35 inherited REDs carried intact to TB29. |
| Stable accounting | 66/17/49; debt 1; CP2 491/491 accepted; R3 403/497 rejected; TB28 462/497 candidate; CP3 selector 497 frozen. |
| New candidates/obligations recorded | None; TB29 harvest is the existing RA-136.4 obligation, no new regression or selector mutation. |
| ORIENTATION currency line | Updated to CB28A-REV accepted, TB29 next (2026-10-22). |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current handoff corrected; §4 unchanged, no new witness; §8 existing causal-diagnostic/non-vacuity pattern, no novel case. |
| CHANGELOG | One CB28A-REV acceptance / TB29 next entry added. |
| ROADMAP | CP3 remains active; stale “CB27 next” summary corrected; no gate promotion. |
| Selector manifest | n/a — byte-frozen selector unchanged. |
| LESSONS | Existing evidence/non-vacuity and diagnostic reason distinctions (§§1,2,5,7) apply; no novel pattern. |
| Consolidation under CLEAN_UP_POLICY | No historical deletion: RA-136 / CB28A record and 35-row inventory remain load-bearing. |
| Successor frozen | `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST`, typed-cause harvest plan includes explicit 44-case contract and falsifiers. |
| Turn boundary held | Review-only: no compile, binary execution or source/test/fixture/selector/workflow mutation. |
| review_check.py boundary | Ran read-only on snapshot-derived archive. Product/selector check initially reported clean, but historical rewrite-base ancestry check fails because exported source contains no Git history. **Full genuine Git-history gate not certified**; exact GitHub commit diff and package checks are independent bounded evidence. |
| `STATUS` lifecycle maintained | Entry beacon written; final direct closeout beacon is separately committed as last repository action after documentation and cleanup. |
| Pushed to origin, branch in sync | Verify remote doc commit and branch head after patch application. This Web snapshot has no `.git`; no local `git status -sb` sync claim. |
